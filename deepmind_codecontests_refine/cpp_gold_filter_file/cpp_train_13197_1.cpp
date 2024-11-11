#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    ll ans=0;
    for (int i=0;i<n-1;i++)
        ans+=a[(i+1)/2];
    cout<<ans<<endl;
    return 0;
}