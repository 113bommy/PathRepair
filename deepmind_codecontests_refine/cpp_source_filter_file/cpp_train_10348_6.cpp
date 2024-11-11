#include <bits/stdc++.h>
int main() {
  int n, m, ans, i, j, a = 1;
  scanf("%d%d", &n, &m);
  ans = m + n - 1;
  printf("%d\n", ans);
  for (i = 0; i < n; i++) {
    if (i == 0) {
      for (j = 0; j < m; j++) printf("%d%d\n", i + 1, j + 1);
    } else
      printf("%d%d\n", i + 1, a);
  }
  return 0;
}
