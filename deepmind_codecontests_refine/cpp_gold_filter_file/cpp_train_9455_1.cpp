#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    int ans=a[0];
    for(int i=1;i<n-1;i++)if(abs((double)ans-(double)(a[n-1]*1.0/2))>abs((double)a[i]-(double)(a[n-1]*1.0/2)))ans=a[i];
    cout << a[n-1] << " " << ans << endl;
}