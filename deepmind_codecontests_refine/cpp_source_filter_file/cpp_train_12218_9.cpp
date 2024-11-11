#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int room[n][m];
  int pref[n + 1][m + 1];
  for (int i = 0; i < n + 1; i++) {
    pref[i][0] = 0;
  }
  for (int i = 0; i < m + 1; i++) {
    pref[0][i] = 0;
  }
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      room[i][j] = s[j] - '0';
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      pref[i][j] = room[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] -
                   pref[i - 1][j - 1];
    }
  }
  int ans = 0;
  int dp[n + 1][m + 1][n + 1][m + 1];
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      for (int k = i; k < n + 1; k++) {
        for (int l = j; l < m + 1; l++) {
          if (pref[k][l] + pref[i - 1][j - 1] - pref[i - 1][l] -
                  pref[k][j - 1] ==
              0) {
            dp[i][j][k][l] = (k - i + 1) * (l - j + 1);
            ans = max(ans, dp[i][j][k][l]);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
