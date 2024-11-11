#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 21, SQ = 350;
int n, m, q;
char c[MAXN][10];
int nx[MAXN][10], ny[MAXN][10];
char tc;
int x, y;
void dfs(int fr, int to) {
  for (int i = fr; i <= to; i++)
    for (int j = 1; j <= m; j++) nx[i][j] = ny[i][j] = -1;
  for (int j = 1; j <= m; j++)
    if (c[fr][j] == '^') {
      nx[fr][j] = fr - 1;
      ny[fr][j] = j;
    }
  for (int i = fr; i <= to; i++) {
    nx[i][0] = i;
    ny[i][0] = 0;
    nx[i][m + 1] = i;
    ny[i][m + 1] = m + 1;
  }
  for (int i = fr; i <= to; i++) {
    for (int j = 1; j <= m; j++) {
      if (i != fr && c[i][j] == '^') {
        nx[i][j] = nx[i - 1][j];
        ny[i][j] = ny[i - 1][j];
      } else if (c[i][j] == '<') {
        nx[i][j] = nx[i][j - 1];
        ny[i][j] = ny[i][j - 1];
      }
    }
    for (int j = m; j >= 1; j--)
      if (c[i][j] == '>') {
        nx[i][j] = nx[i][j + 1];
        ny[i][j] = ny[i][j + 1];
      }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  for (int i = 1; i <= n; i += SQ) dfs(i, min(n, i + SQ - 1));
  while (q--) {
    cin >> tc >> x >> y;
    if (tc == 'A') {
      int tmpx = x, tmpy = y;
      while (x > 0 && y > 0 && y <= m) {
        x = nx[tmpx][tmpy];
        y = ny[tmpx][tmpy];
        tmpx = x;
        tmpy = y;
      }
      cout << x << ' ' << y << '\n';
    } else {
      cin >> tc;
      c[x][y] = tc;
      int gp = (x - 1) / SQ;
      dfs(gp * SQ + 1, min(n, gp * SQ + SQ));
    }
  }
  return 0;
}
