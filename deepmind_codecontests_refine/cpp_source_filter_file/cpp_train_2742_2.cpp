#include <bits/stdc++.h>
int main() {
  int x[100], y[100], l[100], t, i, j;
  for (i = 0; i < 3; i++) scanf("%d%d", &x[i], &y[i]);
  t = 0;
  for (j = 0; j < 13; j++) {
    if (j != 0 && j < 4) {
      x[j - 1]--;
      if (j > 1) x[j - 2]++;
    }
    if (j > 3 && j <= 6) {
      x[j - 2]++;
      y[j - 4]--;
      if (j > 4) y[j - 5]++;
    }
    if (j > 6 && j <= 9) {
      y[j - 5]++;
      y[j - 7]++;
      if (j > 7) y[j - 8]--;
    }
    if (j > 9) {
      x[j - 8]++;
      y[j - 9]--;
      if (j > 10) x[j - 11]--;
    }
    l[0] = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
    l[1] = (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]);
    l[2] = (x[2] - x[0]) * (x[2] - x[0]) + (y[2] - y[0]) * (y[2] - y[0]);
    if (l[0] != 0 && l[1] != 0 && l[2] != 0) {
      if (l[0] + l[1] == l[2]) t = 1;
      if (l[1] + l[2] == l[0]) t = 1;
      if (l[0] + l[2] == l[1]) t = 1;
      if (t == 1 && j == 0) {
        printf("RIGHT");
        break;
      }
      if (t == 1) {
        printf("ALMOST");
        break;
      }
    }
  }
  if (t == 0) printf("NEITHER");
  return 0;
}
