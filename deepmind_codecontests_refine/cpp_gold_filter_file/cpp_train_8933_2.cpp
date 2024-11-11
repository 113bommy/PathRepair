#include <iostream>
using namespace std;
typedef long long ll;
ll n,m,MOD=998244353,a,b,ans,bik[300001],A[300001],B[300001];
ll f(ll x,ll y){
    if(y==0)return 1;
    if(y%2==0)return f(x,y/2)*f(x,y/2)%MOD;
    return x*f(x,y-1)%MOD;
}
ll comb(ll x, ll y){
    return bik[x]*f(bik[x-y],MOD-2)%MOD*f(bik[y],MOD-2)%MOD;
}
int main(void){
    bik[0]=1;
    for(ll i=1;i<=300000;i++){
        bik[i]=bik[i-1]*i;
        bik[i]%=MOD;
    }
    cin>>n>>a>>b>>m;
    for(ll i=0LL;i<=min(n,(m/a));i++){
        A[i]=comb(n,i);
    }
    for(ll i=0LL;i<=min(n,(m/b));i++){
        B[i]=comb(n,i);
    }
    for(ll i=0LL;i<=min(n,(m/a));i++){
        if((m-i*a)%b==0&&(m-i*a)/b<=n){
            ans+=A[i]*B[(m-i*a)/b]%MOD;
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}
