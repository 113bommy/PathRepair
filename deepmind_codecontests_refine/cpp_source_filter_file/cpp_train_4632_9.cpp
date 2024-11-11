#include <bits/stdc++.h>
int solve(int *a, int n, int k, int x, int m) {
  int i, l = 0, sum;
  for (i = 0; i < k; i++)
    if (a[i] < m) l++;
  if (l > n / 2) return 0;
  for (i = k; i < n; i++) a[i] = i < k + n / 2 - l ? 1 : m;
  sum = 0;
  for (i = 0; i < n; i++) sum += a[i];
  return sum <= x;
}
int main() {
  int i, n, m, k, p, x, y, found, good;
  static int a[999];
  scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (m = y; m <= p; m++) {
    found = 0;
    good = 1;
    for (i = 0; i < k; i++)
      if (a[i] == m) {
        found = 1;
        break;
      }
    if (!found) {
      a[k] = m;
      good = solve(a, n, k + 1, x, m);
    } else
      good = solve(a, n, k, x, m);
    if (good) {
      for (i = k; i <= m; i++) printf("%d ", a[i]);
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
