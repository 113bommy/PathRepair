#include <bits/stdc++.h>
int main() {
  int n, m, k, i, z = 0, y = 0;
  scanf("%d%d%d", &n, &m, &k);
  int a[n];
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i - 1]);
  }
  for (i = 1; i < m; i++) {
    if (a[i - 1] <= k && a[i - 1] != 0) {
      y = i;
    }
  }
  for (i = m + 1; i <= n; i++) {
    if (a[i - 1] <= k && a[i - 1] != 0) {
      z = i;
      break;
    }
  }
  if (y == 0)
    printf("%d", (z - m) * 10);
  else if (z == 0)
    printf("%d", (m - y) * 10);
  else if (m - y < z - m)
    printf("%d", (m - y) * 10);
  else
    printf("%d", (z - m) * 10);
}
