#include <bits/stdc++.h>
using namespace std;
int n, L, W;
int a[100010], b[100010];
double eps = 1e-6;
int f(int y, int x) {
  double m = (a[x] + L + b[y]) / 2.0;
  double t = b[y] - m + L;
  double mi = m / t;
  if (mi < -W + eps) return -1;
  if (mi > W - eps) return 1;
  return 0;
}
int bsearch1(int l, int r, int x) {
  if (r - l <= 1) {
    if (f(l, x) == 0) return l;
    if (f(r, x) == 0) return r;
    return l;
  }
  int m = (l + r) / 2;
  if (f(m, x) >= 0)
    return bsearch1(l, m, x);
  else
    return bsearch1(m + 1, r, x);
}
int bsearch2(int l, int r, int x) {
  if (r - l <= 1) {
    if (f(r, x) == 0) return r;
    if (f(l, x) == 0) return l;
    return r;
  }
  int m = (l + r) / 2;
  if (f(m, x) <= 0)
    return bsearch2(m, r, x);
  else
    return bsearch2(l, m - 1, x);
}
int bsearch3(int l, int r, int x) {
  if (r - l <= 1) {
    if (f(l, x) == 0) return l;
    if (f(r, x) == 0) return r;
    return l;
  }
  int m = (l + r) / 2;
  if (f(m, x) <= 0)
    return bsearch3(l, m, x);
  else
    return bsearch3(m + 1, r, x);
}
int bsearch4(int l, int r, int x) {
  if (r - l <= 1) {
    if (f(r, x) == 0) return r;
    if (f(l, x) == 0) return l;
    return r;
  }
  int m = (l + r) / 2;
  if (f(m, x) >= 0)
    return bsearch4(m, r, x);
  else
    return bsearch4(l, m - 1, x);
}
int main() {
  scanf("%d%d%d", &n, &L, &W);
  int u, v, an = 0, bn = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &u, &v);
    if (v == 1) {
      a[an++] = u;
    } else {
      b[bn++] = u;
    }
  }
  sort(a, a + an);
  sort(b, b + bn);
  long long ans = 0;
  for (int i = 0; i < an; i++) {
    int x = upper_bound(b, b + bn, a[i]) - b;
    if (x == bn) break;
    int l, r;
    if (f(x, i) <= f(bn - 1, i)) {
      l = bsearch1(x, bn - 1, i);
      r = bsearch2(x, bn - 1, i);
    } else {
      l = bsearch3(x, bn - 1, i);
      r = bsearch4(x, bn - 1, i);
    }
    if (f(l, i) == 0 && f(r, i) == 0) ans += r - l + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
