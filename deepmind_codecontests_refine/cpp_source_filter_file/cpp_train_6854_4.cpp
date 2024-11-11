#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    S += "000";
    cout << (S.substr(0, 4) == "YAKI") ? "Yes" : "No" << endl;
    return 0;
}