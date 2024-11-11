#include <bits/stdc++.h>
int p = 1e9 + 7;
using namespace std;
int main() {
  int n, l;
  cin >> n >> l;
  int dp[n][l + 1], a[n][2], dp2[n][l + 1];
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= l; j++) dp[i][j] = dp2[i][j] = 0;
  for (int j = 1; j <= l; j++)
    for (int i = 0; i < n; i++) {
      if (a[i][0] == j)
        dp[i][j] += 1;
      else if (a[i][0] < j) {
        int s = -a[i][0] + j;
        for (int k = 0; k < n; k++) {
          if (i == k) continue;
          if (a[k][1] == a[i][0]) {
            dp[i][j] += dp[k][s];
            dp[i][j] %= p;
          } else if (a[k][0] == a[i][0]) {
            dp[i][j] += dp2[k][s];
            dp[i][j] %= p;
          }
        }
      }
      if (a[i][1] == a[i][0]) continue;
      if (a[i][1] == j)
        dp2[i][j] += 1;
      else if (a[i][1] < j) {
        int s = -a[i][1] + j;
        for (int k = 0; k < n; k++) {
          if (i == k) continue;
          if (a[k][1] == a[i][1]) {
            dp2[i][j] += dp[k][s];
            dp2[i][j] %= p;
          } else if (a[k][1] == a[i][0]) {
            dp2[i][j] += dp2[k][s];
            dp2[i][j] %= p;
          }
        }
      }
    }
  int s = 0;
  for (int i = 0; i < n; i++) {
    s = (s + (dp[i][l] + dp2[i][l]) % p) % p;
  }
  cout << s;
}
