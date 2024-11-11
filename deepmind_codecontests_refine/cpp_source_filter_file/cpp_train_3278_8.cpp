#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int dp[n][8];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 8; ++j) {
      dp[i][j] = 0;
    }
  }
  int a = s[0] - '0';
  dp[0][a % 8] = 1;
  for (int i = 1; i < n; ++i) {
    a = s[i] - '0';
    dp[i][a % 8] = 1;
    for (int j = 0; j < 8; ++j) {
      if (dp[i - 1][j] != 0) {
        dp[i][j] = 1;
        dp[i][(10 * j + a) % 8] = 1;
      }
    }
  }
  string ans;
  bool ok = 0;
  int p;
  for (int i = 0; i < n; ++i) {
    if (dp[i][0] == 1) {
      ok = 1;
      p = i;
      ans += s[i];
      break;
    }
  }
  if (ok) {
    int cmod = 0;
    for (int i = p - 1; i >= 0; --i) {
      int a = s[i + 1] - '0';
      for (int j = 0; j < 8; ++j) {
        if (dp[i][j] && (j * 10 + a) % 8 == cmod) {
          while (i >= 0 && dp[i - 1][j] == dp[i][j]) i--;
          cmod = j;
          ans += s[i];
          break;
        }
      }
    }
    reverse((ans).begin(), (ans).end());
    cout << "YES\n" << ans;
    return 0;
  }
  cout << "NO";
}
