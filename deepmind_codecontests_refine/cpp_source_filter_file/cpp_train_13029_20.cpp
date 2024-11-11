#include <bits/stdc++.h>
using namespace std;
const int N = 200500, M = 3500, mod = 998244353;
int n, m, a[N], b[N], ans[N];
long long A, B, dp[2][M], rs[M + M];
bool was[M];
long long binpow(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return res;
}
long long inv(long long x) { return binpow(x, mod - 2); }
long long invS(long long k) {
  k += m;
  if (was[k]) return rs[k];
  was[k] = 1;
  return rs[k] = inv(A + B + k - m);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    if (a[i])
      A += b[i];
    else
      B += b[i];
  }
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      long long aa = A + j;
      long long bb = B - (i - j);
      dp[1][j + 1] =
          (dp[1][j + 1] + dp[0][j] * aa % mod * invS(j + j - i)) % mod;
      dp[1][j] = (dp[1][j] + dp[0][j] * bb % mod * invS(j + j - i)) % mod;
    }
    for (int j = 0; j <= i + 1; j++) dp[0][j] = dp[1][j], dp[1][j] = 0;
  }
  long long sum, val;
  sum = 0;
  val = 1;
  for (int i = 0; i <= m; i++) {
    sum = (sum + val * dp[0][i]) % mod;
    val = val * (A + i + 1) % mod * inv(A + i) % mod;
  }
  for (int i = 0; i < n; i++)
    if (a[i]) ans[i] = b[i] * sum % mod;
  sum = 0;
  val = 1;
  for (int i = 0; i <= m; i++) {
    sum = (sum + val * dp[0][m - i]) % mod;
    val = val * (B - i - 1 + mod) % mod * inv(B - i) % mod;
  }
  for (int i = 0; i < n; i++)
    if (!a[i]) ans[i] = b[i] * sum % mod;
  for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
  return 0;
}
