#include <bits/stdc++.h>
bool notblank[1002], g[1002][1002];
int G[1002], q_r[1002][2], q_c[1002][2], r[1002], c[1002];
int main() {
  int n, m = 0, x, y, max, rear_r = 0, rear_c = 0;
  bool flag;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    g[x][y] = true;
    G[y]++;
  }
  for (int i = 1; i <= n; i++) r[i] = i;
  for (int i = 1; i < n; i++) {
    flag = false;
    max = i;
    for (int j = i; j <= n; j++)
      if (G[r[max]] < G[r[j]]) {
        max = j;
        flag = true;
      }
    if (flag) {
      q_c[rear_c][0] = r[i];
      q_c[rear_c++][1] = r[max];
      x = r[i];
      r[i] = r[max];
      r[max] = x;
    }
  }
  for (int i = 1; i <= n; i++) c[i] = i;
  for (int i = n; i > 0; i--)
    if (G[r[i]]) {
      for (int j = 1; j <= n; j++)
        if (g[c[j]][r[i]])
          for (int k = n; k > j; k--)
            if (!notblank[k] && !g[c[k]][r[i]]) {
              notblank[k] = true;
              q_r[rear_r][0] = j;
              q_r[rear_r++][1] = k;
              x = c[k];
              c[k] = c[j];
              c[j] = x;
              break;
            }
      for (int k = n; k > i; k--)
        if (g[c[k]][r[i]]) notblank[k] = true;
    }
  printf("%d\n", rear_c + rear_r);
  for (int i = 0; i < rear_c; i++) printf("2 %d %d\n", q_c[i][0], q_c[i][1]);
  for (int i = 0; i < rear_r; i++) printf("1 %d %d\n", q_r[i][0], q_r[i][1]);
  return 0;
}
