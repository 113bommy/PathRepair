#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, n, res1 = 0, res2 = 0;
    cin >> n;
    int a[n];
    for(i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    res2 = a[n-1];
    res1 = a[0];
    for(i=1; i<n-1; i++){
        if(a[i] < 0){
            res2 -= a[i];
        }else{
            res1 -= a[i];
        }
    }
    cout << res2 - res1 << '\n';
    res2 = a[n-1];
    res1 = a[0];
    for(i=1; i<n-1; i++){
        if(a[i] < 0){
            cout << res2 << ' ' << a[i] << '\n';
            res2 -= a[i];
        }else{
            cout << res1 << ' ' << a[i] << '\n';
            res1 -= a[i];
        }
    }
    cout << res2 << ' ' << res1;
    return 0;
}