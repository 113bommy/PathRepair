#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5, M = 998244353;
int n, x[mxN], y[mxN], s[mxN];
long long dp[mxN], p[mxN + 1];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> s[i];
  long long ans = x[n - 1] + 1;
  for (int i = 0; i < n; ++i) {
    int prv = lower_bound(x, x + n, y[i]) - x;
    dp[i] = (x[i] - y[i] + p[i] - p[prv] + M) % M;
    p[i + 1] = (p[i] + dp[i]) % M;
    if (s[i]) ans = (ans + dp[i]) % M;
  }
  cout << ans;
  return 0;
}
