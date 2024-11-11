#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, i, m = 0, s = 0;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> p;
        s += p;
        m = max(m, p)
    }
    cout << s - m/2;
    return 0;
}