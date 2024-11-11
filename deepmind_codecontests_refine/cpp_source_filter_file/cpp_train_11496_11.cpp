#include <bits/stdc++.h>
using namespace std;
string dat[64];
int dp[64][64][64][64];
int main(void) {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = (0); i < (int)(n); ++i) cin >> dat[i];
  for (int i = (0); i < (int)(n); ++i)
    for (int j = (0); j < (int)(m); ++j)
      dp[i][j][i][j] = (int)('1' - dat[i][j]);
  for (int i = (0); i < (int)(n); ++i)
    for (int j = (0); j < (int)(m); ++j)
      for (int k = (i); k < (int)(n); ++k)
        for (int l = (j); l < (int)(m); ++l) {
          if ((k == i || dp[i][j][k - 1][l] == 1) &&
              (l == j || dp[i][j][k][l - 1] == 1) && dp[k][l][k][l] == 1)
            dp[i][j][k][l] = 1;
        }
  for (int i = (0); i < (int)(n); ++i)
    for (int j = (0); j < (int)(m); ++j)
      for (int k = (0); k < (int)(m); ++k)
        for (int l = (0); l < (int)(m); ++l)
          if (k > 0) dp[i][j][k][l] += dp[i][j][k - 1][l];
  for (int i = (0); i < (int)(n); ++i)
    for (int j = (0); j < (int)(m); ++j)
      for (int k = (0); k < (int)(m); ++k)
        for (int l = (0); l < (int)(m); ++l)
          if (l > 0) dp[i][j][k][l] += dp[i][j][k][l - 1];
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      for (int k = (0); k < (int)(n); ++k)
        for (int l = (0); l < (int)(m); ++l)
          if (i < n - 1) dp[i][j][k][l] += dp[i + 1][j][k][l];
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      for (int k = (0); k < (int)(n); ++k)
        for (int l = (0); l < (int)(m); ++l)
          if (j < m - 1) dp[i][j][k][l] += dp[i][j + 1][k][l];
  for (int i = (0); i < (int)(q); ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", dp[a - 1][b - 1][c - 1][d - 1]);
  }
  return 0;
}
