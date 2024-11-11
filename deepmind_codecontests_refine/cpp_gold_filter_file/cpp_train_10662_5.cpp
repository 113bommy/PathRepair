#include <bits/stdc++.h>
struct edge {
  int to, next;
} e[200010 << 1];
int a[200010], head[200010], st[200010], ed[200010], rid[200010], dep[200010];
int n, m, dfn = 0, cnt = 1;
inline void ins(int x, int y) {
  e[++cnt].to = y;
  e[cnt].next = head[x];
  head[x] = cnt;
}
void dfs(int x, int f) {
  st[x] = ++dfn;
  rid[dfn] = x;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != f) {
      dep[e[i].to] = dep[x] + 1;
      dfs(e[i].to, x);
    }
  ed[x] = dfn;
}
struct segtree {
  int l, r, tag, fh;
} t[200010 << 2];
void build(int p, int l, int r) {
  t[p].l = l;
  t[p].r = r;
  t[p].tag = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
  }
}
void change(int p, int l, int r, int val) {
  if (l <= t[p].l && t[p].r <= r) {
    t[p].tag += val;
    return;
  }
  int mid = (t[p].l + t[p].r) >> 1;
  if (l <= mid) change(p << 1, l, r, val);
  if (mid + 1 <= r) change(p << 1 | 1, l, r, val);
}
inline void pushdown(int p) {
  t[p << 1].tag += t[p].tag;
  t[p << 1 | 1].tag += t[p].tag;
  t[p].tag = 0;
}
int query(int p, int x) {
  if (t[p].l == t[p].r)
    return a[rid[t[p].l]] + t[p].tag * ((dep[rid[t[p].l]] & 1) ? 1 : (-1));
  pushdown(p);
  int mid = (t[p].l + t[p].r) >> 1;
  if (x <= mid)
    return query(p << 1, x);
  else
    return query(p << 1 | 1, x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    ins(x, y);
    ins(y, x);
  }
  dep[1] = 1;
  dfs(1, 1);
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1) {
      int val;
      scanf("%d", &val);
      val *= (dep[x] & 1) ? 1 : (-1);
      change(1, st[x], ed[x], val);
    } else
      printf("%d\n", query(1, st[x]));
  }
  return 0;
}
