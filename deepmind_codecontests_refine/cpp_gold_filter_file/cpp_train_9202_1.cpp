#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int n, dp[40010][11], ans, sx, sy, on[40010];
char c[5][40010];
bool a[40010][5], b[40010][5];
long long get_res() {
  memset(dp, 0, sizeof(dp));
  memset(on, 0, sizeof(on));
  long long res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 3; j++)
      if (b[i][j]) on[i] |= 1 << j - 1;
  dp[1][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= 7; k++) {
      if (k & on[i]) continue;
      int kk = k | on[i];
      if (kk == 0) {
        (dp[i + 1][7] += dp[i][k]) %= Mod;
        (dp[i + 1][1] += dp[i][k]) %= Mod;
        (dp[i + 1][4] += dp[i][k]) %= Mod;
        continue;
      }
      if ((kk == 7 || kk == 1 || kk == 4) && i == n) (res += dp[i][k]) %= Mod;
      if (7 - kk == 3) (dp[i + 1][0] += dp[i][k]) %= Mod;
      if (7 - kk == 6) (dp[i + 1][0] += dp[i][k]) %= Mod;
      (dp[i + 1][7 - kk] += dp[i][k]) %= Mod;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 3; i++) scanf("%s", c[i] + 1);
  for (int j = 1; j <= 3; j++) {
    for (int i = 1; i <= n; i++) {
      if (c[j][i] == '.') a[i][j] = 0;
      if (c[j][i] == 'O') sx = i, sy = j, a[i][j] = 1;
      if (c[j][i] == 'X') a[i][j] = 1;
    }
  }
  for (int i = 1; i <= 15; i++) {
    int x = i, xx = 1, sum = 0;
    memcpy(b, a, sizeof(a));
    bool flag = 0;
    while (x) {
      if (x & 1) {
        sum++;
        if (xx == 1) {
          if (sx <= 2) {
            flag = 1;
            break;
          }
          if (b[sx - 1][sy] || b[sx - 2][sy]) {
            flag = 1;
            break;
          }
          b[sx - 1][sy] = b[sx - 2][sy] = 1;
        }
        if (xx == 2) {
          if (sx >= n - 1) {
            flag = 1;
            break;
          }
          if (b[sx + 1][sy] || b[sx + 2][sy]) {
            flag = 1;
            break;
          }
          b[sx + 1][sy] = b[sx + 2][sy] = 1;
        }
        if (xx == 4) {
          if (sy <= 2) {
            flag = 1;
            break;
          }
          if (b[sx][sy - 1] || b[sx][sy - 2]) {
            flag = 1;
            break;
          }
          b[sx][sy - 1] = b[sx][sy - 2] = 1;
        }
        if (xx == 8) {
          if (sy >= 2) {
            flag = 1;
            break;
          }
          if (b[sx][sy + 1] || b[sx][sy + 2]) {
            flag = 1;
            break;
          }
          b[sx][sy + 1] = b[sx][sy + 2] = 1;
        }
      }
      x /= 2;
      xx *= 2;
    }
    if (!flag) {
      long long res = get_res();
      if (sum % 2)
        (ans += res) %= Mod;
      else
        ans = (ans - res + Mod) % Mod;
    }
  }
  cout << ans;
}
