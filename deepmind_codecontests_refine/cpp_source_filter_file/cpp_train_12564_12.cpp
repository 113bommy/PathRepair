#include <bits/stdc++.h>
int len, rest;
int space[10][110] = {0};
int num = 0;
int ans[21000][3] = {0};
void Check() {
  for (int i = 1; i <= len; i++)
    if (space[1][i] != 0 && space[1][i] == space[2][i]) {
      num++;
      rest--;
      ans[num][0] = space[2][i];
      ans[num][1] = 1;
      ans[num][2] = i;
      space[2][i] = 0;
    }
  for (int i = 1; i <= len; i++)
    if (space[4][i] != 0 && space[3][i] == space[4][i]) {
      num++;
      rest--;
      ans[num][0] = space[3][i];
      ans[num][1] = 4;
      ans[num][2] = i;
      space[3][i] = 0;
    }
  return;
}
void Rotate() {
  int px = 0, py = 0;
  for (int k = 2; k <= 3 && !px; k++)
    for (int i = 1; i <= len && !px; i++)
      if (space[k][i] == 0) {
        px = k;
        py = i;
      }
  for (int time = 0; time < len * 2; time++) {
    int nx, ny;
    if (px == 2)
      if (py < len) {
        nx = 2;
        ny = py + 1;
      } else {
        nx = 3;
        ny = len;
      }
    else if (py > 1) {
      nx = 3;
      ny = py - 1;
    } else {
      nx = 2;
      ny = 1;
    }
    if (space[nx][ny] != 0) {
      num++;
      ans[num][0] = space[nx][ny];
      ans[num][1] = px;
      ans[num][2] = py;
      space[px][py] = space[nx][ny];
      space[nx][ny] = 0;
    }
    px = nx;
    py = ny;
  }
  return;
}
int main() {
  int num_car;
  scanf("%d%d", &len, &num_car);
  rest = num_car;
  for (int k = 1; k <= 4; k++)
    for (int i = 1; i <= len; i++) scanf("%d", &space[k][i]);
  Check();
  if (rest == num_car && num_car == len * 2) {
    printf("-1\n");
    return 0;
  }
  while (rest) {
    Rotate();
    Check();
  }
  printf("%d\n", num);
  for (int i = 1; i <= num; i++)
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  return 0;
}
