#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
const long long MAXK = 2e3 + 10;
const long long MAX_LOG = 23;
const long long Mod = 1e9 + 7;
pair<long long, long long> a[MAXN];
long long dp[MAXK][MAX_LOG];
long long rev[MAXN];
long long fact[MAXN];
long long pw(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  long long w = pw(x, n / 2);
  w *= w;
  w %= Mod;
  if (n & 1) {
    w *= x;
    w %= Mod;
  }
  return w;
}
long long c(long long n, long long k) {
  if (n < 0 || k > n) {
    return 0;
  }
  return (fact[n] * ((rev[k] * rev[n - k]) % Mod)) % Mod;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k, s, e = 0, res = 0;
  cin >> n >> m >> k >> s;
  fact[0] = 1;
  rev[0] = 1;
  for (long long i = 1; i < MAXN; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= Mod;
    rev[i] = pw(fact[i], Mod - 2);
  }
  for (long long i = 0; i < k; i++) {
    cin >> a[i].first >> a[i].second;
  }
  a[k].first = n;
  a[k].second = m;
  sort(a, a + k + 1);
  for (long long i = 0; i <= k; i++) {
    for (long long j = 0; j < MAX_LOG; j++) {
      dp[i][j] = c(a[i].first + a[i].second - 2, a[i].first - 1);
      for (long long u = 0; u < i; u++) {
        dp[i][j] +=
            Mod -
            ((dp[u][j] * c(a[i].first - a[u].first + a[i].second - a[u].second,
                           a[i].first - a[u].first)) %
             Mod);
        dp[i][j] %= Mod;
      }
    }
    for (long long j = MAX_LOG - 1; j > 0; j--) {
      dp[i][j] += Mod - dp[i][j - 1];
      dp[i][j] %= Mod;
    }
  }
  for (long long i = 0; i < MAX_LOG; i++) {
    res += dp[k][i] * s;
    res %= Mod;
    e += dp[k][i];
    e %= Mod;
    s = (s / 2) + (s & 1);
  }
  e = Mod - e;
  e %= Mod;
  e += c(n + m - 2, n - 1);
  e %= Mod;
  res += e;
  res %= Mod;
  res *= pw(c(n + m - 2, n - 1), Mod - 2);
  res %= Mod;
  cout << res;
}
