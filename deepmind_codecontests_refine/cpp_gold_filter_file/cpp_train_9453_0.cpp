#include <bits/stdc++.h>
using namespace std;

int main(){
    map<string,string> mp;
    mp["A"]="T";mp["T"]="A",mp["C"]="G",mp["G"]="C";
    string s;
    cin >> s;
    cout << mp[s];
}
