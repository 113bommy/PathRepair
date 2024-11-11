#include<bits/stdc++.h>
using namespace std;
const int N=2005,mod=1000000007;
int n,k,dp[N][N],fac[N*N],ifac[N*N];
int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)r=1ll*r*a%mod;return r;}
int C(int a,int b){return a<0||b<0||a<b?0:1ll*fac[a]*ifac[b]%mod*ifac[a-b]%mod;}
int main()
{
	for(int i=fac[0]=1;i<N*N;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N*N-1]=pw(fac[N*N-1],mod-2);
	for(int i=N*N-1;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	scanf("%d%d",&n,&k);
	if(k==1){puts("1");return 0;}
	dp[0][0]=1;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)
	{
		if(i)dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		if(j)dp[i][j]=(dp[i][j]+1ll*dp[i][j-1]*C(n*k-i-(j-1)*(k-1)-1,k-2))%mod;
	}
	printf("%d\n",1ll*dp[n][n]*fac[n]%mod);
	return 0;
}