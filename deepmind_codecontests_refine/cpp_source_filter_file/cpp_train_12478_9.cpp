#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int count=0;
    for(int i=1;i<=n;i++){
        if(s.substr(n-i,i)==t.substr(0.i)) count=i;
    }
    cout << n+n-count << endl;
}