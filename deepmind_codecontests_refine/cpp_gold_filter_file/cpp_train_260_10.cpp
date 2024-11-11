#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e5 + 10, MAXlg = 22, MAXx = (1 << 20) + 10, lg = 20,
          x = (1 << 21);
int dp[MAXx][MAXlg], n, m, cnt, ar2[MAXlg];
char ar[MAXlg][MAXn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> ar[i][j];
    }
  for (int i = 0; i < m; i++) {
    int hp = 0, hp2 = 0;
    for (int j = 0; j < n; j++) {
      hp *= 2;
      if (ar[j][i] - '0' != 0) {
        hp++;
        cnt++;
      }
    }
    dp[hp][0]++;
  }
  for (int i = 0; i < n; i++)
    for (int j = n; j >= 1; j--)
      for (int y = 0; y < (1 << n); y++) dp[y][j] += dp[y ^ (1 << i)][j - 1];
  for (int j = 0; j < (1 << n); j++) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += min(i, n - i) * dp[j][i];
    }
    cnt = min(cnt, ans);
  }
  cout << cnt;
}
