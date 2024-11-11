#include <bits/stdc++.h>
using namespace std;
int n, m, type[2010][2010], can[2010], dpc[2010], f[2010][2][2];
long long dpr[2010], mod = 1e9 + 7;
char board[2010][2010], t[3][3];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 4 * n + 1; i++)
    for (int j = 1; j <= 4 * m + 1; j++) scanf(" %c", board[i] + j);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int co = 0;
      for (int x1 = 0; x1 < 3; x1++)
        for (int y1 = 0; y1 < 3; y1++)
          t[x1][y1] = board[4 * (i - 1) + 2 + x1][4 * (j - 1) + 2 + y1],
          co += t[x1][y1] == 'O';
      if (co == 0 or co == 1 or co == 4 or co == 5)
        type[i][j] = 2;
      else {
        if (co == 2 and t[0][2] == 'O') type[i][j] = 1;
        if (co == 3 and t[0][2] == 'O') type[i][j] = 1;
        if (co == 6 and t[1][0] == 'O') type[i][j] = 1;
      }
    }
  for (int i = 1; i <= m; i++) {
    can[i] = 1;
    if (n % 2) can[i] = 0;
    for (int j = 1; j <= n; j++)
      if (!type[j][i]) can[i] = 0;
  }
  for (int j = 1; j < m; j++) {
    for (int i = 0; i <= n; i++)
      f[i][0][0] = f[i][1][0] = f[i][0][1] = f[i][1][1] = 0;
    f[1][0][0] = 1;
    if (type[1][j] != 1 and type[1][j + 1] != 1) f[1][1][1] = 1;
    for (int i = 1; i < n; i++) {
      if (type[i][j] != 0 and type[i][j + 1] != 0 and type[i + 1][j] != 0 and
          type[i + 1][j + 1] != 0)
        f[i + 1][1][1] += f[i][0][0];
      if (type[i + 1][j] != 1 and type[i + 1][j + 1] != 1)
        f[i + 1][1][1] += f[i][1][1];
      if (type[i][j + 1] != 0 and type[i + 1][j + 1] != 0)
        f[i + 1][0][1] += f[i][1][0];
      if (type[i][j] != 0 and type[i + 1][j] != 0) f[i + 1][1][0] += f[i][0][1];
      f[i + 1][0][0] += f[i][1][1];
      for (int p = 0; p < 2; p++)
        for (int q = 0; q < 2; q++) f[i][p][q] %= mod;
    }
    dpc[j] = f[n][1][1];
  }
  dpr[0] = 1;
  dpr[1] = can[1];
  for (int j = 2; j <= m; j++) {
    dpr[j] = dpr[j - 2] * dpc[j - 1] + dpr[j - 1] * can[j] -
             dpr[j - 2] * can[j - 1] * can[j];
    dpr[j] %= mod;
    dpr[j] += mod;
    dpr[j] %= mod;
  }
  cout << dpr[m];
}
