#include <bits/stdc++.h>
int main() {
  int n, m, i, j;
  scanf("%d %d", &n, &m);
  int a[n];
  for (i = 0; i < n; i++) scanf("%d\n", &a[i]);
  int b[m];
  for (i = 0; i < m; i++) scanf("%d\n", &b[i]);
  j = 1;
  printf("%d\n", n + m - 1);
  for (i = 1; i <= n; i++) {
    printf("%d %d\n", i, j);
  }
  j++;
  i = 1;
  for (j = 2; j <= m; j++) printf("%d %d\n", i, j);
  return 0;
}
