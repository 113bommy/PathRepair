#include <bits/stdc++.h>
int main() {
  int m, n, i, x, last = 0;
  scanf("%d", &m);
  scanf("%d\n", &n);
  for (i = 1; i <= m; i++) {
    scanf("%d", &x);
    printf("%d ", (last + x) / n);
    last = (last + x) % n;
  }
  return (0);
}
