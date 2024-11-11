#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN = 100000;
int BLOCK;
struct node
{
	int to,co,ct;
	node(){}
	node(int xx,int yy,int zz)
	{
		to=xx,co=yy,ct=zz;
	}
};
vector<node>g[MAXN];
void addedge(int u, int v, int c, int d) {
	g[u].push_back(node(v,c,d));
	g[v].push_back(node(u,c,d));
}
int clr[MAXN + 5], dis[MAXN + 5];
int fa[MAXN + 5][20], dep[MAXN + 5];
int dfn[2*MAXN + 5], fir[MAXN + 5], bac[MAXN + 5], dcnt = 0;
void dfs(int x, int pre) {
	dfn[++dcnt] = x, fir[x] = dcnt;
	fa[x][0] = pre, dep[x] = dep[pre] + 1;
	for(int i=1;i<20;i++)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i].to;
		if( v != pre ) {
			dfs(v, x);
			clr[v] = g[x][i].co, dis[v] = g[x][i].ct;
		}
	}
	dfn[++dcnt] = x, bac[x] = dcnt;
}
int lca(int u, int v) {
	if( dep[u] < dep[v] ) swap(u, v);
	for(int i=19;i>=0;i--)
		if( dep[fa[u][i]] >= dep[v] )
			u = fa[u][i];
	if( u == v ) return u;
	for(int i=19;i>=0;i--)
		if( fa[u][i] != fa[v][i] )
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
struct query{
	int le, ri, num;
	int x, y;
}qry[MAXN + 5];
bool operator < (query a, query b) {
	return (a.le/BLOCK == b.le/BLOCK) ? a.ri < b.ri : a.le < b.le;
}
int nwres, cnt[MAXN + 5], tag[MAXN + 5];
int sum[MAXN + 5], ans[MAXN + 5];
void update(int x) {
	int y = dfn[x];
	if( tag[y] )
		cnt[clr[y]]--, sum[clr[y]] -= dis[y], nwres -= dis[y];
	else cnt[clr[y]]++, sum[clr[y]] += dis[y], nwres += dis[y];
	tag[y] ^= 1;
}
int main() {
	int N, Q; scanf("%d%d", &N, &Q);
	for(int i=1;i<N;i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		addedge(a, b, c, d);
	}
	dfs(1, 0);
	BLOCK=sqrt(N);
	for(int i=1;i<=Q;i++) {
		int x, y, u, v; scanf("%d%d%d%d", &x, &y, &u, &v);
		int l = lca(u, v);
		if( l == u || l == v ) {
			if( l == v ) swap(u, v);
			qry[i].le = fir[u] + 1, qry[i].ri = fir[v];
		}
		else {
			if( fir[u] > fir[v] ) swap(u, v);
			qry[i].le = bac[u], qry[i].ri = fir[v];
		}
		qry[i].num = i, qry[i].x = x, qry[i].y = y;
	}
	sort(qry + 1, qry + Q + 1);
	int l = 1, r = 0;
	for(int i=1;i<=Q;i++) {
		while( l > qry[i].le ) update(--l);
		while( r < qry[i].ri ) update(++r);
		while( l < qry[i].le ) update(l++);
		while( r > qry[i].ri ) update(r--);
		ans[qry[i].num] = nwres - sum[qry[i].x] + cnt[qry[i].x]*qry[i].y;
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n", ans[i]);
}
