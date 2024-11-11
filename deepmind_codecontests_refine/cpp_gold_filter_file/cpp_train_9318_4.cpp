#include <bits/stdc++.h>
using namespace std;
const int N = 5003, md = 1000 * 1000 * 1000 + 7;
int suf[N][N], dp[N][N];
int n;
string s;
int fix(const int a) {
  if (a < 0)
    return a + md;
  else
    return a % md;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  s = "0" + s;
  for (int i = n; i; i--)
    for (int j = i - 1; j; j--)
      if (s[j] < s[i])
        suf[j][i] = 0;
      else if (s[j] == s[i]) {
        if (suf[j + 1][i + 1] == -1)
          suf[j][i] = -1;
        else
          suf[j][i] = suf[j + 1][i + 1] + 1;
      } else
        suf[j][i] = -1;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    for (int j = 2; j <= i; j++)
      if (s[j] == '0')
        dp[i][j] = dp[i][j - 1];
      else {
        if (2 * j < i)
          dp[i][j] = fix(dp[i][j - 1] + dp[j - 1][j - 1]);
        else {
          int k = 2 * j - i - 1;
          if (suf[k][j] != -1 && suf[k][j] < j - k) {
            dp[i][j] =
                fix(dp[i][j - 1] + fix(dp[j - 1][j - 1] - dp[j - 1][k - 1]));
          } else
            dp[i][j] = fix(dp[i][j - 1] + fix(dp[j - 1][j - 1] - dp[j - 1][k]));
        }
      }
  }
  cout << dp[n][n] << "\n";
  return 0;
}
