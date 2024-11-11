#include <bits/stdc++.h>
using namespace std;
char dp[1005][105][105];
int main() {
  int r, c, k, i, j, l, mat[105][105];
  scanf("%d %d %d", &r, &c, &k);
  memset(dp, 0, sizeof(dp));
  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++) {
      scanf("%1d", &mat[i][j]);
      if (i == 1) dp[mat[i][j]][i][j] = 'r';
    }
  int mak;
  for (i = 1; i < r; i++)
    for (j = 1; j <= c; j++)
      for (l = 0; l < 1000; l++)
        if (dp[l][i][j] != 0) {
          if (j < c) {
            dp[l + mat[i + 1][j + 1]][i + 1][j + 1] = 'L';
          }
          if (j > 1) {
            dp[l + mat[i + 1][j - 1]][i + 1][j - 1] = 'R';
          }
        }
  int C;
  mak = -1;
  for (i = 1; i <= c; i++)
    for (j = 0; j < 1000; j++)
      if (dp[j][r][i] != 0 && (j % (k + 1)) == 0 && j > mak) {
        mak = j;
        C = i;
      }
  if (mak == -1) {
    printf("-1\n");
    return 0;
  }
  c = C;
  printf("%d\n%d\n", mak, c);
  j = mak;
  while (dp[j][r][c] == 'R' || dp[j][r][c] == 'L') {
    printf("%c", dp[j][r][c]);
    if (dp[j][r][c] == 'R') {
      j -= mat[r][c];
      r--;
      c++;
    } else if (dp[j][r][c] == 'L') {
      j -= mat[r][c];
      r--;
      c--;
    }
  }
  printf("\n");
  return 0;
  return 0;
}
