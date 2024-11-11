#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, MOD;
  cin >> N >> MOD;
  auto add_self = [&](long long& a, long long b) {
    a += b;
    if (a >= MOD) {
      a -= MOD;
    }
  };
  vector<long long> dp(N + 1), preffix_sum(N + 1);
  dp[1] = preffix_sum[1] = 1;
  for (long long i = 2; i <= N; ++i) {
    dp[i] = preffix_sum[i - 1];
    long long z = 2;
    while (i / z > 0) {
      long long nxt = i / (i / z);
      add_self(dp[i], (nxt - z + 1) * dp[i / z]);
      z = nxt + 1;
    }
    preffix_sum[i] = preffix_sum[i - 1];
    add_self(preffix_sum[i], dp[i]);
  }
  cout << dp[N] << '\n';
}
