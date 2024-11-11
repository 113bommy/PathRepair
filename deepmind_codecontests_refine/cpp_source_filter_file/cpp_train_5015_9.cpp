#include <bits/stdc++.h>
using namespace std;
long long n, m, k, t, x, y, i, j;
string s, T = "RGB";
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    long long dp[3][n + 1];
    memset(dp, 0, 3 * (n + 1) * sizeof(dp[0][0]));
    long long ans = 1e2;
    for (i = 0; i < n; i++) {
      for (j = 0; j < 3; j++) {
        if (s[i] != T[(i + j) % 3]) dp[j][i]++;
        dp[j][i] += dp[j][i - 1];
        if (i > k - 2) ans = min(ans, (dp[j][i] - dp[j][i - k]));
      }
    }
    cout << ans << endl;
  }
}
