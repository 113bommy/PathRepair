#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=1000000007;
const int inv2=mod+1>>1;
const int Maxn=3005;
int n,q,a[Maxn];
int p[Maxn][Maxn],t;
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) p[i][j]=a[i]>a[j];
	for (int q_=0;q_<q;++q_)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p[x][y]=p[y][x]=1LL*(p[x][y]+p[y][x])*inv2%mod;
		for (int i=1;i<=n;++i) if(i!=x && i!=y)
			p[i][x]=p[i][y]=1LL*(p[i][x]+p[i][y])*inv2%mod,
			p[x][i]=p[y][i]=1LL*(p[x][i]+p[y][i])*inv2%mod;
	}
	for (int i=1;i<=n;++i) for (int j=n;j>i;--j) ans=(ans+p[i][j])%mod;
	for (int i=0;i<q;++i) ans=(ans<<1)%mod;
	printf("%d\n",ans);
	return 0;
}