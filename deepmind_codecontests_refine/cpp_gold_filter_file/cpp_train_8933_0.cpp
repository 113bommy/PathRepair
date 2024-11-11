#include<cstdio>
#include<cassert>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
const ll mod = 998244353;



ll inv[maxn] ,fac[maxn];


void prec(int n){
	inv[0] = 1;inv[1] = 1;fac[1] = 1;fac[0]= 1;
	for(int i = 2;i <= n;i++) inv[i] = mod - inv[mod % i] * (mod / i) % mod ;
	for(int i = 2;i <= n;i++) inv[i] = (inv[i] * inv[i - 1]) % mod,fac[i] = (fac[i - 1] * i) % mod;
}
ll C(ll n,ll m){ if(n < m) return 0;return inv[m] * inv[n - m] % mod * fac[n] % mod;	}

int main(){
	ll n,A,B,k;
	prec(maxn - 1);
	scanf("%lld%lld%lld%lld",&n,&A,&B,&k);
	ll ans = 0;
	for(ll a = 0;a <= n;a++){
		ll x = k - a * A;
		if(x < 0) continue;
		if(x % B) continue;
		ll b = x / B;
		if(b > n || b < 0 ) continue; 
		ans = (ans + C(n,a) * C(n,b) % mod) % mod;
	}	
	printf("%lld\n",ans);
}