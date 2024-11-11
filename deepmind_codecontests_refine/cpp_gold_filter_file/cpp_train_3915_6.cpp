#include <bits/stdc++.h>
using namespace std;
const int MX = 200007;
int vis[3][MX];
vector<int> adj[MX];
void dfs(int x, int p, int par) {
  for (auto nx : adj[x]) {
    if (nx == par) continue;
    vis[p][nx] = vis[p][x] + 1;
    dfs(nx, p, x);
  }
}
int main() {
  memset(vis, -1, sizeof vis);
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vis[0][1] = 0;
  vis[1][x] = 0;
  dfs(1, 0, -1);
  dfs(x, 1, -1);
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (vis[0][i] > vis[1][i]) res = max(res, 2 * vis[0][i]);
  cout << res << endl;
  return 0;
}
