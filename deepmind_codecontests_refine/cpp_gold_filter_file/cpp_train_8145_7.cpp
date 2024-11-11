#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int N = 1e5 + 4;
int tim, siz[N], fa[N], dep[N], son[N], top[N], dfn[N], idx[N];
int D, rt, f[N], mxd[N];
vector<int> e[N];
void dfs_1(int x) {
  siz[x] = 1;
  son[x] = 0;
  mxd[x] = x;
  for (auto v : e[x])
    if (v != fa[x]) {
      fa[v] = x;
      dep[v] = dep[x] + 1;
      dfs_1(v);
      siz[x] += siz[v];
      if (siz[v] > siz[son[x]]) son[x] = v;
      if (dep[mxd[v]] > dep[mxd[x]]) mxd[x] = mxd[v];
    }
}
void dfs_2(int x, int tp) {
  top[x] = tp;
  idx[dfn[x] = ++tim] = x;
  if (son[x]) dfs_2(son[x], tp);
  for (auto v : e[x])
    if (v != fa[x] && v != son[x]) dfs_2(v, v);
}
inline int findkth(int x, int k) {
  if (k >= dep[x]) return rt;
  while (dep[x] - dep[top[x]] < k) {
    k -= dep[x] - dep[top[x]] + 1;
    x = fa[top[x]];
  }
  return idx[dfn[x] - k];
}
inline int getlca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] > dep[top[y]])
      x = fa[top[x]];
    else
      y = fa[top[y]];
  }
  return dep[x] < dep[y] ? x : y;
}
inline int distan(int x, int y) {
  return dep[x] + dep[y] - dep[getlca(x, y)] * 2;
}
inline bool isson(int x, int y) {
  return dfn[x] <= dfn[y] && dfn[y] <= dfn[x] + siz[x] - 1;
}
void dfs_3(int x) {
  f[x] = mxd[x] = 0;
  for (auto v : e[x])
    if (v != fa[x]) {
      dfs_3(v);
      if (mxd[v] + 1 >= D) f[x]++;
      mxd[x] = max(mxd[x], mxd[v] + 1);
    }
}
void dfs_4(int x, int d) {
  if (d >= D) f[x]++;
  if (f[x] >= 3) rt = x;
  int p1 = 0, v1 = d, v2 = 0;
  for (auto v : e[x])
    if (v != fa[x]) {
      if (mxd[v] + 1 > v1) {
        v2 = v1;
        v1 = mxd[v] + 1;
        p1 = v;
      } else if (mxd[v] + 1 > v2)
        v2 = mxd[v] + 1;
    }
  for (auto v : e[x])
    if (v != fa[x]) {
      dfs_4(v, (v == p1 ? v2 : v1) + 1);
    }
}
inline void slpf(int x) {
  fa[x] = dep[x] = tim = 0;
  dfs_1(x);
  dfs_2(x, x);
}
int n, S, T;
inline void solve() {
  for (int i = 1; i <= n; i++) e[i].clear();
  rt = 0;
  n = read();
  S = read();
  T = read();
  for (int i = 1, u, v; i < n; i++) {
    u = read();
    v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  slpf(1);
  D = distan(S, T);
  dfs_3(1);
  dfs_4(1, 0);
  if (!rt) {
    puts("NO");
    return;
  }
  slpf(rt);
  for (int tt = n + 1; tt; tt--) {
    if (isson(S, T) || isson(T, S)) {
      puts("YES");
      return;
    }
    if (S == mxd[S]) {
      S = findkth(S, dep[mxd[T]] - dep[T]);
      T = mxd[T];
    } else {
      T = findkth(T, dep[mxd[S]] - dep[S]);
      S = mxd[S];
    }
  }
  puts("NO");
}
int main() {
  for (int T = read(); T--;) solve();
  return (0 - 0);
}
