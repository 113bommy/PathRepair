#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 2000000000
#define pb push_back
int N, M, P, a, b;
int t[10];
struct edge
{
	int to;
	double cost;
	edge(int to, double cost):to(to), cost(cost){}
};
vector<edge> g[40];
double dp[40][1<<8];
double rec(int v, int bit)
{
	if(dp[v][bit]!=-1)return dp[v][bit];
	double res = INF;
	for(int i=0; i<g[v].size(); i++)
	{
		int u = g[v][i].to;
		double cost = g[v][i].cost;
		for(int j=0; j<N; j++)
		{
			if(!((bit>>j)&1))
			{
				res=min(res, rec(u, bit|(1<<j))+cost/t[j]);
			}
		}
	}
	return dp[v][bit]=res;
}
int main()
{
	while(1)
	{
		for(int i=0; i<40; i++)g[i].clear();
		scanf("%d %d %d %d %d", &N, &M, &P, &a, &b);
		if(N==0&&M==0&&P==0&&a==0&&b==0)break;
		a--; b--;
		for(int i=0; i<N; i++)scanf("%d", &t[i]);
		for(int i=0; i<P; i++)
		{
			int x, y;
			double z;
			scanf("%d %d %lf", &x, &y, &z);
			x--; y--;
			g[x].pb(edge(y, z));
			g[y].pb(edge(x, z));
		}
		for(int i=0; i<M; i++)for(int j=0; j<(1<<N); j++)dp[i][j]=-1;
		dp[a][(1<<N)-1]=0;
		double ans = INF;
		for(int i=0; i<(1<<N); i++)ans = min(ans, rec(b, i));
		if(ans == INF)printf("Impossible\n");
		else prinatf("%f\n", ans);
	}
	return 0;
}
