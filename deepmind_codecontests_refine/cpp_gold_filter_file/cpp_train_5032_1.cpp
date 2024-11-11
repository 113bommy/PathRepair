#include <bits/stdc++.h>
void swap(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}
int main() {
  int i, j, a, b, k, n, m, hold, sell[20][110] = {}, buy[20][200] = {},
                                 num[20][200] = {};
  int gain[100][2] = {}, max = -99999, now, size;
  char in[20];
  scanf("%d%d%d", &n, &m, &hold);
  for (i = 0; i < n; i++) {
    scanf("%s", in);
    for (j = 0; j < m; j++)
      scanf("%d%d%d", &buy[i][j], &sell[i][j], &num[i][j]);
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      for (k = 0; k < m; k++) {
        gain[k][0] = sell[j][k] - buy[i][k];
        gain[k][1] = num[i][k];
      }
      for (a = 0; a < k; a++)
        for (b = a + 1; b < k; b++)
          if (gain[a][0] < gain[b][0]) {
            swap(&gain[a][0], &gain[b][0]);
            swap(&gain[a][1], &gain[b][1]);
          }
      now = 0;
      size = 0;
      for (k = 0; k < m; k++) {
        if (gain[k][0] * gain[k][1] >= 0)
          if (size + gain[k][1] <= hold) {
            size += gain[k][1];
            now += gain[k][0] * gain[k][1];
          } else {
            now += gain[k][0] * (hold - size);
            break;
          }
        else
          break;
      }
      if (now > max) max = now;
    }
  printf("%d", max);
}
