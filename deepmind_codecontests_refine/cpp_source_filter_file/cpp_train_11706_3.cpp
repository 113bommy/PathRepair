#include <bits/stdc++.h>
using namespace std;
char puzzle[500][500];
char tt[500][500];
int row, col, ans;
int x[500][500], y[500][500], z[1000][500], w[1000][500];
void cal(void) {
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(z, 0, sizeof(z));
  memset(w, 0, sizeof(w));
  for (int i = (1); i <= (row); i++) {
    for (int j = (1); j <= (col); j++) {
      x[i][j] = x[i][j - 1] + puzzle[i][j] - '0';
      y[i][j] = y[i - 1][j] + puzzle[i][j] - '0';
      z[i + j][i] = z[i + j][i - 1] + puzzle[i][j] - '0';
      w[i - j + 500][i] = z[i - j + 500][i - 1] + puzzle[i][j] - '0';
    }
  }
  for (int i = (1); i <= (row); i++) {
    for (int j = (1); j <= (col); j++) {
      for (int p = (i + j + 1); p <= (row + col); p++) {
        if (p - j > row || p - i > col) continue;
        if (x[i][p - i] - x[i][j - 1] > 0) continue;
        if (y[p - j][j] - y[i - 1][j] > 0) continue;
        if (z[p][p - j] - z[p][i - 1] > 0) continue;
        ans++;
      }
    }
  }
  for (int j = (1); j <= (col); j++) {
    for (int p = (j + 1); p <= (j + row); p++) {
      for (int q = (1 - j); q <= (p - 2 * j - 1); q++) {
        if ((p - 2 * j - q) % 2) continue;
        if ((p - q) / 2 > col) continue;
        if (y[p - j][j] - y[q + j - 1][j] > 0) continue;
        if (z[p][p - j] - z[p][(p + q) / 2 - 1] > 0) continue;
        if (w[q + 500][(p + q) / 2] - w[q + 500][q + j - 1] > 0) continue;
        ans++;
      }
    }
  }
}
void rolate(void) {
  for (int i = (1); i <= (row); i++) {
    for (int j = (1); j <= (col); j++) {
      tt[j][-i + row + 1] = puzzle[i][j];
    }
  }
  memcpy(puzzle, tt, sizeof(tt));
  swap(row, col);
}
void solve(void) {
  ans = 0;
  for (int i = (1); i <= (row); i++) scanf("%s", puzzle[i] + 1);
  for (int step = 0; step < (4); step++) {
    cal();
    rolate();
  }
  printf("%d\n", ans);
}
int main(void) {
  while (2 == scanf("%d%d", &row, &col)) solve();
  return 0;
}
