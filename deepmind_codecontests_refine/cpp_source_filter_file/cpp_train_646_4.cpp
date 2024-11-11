#include <bits/stdc++.h>
using namespace std;
int n, m, K, mxd, Log[150012], h[150012],
    cnt = 0, dep[150012], siz[150012], son[150012], fa[150012], tp[150012],
    L[150012], R[150012], dfst = 0, f[150012][19], X[150012], Y[150012];
long long ans = 0;
struct Edge {
  int to, next;
} e[150012 << 1];
inline void AddEdge(int x, int y) {
  e[++cnt] = (Edge){y, h[x]};
  h[x] = cnt;
}
void dfs1(int x, int prt) {
  int i, y;
  siz[x] = 1;
  fa[x] = prt;
  dep[x] = dep[prt] + 1;
  f[x][0] = prt;
  for (i = 1; i <= Log[dep[x]]; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (i = h[x]; i; i = e[i].next)
    if ((y = e[i].to) != prt) {
      dfs1(y, x);
      siz[x] += siz[y];
      if (siz[y] > siz[son[x]]) son[x] = y;
    }
}
void dfs2(int x, int T) {
  L[x] = ++dfst;
  tp[x] = T;
  int i, y;
  if (son[x]) dfs2(son[x], T);
  for (i = h[x]; i; i = e[i].next)
    if (((y = e[i].to) != fa[x]) && (e[i].to != son[x])) dfs2(y, y);
  R[x] = dfst;
}
inline int LCA(int x, int y) {
  int fx = tp[x], fy = tp[y];
  while (fx != fy) {
    if (dep[fx] < dep[fy]) swap(x, y), swap(fx, fy);
    x = fa[fx];
    fx = tp[x];
  }
  return (dep[x] < dep[y]) ? x : y;
}
int tot = 0, c[150012 * 20][2], s[150012 * 20];
void Ins(int &p, int l, int r, int x, int v) {
  if (!p) s[p = ++tot] = 0, c[p][0] = c[p][1] = 0;
  s[p] += v;
  if (l == r) return;
  int mid = (l + r) >> 1;
  (x <= mid) ? Ins(c[p][0], l, mid, x, v) : Ins(c[p][1], mid + 1, r, x, v);
}
int Merge(int x, int y, int l, int r) {
  if ((!x) || (!y)) return (x | y);
  if (l == r) {
    s[x] += s[y];
    return x;
  }
  int mid = (l + r) >> 1;
  s[x] += s[y];
  c[x][0] = Merge(c[x][0], c[y][0], l, mid);
  c[x][1] = Merge(c[x][1], c[y][1], mid + 1, r);
  return x;
}
int Ask(int p, int l, int r, int L, int R) {
  if ((!p) || (R < l) || (r < L)) return 0;
  if ((L <= l) && (r <= R)) return s[p];
  int mid = (l + r) >> 1;
  return Ask(c[p][0], l, mid, L, R) + Ask(c[p][1], mid + 1, r, L, R);
}
inline int jump(int x, int de) {
  if (dep[x] < de) return -1;
  for (int i = Log[dep[x]]; i >= 0; i--)
    if (dep[f[x][i]] >= de) x = f[x][i];
  return x;
}
vector<int> I1[150012], D1[150012], I2[150012];
int rt[150012], st[150012], cn = 0;
vector<int> q[150012];
void dfs4(int x, int we) {
  int i, y, p;
  st[++cn] = x;
  for (auto v : q[x]) {
    p = jump(v, max(K - dep[x] + dep[we], 1) + dep[we]);
    if (~p) ans += Ask(rt[x], 1, n, L[p], R[p]);
    if (dep[x] - K >= dep[we]) {
      p = jump(v, dep[we] + 1);
      if (~p) ans -= Ask(rt[x], 1, n, L[p], R[p]);
    }
    p = jump(v, dep[we] + K);
    if (~p) ans -= Ask(rt[x], 1, n, L[p], R[p]);
    Ins(rt[x], 1, n, L[v], 1);
  }
  for (i = h[x]; i; i = e[i].next)
    if ((y = e[i].to) != fa[x]) {
      dfs4(y, we);
      if (q[y].size() > q[x].size()) q[y].swap(q[x]), swap(rt[x], rt[y]);
      for (auto v : q[y]) {
        q[x].push_back(v);
        p = jump(v, max(K - dep[x] + dep[we], 1) + dep[we]);
        if (~p) ans += Ask(rt[x], 1, n, L[p], R[p]);
        if (dep[x] - K >= dep[we]) {
          p = jump(v, dep[we] + 1);
          if (~p) ans -= Ask(rt[x], 1, n, L[p], R[p]);
        }
        p = jump(v, dep[we] + K);
        if (~p) ans -= Ask(rt[x], 1, n, L[p], R[p]);
      }
      rt[x] = Merge(rt[x], rt[y], 1, n);
      q[y].clear();
    }
}
void solve(int we) {
  if (I2[we].empty()) return;
  int i, x, y;
  for (auto v : I2[we]) {
    x = X[v];
    y = Y[v];
    if (L[x] > L[y]) swap(x, y);
    q[y].push_back(x);
  }
  for (i = h[we]; i; i = e[i].next)
    if (((y = e[i].to) != fa[we]) && (e[i].to != son[we])) dfs4(y, we);
  for (i = 1; i <= cn; i++) q[st[i]].clear(), rt[st[i]] = 0;
  cn = 0;
  tot = 0;
}
void dfs3(int x, int prt) {
  int i, y, v1 = 0, v2 = 0;
  for (auto v : I1[x]) Ins(rt[x], 1, mxd, v, 1);
  for (i = h[x]; i; i = e[i].next)
    if ((y = e[i].to) != prt) {
      dfs3(y, x);
      rt[x] = Merge(rt[x], rt[y], 1, mxd);
    }
  for (auto v : D1[x]) Ins(rt[x], 1, mxd, v, -1);
  if (dep[x] > K) v1 = Ask(rt[x], 1, mxd, 1, dep[x] - K);
  if (dep[x] > (K + 1)) v2 = Ask(rt[x], 1, mxd, 1, dep[x] - K - 1);
  ans += 1ll * v1 * (v1 - 1) / 2 - 1ll * v2 * (v2 - 1) / 2;
}
int main() {
  Log[0] = -1;
  for (int i = 1; i < 150012; i++) Log[i] = Log[i >> 1] + 1;
  scanf("%d%d%d", &n, &m, &K);
  int i, x, y, p;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    AddEdge(x, y);
    AddEdge(y, x);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  for (i = 1; i <= n; i++) mxd = max(mxd, dep[i]);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    X[i] = x;
    Y[i] = y;
    if (dep[x] < dep[y]) swap(x, y);
    p = LCA(x, y);
    I1[x].push_back(dep[p]);
    D1[p].push_back(dep[p]);
    if (p != y) {
      I1[y].push_back(dep[p]);
      D1[p].push_back(dep[p]);
      I2[p].push_back(i);
    }
  }
  dfs3(1, 0);
  for (i = 1; i <= n; i++) rt[i] = 0;
  tot = 0;
  for (i = 1; i <= n; i++) solve(i);
  printf("%lld", ans);
  return 0;
}
