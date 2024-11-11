#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
long long n, x, m, MOD;
struct MAT {
  long long x[2][2];
  MAT() {
    int i, j;
    for (i = 0; i < 2; i++)
      for (j = 0; j < 2; j++) x[i][j] = 0;
  }
  MAT operator*(const MAT &p) const {
    MAT res;
    int i, j, k;
    for (i = 0; i < 2; i++)
      for (j = 0; j < 2; j++)
        for (k = 0; k < 2; k++)
          res.x[i][j] += x[i][k] * p.x[k][j], res.x[i][j] %= MOD;
    return res;
  }
};
int main() {
  int i, j, k;
  cin >> n >> x >> m >> MOD;
  for (i = m; i < 63; i++) {
    if ((1ll << i) & x) return printf("0"), 0;
  }
  long long dab = 1;
  for (i = 0; i < m; i++) {
    MAT res, fib;
    res.x[0][0] = res.x[1][1] = 1;
    fib.x[0][0] = fib.x[0][1] = fib.x[1][0] = 1;
    for (j = 0; j < 63; j++) {
      if ((1ll << j) & (n + 1)) res = res * fib;
      fib = fib * fib;
    }
    if (!((1ll << i) & x))
      dab *= res.x[0][0], dab %= MOD;
    else {
      long long r, t;
      r = 1, t = 2;
      for (j = 0; j < 63; j++) {
        if ((1ll << j) & n) r = r * t, r %= MOD;
        t = t * t, t %= MOD;
      }
      dab *= (r - res.x[0][0] + MOD) % MOD, dab %= MOD;
    }
  }
  cout << dab;
  return 0;
}
