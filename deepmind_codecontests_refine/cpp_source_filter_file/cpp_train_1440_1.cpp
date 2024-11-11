#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, i;
    cin >> n >> x;
    int m[n];
    for(i=0; i<n; i++){
        cin >> m[i];
        x -= m[i];
    }
    sort(m, m+n);
    cout >> n + x/m[0];
    return 0;
}