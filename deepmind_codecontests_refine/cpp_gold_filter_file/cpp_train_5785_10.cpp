#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
pair<int, int> rc[2005];
int r[2005];
int c[2005];
long long dp[2005][25];
long long inv[200010];
long long val[35];
long long fact[200010];
long long invFact[200010];
long long powmod(long long a, long long b) {
  if (b == 0) {
    return 1 % MOD;
  } else if (b == 1) {
    return a % MOD;
  } else {
    long long temp = powmod(a, b >> 1);
    if (b & 1) {
      return ((temp * temp) % MOD) * a % MOD;
    } else {
      return temp * temp % MOD;
    }
  }
}
long long ncr(int n, int r) {
  if (r < 0 || r > n) {
    return 0;
  }
  return ((fact[n] * invFact[n - r] % MOD) * invFact[r]) % MOD;
}
long long f(int i, int j) {
  if (r[i] > r[j] || c[i] > c[j]) {
    return 0;
  }
  return ncr((r[j] - r[i]) + (c[j] - c[i]), c[j] - c[i]);
}
int n, m, k, s;
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  inv[1] = 1;
  for (int i = 2; i <= n + m + 5; i++) {
    inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
  }
  val[0] = s;
  for (int i = 1; i <= 25; i++) {
    val[i] = (val[i - 1] + 1) >> 1;
  }
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i <= n + m + 5; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    invFact[i] = invFact[i - 1] * inv[i] % MOD;
  }
  for (int i = 0; i < k; i++) {
    int r, c;
    scanf("%d%d", &r, &c);
    rc[i] = pair<int, int>(r, c);
  }
  rc[k] = pair<int, int>(n, m);
  sort(rc, rc + (k + 1));
  for (int i = 0; i <= k; i++) {
    r[i] = rc[i].first;
    c[i] = rc[i].second;
  }
  for (int hit = 0; hit <= 22; hit++) {
    for (int i = 0; i <= k; i++) {
      dp[i][hit] = ncr(r[i] - 1 + c[i] - 1, c[i] - 1);
      for (int j = 0; j < i; j++) {
        dp[i][hit] -= f(j, i) * dp[j][hit] % MOD;
      }
      for (int h = 0; h < hit; h++) {
        dp[i][hit] -= dp[i][h];
      }
      dp[i][hit] %= MOD;
      dp[i][hit] = (dp[i][hit] + MOD) % MOD;
    }
  }
  long long totalWays = ncr((n - 1) + (m - 1), m - 1);
  long long excessWays = totalWays;
  long long ans = 0;
  for (int i = 0; i <= 22; i++) {
    excessWays -= dp[k][i];
    ans += dp[k][i] * val[i] % MOD;
  }
  ans %= MOD;
  excessWays %= MOD;
  excessWays = (excessWays + MOD) % MOD;
  ans = (ans + excessWays) % MOD;
  printf("%lld", ans * powmod(totalWays, MOD - 2) % MOD);
  return 0;
}
