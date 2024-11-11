#include <bits/stdc++.h>
int n, m, a[105], b[105];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) a[i] = 2;
  if (n > 2) a[n] = n - 2;
  if (n == 2) a[1] = 3, a[2] = 4;
  if (n == 1) a[1] = 1;
  for (int i = 1; i < m; i++) b[i] = 2;
  if (m > 2) b[m] = m - 2;
  if (m == 2) b[1] = 3, b[2] = 4;
  if (m == 1) b[1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[i] * b[j]);
    printf("\n");
  }
}
