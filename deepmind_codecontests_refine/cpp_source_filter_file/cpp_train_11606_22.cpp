#include <bits/stdc++.h>
int max[25][25];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i < 25; i++) max[1][i] = 1;
  for (i = 2; i < 25; i++)
    for (int j = 1; j < 25; j++) max[i][j] = max[i][j - 1] - max[i - 1][j];
  printf("%d\n", max[n][n]);
  return 0;
}
