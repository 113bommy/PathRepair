#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
const long long INF = 1e18;
const long long MOD = 998244353;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
long long fac[MAXN], inv[MAXN], sum[MAXN], dp[MAXN][30];
long long Ent(long long r, long long n) {
  if (n < 0 || r > n) {
    return 0;
  }
  return (fac[n] * inv[r] % MOD) * inv[n - r] % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  fac[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = poww(fac[i], MOD - 2, MOD);
  }
  long long n, ts = 0;
  string s, t;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (i > 0 && s[i] == s[i - 1]) {
      continue;
    }
    t += s[i];
    ts++;
  }
  sum[0] = 1;
  for (int i = 1; i <= ts; i++) {
    for (int j = 1; j <= i; j++) {
      long long k = dp[j][t[i - 1] - 'a'];
      dp[j][t[i - 1] - 'a'] =
          (sum[j - 1] - dp[j - 1][t[i - 1] - 'a'] + MOD) % MOD;
      sum[j] = (sum[j] + (dp[j][t[i - 1] - 'a'] - k + MOD)) % MOD;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= ts; i++) {
    ans = (ans + sum[i] * Ent(i - 1, n - 1)) % MOD;
  }
  cout << ans;
}
