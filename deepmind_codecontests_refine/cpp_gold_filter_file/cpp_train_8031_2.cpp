#include <bits/stdc++.h>
int main() {
  char lawn[200][200];
  int n, m;
  scanf("%d%d", &n, &m);
  int same, down, curr_col = 1, steps = 0;
  int i, j, weed = 0, z = n, flag = 0;
  for (i = 1; i <= n; i++) {
    scanf("%s", lawn[i] + 1);
  }
  for (i = n; i >= 1; i--) {
    for (j = 1; j <= m; j++) {
      if (lawn[i][j] == 'W') {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  n = i;
  for (i = 1; i <= n; i++) {
    if (curr_col == 0) curr_col = 1;
    if (curr_col == m + 1) curr_col = m;
    same = curr_col;
    down = curr_col;
    if (i % 2 == 0) {
      for (j = curr_col; j >= 1; j--) {
        if (lawn[i][j] == 'W') {
          same = j;
        }
        if (i < n) {
          if (lawn[i + 1][j] == 'W') down = j;
        }
      }
      int x, y;
      x = curr_col - same;
      y = curr_col - down;
      curr_col = same > down ? down : same;
      steps += x > y ? x + 1 : y + 1;
    } else {
      for (j = curr_col; j <= m; j++) {
        if (lawn[i][j] == 'W') {
          same = j;
        }
        if (i < n) {
          if (lawn[i + 1][j] == 'W') down = j;
        }
      }
      int x, y;
      x = same - curr_col;
      y = down - curr_col;
      curr_col = same > down ? same : down;
      steps += x > y ? x + 1 : y + 1;
    }
  }
  if (steps == 0)
    printf("0");
  else
    printf("%d\n", steps - 1);
  return 0;
}
