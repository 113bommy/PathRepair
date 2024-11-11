#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[100010];
int n, m, x, y;
vector<int> door[100010];
int vs[100010];
int r[100010];
void dfs(int u, int clor) {
  if (vs[u] == clor) return;
  if (vs[u] != -1) {
    cout << "NO";
    exit(0);
  }
  vs[u] = clor;
  for (auto v : adj[u])
    if (v.second == 0)
      dfs(v.first, clor);
    else
      dfs(v.first, 1 - clor);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    door[i].clear();
  }
  for (int i = 1; i <= n; i++) cin >> r[i];
  for (int i = 1; i <= m; i++) {
    cin >> x;
    for (int j = 1; j <= x; j++) {
      cin >> y;
      door[y].push_back(i);
    }
  }
  memset(vs, -1, sizeof(vs));
  for (int i = 1; i <= n; i++) {
    int u = door[i][0];
    int v = door[i][1];
    adj[u].push_back({v, 1 - r[i]});
    adj[v].push_back({u, 1 - r[i]});
  }
  for (int i = 1; i <= m; i++)
    if (vs[i] == -1) dfs(i, 0);
  cout << "YES";
  return 0;
}
