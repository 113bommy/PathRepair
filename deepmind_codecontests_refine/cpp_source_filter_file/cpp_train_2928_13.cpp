#include <bits/stdc++.h>
using namespace std;
const long long MaxN = 200 + 10;
long long dp[MaxN][MaxN];
long long n, a[MaxN];
long long k, x;
int main() {
  cin >> n >> k >> x;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  if (x < n / k) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= x; j++) dp[i][j] = -(1ll << 60);
  for (int i = 1; i <= k; i++) dp[i][1] = a[i];
  for (long long i = 2; i <= n; i++) {
    for (long long j = 2; j <= x; j++) {
      long long ans = 0;
      for (long long pf = max(i - k, 1ll); pf <= i - 1; pf++) {
        dp[i][j] = max(dp[i][j], dp[pf][j - 1] + a[i]);
      }
    }
  }
  long long ans = -(1ll << 60);
  for (long long i = 1; i <= n; i++) ans = max(ans, dp[i][x]);
  if (ans >= 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
