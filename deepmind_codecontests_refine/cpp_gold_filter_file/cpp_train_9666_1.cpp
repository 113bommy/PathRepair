#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000 + 10;
typedef long long ll;
vector<int> q[MAXN];
int color[MAXN];
int flag[MAXN];
int n, m, k;
int v[MAXN], d[MAXN], c[MAXN];
void dfs(int x, int cnt, int c)
{
	if (!color[x])
		color[x] = c;
	if (flag[x] >= cnt)
		return;
	if (cnt == 0)
		return;
	flag[x] = cnt;
	for (int i = 0; i < q[x].size(); i++)
		dfs(q[x][i], cnt - 1, c);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		q[x].push_back(y);
		q[y].push_back(x);
	}
	
	cin >> k;
	for (register int i = 1; i <= k; i++)
		cin >> v[i] >> d[i] >> c[i];
	for (register int i = k; i >= 1; i--)
		dfs(v[i], d[i], c[i]);
	for (register int i = 1; i <= n; i++)
		cout << color[i] << "\n";
	return 0;
}