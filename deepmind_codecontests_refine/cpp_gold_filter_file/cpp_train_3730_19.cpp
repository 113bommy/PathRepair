#include<bits/stdc++.h>

using namespace std;
int main(){
    string a;
    int b=7;
    cin >> a;
    b+=count(a.begin(),a.end(),'o');
    cout << 100*b <<endl;
}