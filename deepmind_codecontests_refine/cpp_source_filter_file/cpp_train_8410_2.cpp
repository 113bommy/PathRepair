#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
using ll = long long;
using namespace std;
ll n,k,s=0,a[550],b[550],ans=0;
ll f(ll p){
    ll s2=0,s3=0;
    rep(i,0,n){b[i]=a[i]%p;s2+=b[i];}
    sort(b,b+n);
    rep(i,0,n-s2/p)s3+=b[i];
    return s3<=k?p:0;
}
int main(){
    cin>>n>>k;
    rep(i,0,n) {cin>>a[i];s+=a[i];}
    for(ll p=1;(p*p)<=s;p++) if(s%p==0){
        ans=max(ans,f(p));
        ans=max(ans,f(s/p));
    cout<<ans;
}