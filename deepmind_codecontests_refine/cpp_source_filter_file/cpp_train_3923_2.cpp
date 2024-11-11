#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <typename T>
inline void uin(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
inline void uax(T &a, T b) {
  if (b > a) a = b;
}
const int maxn = 228228;
struct Fenwick {
  vector<int> t;
  int n;
  Fenwick() {}
  Fenwick(int _n) {
    n = _n;
    t.resize(n + 1);
  }
  void upd(int i, int dx) {
    --i;
    for (; i < n; i = (i | (i + 1))) {
      t[i] += dx;
    }
  }
  int getr(int r) {
    --r;
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      res += t[r];
    }
    return res;
  }
  int get(int l, int r) { return getr(r) - getr(l - 1); }
};
int n, m, q;
vector<int> g[maxn], pathes[maxn + maxn];
int p[maxn][20], tin[maxn], tout[maxn], deep[maxn], cup[maxn], go[maxn];
int ans[maxn];
int start[maxn + maxn], End[maxn + maxn], gop[maxn][20];
int lft[maxn], rgt[maxn], sz[maxn];
int timer = 1, TIMER = 1;
void dfs(int v, int par = 1) {
  if (v != 1) {
    deep[v] = deep[par] + 1;
  }
  p[v][0] = par;
  for (int i = 1; i < 20; ++i) {
    p[v][i] = p[p[v][i - 1]][i - 1];
  }
  tin[v] = timer++;
  lft[v] = TIMER++;
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != par) {
      dfs(to, v);
      sz[v] += sz[to];
    }
  }
  rgt[v] = lft[v] + sz[v] - 1;
  tout[v] = timer++;
}
bool anc(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }
int get_lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  int k = 19;
  while (k >= 0) {
    if (!anc(p[u][k], v)) {
      u = p[u][k];
    }
    --k;
  }
  return p[u][0];
}
struct event {
  int st, fin, num;
  event() {}
  event(int _st, int _fin, int _num) {
    st = _st;
    fin = _fin;
    num = _num;
  }
};
vector<event> asks[maxn];
void zhfs(int v) {
  go[v] = cup[v];
  for (int to : g[v]) {
    if (to != p[v][0]) {
      zhfs(to);
      if (deep[go[to]] < deep[go[v]]) {
        go[v] = go[to];
      }
    }
  }
}
void zhfs2(int v) {
  gop[v][0] = go[v];
  for (int i = 1; i < 20; ++i) {
    gop[v][i] = gop[gop[v][i - 1]][i - 1];
  }
  for (int to : g[v]) {
    if (to != p[v][0]) {
      zhfs2(to);
    }
  }
}
void precalctamvcetipo() {
  for (int i = 1; i <= (int)n; ++i) cup[i] = i;
  for (int i = 1; i <= (int)m; ++i) {
    int u = start[i], v = End[i];
    int lca = get_lca(u, v);
    if (deep[cup[u]] > deep[lca]) {
      cup[u] = lca;
    }
    if (deep[cup[v]] > deep[lca]) {
      cup[v] = lca;
    }
  }
  zhfs(1);
  zhfs2(1);
}
int solve(int u, int v) {
  int k = 19;
  int res = 0;
  while (k >= 0) {
    if (deep[gop[u][k]] > deep[v]) {
      res += (1 << k);
      u = gop[u][k];
    }
    --k;
  }
  if (deep[gop[u][0]] > deep[v]) {
    return -1;
  }
  return res + 1;
}
int goup(int v, int jump) {
  int k = 19;
  while (k >= 0 && jump >= 0) {
    if ((1 << k) <= jump) {
      jump -= (1 << k);
      v = p[v][k];
    }
    --k;
  }
  return v;
  return v;
}
Fenwick f;
int was[maxn + maxn];
void jfs(int v) {
  for (event ev : asks[v]) {
    was[ev.num] = f.get(lft[ev.fin], rgt[ev.fin]);
  }
  for (int ind : pathes[v]) {
    f.upd(lft[End[ind]], 1);
  }
  for (int to : g[v]) {
    if (to != p[v][0]) {
      jfs(to);
    }
  }
  for (event ev : asks[v]) {
    if (f.get(lft[ev.fin], rgt[ev.fin]) != was[ev.num]) {
      --ans[ev.num];
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int parrrrrrrrrrr;
    cin >> parrrrrrrrrrr;
    g[i].push_back(parrrrrrrrrrr);
    g[parrrrrrrrrrr].push_back(i);
  }
  dfs(1);
  cin >> m;
  for (int i = 1; i <= (int)m; ++i) {
    int u, v;
    cin >> u >> v;
    start[i] = u;
    End[i] = v;
    start[m + i] = v;
    End[m + i] = u;
    pathes[u].push_back(i);
    pathes[v].push_back(m + i);
  }
  precalctamvcetipo();
  cin >> q;
  for (int I = 1; I <= (int)q; ++I) {
    int u, v;
    cin >> u >> v;
    if (anc(u, v)) {
      swap(u, v);
    }
    if (anc(v, u)) {
      ans[I] = solve(u, v);
      continue;
    }
    int lca = get_lca(u, v);
    int a = solve(u, lca);
    int b = solve(v, lca);
    int lu = goup(u, a - 1);
    int lv = goup(v, b - 1);
    if (a == -1 || b == -1) {
      ans[I] = -100;
      continue;
    }
    ans[I] = a + b;
    asks[lu].push_back(event(lu, lv, I));
  }
  f = Fenwick(n);
  jfs(1);
  for (int i = 1; i <= (int)q; ++i) {
    if (ans[i] < -50) {
      cout << "-1\n";
    } else {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}
