#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353,N=400010;
ll n,m,k,ans,jc[N],in[N],jcin[N];
ll exp(ll b,ll e,ll l){
	if(e==0) return 1;
	ll tmp=exp(b,e>>1,l);
	if(e&1) return tmp*tmp%l*b%l;
	else return tmp*tmp%l;
}
ll c(ll x,ll y){
	return jc[x]*jcin[y]%mod*jcin[x-y]%mod;
}
int main()
{
	scanf("%lld %lld %lld",&n,&m,&k);
	jc[0]=jcin[0]=1;
	jc[1]=in[1]=jcin[1]=1;
	for(ll i=2;i<N;++i){
		jc[i]=jc[i-1]*i%mod;
		in[i]=(mod-mod/i)*in[mod%i]%mod;
		jcin[i]=jcin[i-1]*in[i]%mod;
	}
	for(ll i=0;i<=k;++i){
		ll j=n-i;
		ans+=m*exp(m-1,j-1,mod)%mod*c(i+j-1,j-1)%mod;
		ans%=mod;
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}