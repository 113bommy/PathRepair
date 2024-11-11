#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int dp[2][5 * 123][5 * 123];
char a[5 * 123][5 * 123];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
}
void add(int &a, int b) {
  a += b;
  if (a >= 1e9 + 7) a -= 1e9 + 7;
}
bool check(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return true;
  return (x1 == x2 && y1 + 1 == y2) || (x1 + 1 == x2 && y1 == y2);
}
void solve() {
  int len = (n + m) / 2 + 1;
  for (int s = 2, v = 0; s <= len; s++, v ^= 1) {
    memset(dp[v], 0, sizeof(dp[v]));
    for (int i = 1; i < s && i <= n; i++)
      for (int j = 1; j < s && j <= n; j++) {
        int x1 = i, y1 = s - i;
        int x2 = n - j + 1, y2 = m - s + j + 1;
        if (x1 > x2 || y1 > y2 || a[x1][y1] != a[x2][y2])
          dp[v][i][j] = 0;
        else if (s == 2) {
          dp[v][i][j] = 1;
        } else {
          if (x1 > 1) {
            if (x2 < n) add(dp[v][i][j], dp[v ^ 1][i - 1][j - 1]);
            if (y2 < m) add(dp[v][i][j], dp[v ^ 1][i - 1][j]);
          }
          if (y1 > 1) {
            if (x2 < n) add(dp[v][i][j], dp[v ^ 1][i][j - 1]);
            if (y2 < m) add(dp[v][i][j], dp[v ^ 1][i][j - 1]);
          }
        }
        if (check(x1, y1, x2, y2)) add(ans, dp[v][i][j]);
      }
  }
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
}
