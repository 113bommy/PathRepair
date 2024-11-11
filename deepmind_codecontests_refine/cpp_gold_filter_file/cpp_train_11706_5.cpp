#include <bits/stdc++.h>
const int N = 403;
int n, m;
bool t[N][N];
int di[8] = {1, 1, 0, -1, -1, -1, 0, 1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int wa[8][N][N];
void fillwa() {
  for (int d = 0; d < 8; d++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (t[i][j] == 0) wa[d][i][j] = -1;
}
int getwa(int d, int i, int j) {
  if (wa[d][i][j] < 0) wa[d][i][j] = getwa(d, i + di[d], j + dj[d]) + 1;
  return wa[d][i][j];
}
void computewa() {
  fillwa();
  for (int d = 0; d < 8; d++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) getwa(d, i, j);
}
char buf[402];
int main() {
  scanf("%d %d", &n, &m);
  n += 2;
  m += 2;
  for (int j = 0; j < m; j++) {
    t[0][j] = 1;
    t[n - 1][j] = 1;
  }
  for (int i = 1; i < n - 1; i++) {
    t[i][0] = 1;
    t[i][m - 1] = 1;
    scanf("%s", buf);
    for (int j = 1; j < m - 1; j++) {
      t[i][j] = buf[j - 1] - '0';
    }
  }
  computewa();
  int w = 0;
  for (int d1 = 0, d2 = 2; d1 < 8; d1++, d2 = (d1 + 2) % 8) {
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++)
        if (t[i][j] == 0) {
          for (int k = 1; t[i + di[d1] * k][j + dj[d1] * k] == 0 &&
                          t[i + di[d2] * k][j + dj[d2] * k] == 0;
               k++) {
            int d3 = (d2 + 1) % 8;
            int ksz = (d1 % 2 == 0 ? k : k * 2);
            w += (wa[d3][i + di[d1] * k][j + dj[d1] * k] >= ksz);
          }
        }
    }
  }
  printf("\n%d\n", w);
}
