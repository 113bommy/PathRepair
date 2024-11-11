#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#define pii pair<int,int>
#define s1 first
#define s2 second
#define N 200001
using namespace std;struct edge{int v,next;edge(){}edge(int _v,int _next){v=_v;next=_next;}}e[N<<1];int head[N],sz;
void init(){memset(head,-1,sizeof(head));sz=0;}void insert(int u,int v){e[++sz]=edge(v,head[u]);head[u]=sz;}
map<int,int> dp[N];vector<int> cc[N];int siz[N],n,c[N];long long ans[N];
void dfs(int u,int f)
{
	for(int i=head[u];~i;i=e[i].next)
	{
		if(e[i].v==f)continue;dfs(e[i].v,u);siz[u]+=siz[e[i].v];int tmp=siz[e[i].v];
		if(dp[e[i].v].count(c[u]))tmp-=dp[e[i].v][c[u]];cc[c[u]].push_back(tmp);
		if(dp[u].size()<dp[e[i].v].size())swap(dp[u],dp[e[i].v]);
		for(map<int,int>::iterator it=dp[e[i].v].begin();it!=dp[e[i].v].end();++it)dp[u][it->s1]+=it->s2;
	}dp[u][c[u]]=++siz[u];
}
int main()
{
	init();scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",c+i);for(int i=1,u,v;i<n;++i)scanf("%d%d",&u,&v),insert(u,v),insert(v,u);
	dfs(1,1);for(int i=1;i<=n;++i)ans[i]=1ll*n*(n+1)/2;for(int i=1;i<=n;++i)cc[i].push_back(n-dp[1][i])
	for(int i=1;i<=n;++i)for(int j=0;j<cc[i].size();++j)ans[i]-=1ll*cc[i][j]*(cc[i][j]+1)/2;for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);putchar(10);return 0;
}