#include <bits/stdc++.h>
using namespace std;
inline void solve() {
  long long r, n, cur = 0;
  cin >> r >> n;
  vector<long long> dp(n, 0), t(n), x(n), y(n), res(n + 1, 0);
  for (long long i = 0; i < n; i++) {
    cin >> t[i] >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  for (long long i = 0; i < n; i++) {
    if (x[i] + y[i] > t[i])
      dp[i] = -1;
    else {
      long long from = max(0LL, i - 2 * r);
      dp[i] = 1 + res[from];
      for (long long j = from + 1; j < i; j++) {
        long long dis = abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[j];
        if (dis <= t[i] and dp[j] >= 0) dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res[i + 1] = max(res[i], dp[i]);
  }
  cout << res[n] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n = 1;
  while (n--) solve();
  return 0;
}
