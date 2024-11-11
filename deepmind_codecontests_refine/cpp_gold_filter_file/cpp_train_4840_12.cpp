#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 5][n + 5], b[105] = {0}, count = 0;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (a[i][j] == 1)
        b[i]++;
      else if (a[i][j] == 2)
        b[j]++;
      else if (a[i][j] == 3) {
        b[i]++;
        b[j]++;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (b[i] == 0) count++;
  }
  printf("%d\n", count);
  for (i = 1; i <= n; i++) {
    if (b[i] == 0) printf("%d ", i);
  }
  return 0;
}
