#include <bits/stdc++.h>
using namespace std;
template <typename T>
void R(T &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
const int N = 210000, M = 1510000;
int n, t, q, p[N], y[N], x[N];
struct Tree {
  int l, r, g1, g2;
  double f1, f2, ans;
  inline void update() {
    ans = p[l] * min((double)x[l] / (x[l] + y[l]), 0.5);
    if (x[l] >= y[l])
      f1 = 0;
    else {
      f1 = (double)p[l] * (x[l] + 1) / (x[l] + 1 + y[l]);
      f1 -= (double)p[l] * x[l] / (x[l] + y[l]);
    }
    if (x[l]) {
      if (x[l] > y[l])
        f2 = 0;
      else {
        f2 = (double)p[l] * x[l] / (x[l] + y[l]);
        f2 -= (double)p[l] * (x[l] - 1) / (x[l] - 1 + y[l]);
      }
    } else
      f2 = 1e18;
  }
} tree[N << 2];
void up(int o) {
  if (tree[(o << 1)].f1 > tree[(o << 1 | 1)].f1) {
    tree[o].f1 = tree[(o << 1)].f1;
    tree[o].g1 = tree[(o << 1)].g1;
  } else {
    tree[o].f1 = tree[(o << 1 | 1)].f1;
    tree[o].g1 = tree[(o << 1 | 1)].g1;
  }
  if (tree[(o << 1)].f2 < tree[(o << 1 | 1)].f2) {
    tree[o].f2 = tree[(o << 1)].f2;
    tree[o].g2 = tree[(o << 1)].g2;
  } else {
    tree[o].f2 = tree[(o << 1 | 1)].f2;
    tree[o].g2 = tree[(o << 1 | 1)].g2;
  }
  tree[o].ans = tree[(o << 1)].ans + tree[(o << 1 | 1)].ans;
}
void bd(int o, int l, int r) {
  tree[o].l = l, tree[o].r = r;
  if (l == r) {
    tree[o].g1 = tree[o].g2 = l;
    tree[o].update();
    return;
  }
  int mid = (l + r) >> 1;
  if (l <= mid) bd((o << 1), l, mid);
  if (r > mid) bd((o << 1 | 1), mid + 1, r);
  up(o);
}
void change(int o, int x) {
  if (tree[o].l == tree[o].r) {
    tree[o].update();
    return;
  }
  int mid = (tree[o].l + tree[o].r) >> 1;
  if (x <= mid)
    change((o << 1), x);
  else
    change((o << 1 | 1), x);
  up(o);
}
int main() {
  R(n), R(t), R(q);
  for (int i = 1; i <= n; ++i) R(p[i]);
  for (int i = 1; i <= n; ++i) R(y[i]);
  bd(1, 1, n);
  while (t--) ++x[tree[1].g1], change(1, tree[1].g1);
  int a, b;
  for (int i = 1; i <= q; ++i) {
    R(a), R(b);
    if (a == 1)
      ++y[b];
    else
      --y[b];
    change(1, b);
    while (tree[1].f1 > tree[1].f2) {
      int t1 = tree[1].g1, t2 = tree[1].g2;
      ++x[tree[1].g1], --x[tree[1].g2];
      change(1, t1);
      change(1, t2);
    }
    printf("%.12lf\n", tree[1].ans);
  }
  return 0;
}
