#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 150001;
const long long MAXM = 300;
long long a[MAXM], b[MAXM], t[MAXM];
long long dp[MAXN];
deque<pair<long long, long long>> dq;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, d;
  cin >> n >> m >> d;
  for (long long i = 0; i < m; i++) cin >> a[i] >> b[i] >> t[i];
  for (long long i = 0; i <= n; ++i) dp[i] = 0;
  long long pt = 1;
  for (long long i = 0; i < m; i++) {
    dq.clear();
    long long maxd = min((t[i] - pt) * d, n);
    for (long long j = 1; j <= maxd; j++) {
      while (!dq.empty() and dq.back().first <= dp[j]) dq.pop_back();
      dq.push_back({dp[j], j});
    }
    for (long long j = 1, l, r; j <= n; ++j) {
      r = j + maxd, l = j - maxd;
      if (r <= n) {
        while (!dq.empty() and dq.back().first <= dp[r]) dq.pop_back();
        dq.push_back({dp[r], r});
      }
      while (!dq.empty() and dq.front().second < l) dq.pop_front();
      dp[j] = dq.front().first + (b[i] - abs(a[i] - j));
    }
    pt = t[i];
  }
  long long ans = LLONG_MIN;
  for (long long j = 1; j <= n; j++) {
    ans = max(ans, dp[j]);
  }
  cout << ans;
  return 0;
}
