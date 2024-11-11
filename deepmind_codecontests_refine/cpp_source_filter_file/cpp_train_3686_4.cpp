#include <bits/stdc++.h>
using namespace std;
bool isRed[111111], v[111111];
int d[111111];
vector<int> adj[111111];
int lca[111111][20], depth[111111];
void dfs(int cur, int prev, int cdepth) {
  lca[cur][0] = prev;
  depth[cur] = cdepth;
  for (int i = 0; i < adj[cur].size(); i++)
    if (adj[cur][i] != prev) dfs(adj[cur][i], cur, cdepth + 1);
}
int getLca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; i < 20; i++)
    if ((diff >> i) & 1) u = lca[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (lca[u][i] != lca[v][i]) {
      u = lca[u][i];
      v = lca[v][i];
    }
  return u;
}
int getDist(int u, int v) {
  return depth[u] + depth[v] - depth[getLca(u, v)] * 2;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(lca, -1, sizeof lca);
  dfs(1, -1, 0);
  for (int level = 0; level <= 18; level++)
    for (int i = 1; i <= n; i++)
      if (lca[i][level] != -1) lca[i][level + 1] = lca[lca[i][level]][level];
  for (int i = 1; i <= n; i++)
    v[i] = 0, d[i] = numeric_limits<int>::max(), isRed[i] = false;
  int sqm = sqrt(m);
  vector<int> newReds;
  isRed[1] = true;
  for (int mm = 0; mm < m; mm++) {
    if (mm % sqm == 0) {
      for (int i = 0; i < newReds.size(); i++) isRed[newReds[i]] = true;
      queue<int> Q;
      for (int i = 1; i <= n; i++)
        if (isRed[i] == 1)
          Q.push(i), v[i] = 1, d[i] = 0;
        else
          v[i] = 0;
      while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
          if (v[adj[cur][i]] == 0 && d[adj[cur][i]] > d[cur] + 1) {
            v[adj[cur][i]] = 1;
            d[adj[cur][i]] = d[cur] + 1;
            Q.push(adj[cur][i]);
          }
      }
      newReds.clear();
    }
    int type, v;
    scanf("%d %d", &type, &v);
    if (type == 1)
      newReds.push_back(v);
    else {
      int ans = d[v];
      for (int i = 0; i < newReds.size(); i++)
        ans = min(ans, getDist(v, newReds[i]));
      printf("%d\n", ans);
    }
  }
  return 0;
}
