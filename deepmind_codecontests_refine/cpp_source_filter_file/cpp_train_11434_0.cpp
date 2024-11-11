#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N=3e3+2;
ll mod,g[N][N],C[N][N],f[N];

ll modpow(ll x,ll y,ll p,ll res=1) {
    for(;y;y>>=1,x=x*x%p) if(y&1) res=res*x%p;
    return res;
}

int main() {
    int n;scanf("%d%lld",&n,&mod);
    for(int i=0;i<=n;++i) {
        C[i][0]=g[i][0]=1;
        for(int j=1;j<=i;++j) 
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod,
            g[i][j]=(g[i-1][j-1]+1ll*(j+1)*g[i-1][j]%mod)%mod;
    }
    ll ans=0;
    for(int i=0;i<=n;++i) {
        ll k=C[n][i];
        if(i&1) k=mod-k;
        ll x=pow(2,n-i,mod-1);x=pow(2,x,mod);
        ll num=pow(2,n-i,mod),y=1,res=0;
        for(int j=0;j<=i;++j)
            res=(res+1ll*g[i][j]*y%mod)%mod,y=num*y%mod;
        ans=(ans+k*res%mod*x%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}