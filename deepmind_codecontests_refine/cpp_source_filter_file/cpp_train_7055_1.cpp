#include<vector>
#include<iostream>
#include<list>
#include<algorithm>
#include<chrono>
#include<map>
#include<set>
#include<string>
#include<unordered_map>


using namespace std;
typedef long long ll;
const int mod=1e9+7;

ll qpow(ll a,ll n){
    ll res=1;
    while(n)
    {
        if(n&1) res = res*a%mod;
        a=a*a%mod;
        n >> = 1;
    }
    return res;
}

int n,m;
ll ans,f[500005]={1},inv[500005]={1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>m;
    for(int i=1;i<=5e5;i++){
        f[i] = f[i-1] * i%mod;
        inv[i] = qpow(f[i],mod-2); //质数模下的逆元，根据费马定理
    }
    for(int i=0;i<=n;i++){
        ans = (ans+ ((i&1)?-1:1)*f[n]*inv[i]%mod*inv[n-i]%mod*f[m]%mod*inv[m-i]%mod*f[m-i]%mod*inv[m-n]%mod*f[m-i]%mod*inv[m-n]%mod)%mod;
    }
    cout<<(ans+mod)%mod<<endl;
    return 0;
}