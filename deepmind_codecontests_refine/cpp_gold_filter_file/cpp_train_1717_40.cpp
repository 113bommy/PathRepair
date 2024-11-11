#include <bits/stdc++.h>
using namespace std;
long long mod;
struct Matrix {
  int n, m, d[5][5];
  Matrix(int a, int b) {
    n = a, m = b;
    memset(d, 0, sizeof(d));
  }
  void Copy(int *tmp) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        d[i][j] = (*tmp) % mod;
        tmp++;
      }
  }
  friend Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix c(a.n, b.m);
    for (int i = 0; i < a.n; i++)
      for (int j = 0; j < b.m; j++) {
        long long tmp = 0;
        for (int k = 0; k < a.m; k++) {
          tmp += (long long)a.d[i][k] * b.d[k][j] % mod;
          tmp %= mod;
        }
        c.d[i][j] = tmp % mod;
      }
    return c;
  }
};
long long solve(long long n) {
  Matrix A(1, 2), B(2, 2);
  int x[2] = {1, 1};
  int y[4] = {0, 1, 1, 1};
  A.Copy(x);
  B.Copy(y);
  while (n) {
    if (n & 1) A = A * B;
    B = B * B;
    n >>= 1;
  }
  return A.d[0][0] % mod;
}
long long qpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
int main() {
  long long ans, ti, k;
  int l;
  while (scanf("%I64d %I64d %d %I64d", &ti, &k, &l, &mod) != EOF) {
    if ((l < 64 && (1ULL << l) <= k) || mod == 1) {
      printf("0\n");
      continue;
    }
    long long tmp0 = solve(ti + 1);
    long long tmp1 = (qpow(2, ti) - tmp0 + mod) % mod;
    ans = 1;
    for (int i = 0; i < l; i++) {
      if (k & 1)
        ans = ans * tmp1 % mod;
      else
        ans = ans * tmp0 % mod;
      k >>= 1;
    }
    ans = ans % mod;
    printf("%I64d\n", ans);
  }
  return 0;
}
