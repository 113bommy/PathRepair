#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
long long dp[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a;
  for (long long i = 0; i < n; ++i) cin >> a, dp[a]++;
  long long ans = 0;
  for (long long i = N; i >= 1; --i) {
    if (!dp[i]) continue;
    for (long long j = 2 * i; j <= N; j += i) {
      dp[i] = max(dp[i], 1 + dp[j]);
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << '\n';
}
