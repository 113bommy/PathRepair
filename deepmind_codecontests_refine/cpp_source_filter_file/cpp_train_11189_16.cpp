#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool t = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') t = true, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
  return t ? -x : x;
}
int n, Q, lans;
struct Line {
  int v, next, w;
} e[100100 << 1];
int h[100100], cnt = 1;
inline void Add(int u, int v, int w) {
  e[cnt] = (Line){v, h[u], w};
  h[u] = cnt++;
}
struct Tree {
  int rt, p[19][100100], dfn[100100], low[100100], ln[100100], md[100100],
      dep[100100], tim;
  void dfs(int u, int ff) {
    p[0][u] = ff;
    ln[dfn[u] = ++tim] = u;
    md[u] = dep[u];
    for (int i = 1; i < 19; ++i) p[i][u] = p[i - 1][p[i - 1][u]];
    for (int i = h[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (v == ff) continue;
      dep[v] = dep[u] + e[i].w;
      dfs(v, u);
      md[u] = max(md[u], md[v]);
    }
    low[u] = tim;
  }
  pair<int, int> mx[100100 << 2];
  int tag[100100 << 2];
  void pushup(int now) { mx[now] = max(mx[(now << 1)], mx[(now << 1 | 1)]); }
  void Build(int now, int l, int r) {
    if (l == r) {
      mx[now] = make_pair(dep[ln[l]], ln[l]);
      return;
    }
    int mid = (l + r) >> 1;
    Build((now << 1), l, mid);
    Build((now << 1 | 1), mid + 1, r);
    pushup(now);
  }
  void Modify(int now, int l, int r, int L, int R, int w) {
    if (L <= l && r <= R) {
      mx[now].first += w;
      tag[now] += w;
      return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) Modify((now << 1), l, mid, L, R, w);
    if (R > mid) Modify((now << 1 | 1), mid + 1, r, L, R, w);
    pushup(now);
    mx[now].first += tag[now];
  }
  int ans[100100], vis[100100];
  void pre(int _rt) {
    rt = _rt;
    dfs(rt, 0);
    Build(1, 1, n);
    for (int i = 2; i <= n; ++i) {
      ans[i] = ans[i - 1] + mx[1].first;
      for (int j = mx[1].second; j && !vis[j]; j = p[0][j])
        vis[j] = i, Modify(1, 1, n, dfn[j], low[j], dep[p[0][j]] - dep[j]);
    }
  }
  int Solve(int x, int y) {
    y = min(y, n);
    if (vis[x] <= y) return ans[y];
    int u = x;
    for (int i = 18; ~i; --i)
      if (vis[p[i][x]] > y) x = p[i][x];
    x = p[0][x];
    return ans[y] + md[u] - dep[x] - min(ans[y] - ans[y - 1], md[x] - dep[x]);
  }
} T1, T2;
int mx, rt;
void dfs(int u, int ff, int dep) {
  if (dep > mx) mx = dep, rt = u;
  for (int i = h[u]; i; i = e[i].next)
    if (e[i].v != ff) dfs(e[i].v, u, dep + e[i].w);
}
int main() {
  n = read();
  Q = read();
  for (int i = 1, u, v, w; i < n; ++i)
    u = read(), v = read(), w = read(), Add(u, v, w), Add(v, u, w);
  mx = 0;
  dfs(1, 0, 0);
  T1.pre(rt);
  mx = 0;
  dfs(rt, 0, 0);
  T2.pre(rt);
  while (Q--) {
    int u = (read() + lans - 1) % n + 1, v = (read() + lans - 1) % n + 1;
    printf("%d\n", lans = min(T1.Solve(u, v << 1), T2.Solve(u, v << 1)));
  }
  return 0;
}
