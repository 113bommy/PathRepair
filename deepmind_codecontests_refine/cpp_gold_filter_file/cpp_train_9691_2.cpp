#include <bits/stdc++.h>
int main() {
  int i, m, n, count = 0;
  int a[1002];
  while (~scanf("%d%d", &m, &n)) {
    for (i = 0; i < m; i++) {
      scanf("%d", &a[i]);
    }
    for (i = m - 1; i > 0; i--) {
      if (a[i] - a[i - 1] > 2 * n) {
        count += 2;
      } else if (a[i] - a[i - 1] == 2 * n) {
        count += 1;
      } else {
        count += 0;
      }
    }
    printf("%d\n", count + 2);
    count = 0;
  }
}
