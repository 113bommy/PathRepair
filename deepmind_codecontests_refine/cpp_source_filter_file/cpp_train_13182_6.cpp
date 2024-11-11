#include <bits/stdc++.h>
using namespace std;
const int maxl = 100005, maxg = 25;
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -w;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = (s << 1) + (s << 3) + (ch ^ '0');
    ch = getchar();
  }
  return s * w;
}
int n, tree_root, q, nowtim = 0, cnt = 0, tot = 0, x, y, k, treedeep = 0,
                     lastans;
int a[maxl], head[maxl], siz[maxl], dfn[maxl], depth[maxl], root[maxl],
    maxinum_rt[maxl];
struct edge {
  int nxt, to;
} e[2 * maxl];
struct Segment_tree {
  int l, r, val;
} tree[maxl * maxg];
struct node {
  int d1, d2, d3;
} tmp[2 * maxl];
bool cmp(node tmpx, node tmpy) { return tmpx.d1 < tmpy.d1; }
void add_edge(int u, int v) {
  cnt++;
  e[cnt].to = v, e[cnt].nxt = head[u], head[u] = cnt;
}
void dfs(int now, int fath) {
  siz[now] = 1, dfn[now] = ++nowtim, depth[now] = depth[fath] + 1;
  treedeep = max(treedeep, depth[now]);
  for (int i = head[now]; i; i = e[i].nxt) {
    int y = e[i].to;
    if (y == fath) continue;
    dfs(y, now), siz[now] += siz[y];
  }
}
void pushup(int rt) {
  tree[rt].val = min(tree[tree[rt].l].val, tree[tree[rt].r].val);
}
int ducati_clone(int rt) {
  tot++;
  tree[tot] = tree[rt];
  return tot;
}
int build_tree(int l, int r, int rt) {
  rt = ++tot;
  if (l == r) {
    tree[rt].val = 200000009;
    return rt;
  }
  int mid = (l + r) >> 1;
  tree[rt].l = build_tree(l, mid, rt << 1);
  tree[rt].r = build_tree(mid + 1, r, (rt << 1) | 1);
  pushup(rt);
  return rt;
}
int change(int nl, int l, int r, int rt, int kk) {
  rt = ducati_clone(rt);
  if (l == r) {
    tree[rt].val = kk;
    return rt;
  }
  int mid = (l + r) >> 1;
  if (nl <= mid)
    tree[rt].l = change(nl, l, mid, tree[rt].l, kk);
  else
    tree[rt].r = change(nl, mid + 1, r, tree[rt].r, kk);
  pushup(rt);
  return rt;
}
int query(int nl, int nr, int l, int r, int rt) {
  if (nl <= l && r <= nr) return tree[rt].val;
  int mid = (l + r) >> 1, minv = 200000009;
  if (nl <= mid) minv = query(nl, nr, l, mid, tree[rt].l);
  if (nr > mid) minv = min(minv, query(nl, nr, mid + 1, r, tree[rt].r));
  return minv;
}
int tree_query(int maxdeep, int le, int ri) {
  maxdeep = min(maxdeep, treedeep);
  maxdeep = maxinum_rt[maxdeep];
  return query(le, ri, 1, n, root[maxdeep]);
}
signed main() {
  n = read(), tree_root = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i < n; i++) {
    x = read(), y = read();
    add_edge(x, y), add_edge(y, x);
  }
  dfs(tree_root, 0);
  for (int i = 1; i <= n; i++)
    tmp[i].d1 = depth[i], tmp[i].d2 = dfn[i], tmp[i].d3 = a[i];
  sort(tmp + 1, tmp + n + 1, cmp);
  for (int i = 1; i <= n; i++)
    maxinum_rt[tmp[i].d1] = max(maxinum_rt[tmp[i].d1], i);
  root[0] = build_tree(1, n, root[0]);
  for (int i = 1; i <= n; i++)
    root[i] = change(tmp[i].d2, 1, n, root[i - 1], tmp[i].d3);
  q = read();
  while (q--) {
    x = read(), k = read();
    x = ((x + lastans) % n) + 1;
    k = (k + lastans) % n;
    lastans = tree_query(depth[x] + k, dfn[x], dfn[x] + siz[x] - 1);
    printf("%d\n", lastans);
  }
  return 0;
}
