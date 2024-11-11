#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int a[1010], b[1010];
double f[1010];
int par[1010];
int n, m;
inline void getans(int x) {
  if (x == 0) return;
  getans(par[x]);
  printf("%d ", x);
}
inline bool check(double L) {
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = 214748364777777.0;
    for (int j = 0; j < i; j++) {
      double tmp = f[j] + sqrt(1.0 * abs(a[i] - a[j] - m)) - L * b[i];
      if (tmp < f[i]) {
        f[i] = tmp;
        par[i] = j;
      }
    }
  }
  if (f[n] < 0)
    return 1;
  else
    return 0;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
  double l = 0, r = 1e10;
  while (r - l > 1e-8) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  getans(n);
  return 0;
}
