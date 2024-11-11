#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[9][1 << 9][1 << 9];
char grid[9][1 << 9][1 << 9][9][9];
inline int isSet(int mask, int i) {
  if (i < 0 || i >= n) return 1;
  return (mask >> i) & 1;
}
void compute(int row, int i, int mask1, int mask2, int mask3, int val,
             char gd[9][9]) {
  if (i == n) {
    if (dp[row][mask2][mask3] < val) {
      dp[row][mask2][mask3] = val;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          grid[row][mask2][mask3][i][j] = gd[i][j];
        }
      }
    }
    return;
  }
  compute(row, i + 1, mask1, mask2, mask3, val, gd);
  if (!isSet(mask1, i + 2) && !isSet(mask2, i) && !isSet(mask2, i + 1) &&
      !isSet(mask2, i + 2) && !isSet(mask3, i + 2)) {
    char ngd[9][9];
    memcpy(ngd, gd, sizeof(char) * 81);
    ngd[i + 2][row - 2] = char('A' + val);
    ngd[i][row - 1] = char('A' + val);
    ngd[i + 1][row - 1] = char('A' + val);
    ngd[i + 2][row - 1] = char('A' + val);
    ngd[i + 2][row] = char('A' + val);
    compute(row, i + 1, mask1 ^ (4 << i), mask2 ^ (7 << i), mask3 ^ (4 << i),
            val + 1, ngd);
  }
  if (!isSet(mask1, i + 1) && !isSet(mask2, i + 1) && !isSet(mask3, i) &&
      !isSet(mask3, i + 1) && !isSet(mask3, i + 2)) {
    char ngd[9][9];
    memcpy(ngd, gd, sizeof(char) * 81);
    ngd[i + 1][row - 2] = char('A' + val);
    ngd[i + 1][row - 1] = char('A' + val);
    ngd[i][row] = char('A' + val);
    ngd[i + 1][row] = char('A' + val);
    ngd[i + 2][row] = char('A' + val);
    compute(row, i + 1, mask1 ^ (2 << i), mask2 ^ (2 << i), mask3 ^ (7 << i),
            val + 1, ngd);
  }
  if (!isSet(mask1, i) && !isSet(mask2, i) && !isSet(mask2, i + 1) &&
      !isSet(mask2, i + 2) && !isSet(mask3, i)) {
    char ngd[9][9];
    memcpy(ngd, gd, sizeof(char) * 81);
    ngd[i][row - 2] = char('A' + val);
    ngd[i][row - 1] = char('A' + val);
    ngd[i + 1][row - 1] = char('A' + val);
    ngd[i + 2][row - 1] = char('A' + val);
    ngd[i][row] = char('A' + val);
    compute(row, i + 1, mask1 ^ (1 << i), mask2 ^ (7 << i), mask3 ^ (1 << i),
            val + 1, ngd);
  }
  if (!isSet(mask1, i) && !isSet(mask1, i + 1) && !isSet(mask1, i + 2) &&
      !isSet(mask2, i + 1) && !isSet(mask3, i + 1)) {
    char ngd[9][9];
    memcpy(ngd, gd, sizeof(char) * 81);
    ngd[i][row - 2] = char('A' + val);
    ngd[i + 1][row - 2] = char('A' + val);
    ngd[i + 2][row - 2] = char('A' + val);
    ngd[i + 1][row - 1] = char('A' + val);
    ngd[i + 1][row] = char('A' + val);
    compute(row, i + 1, mask1 ^ (7 << i), mask2 ^ (2 << i), mask3 ^ (2 << i),
            val + 1, ngd);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  cin >> n >> m;
  if (n < 3 || m < 3) {
    cout << 0 << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << '.';
      }
      cout << '\n';
    }
    exit(0);
  }
  memset(dp, 0xf7, sizeof(dp));
  for (int i = 0; i < m; i++) {
    for (int m1 = 0; m1 < (1 << n); m1++) {
      for (int m2 = 0; m2 < (1 << n); m2++) {
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < m; k++) {
            grid[i][m1][m2][j][k] = '.';
          }
        }
      }
    }
  }
  dp[1][0][0] = 0;
  for (int i = 2; i < m; i++) {
    for (int mask1 = 0; mask1 < (1 << n); mask1++) {
      for (int mask2 = 0; mask2 < (1 << n); mask2++) {
        if (dp[i - 1][mask1][mask2] < 0) continue;
        compute(i, 0, mask1, mask2, 0, dp[i - 1][mask1][mask2],
                grid[i - 1][mask1][mask2]);
      }
    }
  }
  int mask2 = 0, mask3 = 0;
  for (int m1 = 0; m1 < (1 << n); m1++) {
    for (int m2 = 0; m2 < (1 << n); m2++) {
      if (dp[m - 1][mask2][mask3] < dp[m - 1][m1][m2]) {
        mask2 = m1;
        mask3 = m2;
      }
    }
  }
  cout << dp[m - 1][mask2][mask3] << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[m - 1][mask2][mask3][i][j];
    }
    cout << '\n';
  }
  return 0;
}
