#include <bits/stdc++.h>
const int N = 1010;
int a[N], b[N], n, d, k, m, i, j, u;
int main() {
  scanf("%d%d%d", &n, &k, &d);
  if (k >= n) {
    for (i = 0; i < d; i++) {
      for (j = 1; j <= n; j++) printf("%d ", j);
      printf("\n");
    }
  } else {
    m = n;
    for (i = 0; i < d; i++) m = m / k + (m % k ? 1 : 0);
    if (m <= 1) {
      m = n;
      for (i = 0; i < d; i++) {
        m = m / k + (m % k ? 1 : 0);
        for (j = 0; j < n; j++) {
          if (j && a[j] == a[j - 1])
            ++u;
          else
            u = 0;
          b[j] = u;
        }
        for (j = 0; j < n; j++) a[j] = b[j] / m % k + 1;
        for (j = 0; j < n; j++) printf("%d ", a[j]);
        printf("\n");
      }
    } else
      puts("-1");
  }
  return 0;
}
