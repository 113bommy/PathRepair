#include <bits/stdc++.h>
int main() {
  int a[5][5], i, j;
  for (i = 0; i < 5; i++)
    for (j = 0; j < 4; j++) a[i][j] = 0;
  for (i = 1; i <= 3; i++)
    for (j = 1; j <= 3; j++) scanf("%i", &a[i][j]);
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      if ((a[i][j] + a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1]) & 1)
        printf("0");
      else
        printf("1");
    }
    printf("\n");
  }
  return 0 - 0 - 0;
}
