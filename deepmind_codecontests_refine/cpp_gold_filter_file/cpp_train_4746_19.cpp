#include <bits/stdc++.h>
using namespace std;
int n, b[255][255], c[255][255], m, dp[255], F[255][2];
char a[4 * 255][4 * 255];
void up(int &F, int x) { F = (F + x) % 1000000007; }
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= 4 * n + 1; i++) {
    for (int j = 1; j <= 4 * m + 1; j++) scanf("%c", &a[i][j]);
    scanf("\n");
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      b[i][j] = 0;
      int u = 4 * i - 2, v = 4 * j - 2;
      for (int ii = u; ii <= u + 2; ii++)
        for (int jj = v; jj <= v + 2; jj++) b[i][j] += (a[ii][jj] == 'O');
      if (b[i][j] == 2 || b[i][j] == 3) {
        if (a[u][v] == 'O')
          c[i][j] = 1;
        else
          c[i][j] = 2;
      }
      if (b[i][j] == 6) {
        if (a[u][v + 1] == 'O')
          c[i][j] = 1;
        else
          c[i][j] = 2;
      }
    }
  dp[0] = 1;
  for (int i = 0; i <= m - 1; i++)
    if (dp[i]) {
      int check = 0;
      for (int j = 1; j <= n; j++)
        if (c[j][i + 1] == 1) check = 1;
      if (check == 0 && n % 2 == 0) up(dp[i + 1], dp[i]);
      if (i == m - 1) continue;
      for (int j = 0; j <= n; j++)
        for (int t = 0; t <= 1; t++) F[j][t] = 0;
      F[0][0] = 1;
      for (int j = 0; j <= n - 1; j++)
        for (int t = 0; t <= 1; t++)
          if (F[j][t]) {
            if (c[j + 1][i + 1] != 2 && c[j + 1][i + 2] != 2) {
              up(F[j + 1][1], F[j][t]);
            }
            if (j < n - 1 && c[j + 1][i + 1] != 1 && c[j + 1][i + 2] != 1 &&
                c[j + 2][i + 1] != 1 && c[j + 2][i + 2] != 1) {
              up(F[j + 2][t], F[j][t]);
            }
          }
      up(dp[i + 2], ((long long)dp[i] * F[n][1]) % 1000000007);
    }
  cout << dp[m];
  return 0;
}
