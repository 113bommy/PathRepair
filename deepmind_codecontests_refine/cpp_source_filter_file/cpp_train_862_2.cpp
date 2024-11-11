#include <bits/stdc++.h>
using namespace std;
template <typename T>
void cmax(T& x, T y) {
  if (x < y) x = y;
}
template <typename T>
void cmin(T& x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const int N = 705, P = 1e9 + 7;
int n, a[N], dp[N][N][3][3], o[N], st;
char s[N];
inline void add(int& x, int y) { x = (x + y) % P; }
inline void solve(int l, int r) {
  if (l + 1 == r) {
    dp[l][r][0][1] = dp[l][r][0][2] = dp[l][r][1][0] = dp[l][r][2][0] = 1;
    return;
  }
  if (a[l] == r) {
    solve(l + 1, r - 1);
    for (int i = (0), iend = (2); i <= iend; i++)
      for (int j = (0), jend = (2); j <= jend; j++)
        for (int k = (0), kend = (2); k <= kend; k++)
          for (int w = (0), wend = (2); w <= wend; w++)
            if ((i == 0 || i != k) && (j == 0 || j != w) && (i + j != 0) &&
                (i == 0 || j == 0))
              add(dp[l][r][i][j], dp[l + 1][r - 1][k][w]);
  } else {
    solve(l, a[l]), solve(a[l] + 1, r);
    for (int i = (0), iend = (2); i <= iend; i++)
      for (int j = (0), jend = (2); j <= jend; j++)
        for (int k = (0), kend = (2); k <= kend; k++)
          for (int w = (0), wend = (2); w <= wend; w++)
            if (j == 0 || j != k)
              add(dp[l][r][i][w],
                  1ll * dp[l][a[l]][i][j] * dp[a[l] + 1][r][k][w]);
  }
}
int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = (1), iend = (n); i <= iend; i++) {
    if (s[i] == '(')
      o[++st] = i;
    else
      a[o[st]] = i, st--;
  }
  solve(1, n);
  int ans = 0;
  for (int i = (0), iend = (2); i <= iend; i++)
    for (int j = (0), jend = (2); j <= jend; j++) add(ans, dp[1][n][i][j]);
  printf("%d", ans);
}
