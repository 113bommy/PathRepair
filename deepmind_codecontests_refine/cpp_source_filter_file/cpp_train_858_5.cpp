#include <bits/stdc++.h>
using namespace std;
int n, zx, siz[100010], fa[100010];
vector<int> edge[100010];
void dfs(int u, int fat) {
  bool f = 1;
  siz[u] = 1;
  fa[u] = fat;
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v == fat) continue;
    dfs(v, u);
    siz[u] += siz[v];
    if (siz[v] * 2 > n) f = 0;
  }
  if (2 * (n - siz[u]) > n) f = 0;
  if (f) zx = u;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    n = zx = 0;
    memset(siz, 0, sizeof siz);
    memset(fa, 0, sizeof fa);
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1, 0);
    bool f = 1;
    for (int i = 0; i < edge[zx].size(); i++) {
      if (edge[zx][i] == fa[zx]) continue;
      if (2 * siz[edge[zx][i]] == n) {
        f = 0;
        for (int j = 0; i < edge[edge[zx][i]].size(); j++) {
          if (edge[edge[zx][i]][j] == zx) continue;
          cout << edge[zx][i] << ' ' << edge[edge[zx][i]][j] << endl;
          cout << edge[edge[zx][i]][j] << ' ' << zx << endl;
          break;
        }
        break;
      }
    }
    if (f && siz[zx] * 2 == n) {
      f = 0;
      for (int i = 0; i < edge[fa[zx]].size(); i++) {
        if (edge[fa[zx]][i] == zx) continue;
        cout << fa[zx] << ' ' << edge[fa[zx]][i] << endl;
        cout << edge[fa[zx]][i] << ' ' << zx << endl;
        break;
      }
    }
    if (f) {
      cout << zx << ' ' << edge[zx][0] << endl;
      cout << zx << ' ' << edge[zx][0] << endl;
    }
    for (int i = 1; i <= n; i++) edge[i].clear();
  }
  return 0;
}
