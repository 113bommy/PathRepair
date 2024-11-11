#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
using namespace std;
std::vector<int> adj[200005];
int dp[200005][20], dis[200005] = {0}, tin[200005], tout[200005], tim = 0;
void dfs(int u, int par) {
  tin[u] = ++tim;
  for (int v : adj[u]) {
    if (v == par) continue;
    dp[v][0] = u;
    dis[v] = dis[u] + 1;
    dfs(v, u);
  }
  tout[u] = ++tim;
}
bool is_ancestor(int u, int v) {
  if (tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
  return false;
}
int LCA(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = 19; i >= 0; i--) {
    if (!is_ancestor(dp[u][i], v)) u = dp[u][i];
  }
  return dp[u][0];
}
int cal_dis(int a, int b) {
  int lca = LCA(a, b);
  return dis[a] + dis[b] - 2 * dis[lca];
}
bool solve(long long int x, long long int y, long long int a, long long int b,
           long long int k) {
  int dist = cal_dis(a, b);
  if (k >= dist && (k - dist) % 2 == 0) return true;
  dist = cal_dis(a, x) + 1 + cal_dis(y, b);
  if (k >= dist && (k - dist) % 2 == 0) return true;
  dist = cal_dis(a, y) + 1 + cal_dis(x, b);
  if (k >= dist && (k - dist) % 2 == 0) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  dp[1][0] = 1;
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) dp[j][i] = dp[dp[j][i - 1]][i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    long long int x, y, a, b, k;
    cin >> x >> y >> a >> b >> k;
    if (solve(x, y, a, b, k))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
