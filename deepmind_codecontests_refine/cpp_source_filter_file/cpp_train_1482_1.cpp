#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int a[60][30050], s[60][30050];
int lmax[30050], rmax[30050];
int dp[30050], newdp[30050];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      s[i][j] = a[i][j] + s[i][j - 1];
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) lmax[j] = max(lmax[j - 1], dp[j]);
    for (int j = m; j >= 1; j--) rmax[j] = max(rmax[j + 1], dp[j]);
    for (int j = 1; j <= m - k + 1; j++) {
      int val =
          s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
      newdp[j] = max(lmax[max(j - k, 0)], rmax[min(j + k, m + 1)]) + val;
      for (int h = max(j - k + 1, 1); h <= min(j + k - 1, m); h++) {
        int r = min(j + k - 1, h + k - 1), l = max(j, h);
        newdp[j] = max(newdp[j], val + dp[h] - s[i][r] - s[i][l - 1]);
      }
    }
    for (int i = 1; i <= m; i++) dp[i] = newdp[i];
  }
  for (int i : dp) ans = max(ans, i);
  cout << ans;
}
