#include <bits/stdc++.h>
using namespace std;
double dp[1010][1010];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int main() {
  int n = read(), m = read();
  int x = read(), y = read();
  if (n == x) return puts("0"), 0;
  if (m == 1) return printf("%d\n", 2 * (n - x)), 0;
  for (int i = n - 1; i >= x; i--) {
    for (int t = 1; t <= 50; t++) {
      dp[i][1] = (dp[i][1] + dp[i][2] + dp[i + 1][1]) / 3.0 + 1;
      dp[i][m] = (dp[i][m] + dp[i][m - 1] + dp[i + 1][m]) / 3.0 + 1;
      for (int j = 2; j <= m - 1; j++)
        dp[i][j] =
            (dp[i][j] + dp[i][j - 1] + dp[i][j + 1] + dp[i + 1][j]) / 4.0 + 1;
    }
  }
  printf("%0.6lf", dp[x][y]);
  return 0;
}
