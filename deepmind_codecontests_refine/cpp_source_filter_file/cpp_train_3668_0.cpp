#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 2;
int n, w[MAX], dp[MAX], ans[MAX];
vector<int> adj[MAX];
void dfs1(int u, int p) {
  dp[u] = w[u];
  for (auto v : adj[u]) {
    if (v == p) continue;
    dfs1(v, u);
    dp[u] += max(0, dp[v]);
  }
}
void dfs2(int u, int p) {
  ans[u] = dp[u];
  for (auto v : adj[u]) {
    if (v == p) continue;
    int pu = dp[u], pv = dp[v];
    dp[u] -= max(0, dp[v]);
    dp[v] += max(0, dp[u]);
    dfs2(v, u);
    dp[u] = pu;
    dp[v] = pv;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    if (w[i] == 0) w[i] = -1;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
}
