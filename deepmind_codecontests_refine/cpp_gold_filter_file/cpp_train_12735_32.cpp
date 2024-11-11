#include <bits/stdc++.h>
using namespace std;
int n, m, opt;
const int MAXN = 100006;
int fa[MAXN], siz[MAXN], de[MAXN], to[MAXN << 1], nxt[MAXN << 1], head[MAXN],
    son[MAXN], top_[MAXN], id[MAXN];
int tree[MAXN << 2], maxx[MAXN << 2];
int cnt, tot;
inline void add_edge(int x, int y) {
  ++cnt;
  to[cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
inline int dfs1(int now, int fath) {
  fa[now] = fath;
  siz[now] = 1;
  de[now] = de[fath] + 1;
  int maxn = -1;
  for (register int i = head[now]; i; i = nxt[i]) {
    if (to[i] == fath) continue;
    siz[now] += dfs1(to[i], now);
    if (siz[now] > maxn) {
      maxn = siz[now];
      son[now] = to[i];
    }
  }
  return siz[now];
}
inline void dfs2(int now, int _top) {
  top_[now] = _top;
  id[now] = ++tot;
  if (!son[now]) return;
  dfs2(son[now], _top);
  for (register int i = head[now]; i; i = nxt[i]) {
    if (to[i] == fa[now] || to[i] == son[now]) continue;
    dfs2(to[i], to[i]);
  }
  return;
}
inline void undate(int L, int R, int l, int r, int k, int v) {
  if (L <= l && r <= R) {
    tree[k] = v;
    maxx[k] = !v;
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid) undate(L, R, l, mid, k << 1, v);
  if (R > mid) undate(L, R, mid + 1, r, k << 1 | 1, v);
  tree[k] = tree[k << 1] + tree[k << 1 | 1];
  maxx[k] = max(maxx[k << 1], maxx[k << 1 | 1]);
  return;
}
inline void build(int k, int l, int r) {
  if (l == r) {
    tree[k] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  tree[k] = tree[k << 1] + tree[k << 1 | 1];
  return;
}
inline int query(int L, int R, int l, int r, int k) {
  if (L <= l && r <= R) {
    return tree[k];
  }
  int res = 0;
  int mid = (l + r) >> 1;
  if (L <= mid) res += query(L, R, l, mid, k << 1);
  if (R > mid) res += query(L, R, mid + 1, r, k << 1 | 1);
  return res;
}
inline int Mquery(int L, int R, int l, int r, int k) {
  if (L <= l && r <= R) {
    return maxx[k];
  }
  int mid = (l + r) >> 1;
  int res = 0;
  if (L <= mid) res = max(res, Mquery(L, R, l, mid, k << 1));
  if (R > mid) res = max(res, Mquery(L, R, mid + 1, r, k << 1 | 1));
  return res;
}
inline int C(int x, int y) {
  int res = 0, now = 0;
  while (top_[x] != top_[y]) {
    if (de[top_[x]] < de[top_[y]]) swap(x, y);
    res += query(id[top_[x]], id[x], 1, n, 1);
    now += Mquery(id[top_[x]], id[x], 1, n, 1);
    x = fa[top_[x]];
  }
  if (id[x] > id[y]) swap(x, y);
  res += query(id[x] + 1, id[y], 1, n, 1);
  now += Mquery(id[x] + 1, id[y], 1, n, 1);
  if (now) return -1;
  return res;
}
int main() {
  int x, y;
  scanf("%d", &n);
  for (register int i = 1; i < n; i = -~i) {
    scanf("%d%d", &x, &y);
    add_edge(x, y);
    add_edge(y, x);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  build(1, 1, n);
  int tmp;
  scanf("%d", &m);
  for (register int i = 1; i <= m; i = -~i) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d", &x);
      y = (id[to[x * 2]] < id[to[x * 2 - 1]] ? to[x * 2 - 1] : to[x * 2]);
      undate(id[y], id[y], 1, n, 1, 1);
    }
    if (opt == 2) {
      scanf("%d", &x);
      y = (id[to[x * 2]] < id[to[x * 2 - 1]] ? to[x * 2 - 1] : to[x * 2]);
      undate(id[y], id[y], 1, n, 1, 0);
    }
    if (opt == 3) {
      scanf("%d%d", &x, &y);
      tmp = C(x, y);
      if (tmp == -1)
        puts("-1");
      else
        printf("%d\n", tmp);
    }
  }
  return 0;
}
