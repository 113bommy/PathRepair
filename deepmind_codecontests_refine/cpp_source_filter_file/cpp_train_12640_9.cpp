#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long MOD = 1e9 + 7;
int m;
int pre[N], pre2[N];
long long x[N], y[N], tot;
long long dp[N][1005], fac[1106], inv[1106];
long long mul(long long a, long long b) { return (a * b) % MOD; }
long long add(long long a, long long b) { return (a + b) % MOD; }
long long fastexp(long long a, long long b) {
  if (b == 0) return 1;
  if (a == 0) return 0;
  long long x = fastexp(a, b >> 1);
  x = mul(x, x);
  if (b & 1) x = mul(x, a);
  return x;
}
void factorials() {
  fac[0] = 1;
  for (int i = 1; i <= 1105; i++) fac[i] = mul(fac[i - 1], i);
}
void inverses() {
  inv[0] = 1;
  for (int i = 1; i <= 1105; i++) inv[i] = fastexp(fac[i], MOD - 2);
}
long long ncr(int a, int b) {
  long long x = mul(fac[a], inv[b]);
  x = mul(x, inv[a - b]);
  return x;
}
int main() {
  factorials();
  inverses();
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%lld", x + i);
    pre[i] = x[i] + pre[i - 1];
    tot += x[i];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld", y + i);
  }
  for (int i = m; i > 0; i--) {
    pre2[i] = pre2[i + 1] + y[i] - x[i];
  }
  long long ans = fac[m];
  for (int i = 1; i <= m; i++) ans = mul(ans, inv[x[i]]);
  dp[m + 1][0] = 1;
  long long cur = 0;
  for (int i = m; i > 0; i--) {
    for (int j = 0; j <= 1000; j++) {
      if (j > pre[i - 1] or j > pre2[i]) break;
      cur = x[i] + j;
      for (int k = min(cur, y[i]); k >= 0; k--) {
        if (dp[i + 1][cur - k] == 0) break;
        dp[i][j] = add(dp[i][j], mul(ncr(cur, k), dp[i + 1][cur - k]));
      }
    }
  }
  ans = mul(ans, dp[1][0]);
  printf("%lld\n", ans);
}
