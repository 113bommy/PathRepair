#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2 * 1e5 + 5;
long long dp[N];
int main() {
  long long ans, r, g, tmp, h;
  double temp;
  memset(dp, 0, sizeof(dp));
  dp[0] = dp[1] = 1;
  ans = 0;
  cin >> r >> g;
  tmp = r + g;
  for (h = 1; h * (h + 1) / 2 <= tmp; h++)
    ;
  h--;
  tmp = r < g ? r : g;
  for (int i = 2; i <= h; i++) {
    for (int j = tmp; j > 0; j--) {
      if (j - i >= 0) dp[j] = (dp[j] + dp[j - i]) % mod;
    }
  }
  for (int i = 0; i <= tmp; i++) {
    if (h * (h + 1) / 2 - i <= r + g - tmp) ans = (ans + dp[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
