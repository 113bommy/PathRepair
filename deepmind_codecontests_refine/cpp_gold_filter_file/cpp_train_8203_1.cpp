#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=605,mod=1e9+7;
int n,m,a[N<<1],f[N<<1][N][N],cur,q[N<<1],tp; bool ext[N<<1],vis[N<<1];
inline void inc(int& x,CI y)
{
	if ((x+=y)>=mod) x-=mod;
}
int main()
{
	RI i,j,k; for (scanf("%d",&n),i=1;i<=2*n;++i)
	scanf("%d",&a[i]),ext[~a[i]?a[i]:0]=1;
	for (i=1;i<=n;++i) if (!~a[2*i-1]&&!~a[2*i]) ++cur;
	else if (~a[2*i-1]&&~a[2*i]) vis[a[2*i-1]]=vis[a[2*i]]=1;
	for (i=1;i<=2*n;++i) if (!vis[i]) q[++m]=ext[i];
	for (n=m,f[n][0][0]=1,i=n;i;--i) for (j=0;j<=n;++j)
	for (k=0;k<=n;++k) if (tp=f[i][j][k])
	{
		if (q[i]) inc(f[i-1][j+1][k],tp),k&&(inc(f[i-1][j][k-1],tp),0);
		else inc(f[i-1][j][k+1],tp),k&&(inc(f[i-1][j][k-1],tp),0),j&&(inc(f[i-1][j-1][k],1LL*tp*j%mod),0);
	}
	int ans=f[0][0][0]; for (i=1;i<=cur;++i) ans=1LL*ans*i%mod;
	return printf("%d",ans),0;
}