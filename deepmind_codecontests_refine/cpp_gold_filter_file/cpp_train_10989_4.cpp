#include <bits/stdc++.h>
using namespace std;
long long dp[100005];
int tol;
void init() {
  dp[0] = 1;
  dp[1] = 2;
  for (tol = 2;; ++tol) {
    dp[tol] = dp[tol - 1] + dp[tol - 2];
    if (dp[tol] > 1e18) break;
  }
}
void solve() {
  long long n;
  while (cin >> n) {
    int ans = upper_bound(dp, dp + tol, n) - dp - 1;
    cout << ans << endl;
  }
}
int main() {
  init();
  solve();
  return 0;
}
