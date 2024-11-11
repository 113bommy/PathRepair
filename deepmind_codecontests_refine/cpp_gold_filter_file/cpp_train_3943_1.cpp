#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1000000007;
ll fact[200002];
ll ncr[200003];

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res=(res*a)%mod;
        
       b>>=1;
       a=(a*a)%mod;
       
    }

return res;
}

ll solve(ll x, ll y) {
    ll res = fact[x+y];
    res=(res*ncr[x])%mod;
    res=(res*ncr[y])%mod;
return res;
}

int main() {
    fact[0]=1;
    ncr[0]= 1;
    for(int x=1; x<=2e5;x++) {fact[x] = (x*fact[x-1])%mod;
        ncr[x] = power(fact[x],mod-2);
    }

    ll h,w,a,b;
    cin>>h>>w>>a>>b;
    ll y = h-a-1;
    ll ans = 0;
    for(int i=b;i<w;i++) {
        ll r1=solve(y,i);
        ll r2=solve(h-y-2,w-i-1);

        ans+=(r1*r2)%mod;
        ans=ans%mod;
    }

    cout<<ans<<endl;

}

