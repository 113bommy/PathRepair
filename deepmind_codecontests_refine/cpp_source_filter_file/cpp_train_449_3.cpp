#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n;
long long dp[2 * N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  long long ans = dp[1];
  for (int i = 1; i <= n; ++i) {
    int t, c;
    cin >> t >> c;
    t += 1;
    for (int j = 4000; j >= t; --j) dp[j] = min(dp[j], dp[j - t] + c);
  }
  for (int i = (n), _b = (4000); i <= _b; ++i) ans = min(ans, dp[i]);
  cout << dp[n] << endl;
  return 0;
}
