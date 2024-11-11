#include <bits/stdc++.h>
using namespace std;
const double EPS = -1e8;
const double Pi = acos(-1);
bool inline equ(double a, double b) { return fabs(a - b) < EPS; }
int n, m, q;
int in[4][1010][1010];
int dp[4][1010][1010];
inline void input() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (m); j++) {
      int x;
      scanf("%d", &x);
      in[0][i][j] = x;
      in[1][m - j + 1][i] = x;
      in[2][n - i + 1][m - j + 1] = x;
      in[3][j][n - i + 1] = x;
    }
}
inline void makedp(int DP[1010][1010], int IN[1010][1010], int N, int M) {
  for (int i = (1); i <= (N); i++)
    for (int j = (1); j <= (M); j++)
      if (IN[i][j] == 0)
        DP[i][j] = 0;
      else
        DP[i][j] = DP[i][j - 1] + 1;
}
inline void upd(int DP[1010][1010], int IN[1010][1010], int N, int M, int x,
                int y) {
  IN[x][y] ^= 1;
  for (int j = (1); j <= (M); j++)
    if (IN[x][j] == 0)
      DP[x][j] = 0;
    else
      DP[x][j] = DP[x][j - 1] + 1;
}
inline int qry(int DP[1010][1010], int IN[1010][1010], int N, int M, int x,
               int y) {
  if (IN[x][y] == 0) return 0;
  int j = x, res = DP[x][y], wide = 100010;
  for (int i = (x); i <= (N); i++) {
    wide = min(wide, DP[i][y]);
    while (j > 0 && DP[j][y] >= wide) j--;
    res = max(res, wide * (i - j));
  }
  j = x, wide = 100010;
  for (int i = (x); i >= (1); i--) {
    wide = min(wide, DP[i][y]);
    while (j <= M && DP[j][y] >= wide) j++;
    res = max(res, wide * (j - i));
  }
  return res;
}
inline void solve() {
  makedp(dp[0], in[0], n, m);
  makedp(dp[1], in[1], m, n);
  makedp(dp[2], in[2], n, m);
  makedp(dp[3], in[3], m, n);
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      upd(dp[0], in[0], n, m, x, y);
      upd(dp[1], in[1], m, n, m - y + 1, x);
      upd(dp[2], in[2], n, m, n - x + 1, m - y + 1);
      upd(dp[3], in[3], m, n, y, n - x + 1);
    } else {
      int a1 = qry(dp[0], in[0], n, m, x, y);
      int a2 = qry(dp[1], in[1], m, n, m - y + 1, x);
      int a3 = qry(dp[2], in[2], n, m, n - x + 1, m - y + 1);
      int a4 = qry(dp[3], in[3], m, n, y, n - x + 1);
      printf("%d\n", max(max(a1, a2), max(a3, a4)));
    }
  }
}
int main() {
  input();
  solve();
}
