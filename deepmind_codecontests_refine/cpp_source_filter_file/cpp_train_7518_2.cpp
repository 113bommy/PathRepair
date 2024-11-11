#include <bits/stdc++.h>
using namespace std;
inline pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
  return pair<int, int>(max(x.first, y.first), min(x.second, y.second));
}
vector<int> e[500005];
int fa[500005][20], dep[500005];
void dfs1(int x) {
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa[x][0]) {
      int u = e[x][i];
      fa[u][0] = x;
      dep[u] = dep[x] + 1;
      for (int j = 1; j < 20; j++) fa[u][j] = fa[fa[u][j - 1]][j - 1];
      dfs1(u);
    }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int d = dep[x] - dep[y];
  for (int i = 0; i < 20; i++)
    if ((d >> i) & 1) x = fa[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  return fa[x][0];
}
int jump(int x, int d) {
  for (int i = 0; i < 20; i++)
    if ((d >> i) & 1) x = fa[x][i];
  return x;
}
vector<pair<int, int> > ee[500005];
int size[500005];
void dfs2(int x, int fa) {
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) {
      int u = e[x][i];
      dfs2(u, x);
      size[x] += size[u];
    }
  if (size[x]) {
    ee[x].push_back(pair<int, int>(fa, 0));
    ee[fa].push_back(pair<int, int>(x, 0));
  }
}
int col[500005], id[500005];
void dfs3(int x) {
  for (int i = 0; i < ee[x].size(); i++) {
    int u = ee[x][i].first;
    if (!id[u]) {
      id[u] = id[x];
      col[u] = col[x] ^ ee[x][i].second;
      dfs3(u);
    } else if ((col[x] ^ col[u]) != ee[x][i].second) {
      puts("-1");
      exit(0);
    }
  }
}
pair<int, int> f[500005], g[500005];
int vis[500005];
bool dfs4(int x, int fa, int k) {
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) {
      int u = e[x][i];
      if (!dfs4(u, x, k)) return 0;
    }
  f[x] = pair<int, int>(1, k);
  int sz = 0;
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa && id[e[x][i]]) {
      int u = e[x][i];
      if (id[u] == id[x]) {
        if (!col[u])
          f[x] = merge(f[x], pair<int, int>(1, f[u].second - 1));
        else
          f[x] = merge(f[x], pair<int, int>(f[u].first + 1, k));
      } else {
        if (!vis[id[u]]) {
          vis[id[u]] = ++sz;
          g[sz] = pair<int, int>(1, k);
        }
        int t = vis[id[u]];
        if (!col[u])
          g[t] = merge(g[t], pair<int, int>(1, f[u].second - 1));
        else
          g[t] = merge(g[t], pair<int, int>(f[u].first + 1, k));
      }
    }
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) vis[id[e[x][i]]] = 0;
  if (f[x].first > f[x].second) return 0;
  pair<int, int> u(1, k);
  for (int i = 1; i <= sz; i++) {
    if (g[i].first > g[i].second) return 0;
    if (k - g[i].second + 1 < g[i].first)
      g[i] = pair<int, int>(k - g[i].second + 1, k - g[i].first + 1);
    u = merge(u, g[i]);
  }
  pair<int, int> t1 = merge(u, f[x]),
                 t2 = merge(pair<int, int>(k - u.second + 1, k - u.first + 1),
                            f[x]);
  if (t1.first > t1.second && t2.first > t2.second) return 0;
  if (t1.first > t1.second)
    f[x] = t2;
  else if (t2.first > t1.second)
    f[x] = t1;
  else
    f[x] = pair<int, int>(min(t1.first, t2.first), max(t1.second, t2.second));
  return 1;
}
int ans[500005], val[500005];
bool d[500005];
void dfs5(int x, int fa, int k, bool v) {
  int sz = 0;
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa && id[e[x][i]] != id[x]) {
      int u = e[x][i];
      if (!vis[id[u]]) {
        vis[id[u]] = ++sz;
        val[sz] = id[u];
        g[sz] = pair<int, int>(1, k);
      }
      int t = vis[id[u]];
      if (!col[u])
        g[t] = merge(g[t], pair<int, int>(1, f[u].second - 1));
      else
        g[t] = merge(g[t], pair<int, int>(f[u].first + 1, k));
    }
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) vis[id[e[x][i]]] = 0;
  for (int i = 1; i <= sz; i++)
    d[val[i]] = ((g[i].first <= ans[x] && g[i].second >= ans[x]) ? 0 : 1);
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) {
      int u = e[x][i];
      if (!id[u]) {
        ans[u] = f[u].first;
        dfs5(u, x, k, 0);
      } else {
        bool c = ((id[u] == id[x]) ? v : d[id[u]]);
        if (!c)
          ans[u] = ((!col[u]) ? f[u].second : f[u].first);
        else
          ans[u] = ((col[u]) ? k - f[u].first + 1 : k - f[u].second + 1);
        dfs5(u, x, k, c);
      }
    }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs1(1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int p = lca(x, y), u, v;
    if (p != x) {
      size[x]++;
      size[u = jump(x, dep[x] - dep[p] - 1)]--;
    }
    if (p != y) {
      size[y]++;
      size[v = jump(y, dep[y] - dep[p] - 1)]--;
    }
    if (p != x && p != y) {
      ee[u].push_back(pair<int, int>(v, 1));
      ee[v].push_back(pair<int, int>(u, 1));
    }
  }
  dfs2(1, 0);
  int cnt = 0;
  for (int i = 2; i <= n; i++)
    if (!id[i]) {
      id[i] = ++cnt;
      dfs3(i);
    }
  int l = 1, r = n;
  while (l < r) {
    int mid = ((l + r) >> 1);
    bool v = dfs4(1, 0, mid);
    if (v)
      r = mid;
    else
      l = mid + 1;
  }
  dfs4(1, 0, l);
  ans[1] = f[1].first;
  dfs5(1, 0, l, 0);
  printf("%d\n", l);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
