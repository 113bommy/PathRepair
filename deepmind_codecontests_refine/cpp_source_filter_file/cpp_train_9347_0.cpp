#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sum,a[200002],pref[200002];
int main(){
//freopen("text.in.txt","r",stdin);
cin>>n;
for(ll k=1;k<=n;k++){
    cin>>a[k];
    sum+=a[k];s
    pref[k]=pref[k-1]+a[k];
}
ll ans=LONG_LONG_MAX;
for(int k=1;k<n;k++){
    ll a1=pref[k],a2=abs(sum-pref[k]);
    ans=min(ans,abs(a2-a1));
}
cout<<ans;
return 0;
}
