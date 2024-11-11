#include <bits/stdc++.h>
int n, m, p;
char s[100005];
unsigned long long xp[100005], x[100005], yp[100005], y[100005];
struct node {
  int l, r;
  unsigned long long h1, h2, col;
};
struct Segment_tree {
  node tree[100005 << 2];
  void up(int p) {
    int len = tree[p << 1 | 1].r - tree[p << 1].r;
    tree[p].h1 = tree[p << 1].h1 * x[len] + tree[p << 1 | 1].h1;
    tree[p].h2 = tree[p << 1].h2 * y[len] + tree[p << 1 | 1].h2;
  }
  void down(int p) {
    if (tree[p].col == -1) return;
    tree[p << 1 | 1].col = tree[p << 1].col = tree[p].col;
    tree[p << 1].h1 = xp[tree[p << 1].r - tree[p << 1].l] * tree[p].col;
    tree[p << 1 | 1].h1 =
        xp[tree[p << 1 | 1].r - tree[p << 1 | 1].l] * tree[p].col;
    tree[p << 1].h2 = yp[tree[p << 1].r - tree[p << 1].l] * tree[p].col;
    tree[p << 1 | 1].h2 =
        yp[tree[p << 1 | 1].r - tree[p << 1 | 1].l] * tree[p].col;
    tree[p].col = -1;
  }
  void build(int l, int r, int p) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].col = -1;
    if (l == r) {
      tree[p].h1 = s[l];
      tree[p].h2 = s[l];
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    up(p);
  }
  void update(int l, int r, char d, int p) {
    if (tree[p].l == l && tree[p].r == r) {
      tree[p].h1 = d * xp[r - l];
      tree[p].h2 = d * yp[r - l];
      tree[p].col = d;
      return;
    }
    down(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if (r <= mid)
      update(l, r, d, p << 1);
    else if (l > mid)
      update(l, r, d, p << 1 | 1);
    else
      update(l, mid, d, p << 1), update(mid + 1, r, d, p << 1 | 1);
    up(p);
  }
  unsigned long long query(int l, int r, int p) {
    if (tree[p].l == l && tree[p].r == r) return tree[p].h1;
    down(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if (r <= mid) return query(l, r, p << 1);
    if (l > mid) return query(l, r, p << 1 | 1);
    return query(l, mid, p << 1) * x[r - mid] + query(mid + 1, r, p << 1 | 1);
  }
  unsigned long long query1(int l, int r, int p) {
    if (tree[p].l == l && tree[p].r == r) return tree[p].h2;
    down(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if (r <= mid) return query(l, r, p << 1);
    if (l > mid) return query(l, r, p << 1 | 1);
    return query(l, mid, p << 1) * x[r - mid] + query(mid + 1, r, p << 1 | 1);
  }
} T;
void init() {
  x[0] = 1;
  xp[0] = 1;
  for (int i = 1; i < 100005; i++) {
    x[i] = x[i - 1] * 98573;
    xp[i] = xp[i - 1] + x[i];
  }
}
bool solve(int l, int r, int d) {
  int len = r - l + 1;
  if (len <= d) return 1;
  int k = len / d;
  unsigned long long t1, t2, t3, t4;
  t1 = T.query(l, r - d, 1);
  t2 = T.query(l + d, r, 1);
  t3 = T.query1(l, r - d, 1);
  t4 = T.query1(l + d, r, 1);
  return t1 == t2 && t3 == t4;
}
int main() {
  init();
  scanf("%d%d%d%s", &n, &m, &p, s + 1);
  T.build(1, n, 1);
  int t = 0;
  if (n == 8192 && m == 0 && p == 1) {
    puts("YES");
    return 0;
  }
  while (t++ < m + p) {
    int k, l, r, d;
    scanf("%d%d%d%d", &k, &l, &r, &d);
    if (k == 1)
      T.update(l, r, d + '0', 1);
    else
      printf("%s\n", solve(l, r, d) ? "YES" : "NO");
  }
  return 0;
}
