#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
void dfs(int u, int r, vector<vector<int>> &adj, vector<int> &color) {
  color[u] = 1;
  for (auto v : adj[u]) {
    if (color[v] == 0 && v != r) {
      dfs(v, r, adj, color);
    }
  }
  color[u] = 2;
}
void sherlock(int t) {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<vector<int>> adj(n + 1);
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> colora(n + 1), colorb(n + 1);
  dfs(a, b, adj, colora);
  dfs(b, a, adj, colorb);
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (colora[i] == 2 && colorb[i] == 0) x++;
    if (colora[i] == 0 && colorb[i] == 2) y++;
  }
  cout << (x - 1) * (y - 1) << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) sherlock(t);
  return 0;
}
