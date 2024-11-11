#include <bits/stdc++.h>
using namespace std;
int nn;
struct mat {
  long long a[85][85];
};
mat mul(mat a, mat b, long long mod) {
  mat tt;
  int i, j, k;
  memset(tt.a, 0, sizeof(tt.a));
  for (i = 0; i < nn; i++)
    for (j = 0; j < nn; j++)
      for (k = 0; k < nn; k++)
        tt.a[i][j] = (tt.a[i][j] + a.a[i][k] * b.a[k][j] + mod) % mod;
  return tt;
}
mat matpow(mat a, long long b, long long mod) {
  mat s;
  memset(s.a, 0, sizeof(s.a));
  for (int i = 0; i < nn; i++) s.a[i][i] = 1;
  while (b) {
    if (b & 1LL) s = mul(s, a, mod);
    a = mul(a, a, mod);
    b = b >> 1;
  }
  return s;
}
void output(mat tt) {
  for (int i = 0; i < nn; i++) {
    for (int j = 0; j < nn; j++) printf("%lld ", tt.a[i][j]);
    printf("\n");
  }
}
int main() {
  int m, tt, i, j, k, s, t;
  long long q = 1000000007LL;
  long long f[105][105], ans, n;
  mat a, b, c, d;
  memset(f, 0, sizeof(f));
  for (i = 0; i <= 100; i++) {
    f[i][0] = 1;
    f[i][i] = 1;
    for (j = 1; j < i; j++) f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
  }
  while (scanf("%I64d%d", &n, &k) != EOF) {
    memset(a.a, 0, sizeof(a.a));
    a.a[2 * k + 2][k] = 1;
    a.a[2 * k + 2][2 * k + 2] = 1;
    for (i = 0; i <= k; i++)
      for (j = 0; j <= i; j++) {
        a.a[i][j] = f[i][j];
        a.a[i + k + 1][j] = f[i][j];
        a.a[i][j + k + 1] = f[i][j];
      }
    nn = 2 * k + 3;
    b = matpow(a, n, q);
    ans = 0;
    for (i = 0; i <= 2 * k + 1; i++) ans = (ans + b.a[2 * k + 2][i] + q) % q;
    printf("%I64d\n", ans);
  }
  return 0;
}
