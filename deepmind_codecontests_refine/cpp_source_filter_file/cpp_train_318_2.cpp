#include <bits/stdc++.h>
using namespace std;
int read();
int n, t, K;
long long A[502], B[502], a[502], b[502], c[502];
long long f[2][402][402], g[2][402][402];
bool linf(long long x) { return x <= (10000000000000000ll >> 1); }
long long calc(long long x, long long lim) {
  long long t = (x - 1 + K) / K;
  return t * K <= lim ? t : 10000000000000000ll;
}
void chmin(long long &x, long long y) { x > y ? x = y : 0; }
int main() {
  n = read(), t = read(), K = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = read(), c[i] = read();
  ++n, a[n] = b[n] = K << 1, c[n] = 10000000000000000ll;
  for (int i = 2; i <= n; ++i) A[i] = A[i - 1] + a[i], B[i] = B[i - 1] + b[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= t; ++j) {
      for (int p = 0; p < 2; ++p) {
        long long &F = f[p][i][j], &G = g[p][i][j];
        F = G = 10000000000000000ll;
        if (linf(f[p][i - 1][j]) && (p ? a[i] : 0) + b[i] * j <= c[i]) {
          F = f[p][i - 1][j];
          G = calc((p ? A[i - 1] : 0) + B[i - 1] * j,
                   (p ? A[i] : 0) + B[i] * j);
        }
        long long rem, t1;
        for (int k = 0; k < j; ++k) {
          if (!linf(g[p][i][k])) continue;
          rem = (p ? A[i] : 0) + B[i] * k - K * g[p][i][k];
          t1 = calc(max(rem + (j - k) * b[i] - c[i], 0ll), rem);
          if (!linf(max(t1, f[0][i - 1][j - k]))) continue;
          chmin(F, g[p][i][k] + t1 + f[0][i - 1][j - k]);
          chmin(G,
                g[p][i][k] + t1 +
                    calc(B[i - 1] * (j - k), B[i] * (j - k) + (rem - t1 * K)));
        }
      }
    }
  }
  printf("%lld\n", f[1][n][t]);
  return 0;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
