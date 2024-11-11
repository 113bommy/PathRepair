#include <bits/stdc++.h>
using namespace std;
const long long N = 4e6 + 10;
long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long n, m;
long long dp[N];
void solve() {
  cin >> n >> mod;
  dp[1] = 1, dp[2] = 2;
  for (long long i = (2); i <= (n); ++i) {
    if (i > 2) dp[i] = (dp[i] + dp[i - 1] * 2 + 1) % mod;
    long long d = dp[i] - dp[i - 1];
    for (long long j = 2; j <= n / i; j++) {
      dp[i * j] += d;
    }
  }
  cout << (dp[n] % mod + mod) % mod << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
