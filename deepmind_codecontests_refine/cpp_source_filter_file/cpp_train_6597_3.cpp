#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, q;
  cin >> n >> q;
  vector<long long> v(n, 0), c(n, 0);
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < q; ++i) {
    long long a, b, c1st = 0, c2nd = 0;
    cin >> a >> b;
    vector<long long> dp(n, -INF);
    for (long long j = 0; j < n; ++j) {
      long long old = dp[c[j]];
      if (c1st == old)
        dp[c[j]] = max(dp[c[j]], c2nd + b * v[j]);
      else
        dp[c[j]] = max(dp[c[j]], c1st + b * v[j]);
      if (-INF != old) dp[c[j]] = max(dp[c[j]], old + a * v[j]);
      if (dp[c[j]] >= c1st && c1st == old) {
        c1st = dp[c[j]];
      } else if (dp[c[j]] >= c1st && c1st != old) {
        c2nd = c1st;
        c1st = dp[c[j]];
      } else if (dp[c[j]] > c2nd && dp[c[j]] < c1st) {
        c2nd = dp[c[j]];
      }
    }
    cout << c1st << endl;
  }
  return 0;
}
