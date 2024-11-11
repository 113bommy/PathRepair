#include <bits/stdc++.h>
inline int read() {
  register int x = 0, f = 1;
  register char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct SegmentTree {
  int n;
  double mul[400005], add[400005], sum[400005];
  inline void build(int p, int l, int r, int *a) {
    mul[p] = 1;
    add[p] = 0;
    if (l == r) {
      sum[p] = a[l];
      return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid, a);
    build(p << 1 | 1, mid + 1, r, a);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
  }
  inline void init(int n, int *a) {
    this->n = n;
    build(1, 1, n, a);
  }
  inline void spread(int p, int l, int r) {
    int mid = l + r >> 1;
    if (mul[p] != 1) {
      mul[p << 1] *= mul[p];
      mul[p << 1 | 1] *= mul[p];
      add[p << 1] *= mul[p];
      add[p << 1 | 1] *= mul[p];
      sum[p << 1] *= mul[p];
      sum[p << 1 | 1] *= mul[p];
      mul[p] = 1;
    }
    if (add[p]) {
      add[p << 1] += add[p];
      add[p << 1 | 1] += add[p];
      sum[p << 1] += add[p] * (mid - l + 1);
      sum[p << 1 | 1] += add[p] * (r - mid);
      add[p] = 0;
    }
  }
  inline void _modify_mul(int p, int l, int r, int L, int R, double val) {
    if (L <= l && r <= R) {
      add[p] *= val;
      mul[p] *= val;
      sum[p] *= val;
      return;
    }
    int mid = l + r >> 1;
    spread(p, l, r);
    if (L <= mid) _modify_mul(p << 1, l, mid, L, R, val);
    if (R > mid) _modify_mul(p << 1 | 1, mid + 1, r, L, R, val);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
  }
  inline void _modify_add(int p, int l, int r, int L, int R, double val) {
    if (L <= l && r <= R) {
      add[p] += val;
      sum[p] += (r - l + 1) * val;
      return;
    }
    int mid = l + r >> 1;
    spread(p, l, r);
    if (L <= mid) _modify_add(p << 1, l, mid, L, R, val);
    if (R > mid) _modify_add(p << 1 | 1, mid + 1, r, L, R, val);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
  }
  inline double _ask(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return sum[p];
    int mid = l + r >> 1;
    spread(p, l, r);
    if (R <= mid) return _ask(p << 1, l, mid, L, R);
    if (L > mid) return _ask(p << 1 | 1, mid + 1, r, L, R);
    return _ask(p << 1, l, mid, L, mid) +
           _ask(p << 1 | 1, mid + 1, r, mid + 1, R);
  }
  inline void modify(int opt, int L, int R, double val) {
    if (opt == 0)
      _modify_mul(1, 1, n, L, R, val);
    else
      _modify_add(1, 1, n, L, R, val);
  }
  inline double ask(int L, int R) { return _ask(1, 1, n, L, R); }
} SGT;
int a[100005];
int main() {
  int n = read(), Q = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  SGT.init(n, a);
  while (Q--) {
    int op = read();
    if (op == 1) {
      int l1 = read(), r1 = read(), l2 = read(), r2 = read();
      int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
      double sum1 = SGT.ask(l1, r1), sum2 = SGT.ask(l2, r2);
      SGT.modify(0, l1, r1, (len1 - 1) / (double)len1);
      SGT.modify(1, l1, r1, sum2 / (len1 * len2));
      SGT.modify(0, l2, r2, (len2 - 1) / (double)len2);
      SGT.modify(1, l2, r2, sum1 / (len1 * len2));
    } else {
      int l = read(), r = read();
      printf("%.5lf\n", SGT.ask(l, r));
    }
  }
  return 0;
}
