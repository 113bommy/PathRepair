#include <bits/stdc++.h>
int mat[12][100005], t, fa[10 * 100005], n, m, q;
class segment_tree {
 public:
  segment_tree() {}
  segment_tree(const segment_tree &x) {
    l = x.l;
    r = x.r;
    c = x.c;
    for (int i = 1; i <= n; ++i) {
      a[i] = x.a[i];
      b[i] = x.b[i];
    }
  }
  int l, r, c, a[12], b[12];
} st[1 << 18];
int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  int px = find(x), py = find(y);
  if (px != py) {
    fa[py] = px;
    return true;
  }
  return false;
}
void combine(const segment_tree &a, const segment_tree &b, segment_tree &c) {
  for (int k = 1; k <= n; ++k) {
    fa[a.a[k]] = a.a[k];
    fa[a.b[k]] = a.b[k];
    fa[b.a[k]] = b.a[k];
    fa[b.b[k]] = b.b[k];
  }
  c.c = a.c + b.c;
  for (int k = 1; k <= n; ++k)
    if (mat[k][a.r] == mat[k][b.l])
      if (merge(a.b[k], b.a[k])) --c.c;
  for (int k = 1; k <= n; ++k) {
    c.a[k] = find(a.a[k]);
    c.b[k] = find(b.b[k]);
  }
  c.l = a.l, c.r = b.r;
}
void push_up(int i) { combine(st[i << 1], st[i << 1 | 1], st[i]); }
void init_st(int i, int l, int r) {
  st[i].l = l;
  st[i].r = r;
  if (l < r) {
    int mid = (l + r) >> 1;
    init_st(i << 1, l, mid);
    init_st(i << 1 | 1, mid + 1, r);
    push_up(i);
  } else {
    for (int k = 1; k <= n; ++k) {
      if (k == 1 || mat[k][l] != mat[k - 1][l]) {
        st[i].a[k] = st[i].b[k] = ++t;
        ++st[i].c;
      } else
        st[i].a[k] = st[i].b[k] = t;
    }
  }
}
void print(const segment_tree &x) {
  printf("(%d,%d,%d)\n", x.l, x.r, x.c);
  for (int i = 1; i <= n; ++i) printf("%d ", x.a[i]);
  printf("\n");
  for (int i = 1; i <= n; ++i) printf("%d ", x.b[i]);
  printf("\n");
}
segment_tree query(int i, int l, int r) {
  if (st[i].l >= l && st[i].r <= r) return st[i];
  int mid = (st[i].l + st[i].r) >> 1;
  if (l > mid)
    return query(i << 1 | 1, l, r);
  else if (r <= mid)
    return query(i << 1, l, r);
  segment_tree lt = query(i << 1, l, r), rt = query(i << 1 | 1, l, r), ret;
  combine(lt, rt, ret);
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &mat[i][j]);
  init_st(1, 1, m);
  for (int l, r; q--;) {
    scanf("%d%d", &l, &r);
    printf("%d\n", query(1, l, r).c);
  }
  return 0;
}
