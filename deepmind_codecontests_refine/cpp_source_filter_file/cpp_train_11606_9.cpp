#include <bits/stdc++.h>
int main() {
  int n, i = 0, j = 0;
  scanf("%d", &n);
  char a[11][11];
  for (i = 0; i < n; i++) a[i][0] = 1;
  for (j = 0; j < n; j++) a[0][j] = 1;
  for (i = 1; i < n; i++) {
    for (j = 1; j < n; j++) {
      a[i][j] = a[i - 1][j] + a[i][j - 1];
    }
  }
  printf("%d\n", a[n - 1][n - 1]);
}
