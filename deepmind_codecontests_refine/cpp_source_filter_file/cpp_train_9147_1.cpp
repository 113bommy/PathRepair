#include <iostream>
#incldue <cstdio>
#define rep(i,n) for(int i=0;i<n;i++)
//#define int long long
using namespace std;

#define INF 999999

int n, m;
int a, b, c;

int cost[100][100];
int mincost[100];
bool used[100];

void init()
{
	rep(i,100) rep(j,100)
	{
		cost[i][j] = INF;
	}
}

int prim()
{
	rep(i,n)
	{
		mincost[i] = INF;
		used[i] = false;
	}

	mincost[0] = 0;
	int res = 0;

	while (true)
	{
		int v = -1;
		rep(u,n)
		{
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		}

		if (v == -1) break;
		used[v] = true;
		res += mincost[v];

		rep(u,n)
		{
			mincost[u] = min(mincost[u], cost[v][u]);
		}
	}

	return res;
}

int main()
{
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		init();

		rep(i,m)
		{
			cin >> a >> b >> c;
			cost[a][b] = c;
			cost[b][a] = c;
		}

		printf("%d\n", prim());
	}
}