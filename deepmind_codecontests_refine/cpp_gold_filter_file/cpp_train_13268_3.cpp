#include <bits/stdc++.h>
int main() {
  int n, i, j, sum = 0;
  scanf("%d", &n);
  int a[n][2];
  for (i = 0; i < n; i++) {
    for (j = 0; j < 2; j++) scanf("%d", &a[i][j]);
  }
  for (i = 0; i < n; i++) {
    if ((a[i][1] - a[i][0]) >= 2) sum++;
  }
  printf("%d \n", sum);
}
