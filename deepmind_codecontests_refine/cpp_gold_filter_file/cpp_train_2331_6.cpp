#include <bits/stdc++.h>
int main() {
  int n, m, s = 0, f = 0, a[205], i, min = 1000;
  scanf("%d", &n);
  m = 2 * n - 1;
  for (i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    if (a[i] < 0) {
      f++;
      a[i] = -1 * a[i];
    }
    s += a[i];
    if (a[i] < min) min = a[i];
  }
  if (n % 2 == 0 && f % 2 != 0)
    printf("%d\n", s - 2 * min);
  else
    printf("%d\n", s);
  return 0;
}
