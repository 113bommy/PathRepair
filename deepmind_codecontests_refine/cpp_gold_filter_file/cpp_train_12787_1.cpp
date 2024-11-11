#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;
const int N = 1e5 + 10, inf = 1e9;

ll deg[N], n, dp[N];
vector <int> adj[N];

void dfs(int v, int p = -1) {
	ll ans = 0;
	int cnt = 0;
	for (auto u : adj[v]) {
		if(u == p) 	continue;
		dfs(u, v);
		dp[v] += dp[u];
		if(dp[u] == 0)
			cnt++;
	}
	if(cnt)
		dp[v] += cnt - 1;
}

int main() {
	// task
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u), adj[u].push_back(v);
		deg[v]++, deg[u]++;
	}
	ll root = inf;
	for (int i = 0; i < n; i++) {
		if(deg[i] > 2)
			root = min(root, i * 1LL);
	}
	if(root == inf) {
		cout << 1 << "\n";
	}
	else {
		dfs(root);
		cout << dp[root] << "\n";
	}
}