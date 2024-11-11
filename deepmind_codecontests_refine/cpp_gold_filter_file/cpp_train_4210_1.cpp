#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const long long maxn = 105;
struct Matrix {
  long long n, m;
  long long c[maxn][maxn];
  Matrix(long long N = 0, long long M = 0) {
    n = N, m = M;
    memset(c, 0, sizeof(c));
  }
  Matrix operator*(const Matrix a) const {
    long long l = n, r = a.m;
    Matrix x = Matrix(l, r);
    for (long long i = 1; i <= l; ++i) {
      for (long long j = 1; j <= r; ++j) {
        for (long long k = 1; k <= m; ++k) {
          x.c[i][j] += c[i][k] * a.c[k][j];
          x.c[i][j] %= mod;
        }
      }
    }
    return x;
  }
} A, B;
long long n, k, x = 4;
long long f[45][45];
Matrix pow(Matrix& x, long long b) {
  Matrix ans = Matrix(x.n, x.m);
  for (long long i = 1; i <= x.m; ++i) ans.c[i][i] = 1;
  while (b) {
    if (b & 1) ans = x * ans;
    x = x * x;
    b >>= 1;
  }
  return ans;
}
inline void init(void) {
  f[0][0] = 1;
  for (long long i = 1; i <= k; ++i) {
    f[i][0] = 1;
    for (long long j = 1; j <= i; ++j)
      f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
  }
  return;
}
signed main() {
  scanf("%lld%lld", &n, &k);
  init();
  A = Matrix(1, 3 + (k << 1));
  A.c[1][1] = 1;
  A.c[1][2] = 2;
  A.c[1][3] = 1;
  for (long long i = 1; i <= k; ++i) {
    A.c[1][3 + i] = 1;
    A.c[1][k + 3 + i] = x % mod;
    x <<= 1;
  }
  B = Matrix(3 + (k << 1), 3 + (k << 1));
  B.c[2][1] = 1;
  B.c[1][2] = B.c[2][2] = 1;
  B.c[3][3] = B.c[3 + (k << 1)][3] = 1;
  for (long long i = 1; i <= k; ++i) {
    B.c[1][i + k + 3] = (1ll << i) % mod;
    B.c[3 + k + i][3 + i] = 1;
    B.c[2][3 + i + k] = 1;
  }
  for (long long i = 1; i <= k; ++i) {
    for (long long j = i; j <= k; ++j) {
      B.c[3 + i][3 + k + j] = (((1ll << j - i) % mod) * f[j][i]) % mod;
      B.c[3 + k + i][3 + k + j] = f[j][i];
    }
  }
  A = A * pow(B, n - 1);
  printf("%lld", A.c[1][3]);
  return 0;
}
