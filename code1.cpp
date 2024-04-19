//final project cs002 sophia wei feburary 16, 2024

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
// #include <iomainip>

using namespace std;

ifstream inStream1;
ifstream inStream2;

void openfile1(string fileName1) { //used to open external file
    inStream1.open(fileName1);
    if (inStream1.fail()) {
        cout << "Input file opening failed. \n";
        exit(1);
    }
}

void openfile2(string fileName2) {
    inStream2.open(fileName2);
    if (inStream2.fail()) {
        cout << "Input file opening failed. \n";
        exit(1);
    }
}

void makeOriginalData(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]) { //case1 without print
    int id_temp[numstudents], cppscore_temp[numstudents], javascore_temp[numstudents];
    int count = 0;
    while (count < numstudents && inStream2 >> id_temp[count] >> cppscore_temp[count] >> javascore_temp[count]) {
        count++; //read all inputs in file inStream2 and store id to temp
    }
    for (int i = 0; i < numstudents; i++) {
        inStream1 >> id1[i] >> name[i];
        for (int j = 0; j < numstudents; j++) {
            if (id1[i] == id_temp[j]) {
                cppscore[i] = cppscore_temp[j]; //replace temp with correct number found at SAME index as id1 (inStream1)
                javascore[i] = javascore_temp[j];
            }
        }
    }
}

void printOriginalData(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]){ //case1 WITH print
    makeOriginalData(numstudents, id1, name, cppscore, javascore);
    for (int i = 0; i < numstudents; i++){ //prints showOriginalData array
        cout << id1[i] << " " << name[i] << " " << cppscore[i] << " " << javascore[i] << endl;
    }
}

void showDataAscendingOrder(int id1[], string name[], int cppscore[], int javascore[], int numstudents) { //case 2 using insertion sort
    makeOriginalData(numstudents, id1, name, cppscore, javascore);

    for (int i = 1; i < numstudents; i++) { //sorts through all arrays at once at same index
        int key_id = id1[i];
        string key_name = name[i];
        int key_cppscore = cppscore[i];
        int key_javascore = javascore[i];
        int j = i - 1;

        while (j >= 0 && id1[j] > key_id) {
            id1[j + 1] = id1[j];
            name[j + 1] = name[j];
            cppscore[j + 1] = cppscore[j];
            javascore[j + 1] = javascore[j];
            j--;
        }
        id1[j + 1] = key_id;
        name[j + 1] = key_name;
        cppscore[j + 1] = key_cppscore;
        javascore[j + 1] = key_javascore;
    }
    for (int i = 0; i < numstudents; i++){ //prints sorted array
        cout << id1[i] << " " << name[i] << " " << cppscore[i] << " " << javascore[i] << endl;
    }

}

void showAverageOfEachCourse(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]){//case3
    makeOriginalData(numstudents, id1, name, cppscore, javascore);
    int cppSum = 0;
    int javaSum = 0;

    for (int i = 0; i < numstudents; i++) { //parse through array and add to total sum
        cppSum += cppscore[i];
        javaSum += javascore[i];
    }

    double cppAverage = static_cast<double>(cppSum) / numstudents; //ensure average is double to allow for decimals; ensure when dividing that one number is double so average is double
    double javaAverage = static_cast<double>(javaSum) / numstudents;

    cout.setf(ios::fixed); //used to set value to 2 decimal points
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Average CPP Score: " << setprecision(2) << cppAverage << endl; 
    cout << "Average Java Score: " << setprecision(2) << javaAverage << endl;
};

void showCppScoreDescendingOrder(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]){ //case4 using insertion sort
    makeOriginalData(numstudents, id1, name, cppscore, javascore);
    for (int i = 1; i < numstudents; i++) { //sorts through all arrays at once at same index
        int key_id = id1[i]; //make a key for every array and sort thorugh the arrays using insertion sort
        string key_name = name[i];
        int key_cppscore = cppscore[i];
        int key_javascore = javascore[i];
        int j = i - 1;

        while (j >= 0 && (cppscore[j] < key_cppscore || (cppscore[j] == key_cppscore && javascore[j] < key_javascore))) { //sort in desceding order with <key_cppscore; if cppscore = keyscore then sort javascore in descending
            id1[j + 1] = id1[j];
            name[j + 1] = name[j];
            cppscore[j + 1] = cppscore[j];
            javascore[j + 1] = javascore[j];
            j--;
        }

        id1[j + 1] = key_id;
        name[j + 1] = key_name;
        cppscore[j + 1] = key_cppscore;
        javascore[j + 1] = key_javascore;

    }

    for (int i = 0; i < numstudents; i++){ //prints sorted array
        cout << id1[i] << " " << name[i] << " " << cppscore[i] << " " << javascore[i] << endl;
    }

}

void makeCppScoreDescendingOrder(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]){ //case4 using insertion sort without print
    makeOriginalData(numstudents, id1, name, cppscore, javascore);
    for (int i = 1; i < numstudents; i++) { //sorts through all arrays at once at same index
        int key_id = id1[i]; //make a key for every array and sort thorugh the arrays using insertion sort
        string key_name = name[i];
        int key_cppscore = cppscore[i];
        int key_javascore = javascore[i];
        int j = i - 1;

        while (j >= 0 && (cppscore[j] < key_cppscore || (cppscore[j] == key_cppscore && javascore[j] < key_javascore))) { //sort in desceding order with <key_cppscore; if cppscore = keyscore then sort javascore in descending
            id1[j + 1] = id1[j];
            name[j + 1] = name[j];
            cppscore[j + 1] = cppscore[j];
            javascore[j + 1] = javascore[j];
            j--;
        }

        id1[j + 1] = key_id;
        name[j + 1] = key_name;
        cppscore[j + 1] = key_cppscore;
        javascore[j + 1] = key_javascore;

    }

}

void makeJavaScoreDescendingOrder(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]){ //case4 using insertion sort
    makeOriginalData(numstudents, id1, name, cppscore, javascore);
    for (int i = 1; i < numstudents; i++) { //sorts through all arrays at once at same index
        int key_id = id1[i]; //make a key for every array and sort thorugh the arrays using insertion sort
        string key_name = name[i];
        int key_cppscore = cppscore[i];
        int key_javascore = javascore[i];
        int j = i - 1;

        while (j >= 0 && (javascore[j] < key_javascore)) { //sort in desceding order with <key_cppscore; if cppscore = keyscore then sort javascore in descending
            id1[j + 1] = id1[j];
            name[j + 1] = name[j];
            cppscore[j + 1] = cppscore[j];
            javascore[j + 1] = javascore[j];
            j--;
        }

        id1[j + 1] = key_id;
        name[j + 1] = key_name;
        cppscore[j + 1] = key_cppscore;
        javascore[j + 1] = key_javascore;

    }

}

void showTopThreeJavaStudents( int numstudents,  int id1[],  string name[],   int cppscore[],  int javascore[]){
    makeJavaScoreDescendingOrder(numstudents, id1, name, cppscore, javascore); //sort score data
    //begin code for finding 3 max Java scores
    int javaMax1 = 0, javaMax2 = 0, javaMax3 = 0;
    int javaMax1Count = 0, javaMax2Count = 0, javaMax3Count = 0;
    int topJavaScoreid1[numstudents], topJavaScoreid2[numstudents], topJavaScoreid3[numstudents];
    string topJavaScorename1[numstudents], topJavaScorename2[numstudents], topJavaScorename3[numstudents];

    //find the 3 max java score's
    for (int i = 0; i < numstudents; i++) {
        if (javascore[i] > javaMax1) {
            javaMax3 = javaMax2;
            javaMax2 = javaMax1;
            javaMax1 = javascore[i];
        } else if (javascore[i] > javaMax2 && javascore[i] < javaMax1) {
            javaMax3 = javaMax2;
            javaMax2 = javascore[i];
        } else if (javascore[i] > javaMax3 && javascore[i] < javaMax2) {
            javaMax3 = javascore[i];
        }
    }

    for (int i = 0; i < numstudents; i++) {  //read through array to find values that match max score numbers
        if (javascore[i] == javaMax1) {
            topJavaScoreid1[javaMax1Count] = id1[i]; //input id into new array
            topJavaScorename1[javaMax1Count] = name[i]; //input name into new array
            javaMax1Count++; //increase count of max1 (first max) number
        } else if (javascore[i] == javaMax2) { //repeat for other max numbers 
            topJavaScoreid2[javaMax2Count] = id1[i];
            topJavaScorename2[javaMax2Count] = name[i];
            javaMax2Count++;
        } else if (javascore[i] == javaMax3) {
            topJavaScoreid3[javaMax3Count] = id1[i];
            topJavaScorename3[javaMax3Count] = name[i];
            javaMax3Count++;
        }
    }

    // print top 3 java students
    cout << "*** Java Rank ***" << endl;
    cout << " [ " << javaMax1 << " ("<<javaMax1Count << " students) ] "<< endl;
    for (int i = 0; i < javaMax1Count; i++) {
        cout << setw(5) << "<" <<  topJavaScoreid1[i] << "> " << setw(15) << topJavaScorename1[i] << endl; //print out new array with stored id
    }
    cout << " [ " <<  javaMax2 << "("<<javaMax2Count << " students) ] " << endl;
    for (int i = 0; i < javaMax2Count; i++) {
        cout << setw(5) << "<" << topJavaScoreid2[i] << "> " << setw(15) << topJavaScorename2[i] << endl;
    }
    cout << " [ " <<  javaMax3 << "("<<javaMax3Count << " students) ] " << endl;
    for (int i = 0; i < javaMax3Count; i++) {
        cout << setw(5) << "<" <<  topJavaScoreid3[i] << "> " << setw(15) << topJavaScorename3[i] << endl;
    }
}

void showTopThreeCppStudents(int numstudents, int id1[], string name[],  int cppscore[], int javascore[]){ //case4 WITH print
    makeCppScoreDescendingOrder(numstudents, id1, name, cppscore, javascore); //sort score data
    //begin code for finding 3 max cpp scores
    int cppMax1 = 0, cppMax2 = 0, cppMax3 = 0;
    int cppMax1Count = 0, cppMax2Count = 0, cppMax3Count = 0;
    int topScoreid1[numstudents], topScoreid2[numstudents], topScoreid3[numstudents];
    string topScorename1[numstudents], topScorename2[numstudents], topScorename3[numstudents];

    //find the 3 max cpp score's
    for (int i = 0; i < numstudents; i++) {
        if (cppscore[i] > cppMax1) {
            cppMax3 = cppMax2;
            cppMax2 = cppMax1;
            cppMax1 = cppscore[i];
        } else if (cppscore[i] > cppMax2 && cppscore[i] < cppMax1) {
            cppMax3 = cppMax2;
            cppMax2 = cppscore[i];
        } else if (cppscore[i] > cppMax3 && cppscore[i] < cppMax2) {
            cppMax3 = cppscore[i];
        }
    }

    for (int i = 0; i < numstudents; i++) {  //read through array to find values that match max score numbers
        if (cppscore[i] == cppMax1) {
            topScoreid1[cppMax1Count] = id1[i]; //input id into new array
            topScorename1[cppMax1Count] = name[i]; //input name into new array
            cppMax1Count++; //increase count of max1 number
        } else if (cppscore[i] == cppMax2) {
            topScoreid2[cppMax2Count] = id1[i];
            topScorename2[cppMax2Count] = name[i];
            cppMax2Count++;
        } else if (cppscore[i] == cppMax3) {
            topScoreid3[cppMax3Count] = id1[i];
            topScorename3[cppMax3Count] = name[i];
            cppMax3Count++;
        }
        
    }

    // print top 3 c++ students
    cout << "*** C++ Rank ***" << endl;
    cout << " [ " << cppMax1 << " ("<<cppMax1Count << " students) ] "<< endl;
    for (int i = 0; i < cppMax1Count; i++) {
        cout << setw(5) << "<" <<  topScoreid1[i] << "> " << setw(15) << topScorename1[i] << endl; //print out new array with stored id
    }
    cout << " [ " <<  cppMax2 << "("<<cppMax2Count << " students) ] " << endl;
    for (int i = 0; i < cppMax2Count; i++) {
        cout << setw(5) << "<" << topScoreid2[i] << "> " << setw(15) << topScorename2[i] << endl;
    }
    cout << " [ " <<  cppMax3 << "("<<cppMax3Count << " students) ] " << endl;
    for (int i = 0; i < cppMax3Count; i++) {
        cout << setw(5) << "<" <<  topScoreid3[i] << "> " << setw(15) << topScorename3[i] << endl;
    }

    showTopThreeJavaStudents(numstudents, id1, name, cppscore, javascore);
}

int main() {
    
    string fileName1, fileName2;
    int input;
    const int numstudents = 36;
    int id1[numstudents], cppscore[numstudents], javascore[numstudents]; //define 4 arrays to the size of numstudents
    string name[numstudents];

    cout << "Enter the fileName1 : "; //student.txt
    cin >> fileName1;
    cout << "Enter the fileName2 : "; //score.txt
    cin >> fileName2;

    openfile1(fileName1);
    openfile2(fileName2);

    cout << "------------------------------------------" << endl;
    cout << "                    Menu                  " << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Show original data" << endl;
    cout << "2. Show data in ascending order of ID" << endl;
    cout << "3. Show average of each course" << endl;
    cout << "4. Show C++ score in descending order" << endl;
    cout << "5. Show top three students of C++ and Java" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose one menu (1~6) : ";
    cin >> input;

    
    switch (input) { //use switch to parse through menu
        case 1:
            cout << "***** Menu 1 Result ****" <<endl;
            cout << "------------------------" <<endl;
            printOriginalData(numstudents, id1, name, cppscore, javascore);
            break;
        case 2:
            cout << "***** Menu 2 Result ****" <<endl;
            cout << "------------------------" <<endl;
            showDataAscendingOrder(id1, name, cppscore, javascore, numstudents);
            break;
        case 3:
            cout << "***** Menu 3 Result ****" <<endl;
            cout << "------------------------" <<endl;
            showAverageOfEachCourse(numstudents, id1, name, cppscore, javascore);
            break;
        case 4:
            cout << "***** Menu 4 Result ****" <<endl;
            cout << "------------------------" <<endl;
            showCppScoreDescendingOrder(numstudents, id1, name, cppscore, javascore);
            break;
        case 5:
            cout << "***** Menu 5 Result ****" <<endl;
            cout << "------------------------" <<endl;
            showTopThreeCppStudents(numstudents, id1, name, cppscore, javascore);
            break;
        case 6:
            break;
    }

    inStream1.close();
    inStream2.close();

    return 0;
}
