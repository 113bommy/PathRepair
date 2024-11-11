#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k,t;
    cin >> k >> t;
    long long total=0;
    long long a[t];
    for(int i=0;i<t;i++){
        cin >> a[i];
        total+=a[i];
    }
    sort(a,a+t);
    total-=a[t-1];
    cout << max(0,a[t-1]-total-1) << endl;
}