#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int dp[30][30] = {};
  int i, j, n, lo, l, r, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s;
    lo = s.size();
    l = s[0] - 97;
    r = s[lo - 1] - 97;
    for (j = 0; j < 26; j++) {
      if (dp[j][l]) dp[j][r] = max(dp[j][r], dp[j][l] + lo);
    }
    dp[l][r] = max(dp[l][r], lo);
  }
  for (i = 0; i < 26; i++) ans = max(ans, dp[i][i]);
  cout << ans;
  return 0;
}
