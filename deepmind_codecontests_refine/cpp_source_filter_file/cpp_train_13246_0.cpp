#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v(n + 5), dp(n + 5);
    for (long long i = 1; i <= n; i++) {
      cin >> v[i];
    }
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
      dp[i] = 1;
      if (i == 1) {
        dp[i] = 1;
      } else {
        for (long long j = 1; j * j <= i; j++) {
          if (i % j == 0) {
            if (v[i] > v[j]) {
              dp[i] = max(dp[i], dp[j] + 1);
            }
            if (v[i] > v[i / j]) {
              dp[i] = max(dp[i], dp[j] + 1);
            }
          }
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
  }
}
