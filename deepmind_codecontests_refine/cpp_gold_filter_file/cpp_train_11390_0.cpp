#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m;
int cnt = 0, hed[N], to[N + N], nxt[N + N];
int fa[N], dep[N], son[N], sz[N], top[N], seg[N], rev[N], idx = 0;
bool lz[N * 4], hv[N * 4];
inline void add(int x, int y) {
  to[++cnt] = y, nxt[cnt] = hed[x], hed[x] = cnt;
}
void dfs1(int u, int ff) {
  fa[u] = ff, dep[u] = dep[ff] + 1, sz[u] = 1;
  for (int i = hed[u]; i; i = nxt[i]) {
    if (to[i] == ff) continue;
    dfs1(to[i], u), sz[u] += sz[to[i]];
    if (sz[son[u]] < sz[to[i]]) son[u] = to[i];
  }
}
void dfs2(int u, int tp) {
  top[u] = tp, seg[u] = ++idx, rev[idx] = u;
  if (son[u]) dfs2(son[u], tp);
  for (int i = hed[u]; i; i = nxt[i])
    if (!top[to[i]]) dfs2(to[i], to[i]);
}
void pushdown(int u) {
  if (lz[u]) {
    hv[u * 2] = hv[u * 2 + 1] = hv[u];
    lz[u * 2] = lz[u * 2 + 1] = 1;
    lz[u] = 0;
  }
}
void mdy(int u, int l, int r, int L, int R, int w) {
  if (l == L && r == R) {
    hv[u] = w, lz[u] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(u);
  if (R <= mid)
    mdy(u * 2, l, mid, L, R, w);
  else if (L > mid)
    mdy(u * 2 + 1, mid + 1, r, L, R, w);
  else
    mdy(u * 2, l, mid, L, mid, w), mdy(u * 2 + 1, mid + 1, r, mid + 1, R, w);
  hv[u] = hv[u * 2] | hv[u * 2 + 1];
}
bool qry(int u, int l, int r, int L, int R) {
  if (l == L && r == R) return hv[u];
  int mid = (l + r) >> 1;
  pushdown(u);
  if (R <= mid) return qry(u * 2, l, mid, L, R);
  if (L > mid) return qry(u * 2 + 1, mid + 1, r, L, R);
  return qry(u * 2, l, mid, L, mid) | qry(u * 2 + 1, mid + 1, r, mid + 1, R);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
  dfs1(1, 0), dfs2(1, 1);
  scanf("%d", &m);
  for (int x, y; m; --m) {
    scanf("%d%d", &x, &y);
    if (x == 1)
      mdy(1, 1, n, seg[y], seg[y] + sz[y] - 1, 1);
    else if (x == 2) {
      for (; y;) mdy(1, 1, n, seg[top[y]], seg[y], 0), y = fa[top[y]];
    } else {
      bool flag = 0;
      for (; y;) flag |= qry(1, 1, n, seg[top[y]], seg[y]), y = fa[top[y]];
      flag ? puts("1") : puts("0");
    }
  }
  return 0;
}
