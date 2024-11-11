#include <bits/stdc++.h>
using namespace std;
void main(){
    int t, a=0, m=0, k=5;
    while (k--) {
        cin >> t;
        a += (t+9)/10*10;
        m = max(m, (990-t)%10);
    }
    cout << a-m << endl;
}