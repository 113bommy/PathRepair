#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
const long long N = 1e5 + 2;
void run() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n, p;
long long a[55], sum[55], dp[55][55];
bool isPossible(long long mask) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (long long k = 1; k <= p; k++) {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 0; j < i; j++) {
        if (dp[j][k - 1] && ((sum[i] - sum[j] & mask) == mask)) {
          dp[i][k] = 1;
          break;
        }
      }
    }
  }
  return dp[n][p];
}
long long solve() {
  cin >> n >> p;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  long long ans = 0;
  for (long long i = 50; i >= 0; i--) {
    if (isPossible(ans | (1LL << i))) {
      ans |= (1LL << i);
    }
  }
  return ans;
}
int32_t main() {
  run();
  cout << solve();
  return 0;
}
