#include <bits/stdc++.h>
int n, iki[105], uc[105], mat[105][105], x, y;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 100; i++) iki[i] = i * (i - 1) / 2;
  for (int i = 1; i <= 100; i++) uc[i] = iki[i] * (i - 2) / 3;
  for (int i = 1;; i++)
    if (uc[i] > n) {
      x = i - 1;
      break;
    }
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= x; j++)
      if (i != j) mat[i][j] = 1;
  n -= uc[x];
  while (n > 0) {
    for (int i = 1; i <= x; i++)
      if (iki[i] > n) {
        y = i - 1;
        break;
      }
    for (int i = 1; i <= y; i++) {
      mat[x + 1][i] = 1;
      mat[i][x + 1] = 1;
    }
    n -= iki[y];
    x++;
  }
  printf("%d\n", x);
  for (int i = 1; i <= x; i++) {
    for (int j = 1; j <= x; j++) printf("%d ", mat[i][j]);
    printf("\n");
  }
}
