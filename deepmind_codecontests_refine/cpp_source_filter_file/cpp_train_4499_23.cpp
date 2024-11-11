#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 200, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long a[MAX], dp[MAX], dp1[MAX], dp0[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 2, q;
  cin >> q;
  a[1] = a[2] = 1;
  for (;; t++) {
    a[t] = a[t - 1] + a[t - 2];
    if (a[t] >= 1e18) break;
  }
  dp[1] = dp[2] = dp[3] = 1;
  for (int i = 4; i <= t; i++) dp[i] = 1 + dp[i - 2];
  while (q--) {
    long long x, ans = 0, la = 0;
    cin >> x;
    for (int i = t; i > 0; i--) {
      dp1[i] = 0;
      if (a[i] <= x) dp1[i] = 1, x -= a[i];
    }
    for (int i = 2; i <= t; i++) {
      if (dp1[i] && la == 0) {
        dp1[i] = 1, dp0[i] = dp[i - 2];
        la = i;
        continue;
      }
      if (dp1[i]) {
        dp1[i] = dp1[la] + dp0[la];
        if ((i - la) % 2 == 1)
          dp0[i] = ((i - la) / 2) * (dp0[la] + dp1[la]);
        else
          dp0[i] = (((i - 1 - la) / 2) * (dp0[la] + dp1[la])) + dp0[la];
        la = i;
      }
    }
    cout << dp0[la] + dp1[la] << "\n";
  }
  return 0;
}
