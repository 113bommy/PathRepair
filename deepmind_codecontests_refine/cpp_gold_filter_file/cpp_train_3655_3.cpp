#include <bits/stdc++.h>
using namespace std;
template <class T>
void in(T &x) {
  x = 0;
  bool f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  if (f) x = -x;
}
int v[1000005], nx[1000005];
int head[100005], cnte = 1;
inline void adde(int uu, int vv) {
  v[++cnte] = vv, nx[cnte] = head[uu];
  head[uu] = cnte;
}
vector<int> e[100005 << 1];
int n, m, q;
int cnt;
int st[100005], tp;
int dfn[100005], low[100005], dk;
void tarjan(int x, int fe) {
  dfn[x] = low[x] = ++dk;
  st[++tp] = x;
  for (register int i = head[x]; i; i = nx[i])
    if (i != fe) {
      if (!dfn[v[i]]) {
        tarjan(v[i], i ^ 1);
        low[x] = min(low[v[i]], low[x]);
        if (low[v[i]] >= dfn[x]) {
          ++cnt;
          while (st[tp + 1] != v[i]) {
            e[st[tp]].push_back(cnt);
            e[cnt].push_back(st[tp]);
            --tp;
          }
          e[x].push_back(cnt);
          e[cnt].push_back(x);
        }
      } else
        low[x] = min(dfn[v[i]], low[x]);
    }
}
int fa[100005 << 1], top[100005 << 1], sz[100005 << 1], hsn[100005 << 1],
    dep[100005 << 1];
void dfs(int x) {
  sz[x] = 1;
  for (register int i = 0, vv; i < e[x].size(); ++i) {
    vv = e[x][i];
    if (vv != fa[x]) {
      fa[vv] = x;
      dep[vv] = dep[x] + 1;
      dfs(vv);
      sz[x] += sz[vv];
      if (sz[vv] > sz[hsn[x]]) hsn[x] = vv;
    }
  }
}
void efs(int x) {
  if (hsn[x]) {
    top[hsn[x]] = top[x];
    efs(hsn[x]);
  }
  for (register int i = 0, vv; i < e[x].size(); ++i) {
    vv = e[x][i];
    if (vv != fa[x] && vv != hsn[x]) {
      top[vv] = vv;
      efs(vv);
    }
  }
}
inline int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
inline void prework() {
  cnt = n;
  tarjan(1, 0);
  dep[1] = fa[1] = top[1] = 1;
  dfs(1);
  efs(1);
}
signed main() {
  in(n), in(m);
  int q;
  in(q);
  for (register int i = 1, a, b; i <= m; ++i) {
    in(a), in(b);
    adde(a, b);
    adde(b, a);
  }
  prework();
  int x, y;
  while (q--) {
    in(x), in(y);
    printf("%d\n", (dep[x] + dep[y] - (dep[lca(x, y)] << 1)) >> 1);
  }
  return 0;
}
