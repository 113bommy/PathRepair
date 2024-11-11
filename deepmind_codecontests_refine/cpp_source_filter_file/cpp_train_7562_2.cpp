#include <bits/stdc++.h>
using namespace std;
int u[100005];
vector<int> g[100005], gf[100005];
bool vis[100005];
stack<int> s;
int scc[100005];
int idx = 1;
vector<int> res;
void dfs1(int u) {
  vis[u] = 1;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (vis[v]) continue;
    dfs1(v);
  }
  s.push(u);
}
void dfs2(int u) {
  vis[u] = 1;
  for (int i = 0; i < gf[u].size(); i++) {
    int v = gf[u][i];
    if (vis[v]) continue;
    dfs2(v);
  }
  scc[u] = idx;
  res.push_back(u);
}
int main() {
  int n, m, h;
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; i++) scanf("%d", &u[i]);
  for (int i = 0; i < m; i++) {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    if ((u[c1] + 1) % h == u[c2]) g[c1].push_back(c2), gf[c2].push_back(c1);
    if ((u[c2] + 1) % h == u[c1]) g[c2].push_back(c1), gf[c1].push_back(c2);
  }
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 0) return !printf("1\n%d\n", i);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    dfs1(i);
  }
  memset(vis, 0, sizeof(vis));
  int mn = 1e9, mi = 0;
  while (!s.empty()) {
    int u = s.top();
    s.pop();
    if (vis[u]) continue;
    res.clear();
    dfs2(u);
    bool ok = 1;
    for (int i = 1; i < res.size(); i++) {
      int u = res[i];
      for (int j = 0; j < g[u].size(); j++) {
        int v = g[u][j];
        if (scc[v] != scc[u]) {
          ok = 0;
          break;
        }
      }
    }
    if (ok)
      if (mn > res.size()) mn = res.size(), mi = idx;
    idx++;
  }
  printf("%d\n", mn);
  for (int i = 1; i <= n; i++) {
    if (scc[i] == mi) printf("%d ", i);
  }
}
