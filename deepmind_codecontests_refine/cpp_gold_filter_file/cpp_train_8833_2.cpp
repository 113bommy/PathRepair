#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int N=2e5+100;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int head[N],nxt[N],to[N],w[N];
int c[3],col[N],e;
bool vis[N],flag;
inline void dfs(int k,int d) {
	c[col[k]=d]++;vis[k]=true;
	for (int i=head[k];i;i=nxt[i],e++)
		if (!vis[to[i]]) dfs(to[i],(d+w[i])%3);
		else if ((d+w[i])%3!=col[to[i]]) flag=false;
}
int main()
{
	int n=gi(),m=gi(),i,a,b,tot=0;LL ans=0;
	for (i=1;i<=m;i++) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot,w[tot]=1;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot,w[tot]=2;
	}
	for (i=1;i<=n;i++)
		if (!vis[i]) {
			c[0]=c[1]=c[2]=e=0;
			flag=true;
			dfs(i,0);
			if (flag)
				if (c[0]&&c[1]&&c[2])
					ans+=1LL*c[0]*c[1]+1LL*c[0]*c[2]+1LL*c[1]*c[2];
				else ans+=e>>1;
			else ans+=1LL*(c[0]+c[1]+c[2])*(c[0]+c[1]+c[2]);
		}
	printf("%lld\n",ans);
	return 0;
}
