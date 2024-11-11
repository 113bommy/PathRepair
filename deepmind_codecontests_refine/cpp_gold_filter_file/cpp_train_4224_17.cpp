#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
const int maxn = 1e5 + 10;
const long long inf = 1e18;
int n, c, p[maxn], s[maxn];
long long dp[maxn];
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i < n + 1; ++i) scanf("%d", p + i);
  for (int i = 1; i < n + 1; ++i) scanf("%d", s + i);
  for (int i = 1; i < n + 1; ++i) {
    dp[i] = inf;
    for (int j = i + 1 - 1; j >= 1; --j)
      dp[j] = min(dp[j - 1] + s[i], dp[j] + (long long)c * j + p[i]);
    dp[0] += p[i];
  }
  long long ans = dp[0];
  for (int i = 0; i < n + 1; ++i) ans = min(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}
