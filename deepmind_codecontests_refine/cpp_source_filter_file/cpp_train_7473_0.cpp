#include<bits/stdc++.h>
#define rp(i,n) for(ll i=0; i<n; i++)
using namespace std;
using ll=long long;

ll RepeatSquare(ll x,ll n,ll mod){
    if(n==0) return 1;
    if(n==1) return x%mod;
    if(n%2==0){
        ll half=RepeatSquare(x,n/2,mod);
        return (half*half)%mod;
    }
    if(n%2==1){
        return x*RepeatSquare(x,n-1,mod)%mod;
    }
}

int main(){
    ll n;
    cin >> n;
    vector<ll> c(n);
    rp(i,n) cin >> c.at(i);
    sort(c.begin(),c.end());
    reverse(c.begin(),c.end());
    ll ans=0;
    ll x=RepeatSquare(4,n-1,1000000007);
    rp(i,n){
        ans += c.at(i)*(i+2);
        ans %=1000000007
    }
    ans *= x;
     ans %= 1000000007;
     cout << ans << endl;
     return 0;
}