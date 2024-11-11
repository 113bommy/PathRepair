#include <bits/stdc++.h>
using namespace std;
bool check(int mask, int pos) { return (bool)(mask & (1 << pos)); }
char str[251][251], str2[251][251];
int dp[2][1 << 16][17][2][2];
int ara[261][17];
int off(int mask, int pos) {
  if (check(mask, pos) == 0) return mask;
  return mask ^ (1 << pos);
}
int dp_func(int n, int m) {
  int ly = 0;
  for (int row = n - 1; row >= 0; row--) {
    ly ^= 1;
    for (int col = m; col >= 0; col--) {
      for (int mask = 0; mask < (1 << m); mask++) {
        for (int xfact = 0; xfact <= 1; xfact++) {
          for (int bol = 0; bol <= 1; bol++) {
            dp[ly][mask][col][bol][xfact] = 0;
            if (row == n - 1 && col == m) {
              dp[ly][mask][col][bol][xfact] = bol <= 1;
              continue;
            }
            if (col == m) {
              dp[ly][mask][col][bol][xfact] = dp[ly ^ 1][mask][0][bol][0];
              continue;
            }
            if (str[row][col] == 'x') {
              dp[ly][mask][col][bol][xfact] =
                  dp[ly][off(mask, col)][col + 1][bol][0];
              continue;
            }
            int ret = 0;
            ret += dp[ly][mask | (1 << col)][col + 1][bol][1];
            if (bol == 0 || xfact || check(mask, col))
              ret += dp[ly][mask][col + 1]
                       [(xfact == 0 && (check(mask, col) == 0)) || bol][xfact];
            dp[ly][mask][col][bol][xfact] = ret %= 1000000007;
          }
        }
      }
    }
  }
  return dp[ly][0][0][0][0];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
  }
  if (n < m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        str2[j][i] = str[i][j];
      }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) str[i][j] = str2[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'x') continue;
      int mask = 0;
      for (int k = j; k < m && str[i][k] != 'x'; k++) {
        mask |= (1 << k);
      }
      ara[i][j] = mask;
    }
  }
  int ans = dp_func(n, m);
  cout << ans << endl;
}
