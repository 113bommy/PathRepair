#include <bits/stdc++.h>
using namespace std;
int n, m, q, cnt, vis[100010], used[100010], dep[100010], val[100010],
    sum[100010], p[100010], par[21][100010];
vector<int> v[100010], g[100010];
vector<pair<int, int> > e;
inline int find_set(int x) { return p[x] == x ? x : p[x] = find_set(p[x]); }
inline void dfs(int x, int pr, int dist) {
  vis[x] = cnt;
  par[0][x] = pr;
  dep[x] = dist;
  for (int i = 0; i < v[x].size(); i++)
    if (v[x][i] != pr) {
      int u = v[x][i];
      if (vis[u]) {
        if (dep[x] < dep[u]) e.push_back(make_pair(x, u));
      } else {
        g[x].push_back(u);
        g[u].push_back(x);
        dfs(u, x, dist + 1);
      }
    }
}
inline void init() {
  for (int i = 0; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      if (par[i][j] == -1)
        par[i + 1][j] = -1;
      else
        par[i + 1][j] = par[i][par[i][j]];
    }
  }
}
inline int lca(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  int k = dep[y] - dep[x];
  for (int i = 0; i <= 20; i++)
    if (k & (1 << i)) {
      y = par[i][y];
    }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (par[i][x] != par[i][y]) {
      x = par[i][x];
      y = par[i][y];
    }
  }
  return par[0][x];
}
inline void dfs2(int x, int pr) {
  used[x] = 1;
  for (int i = 0; i < g[x].size(); i++)
    if (g[x][i] != pr) {
      dfs2(g[x][i], x);
      if (find_set(x) == find_set(g[x][i])) val[x] |= val[g[x][i]];
    }
}
inline void dfs3(int x, int pr) {
  used[x] = 1;
  for (int i = 0; i < g[x].size(); i++)
    if (g[x][i] != pr) {
      if (find_set(x) == find_set(g[x][i])) val[g[x][i]] |= val[x];
      dfs3(g[x][i], x);
    }
}
inline void dfs4(int x, int pr) {
  used[x] = 1;
  sum[x] += val[x];
  for (int i = 0; i < g[x].size(); i++)
    if (g[x][i] != pr) {
      sum[g[x][i]] += sum[x];
      dfs4(g[x][i], x);
    }
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) cnt++, dfs(i, -1, 0);
  init();
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 0; i < e.size(); i++) {
    int x = e[i].first, y = e[i].second;
    int pos = find_set(y);
    while (dep[pos] > dep[x]) {
      p[pos] = par[0][pos];
      pos = find_set(pos);
    }
    if ((dep[y] - dep[x]) % 2 == 0) {
      val[y] = 1;
    }
  }
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs2(i, -1);
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs3(i, -1);
  memset(used, 0, sizeof(used));
  for (int i = 1; i <= n; i++)
    if (!used[i]) dfs4(i, -1);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    if (vis[x] != vis[y]) {
      cout << "No\n";
    } else {
      int l = lca(x, y);
      if ((dep[x] + dep[y] - 2 * dep[l]) % 2 == 1) {
        cout << "Yes\n";
      } else if ((sum[x] + sum[y] - 2 * sum[l]) > 0) {
        cout << "Yes\n";
      } else
        cout << "No\n";
    }
  }
  return 0;
}
