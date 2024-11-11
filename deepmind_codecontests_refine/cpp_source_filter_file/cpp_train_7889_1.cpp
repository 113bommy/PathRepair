#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;

int quickpow(int x,int y)
{
	long long res=1,base=x;
	while(y)
	{
		if(y&1) res*=base,res%=mod;
		y>>=1; base*=base,base%=mod;
	}
	return res;
}
int inv(int x){return quickpow(x,mod-2);}

int prod[1000001];
int iprod[1000001];
int c(int n,int m){return 1ll*prod[n]*iprod[n-m]%mod*iprod[m]%mod;}

int solve2(int n,int m,int s,int l,int r)
{
	s-=m*r;
	if(s<0) return 0;
	int ans=0;
	for(int i=0;i<=n-m&&s-i*l>=0;i++)
	{
		ans=ans+1ll*((i%2==0)?1:-1)*c(s-i*l+n,n)*c(n-m,i)%mod;
		ans%=mod;
	}
	return 1ll*(ans+mod)*c(n,m)%mod;
}

int solve(int n,int m,int s)
{
	int ans=c(s+n,n);
	for(int i=0;i<=s;i++)
		ans=(ans-solve2(n,m,s,i,i)+solve2(n,m,s,i,i+1))%mod;
	return 1ll*(ans+mod)%mod%mod;
}
int main()
{
	int n,m,l,r;
	scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
	
	prod[0]=1,iprod[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		prod[i]=1ll*prod[i-1]*i%mod;
		iprod[i]=inv(prod[i]);
	}
	printf("%lld",(solve(n,m,r)-solve(n,m,l-1)+mod)%mod);
	return 0;
}
