#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using pii = std::pair<long long, long long>;
using namespace std;
const long long maxn = 5005;
long long n, a[maxn], ne[maxn], pre[maxn], dp[maxn][maxn];
long long mod_expo(long long x, long long p) {
  long long res = 1;
  x = ((x % MOD) + MOD) % MOD;
  while (p > 0) {
    if (p & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    p /= 2;
  }
  return res;
}
long long mod_inv(long long x) { return mod_expo(x, MOD - 2); }
vector<long long> fact, inv_fact;
void precalculate_factorials(long long MAX_FACT) {
  fact.resize(MAX_FACT + 1);
  inv_fact.resize(MAX_FACT + 1);
  fact[0] = 1;
  for (long long i = 1; i <= MAX_FACT; i++) fact[i] = (fact[i - 1] * i) % MOD;
  inv_fact[MAX_FACT] = mod_inv(fact[MAX_FACT]);
  for (long long i = MAX_FACT - 1; i >= 0; i--)
    inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}
long long nPr_mod(long long n, long long r) {
  return (n < r) ? 0 : (fact[n] * inv_fact[n - r]) % MOD;
}
long long nCr_mod(long long n, long long r) {
  return (n < r) ? 0 : (nPr_mod(n, r) * inv_fact[r]) % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  precalculate_factorials(maxn);
  cin >> n;
  a[0] = 0;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  long long fi = n + 1;
  for (long long i = n; i > 0; i--) {
    while (fi > i && a[fi - 1] >= 2 * a[i]) fi--;
    ne[i] = fi;
  }
  ne[0] = 1;
  fi = 0;
  for (long long i = 1; i <= n; i++) {
    while (fi < i && 2 * a[fi + 1] <= a[i]) fi++;
    pre[i] = fi;
  }
  dp[0][0] = 1;
  dp[1][0] = -1;
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j < n; j++) {
      if (i > 0) dp[i][j] += dp[i - 1][j];
      dp[i][j] %= MOD;
      if (!dp[i][j]) continue;
      long long placesad = pre[i] - max((j - 1), 0ll);
      long long totalplaces = n - j;
      assert(placesad >= 0 && placesad <= totalplaces);
      dp[ne[i]][j + placesad + 1] +=
          (dp[i][j] * nPr_mod(totalplaces, placesad)) % MOD;
      dp[ne[i]][j + placesad + 1] %= MOD;
    }
  long long ans = 0;
  for (long long j = 1; j <= n; j++)
    if (dp[n][j]) {
      long long placesad = pre[n] - (j - 1);
      long long totalplaces = n - j;
      if (placesad == totalplaces) {
        ans += (dp[n][j] * nPr_mod(totalplaces, placesad)) % MOD;
        ans %= MOD;
      }
    }
  cout << ans << "\n";
  return 0;
}
