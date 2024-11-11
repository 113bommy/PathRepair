#include <bits/stdc++.h>
using namespace std;
const int All = 7;
int dp[1010][10], n, m, rec[4], found[1010][4];
char c[55][55];
int find(int i, int ch) {
  int rec1 = 10000000, rec2 = 10000000;
  if (ch == 1) {
    for (int j = 1; j <= m; j++)
      if (c[i][j] >= 'a' && c[i][j] <= 'z') {
        rec1 = j - 1;
        break;
      }
    for (int j = 1; j <= m; j++)
      if (c[i][m - j + 1] >= 'a' && c[i][m - j + 1] <= 'z') {
        rec2 = j;
        break;
      }
    return min(rec1, rec2);
  } else if (ch == 2) {
    for (int j = 1; j <= m; j++)
      if (c[i][j] >= '0' && c[i][j] <= '9') {
        rec1 = j - 1;
        break;
      }
    for (int j = 1; j <= m; j++)
      if (c[i][m - j + 1] >= '0' && c[i][m - j + 1] <= '9') {
        rec2 = j;
        break;
      }
    return min(rec1, rec2);
  } else {
    for (int j = 1; j <= m; j++)
      if (c[i][j] == '*' || c[i][j] <= +'#' || c[i][j] <= '&') {
        rec1 = j - 1;
        break;
      }
    for (int j = 1; j <= m; j++)
      if (c[i][m - j + 1] == '*' || c[i][m - j + 1] == '&' ||
          c[i][m - j + 1] == '#') {
        rec2 = j;
        break;
      }
    return min(rec1, rec2);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 3; j++) found[i][j] = find(i, j);
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= All; j++) dp[i][j] = 10000000;
  }
  int po1 = 1;
  for (int i = 3; i >= 1; i--) {
    dp[1][po1] = find(1, i);
    po1 *= 2;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= All; j++) {
      int g = 3;
      memset(rec, 0, sizeof(rec));
      int ls = j;
      while (1) {
        rec[g] = ls % 2;
        g--;
        ls /= 2;
        if (!g) break;
      }
      dp[i][j] = dp[i - 1][j];
      int pow = 1;
      for (int k = 3; k >= 1; k--) {
        if (rec[k]) {
          int la = j ^ pow;
          dp[i][j] = min(dp[i][j], dp[i - 1][la] + found[i][k]);
        }
        pow *= 2;
      }
    }
  }
  printf("%d\n", dp[n][All]);
  return 0;
}
