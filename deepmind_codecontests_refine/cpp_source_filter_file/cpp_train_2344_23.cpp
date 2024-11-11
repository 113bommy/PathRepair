#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;
long long n, x, y, mod, t;
long long cp0, cp1, cp2, a1, a2;
struct mat {
  int a[2][2];
  mat(int c = 0) {
    a[0][0] = c, a[0][1] = 0;
    a[1][0] = 0, a[1][1] = c;
  }
  mat(int a00, int a01, int a10, int a11) {
    a[0][0] = a00, a[0][1] = a01;
    a[1][0] = a10, a[1][1] = a11;
  }
  void output() {
    printf("%d %d\n%d %d\n", a[0][0], a[0][1], a[1][0], a[1][1]);
  }
};
mat mul(const mat& a, const mat& b) {
  mat res;
  for (int k = 0; k < (2); ++k)
    for (int i = 0; i < (2); ++i)
      for (int j = 0; j < (2); ++j) {
        res.a[i][j] =
            ((long long)a.a[i][k] * b.a[k][j] % mod + res.a[i][j]) % mod;
      }
  return res;
}
mat cal(const mat& a, long long p) {
  mat res(1), t = a;
  while (p) {
    if (p & 1) res = mul(res, t);
    t = mul(t, t);
    p >>= 1;
  }
  return res;
}
long long fib(long long x1, long long x2, long long my) {
  mat res(1, 0, 1, 1);
  res = cal(res, my);
  return (x1 * res.a[0][0] % mod + x2 * res.a[1][0] % mod) % mod;
}
long long cal(long long x1, long long x2, long long my) {
  mat res(1, 0, 1, 3);
  res = cal(res, my);
  return (x1 * (res.a[0][0] + res.a[1][0]) % mod +
          x2 * (res.a[0][1] + res.a[1][1]) % mod) %
         mod;
}
void solve() {
  long long tot = cal(a1, a2, x);
  a1 = (cp0 + fib(cp1, cp2, x)) % mod;
  a2 = (tot + mod - a1) % mod;
  tot = cal(a1, a2, y);
  printf("%I64d\n", tot);
}
int main() {
  while (scanf("%I64d%I64d%I64d%I64d", &n, &x, &y, &mod) != EOF) {
    a1 = 0LL, a2 = 0LL;
    for (int i = 0; i < (n); ++i) {
      scanf("%I64d", &t);
      if (i == n - 2) cp1 = t;
      if (i == n - 1) cp2 = t;
      if (i == 0) cp0 = t;
      if (i == 0 || i == n - 1) {
        a1 = (a1 + t) % mod;
      } else {
        a2 = (a2 + t) % mod;
      }
    }
    if (n == 1) {
      printf("%I64d\n", t % mod);
      continue;
    }
    solve();
  }
  return 0;
}
