//Ilm kave oi, you know ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e5 + 3;
const int infint = (int)1e9 + 3;
const ll inf = (ll)1e12;
int n, m, sz, cyc, visited[MAXN], md0, md1, md2, e;
vector<pair<int, int> > H[MAXN];
void dfs(int u, int num)
{
	sz++;
	visited[u] = num;
	if(num == 0)	
		md0++;
	else
	if(num == 1)
		md1++;
	else
		md2++;
	
	for (auto v : H[u])
	{
		e++;
		int nw = num;
		if(v.second == 0)
			nw = (nw + 1) % 3;
		else
			nw = (nw + 2) % 3;
		if(visited[v.first] == -1)
			dfs(v.first, nw);
		else
		if(visited[v.first] != nw)
			cyc = 1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		H[u].push_back({v, 0});
		H[v].push_back({u, 1});
	}
	memset(visited, -1, sizeof visited);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		if(visited[i] == -1)
		{
			sz = 0, cyc = 0, md0 = 0, md1 = 0, md2 = 0, e = 0, dfs(i, 0);
			if(cyc == 1)
				ans += 1LL * sz * sz;
			else
			if(mod0 && mod1 && mod2)
				ans += 1LL * md0 * md1 + 1LL * md1 * md2 + 1LL * md2 * md0;
			else
				ans += e / 2;
		}
	cout << ans;
}
