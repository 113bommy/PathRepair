#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    map<int> mp;
    mp[0]=1;
    int sm=0
    ll ans=0;
    for (int i=0;i<n;i++) {
        int a;cin>>a;
        sm=(sm+a)%m;
        ans+=mp[sm];
        mp[sm]++;
    }
    cout<<ans<<endl;
    return 0;
}