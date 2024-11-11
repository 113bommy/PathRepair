#include <bits/stdc++.h>
using namespace std;
const int N = 3005, mo = 998244353;
int n, c, a[N], ans[N], b[N], _[N], ny[N];
int f[N][1 << 11], g[N][305];
void work1() {
  int mx = 0, all = (1 << c) - 1;
  f[0][0] = 1;
  for (int i = 1, _e = n; i <= _e; ++i) {
    int A = a[i] - 1;
    for (int j = 0, _e = mx; j <= _e; ++j)
      for (int k = 0, _e = (1 << c - A - 1) - 1; k <= _e; ++k)
        for (int l = 0, _e = (1 << A) - 1; l <= _e; ++l)
          (f[j][(k << A + 1) + (1 << A) + l] =
               ((long long)f[j][(k << A + 1) + (1 << A) + l] * 2 +
                f[j][(k << A + 1) + l]) %
               mo);
    for (int j = 0, _e = mx; j <= _e; ++j)
      if (f[j][all]) {
        f[j + 1][0] = (f[j + 1][0] + f[j][all]) % mo;
        f[j][all] = 0;
        if (mx == j) ++mx;
      }
  }
  for (int i = 0, _e = n / c; i <= _e; ++i) {
    long long su = 0;
    for (int j = 0, _e = all; j <= _e; ++j) su += f[i][j];
    ans[i] = su % mo;
  }
}
int ksm(int x, int y) {
  int t = 1;
  for (; y; y >>= 1, x = (long long)x * x % mo)
    if (y & 1) t = (long long)t * x % mo;
  return t;
}
void work2() {
  _[0] = 1;
  for (int i = 1, _e = n; i <= _e; ++i) _[i] = _[i - 1] * 2 % mo;
  for (int i = 0, _e = n; i <= _e; ++i) ny[i] = ksm(_[i] - 1, mo - 2);
  ny[0] = 1;
  g[0][0] = 1;
  for (int i = 0, _e = n; i <= _e; ++i) {
    int mx = i / c, all = 0;
    long long su = _[n - i], xs, o = 1;
    for (int j = 1, _e = c; j <= _e; ++j) b[j] = 0;
    for (int j = i + 1, _e = n; j <= _e; ++j) {
      !b[a[j]]++ ? ++all : 0;
      xs = o * ny[b[a[j]] - 1] % mo;
      o = xs * (_[b[a[j]]] - 1) % mo;
      if (all == c) {
        su = (su - xs * _[n - j] % mo + mo) % mo;
        for (int k = 0, _e = mx; k <= _e; ++k)
          g[j][k + 1] = ((long long)g[i][k] * xs + g[j][k + 1]) % mo;
      }
    }
    for (int j = 0, _e = mx; j <= _e; ++j)
      ans[j] = ((long long)g[i][j] * su + ans[j]) % mo;
  }
}
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1, _e = n; i <= _e; ++i) scanf("%d", &a[i]);
  if (c > 11)
    work1();
  else
    work2();
  ans[0] = (ans[0] + mo - 1) % mo;
  for (int i = 0, _e = n; i <= _e; ++i) printf("%d ", ans[i]);
}
