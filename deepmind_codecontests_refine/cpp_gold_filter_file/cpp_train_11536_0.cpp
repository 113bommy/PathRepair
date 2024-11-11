#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{
	int u,v,flag,nxt;
}g[N<<1];
int tot=-1,head[N];
inline void add(int u,int v){
	g[++tot]=edge{u,v,0,head[u]}; head[u]=tot;
	g[++tot]=edge{v,u,0,head[v]}; head[v]=tot;
}
int n,m;
bool vis[N];
int dep[N];
inline void dfs(int u,int fa,int pre){
	int tmp=0; vis[u]=1;
	for(int i=head[u];~i;i=g[i].nxt){
		int v=g[i].v; if(v==fa)continue;
		if(vis[v]&&dep[u]>dep[v]){g[i].flag=1; ++tmp; continue;}else if(vis[v])continue;
		dep[v]=dep[u]+1;dfs(v,u,i); if(g[i].flag)++tmp;
	}
	if((~tmp&1)&&u!=1)g[pre].flag=1;else if(u!=1)g[pre^1].flag=1;
}
int main(){
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	if(m&1)return puts("-1"),0;
	dfs(1,-1,-1);
	for(int i=0; i<=tot; ++i)if(g[i].flag)printf("%d %d\n",g[i].u,g[i].v);
	return 0;
}