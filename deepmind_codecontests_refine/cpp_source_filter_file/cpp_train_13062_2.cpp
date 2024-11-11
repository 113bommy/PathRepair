#include <bits/stdc++.h>
const int C = 701;
long long d[6][C][C], sd2[C];
void mtmul(int a, int b, int c, int n) {
  int i, j, ij;
  for (i = 0; i <= n; i++) {
    for (j = i; j <= n; j++) {
      for (ij = 0; ij <= n; ij++) {
        d[c][i][j] += (d[a][i][ij] * d[b][ij][j]);
      }
    }
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j < i; j++) {
      d[c][i][j] = d[c][j][i];
    }
  }
}
int main() {
  int n, m, i, j, a, b;
  long long wyn = 0;
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    d[1][a][b] = 1, d[1][b][a] = 1;
  }
  mtmul(1, 1, 2, n);
  mtmul(2, 1, 3, n);
  mtmul(2, 3, 5, n);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (d[1][i][j] > 0) {
        d[5][i][i] = d[5][i][i] - d[3][j][j] + 2 * d[2][j][i] -
                     2 * (d[2][j][j] - 1) * d[2][j][i];
      }
    }
    d[5][i][i] = d[5][i][i] - 2 * d[2][i][i] * d[3][i][i] + d[3][i][i];
  }
  for (i = 1; i <= n; i++) wyn += d[5][i][i];
  printf("%d", wyn / 10);
  return 0;
}
