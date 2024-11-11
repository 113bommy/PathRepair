#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define int long long

using namespace std;

const int mo=998244353;

int n,a,b,ans=0,jie[1000001],inv[1000001],k,x0,y0;

int C(int o,int p) {return 1ll*jie[o]*inv[p]%mo*inv[o-p]%mo;}

int mi(int o,int p)
{
	int u=1;
	while(p>0)
	{
		if(p&1) u=1ll*u*o%mo;
		o=1ll*o*o%mo;
		p>>=1;
	}
	return u;
}

signed main()
{
	jie[0]=inv[0]=1;
	for(int i=1;i<=1000000;i++) jie[i]=1ll*jie[i-1]*i%mo;
	for(int i=1;i<=1000000;i++) inv[i]=mi(jie[i],mo-2);
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	for(int i=0;(i<=n)&&(i*a<=k);i++)
	{
		if((k-i*a)%b!=0) continue;
		if(((k-i*a)/b)>n) continue;
		ans=(ans+1ll*C(n,i)*C(n,(k-i*a)/b)%mo)%mo;
	}
	cout<<ans<<endl;
	return 0;
}