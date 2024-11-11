#include<bits/stdc++.h>
 using namespace std;
#define LL long long
#define P pair<LL,LL>
 const LL inf = 0x3f3f3f3f;
 const LL mod = 924844033;
 const LL N = 4e3+10;
 template <typename tp> inline void read(tp &x)
{
	x=0;char c=getchar();int f=0;
	for(;c>'9'||c<'0';f|=(c=='-'),c=getchar());
	for(;c<='9'&&c>='0';x=(x<<3)+(x<<1)+c-'0',c=getchar());
	if(f) x=-x;
}
int n,k,ans;
int vis[N][2],tot,en[N];
LL dp[N][N][2],f[N],fac[N];
signed main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
			if(!vis[i][j])
			{
				for(int x=i,y=j;x<=n;x+=k,y^=1)
					vis[x][y]=1,tot++;
				en[tot]=1;
			}
	en[0]=dp[0][0][0]=1;
	for(int i=0;i<2*n;i++)
		for(int j=0;j<=n;j++)
		{
			dp[i+1][j][0]=(dp[i][j][0]+dp[i][j][1])%mod;
			if(!en[i]) dp[i+1][j+1][1]=dp[i][j][0];
		}
	for(int i=0;i<=n;i++) f[i]=(dp[2*n][i][0]+dp[2*n][i][1])%mod;
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=(1ll*fac[i-1]*i)%mod;
	for(int i=0,j=1;i<=n;i++,j=-j)
		ans=((1ll*ans+1ll*j*fac[n-i]*f[i])%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}