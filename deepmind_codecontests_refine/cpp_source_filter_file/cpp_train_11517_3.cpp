#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];
vector<vector<int> > ans;
int vis[200005];
bool dfs(int u, int p = 0) {
  vector<bool> bad(adj[u].size(), 0);
  vis[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p || vis[v] == 2) {
      bad[i] = true;
      continue;
    }
    if (vis[u] == 1) continue;
    if (dfs(v, u)) {
      bad[i] = true;
      ans.back()[2] = u;
    }
  }
  int f = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    if (bad[i]) continue;
    if (!f)
      f = adj[u][i];
    else
      ans.push_back({f, u, adj[u][i]}), f = 0;
  }
  vis[u] = 2;
  if (f) {
    ans.push_back({f, u, 0});
    return true;
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i] && dfs(i)) ans.pop_back();
  cout << ans.size() << '\n';
  for (auto v : ans) printf("%d %d %d\n", v[0], v[1], v[2]);
  return 0;
}
