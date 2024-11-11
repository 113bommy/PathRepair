#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int n, m, cnt[5], c[100005];
vector<int> g[100005];

void dfs(int cur, int col) {
	if (c[cur] == -1) {
		c[cur] = col;
		cnt[col]++;
		FOR(i, g[cur].size()) {
			dfs(g[cur][i], col^1);
		}
	}
	else if (c[cur] == col^1) {
		cout << 1LL*n*(n-1)/2-m << endl;
		exit(0);
	}
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	FOR(i, m) {
		int u, v;
		cin >> u >> v;
		g[u-1].push_back(v-1);
		g[v-1].push_back(u-1);
	}
	MEM(c, -1);
	dfs(0, 0);
	cout << 1LL*cnt[0]*cnt[1]-m << endl;
	return 0;
}