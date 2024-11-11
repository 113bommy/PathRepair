#include <bits/stdc++.h>
using namespace std;
int tot[160][160];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
void work(int m, int kk) {
  int tmp, tt, x, y, ttn;
  int i, j, dir, flag;
  memset(tot, 0, sizeof(tot));
  tot[75][75] = m;
  while (1) {
    flag = 0;
    for (i = 0; i <= 150; ++i) {
      for (j = 0; j <= 150; ++j)
        if (tot[i][j] >= 4) {
          flag = 1;
          ttn = tot[i][j] / 4;
          tot[i][j] %= 4;
          for (dir = 0; dir < 4; ++dir) {
            x = i + dx[dir];
            y = j + dy[dir];
            tot[x][y] += ttn;
          }
        }
    }
    if (flag == 0) break;
  }
}
inline int abs(int a) { return a < 0 ? -a : a; }
int main() {
  int m, t;
  int i, j;
  scanf("%d%d", &m, &t);
  work(m, 4);
  int a, b;
  for (i = 0; i <= t; ++i) {
    scanf("%d%d", &a, &b);
    if (abs(a) > 74 || abs(b) > 74)
      printf("0\n");
    else
      printf("%d\n", tot[a + 75][b + 75]);
  }
  return 0;
}
