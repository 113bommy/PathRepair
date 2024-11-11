#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long c[200001];
long long dp[511][511];
const long long mod = 998244353ll;
long long solve(long long l, long long r) {
  if (l > r) return 1ll;
  if (l == r) return 1ll;
  if (dp[l][r] != -1) return dp[l][r];
  long long minx = 1000001;
  for (long long i = l; i <= r; i++) minx = min(minx, c[i]);
  long long m = 0;
  for (long long i = l; i <= r; i++) {
    if (minx == c[i]) {
      m = i;
      break;
    }
  }
  long long resl = 0ll;
  for (long long i = l; i <= m; i++) {
    resl += (solve(l, i - 1) * solve(i, m - 1)) % mod;
    resl %= mod;
  }
  long long resr = 0ll;
  for (long long i = m; i <= r; i++) {
    resr += (solve(m + 1, i) * solve(i + 1, r)) % mod;
    resr %= mod;
  }
  return dp[l][r] = (resl * resr) % mod;
}
int32_t main() {
  long long n;
  cin >> n >> n;
  for (long long i = 1; i <= n; i++) cin >> c[i];
  for (long long l = 1; l <= n; l++)
    for (long long r = 1; r <= n; r++) dp[l][r] = -1;
  cout << solve(1, n);
  return 0;
}
