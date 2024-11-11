#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
const int Mod = 1000000007, Mod2 = 998244353;
const int MOD = Mod2;
const int maxn = 2005;
int n, k, cnta[maxn][maxn], dp[maxn][maxn], a[maxn], maxx, curx, cury;
char grid[maxn][maxn];
string str, minn;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = (0); i < ((int)(n)); i++)
    for (int j = (0); j < ((int)(n)); j++) cin >> grid[i][j];
  for (int i = (0); i < ((int)(n)); i++)
    for (int j = (0); j < ((int)(n)); j++) {
      cnta[i][j] = 0;
      if (i) cnta[i][j] = max(cnta[i][j], cnta[i - 1][j]);
      if (j) cnta[i][j] = max(cnta[i][j], cnta[i][j - 1]);
      if (grid[i][j] == 'a') cnta[i][j]++;
    }
  for (int i = (0); i < ((int)(n)); i++) dp[i][n] = dp[n][i] = 1010000000;
  for (int i = (2 * n - 2); i >= ((int)(0)); i--) {
    if (i >= n - 1) {
      for (int j = (i - n + 1); j < ((int)(n)); j++) a[j] = j;
      sort(a + i - n + 1, a + n, [i](int x, int y) {
        return grid[x][i - x] == grid[y][i - y]
                   ? min(dp[x + 1][i - x], dp[x][i - x + 1]) <
                         min(dp[y + 1][i - y], dp[y][i - y + 1])
                   : grid[x][i - x] < grid[y][i - y];
      });
      for (int j = (i - n + 1); j < ((int)(n)); j++) dp[a[j]][i - a[j]] = j;
    } else {
      for (int j = (0); j < ((int)(i + 1)); j++) a[j] = j;
      sort(a, a + i + 1, [i](int x, int y) {
        return grid[x][i - x] == grid[y][i - y]
                   ? min(dp[x + 1][i - x], dp[x][i - x + 1]) <
                         min(dp[y + 1][i - y], dp[y][i - y + 1])
                   : grid[x][i - x] < grid[y][i - y];
      });
      for (int j = (0); j < ((int)(i + 1)); j++) dp[a[j]][i - a[j]] = j;
    }
  }
  for (int i = (2 * n - 2); i >= ((int)(0)); i--) {
    maxx = -1010000000;
    for (int j = (0); j < ((int)(n)); j++)
      if (i - j >= 0 && i - j < n) maxx = max(maxx, cnta[j][i - j]);
    if (maxx + k >= i + 1) {
      826;
      for (int j = (0); j < ((int)(i + 1)); j++) cout << 'a';
      for (int j = (0); j < ((int)(2 * n - 2 - i)); j++) minn += 'z';
      for (int j = (0); j < ((int)(n)); j++)
        if (i - j >= 0 && i - j < n && cnta[j][i - j] == maxx) {
          826;
          curx = j, cury = i - j;
          str.clear();
          for (int ii = (0); ii < ((int)(2 * n - 2 - i)); ii++) {
            if (curx == n - 1)
              cury++;
            else if (cury == n - 1)
              curx++;
            else if (dp[curx + 1][cury] < dp[curx][cury + 1])
              curx++;
            else
              cury++;
            str += grid[curx][cury];
          }
          minn = min(minn, str);
        }
      print(minn);
      return 0;
    }
  }
  curx = 0, cury = 0;
  cout << grid[0][0];
  for (int i = (0); i < ((int)(2 * n - 2)); i++) {
    if (curx == n - 1)
      cury++;
    else if (cury == n - 1)
      curx++;
    else if (dp[curx + 1][cury] < dp[curx][cury + 1])
      curx++;
    else
      cury++;
    cout << grid[curx][cury];
  }
  cout << "\n";
  return 0;
}
