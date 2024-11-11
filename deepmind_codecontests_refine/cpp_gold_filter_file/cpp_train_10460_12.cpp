#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10, K = 30;
int n, m;
vector<int> adj[N];
int dp[K][N], prof[N], sz[N];
void dfs(int v) {
  sz[v] = 1;
  for (auto i : adj[v])
    if (i != dp[0][v])
      dp[0][i] = v, prof[i] = prof[v] + 1, dfs(i), sz[v] += sz[i];
}
int lca(int x, int y) {
  if (prof[y] < prof[x]) swap(x, y);
  int dis = prof[y] - prof[x];
  for (int k = K - 1; k >= 0; k--)
    if ((1 << k) & dis) y = dp[k][y];
  if (x == y) return x;
  for (int k = K - 1; k >= 0; k--)
    if (dp[k][x] != dp[k][y]) x = dp[k][x], y = dp[k][y];
  return dp[0][x];
}
int find(int x, int y) {
  if (prof[y] < prof[x]) swap(x, y);
  int dis = prof[y] - prof[x] - 1;
  for (int k = K - 1; k >= 0; k--)
    if ((1 << k) & dis) y = dp[k][y];
  return y;
}
int get(int v, int dis) {
  for (int k = K - 1; k >= 0; k--)
    if ((1 << k) & dis) v = dp[k][v];
  return v;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dp[0][1] = 1;
  dfs(1);
  for (int k = 1; k < K; k++)
    for (int i = 1; i <= n; i++) dp[k][i] = dp[k - 1][dp[k - 1][i]];
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, Lca;
    cin >> u >> v;
    if (u == v) {
      cout << n << '\n';
      continue;
    }
    Lca = lca(u, v);
    int dis = prof[u] + prof[v] - 2 * prof[Lca];
    if (dis % 2 != 0) {
      cout << "0" << '\n';
      continue;
    }
    int L = prof[u] - prof[Lca], R = prof[v] - prof[Lca];
    if (L == R) {
      int x = find(u, Lca), y = find(v, Lca);
      cout << n - sz[x] - sz[y] << '\n';
      continue;
    }
    if (L > R) {
      int x = get(u, dis / 2);
      x = find(u, x);
      int y = dp[0][x];
      cout << sz[y] - sz[x] << '\n';
      continue;
    }
    if (R > L) {
      int x = get(v, dis / 2);
      x = find(v, x);
      int y = dp[0][x];
      cout << sz[y] - sz[x] << '\n';
      continue;
    }
  }
  return 0;
}
