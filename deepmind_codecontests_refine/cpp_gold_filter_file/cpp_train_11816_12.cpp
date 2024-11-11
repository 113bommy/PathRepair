#include <bits/stdc++.h>
using namespace std;
using ii = pair<long long, long long>;
const long long mod = 1e9 + 7;
long long n, m, k;
vector<ii> e;
long long dp[2001][2001];
long long fact[200001];
long long pw[200001];
namespace geo {
long long pow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long f = pow(a, b / 2);
  f = (f * f) % mod;
  return (f * pow(a, b % 2)) % mod;
}
}  // namespace geo
long long comb(long long k, long long n) {
  if (k > n || k < 0) return 0;
  if (k == n || k == 0) return 1;
  long long cur = (fact[n] * pw[k]) % mod;
  return (cur * pw[n - k]) % mod;
}
long long path(long long x1, long long y1, long long x2, long long y2) {
  long long n = x2 - x1 + 1, m = y2 - y1 + 1;
  return comb(n - 1, n + m - 2);
}
int32_t main() {
  ios::sync_with_stdio(0);
  fact[0] = 1;
  for (long long i = 1; i <= 200001 - 1; i++) fact[i] = (fact[i - 1] * i) % mod;
  for (long long i = 1; i <= 200001 - 1; i++)
    pw[i] = geo::pow(fact[i], mod - 2);
  cin >> n >> m >> k;
  e.push_back({1, 1});
  for (long long i = 1; i <= k; i++) {
    long long x, y;
    cin >> x >> y;
    e.push_back({x, y});
  }
  sort(e.begin(), e.end());
  for (long long i = k; i >= 0; i--) {
    dp[i][i] = path(e[i].first, e[i].second, n, m);
    for (long long j = i + 1; j <= k; j++) {
      dp[i][i] = (dp[i][i] - dp[i][j] + mod) % mod;
    }
    for (long long j = i - 1; j >= 0; j--) {
      dp[j][i] =
          (path(e[j].first, e[j].second, e[i].first, e[i].second) * dp[i][i]) %
          mod;
    }
  }
  cout << dp[0][0];
}
