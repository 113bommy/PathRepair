#include <bits/stdc++.h>
using namespace std;
long long n, num[66][66], dp[66];
string s;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> s;
  long long big = (1ll << 62);
  for (int i = (0); i <= ((int)(s.size()) - 1); i++) {
    num[i][i] = s[i] - '0';
    for (int j = (i + 1); j <= ((int)s.size() - 1); j++) {
      if (num[i][j - 1] > n)
        num[i][j] = n + 1;
      else
        num[i][j] = 10 * num[i][j - 1] + s[j] - '0';
    }
  }
  dp[0] = 0;
  for (int i = (1); i <= (s.size()); i++) {
    dp[i] = big;
    for (int j = (0); j <= (i - 1); j++)
      if (num[j][i - 1] < n) {
        if (j != i - 1 && s[j] == '0') continue;
        if (big / n + 1 < dp[j]) continue;
        dp[i] = min(dp[i], dp[j] * n + num[j][i - 1]);
      }
  }
  cout << dp[s.size()];
}
