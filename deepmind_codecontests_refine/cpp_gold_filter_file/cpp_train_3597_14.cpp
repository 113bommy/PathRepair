#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2010, K = 100010;
long long P[K], P2[K];
long long dp[N][N];
long long sum[N], sumr[N][N], suml[N][N], sumpl[N];
long long cj[K], inv[K];
long long pl[N], pr[N];
int quick(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % mod) {
    if (y & 1) ans = ans * x % mod;
  }
  return ans;
}
long long c(int i, int j) { return cj[j] * inv[i] % mod * inv[j - i] % mod; }
int main() {
  long long a, b;
  int n, m, k;
  int i, j;
  scanf("%d%d", &n, &m);
  scanf("%I64d%I64d", &a, &b);
  scanf("%d", &k);
  P2[0] = 1;
  P2[1] = a * quick(b, mod - 2) % mod;
  a = b - a;
  P[0] = 1;
  P[1] = a * quick(b, mod - 2) % mod;
  for (i = 2; i <= k; i++) {
    P[i] = P[i - 1] * P[1] % mod;
    P2[i] = P2[i - 1] * P2[1] % mod;
  }
  cj[0] = 1;
  for (i = 1; i <= k; i++) cj[i] = cj[i - 1] * i % mod;
  inv[k] = quick(cj[k], mod - 2);
  for (i = k - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (i = 0; i <= m - 1; i++) {
    if (i > k) pl[i + 1] = 0;
    pl[i + 1] = c(i, k) * P2[i] % mod * P[k - i] % mod;
    pr[m - i] = pl[i + 1];
  }
  for (i = 1; i <= m; i++) sumpl[i] = (sumpl[i - 1] + pl[i]) % mod;
  sumr[0][m] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      sum[j] = (sum[j - 1] + pl[j] * sumr[i - 1][j - 1]) % mod;
    for (j = 1; j <= m; j++)
      dp[i][j] =
          ((pr[j] * (sumr[i - 1][m] - suml[i - 1][j + 1]) % mod * sumpl[j] -
            pr[j] * sum[j]) %
               mod +
           mod) %
          mod;
    for (j = 1; j <= m; j++) sumr[i][j] = (sumr[i][j - 1] + dp[i][j]) % mod;
    for (j = 1; j <= m; j++) suml[i][j] = sumr[i][m - j + 1];
  }
  sumr[n][m] = (sumr[n][m] + mod) % mod;
  printf("%I64d", sumr[n][m]);
}
