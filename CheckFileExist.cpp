#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <time.h>

using namespace std;

bool checkFileWithFstream(string path) {
    ifstream isf(path);
    return isf.good();
}

bool checkFileWithFopen(string path) {
    FILE *file;
    errno_t err;
    if ((err = fopen_s(&file, path.c_str(), "r")) == 0) {
        fclose(file);
        return true;
    }

    return false;
}

bool checkFileWithAccess(string path) {
    return false;
}

bool checkFileWithStat(string path) {
    struct stat buffer;
    return stat(path.c_str(), &buffer) == 0;
}

int main()
{
    string path[10] = { "temp.txt", "temp1.txt", "temp2.txt", "temp3.txt", "temp4.txt", "temp5.txt", "temp6.txt", "temp7.txt", "temp8.txt", "temp9.txt" };
    clock_t t = clock();
    cout << "-checkFileWithFstream" << endl;
    for (string t : path) {
        if (checkFileWithFstream(t))
            cout << t << ": File exists." << endl;
        else
            cout << t << ": File does not exists." << endl;
    }
    t = clock() - t;
    cout << "--> " << t << " ticks ~ " << ((float)t) / CLOCKS_PER_SEC << " secs." << endl << endl;

    t = clock();
    cout << "-checkFileWithFopen" << endl;
    for (string t : path) {
        if (checkFileWithFopen(t))
            cout << t << ": File exists." << endl;
        else
            cout << t << ": File does not exists." << endl;
    }
    t = clock() - t;
    cout << "--> " << t << " ticks ~ " << ((float)t) / CLOCKS_PER_SEC << " secs." << endl << endl;

    t = clock();
    cout << "-checkFileWithStat" << endl;
    for (string t : path) {
        if (checkFileWithStat(t))
            cout << t << ": File exists." << endl;
        else
            cout << t << ": File does not exists." << endl;
    }
    t = clock() - t;
    cout << "--> " << t << " ticks ~ " << ((float)t) / CLOCKS_PER_SEC << " secs." << endl << endl;
}