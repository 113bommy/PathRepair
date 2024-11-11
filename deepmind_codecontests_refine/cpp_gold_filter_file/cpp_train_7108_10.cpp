#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = 1e18;
const double EPS = 1e-8;
const int MOD = 998244353;
int n;
int a[5005];
int pos[5005];
long long dp[5005];
long long qpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % MOD;
    x = x * x % MOD;
    n >>= 1;
  }
  return res;
}
long long fac[5005], invfac[5005];
long long A(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return fac[n] * invfac[n - m] % MOD;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
  for (int i = 0; i <= n; ++i) invfac[i] = qpow(fac[i], MOD - 2);
  sort(a + 1, a + 1 + n);
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j + 1 <= n && a[j + 1] * 2 <= a[i]) ++j;
    pos[i] = j;
  }
  if (pos[n] != n - 1) {
    puts("0");
    return;
  }
  dp[0] = 1;
  pos[0] = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= pos[i]; ++j)
      dp[i] =
          (dp[i] + dp[j] * A(n - 2 - pos[j], pos[i] - pos[j] - 1) % MOD) % MOD;
  }
  printf("%lld\n", dp[n]);
  return;
}
int main() {
  int T = 1;
  for (int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
