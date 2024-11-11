#include <bits/stdc++.h>
char map[10][10];
int flag, num[10][10];
int dir[9][2] = {{-1, 0}, {-1, 1}, {0, 1},   {1, 1}, {1, 0},
                 {1, -1}, {0, -1}, {-1, -1}, {0, 0}};
int DFS(int x1, int y1, int step) {
  if (step == 9) return 1;
  int i, tpx, tpy, tpx1, tpy1, cjl;
  int ii, jj;
  for (i = 0; i < 9; i++) {
    tpx = x1 + dir[i][0];
    tpy = y1 + dir[i][1];
    if (tpx > 8 || tpx < 1 || tpy > 8 || tpy < 1) continue;
    if (tpx == 1 && tpy == 8) return 1;
    cjl = 0;
    tpx1 = tpx - step;
    tpy1 = tpy;
    if ((tpx1 >= 1 && tpx1 <= 8 && map[tpx1][tpy1] == 'S') ||
        (tpx1 - 1 >= 1 && tpx1 - 1 <= 8 && map[tpx1 + 1][tpy1] == 'S'))
      continue;
    else
      flag = DFS(tpx, tpy, step + 1);
    if (flag == 1) return 1;
  }
  return 0;
}
int main() {
  int i, j, k;
  while (scanf("%s", map[1] + 1) != EOF) {
    for (i = 2; i <= 8; i++) scanf("%s", map[i] + 1);
    for (i = 1; i <= 8; i++)
      for (j = 1; j <= 8; j++) {
        if (map[i][j] == 'S')
          num[i][j] = 1;
        else
          num[i][j] = 0;
      }
    flag = 0;
    flag = DFS(8, 1, 1);
    if (flag)
      printf("WIN\n");
    else
      printf("LOSE\n");
  }
  return 0;
}
