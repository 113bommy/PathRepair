#include<bits/stdc++.h>
#define REP(i,n)for(ll i=0;i<n;i++)
#define MP make_pair
#define F first
#define S second
typedef long long ll;
using namespace std;
int main(){
    ll n,k,s,t,a[50];cin>>n>>k>>s>>t;
    REP(i,n)cin>>a[i];
    map<pair<ll,ll>,ll> dp[50];
    REP(i,n){
        for(ll j=k-2;j+1;j--){
            for(const auto&l:dp[j]){
                dp[j+1][MP((l.F.F)&a[i],(l.F.S)|a[i])]+=(l.S);
            }
        }
        dp[0][MP(a[i],a[i])]=1;
    }
    n=0;
    REP(i,k)n+=(dp[i][MP(s,t)]);
    cout<<n;
}