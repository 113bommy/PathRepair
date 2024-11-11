#include <bits/stdc++.h>
int a[1010], n, m, c, x, i;
int main() {
  for (scanf("%d%d%d", &n, &m, &c); m--;) {
    scanf("%d", &x);
    if (x * 2 > c)
      for (i = n; a[i] >= x; --i)
        ;
    else
      for (i = 1; a[i] <= x; ++i)
        ;
    printf("%d\n", i), fflush(stdout), a[i] = x;
    for (i = 1; i <= n; i++)
      if (a[i] == 0) break;
    if (i > n) return 0;
  }
}
