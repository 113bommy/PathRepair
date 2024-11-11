#include <bits/stdc++.h>
using namespace std;
const long long N = (1 << 20) + 10;
long long dp[N];
void solve() {
  long long n, m, b;
  cin >> n >> m >> b;
  vector<array<long long, 3>> info;
  for (long long i = 0; i < n; ++i) {
    long long x, k, p;
    cin >> x >> k >> p;
    long long val = 0;
    while (p--) {
      long long task;
      cin >> task;
      --task;
      val |= (1 << task);
    }
    info.push_back({k, x, val});
  }
  memset(dp, 0x3f, sizeof dp);
  sort(info.begin(), info.end());
  long long ans = 2e18;
  dp[0] = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < (1 << m); ++j) {
      long long mask = info[i][2] | j;
      dp[mask] = min(dp[mask], dp[j] + info[i][1]);
    }
    ans = min(ans, dp[(1 << m) - 1] + info[i][0] * b);
  }
  if (ans == 2e18) ans = -1;
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  while (t--) solve();
}
