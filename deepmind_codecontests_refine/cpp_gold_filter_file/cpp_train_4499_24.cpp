#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const long long MAXN = 92 + 10;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
bool is_in[MAXN] = {false};
long long dp[90][2] = {0};
vector<long long> fib;
long long solve() {
  for (int i = 0; i < 90; i++) dp[i][0] = dp[i][1] = 0;
  long long n;
  cin >> n;
  memset(is_in, false, sizeof is_in);
  for (int i = fib.size() - 1; i >= 0; i--) {
    if (n >= fib[i]) n -= fib[i], is_in[i + 1] = true;
  }
  if (n) return cout << 0 << '\n', 0;
  dp[0][1] = 1, dp[0][0] = 0;
  long long lst1 = 0;
  for (int i = 1; i < 90; i++) {
    if (is_in[i]) {
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
      if (!is_in[i - 1] && i > 2)
        dp[i][0] = ((i - lst1) >> 1ll) * dp[lst1][0] +
                   ((i - lst1 - 1) >> 1ll) * dp[lst1][1];
      lst1 = i;
    } else {
      dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    }
  }
  cout << dp[89][0] << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fib.push_back(1);
  fib.push_back(2);
  while (fib.back() < INF) fib.push_back(fib.back() + fib[fib.size() - 2]);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
