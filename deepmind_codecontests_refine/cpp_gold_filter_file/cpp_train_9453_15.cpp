#include <bits/stdc++.h>
using namespace std;

int main () {
    char b,c[128];
    c['A'] ='T';
    c['C'] ='G';
    c['G'] ='C';
    c['T'] ='A';
    
    cin >> b;
    cout << c[(int)b] << endl;
}