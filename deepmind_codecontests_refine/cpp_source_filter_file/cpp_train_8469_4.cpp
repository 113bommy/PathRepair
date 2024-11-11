#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int q, i, j, l, r, k;
  cin >> s >> q;
  int dp[s.length() + 1][s.length() + 1];
  bool isPal[s.length() + 1][s.length() + 1];
  memset(dp, 0, sizeof(dp));
  memset(isPal, true, sizeof(isPal));
  for (k = 1; k <= s.length(); k++) {
    i = 1;
    j = k;
    while (j <= s.length()) {
      if (s[i - 1] == s[j - 1] && isPal[i + 1][j - 1]) {
        isPal[i][j] = true;
      } else
        isPal[i][j] = false;
      if (isPal[i][j]) {
        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + 1;
      } else
        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
      i++;
      j++;
    }
  }
  while (q--) {
    cin >> l >> r;
    cout << dp[l][r] << "\n";
  }
}
