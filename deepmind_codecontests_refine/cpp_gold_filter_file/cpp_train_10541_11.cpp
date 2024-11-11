#include <bits/stdc++.h>
int mod = 1000000007;
using namespace std;
using namespace std;
int k, n;
string s;
int dp[505][505];
int fdp[505][505];
int idp[505][505];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> s;
  n = s.size();
  cin >> k;
  memset(dp, 0, sizeof(dp));
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      if (i == 2) {
        dp[j][j + i - 1] = (s[j] != s[j + i - 1]);
      }
      dp[j][j + i - 1] = dp[j + 1][j + i - 2] + (s[j] != s[j + i - 1]);
    }
  }
  memset(fdp, 0, sizeof(fdp));
  for (int i = 2; i <= k; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      fdp[j][i] = 1000;
      for (int k = j; k < n - i + 1; k++) {
        if (i == 2) {
          if (fdp[j][i] > dp[j][k] + dp[k + 1][n - 1]) {
            fdp[j][i] = dp[j][k] + dp[k + 1][n - 1];
            idp[j][i] = k;
          }
        } else {
          if (fdp[j][i] > dp[j][k] + fdp[k + 1][i - 1]) {
            fdp[j][i] = dp[j][k] + fdp[k + 1][i - 1];
            idp[j][i] = k;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    idp[i][1] = n - 1;
  }
  int ans = INT_MAX;
  fdp[0][1] = dp[0][n - 1];
  int j;
  for (int i = 1; i <= k; i++) {
    if (ans > fdp[0][i]) {
      ans = fdp[0][i];
      j = i;
    }
  }
  cout << ans << '\n';
  int i = 0;
  while (j > 0) {
    int k = idp[i][j];
    int len = k - i + 1;
    if (len == 1)
      cout << s[i];
    else {
      for (int p = i; p < i + len / 2; p++) {
        cout << s[p];
      }
      if (len % 2) cout << s[i + len / 2];
      for (int p = i + len / 2 - 1; p >= i; p--) {
        cout << s[p];
      }
    }
    j--;
    if (j > 0) cout << '+';
    i = k + 1;
  }
}
