#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
struct matrix {
  long long int n, m, a[3][3];
  matrix(int n1, int m1) {
    n = n1, m = m1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = 0;
  }
  void identity() {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[i][j] = (i == j);
  }
};
matrix operator*(matrix A, matrix B) {
  matrix ret(A.n, B.m);
  for (int i = 0; i < A.n; i++) {
    for (int j = 0; j < B.m; j++) {
      for (int k = 0; k < A.m; k++) {
        ret.a[i][j] += (1ll * A.a[i][k] * B.a[k][j]) % mod;
        ;
        ret.a[i][j] %= mod;
      }
    }
  }
  return ret;
}
matrix mat(2, 2), paye(1, 2);
matrix wop(matrix x, long long int y) {
  matrix ret(2, 2);
  ret.identity();
  if (y == 0) return ret;
  ret = wop(x, y / 2);
  ret = ret * ret;
  ret.a[0][0] %= mod;
  ret.a[0][1] %= mod;
  ret.a[1][0] %= mod;
  ret.a[1][1] %= mod;
  if (y & 1) ret = ret * mat;
  ret.a[0][0] %= mod;
  ret.a[0][1] %= mod;
  ret.a[1][0] %= mod;
  ret.a[1][1] %= mod;
  return ret;
}
long long int opwer(long long int x, long long int y) {
  long long int ret = 1;
  for (; y >= 1; y /= 2) {
    if (y & 1) ret *= x;
    x *= x;
    ret %= mod;
    x %= mod;
  }
  return ret;
}
int main() {
  mat.a[0][0] = 0, mat.a[0][1] = 1, mat.a[1][0] = 1, mat.a[1][1] = 1;
  paye.a[0][0] = 0;
  paye.a[1][0] = 1;
  long long int n, k, l, m;
  cin >> n >> k >> l >> m;
  if (l <= 60 && k >= (1ll << l)) return cout << 0, 0;
  mod = m;
  matrix fib(2, 2);
  fib = wop(mat, n + 2);
  long long int ans = 1;
  long long int ze = (fib * paye).a[0][0],
                on = opwer(2, n) - (fib * paye).a[0][0];
  ze %= mod;
  on += mod;
  on %= mod;
  on += mod;
  on %= mod;
  for (int i = 0; i < l; i++) {
    if (k & 1)
      ans *= on;
    else
      ans *= ze;
    ans %= mod;
    k /= 2;
  }
  cout << ans % m;
}
