#include <bits/stdc++.h>
using namespace std;
long long dp[2010][2010];
string s[2010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 1; i < m - 1; i++)
    if (s[0][i] == '.') dp[0][i] = 1 << 0;
  for (int i = 1; i < m - 1; i++)
    if (s[n - 1][i] == '.') dp[n - 1][i] = 1 << 1;
  for (int i = 1; i < n - 1; i++)
    if (s[i][0] == '.') dp[i][0] = 1 << 2;
  for (int i = 1; i < n - 1; i++)
    if (s[i][m - 1] == '.') dp[i][m - 1] = 1 << 3;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (s[i][j] == '.') {
        dp[i][j] += dp[i - 1][j] & (1 << 0);
        dp[i][j] += dp[i][j - 1] & (1 << 2);
      }
      if (s[n - i - 1][m - j - 1] == '.') {
        dp[n - i - 1][m - j - 1] += dp[n - i][m - j - 1] & (1 << 1);
        dp[n - i - 1][m - j - 1] += dp[n - i - 1][m - j] & (1 << 3);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i < m - 1; i++)
    if (dp[0][i] & (1 << 0) && dp[1][i] & (1 << 1)) ans++;
  for (int i = 1; i < n - 1; i++)
    if (dp[i][0] & (1 << 2) && dp[i][1] & (1 << 3)) ans++;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (dp[i][j] & (1 << 0)) {
        if (dp[i][j] & (1 << 2)) ans++;
        if (dp[i][j] & (1 << 3)) ans++;
      }
      if (dp[i][j] & (1 << 1)) {
        if (dp[i][j] & (1 << 2)) ans++;
        if (dp[i][j] & (1 << 3)) ans++;
      }
    }
  }
  for (int i = 1; i < n - 1; i++) {
    int l = 1, r = 1;
    while (l < m - 1) {
      r = l;
      long long c1, c2, c3, c4;
      c1 = c2 = c3 = c4 = 0;
      while (r < m - 1 && s[i][r] == '.') {
        if (dp[i][r] & (1 << 0)) {
          c1++;
          if (r - 1 >= l && dp[i][r - 1] & (1 << 0)) c4++;
        }
        if (dp[i][r] & (1 << 1)) {
          c2++;
          if (r - 1 >= l && dp[i][r - 1] & (1 << 1)) c4++;
        }
        if (dp[i][r] & (1 << 0) && dp[i][r] & (1 << 1)) c3++;
        r++;
      }
      ans += c1 * c2 - c3 - c4 + c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2;
      l = r;
      while (l < m - 1 && s[i][l] != '.') l++;
    }
  }
  for (int i = 1; i < m - 1; i++) {
    int l = 1, r = 1;
    while (l < n - 1) {
      r = l;
      long long c1, c2, c3, c4;
      c1 = c2 = c3 = c4 = 0;
      while (r < n - 1 && s[r][i] == '.') {
        if (dp[r][i] & (1 << 2)) {
          c1++;
          if (r - 1 >= l && dp[r - 1][i] & (1 << 2)) c4++;
        }
        if (dp[r][i] & (1 << 3)) {
          c2++;
          if (r - 1 >= l && dp[r - 1][i] & (1 << 3)) c4++;
        }
        if (dp[r][i] & (1 << 2) && dp[i][r] & (1 << 3)) c3++;
        r++;
      }
      ans += c1 * c2 - c3 + c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2;
      l = r;
      while (l < n - 1 && s[l][i] != '.') l++;
    }
  }
  cout << ans << endl;
  return 0;
}
