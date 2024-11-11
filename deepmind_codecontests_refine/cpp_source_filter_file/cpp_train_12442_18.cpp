#include <bits/stdc++.h>
int main() {
  long long int n, m, i, j;
  long long int a[101][101], min, max;
  scanf("%lld %lld", &n, &m);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%lld", &a[i][j]);
      if (j == 0) {
        min = a[i][j];
        a[i][100] = min;
      } else {
        if (a[i][j] < min) {
          min = a[i][j];
          a[i][100] = min;
        }
      }
    }
  }
  max = a[0][100];
  for (i = 0; i < m; i++)
    if (a[i][100] > max) max = a[i][100];
  printf("%lld\n", max);
  return 0;
}
