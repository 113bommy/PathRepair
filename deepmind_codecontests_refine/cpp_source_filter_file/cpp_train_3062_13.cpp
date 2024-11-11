#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
using namespace std;
const long long N = 2e5 + 100, OO = 1e9 + 7, K = 3e5 + 100, T = 5, M = 1e9 + 7,
                P = 6151, SQ = 810, lg = 20;
long long n, k;
pair<long long, long long> pts[N];
long long dp[SQ + T];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= k; i++) {
    long long x, y;
    cin >> x >> y;
    pts[i].first = y, pts[i].second = n - x + 1;
  }
  sort(pts + 1, pts + k + 1);
  for (long long i = 1; i < SQ; i++) dp[i] = 1e9;
  long long cur = 0, ans;
  for (long long i = 1; i <= n; i++) {
    while (cur < k && pts[cur + 1].first < i) cur++;
    long long cnt = 0;
    dp[0] = min(dp[0], dp[1]);
    long long mn = dp[0];
    for (long long j = 1; j < SQ; j++) {
      mn = min(mn, dp[j + 1]);
      if (cur < k && pts[cur + 1].first == i && pts[cur + 1].second == j)
        cur++, cnt++;
      dp[j] = min(dp[j + 1] - cnt * 3, mn + (1 + j) * j / 2 + 2 - cnt * 3);
    }
  }
  ans = min(dp[0], dp[1]) + k * 3;
  cout << ans << endl;
  return 0;
}
