#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    bool flag = true;
    map<char,char> A, iA;
    for (int i = 0; i < S.size(); ++i) {
        char s = S[i], t = T[i];
        if (A.count(s) && A[s] != t) flag = false;
        if (iA.count(t) && iA[t] != s) flag = false;
        ma[s] = t; ima[t] = s;
    }
    cout << (flag?"Yes":"no") << endl; 
}