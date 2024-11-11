#include <bits/stdc++.h>
int main() {
  int n, a, b, i, j, k, t;
  scanf("%d%d%d", &n, &a, &b);
  for (k = 1; k <= n; k++) {
    scanf("%1d", &t);
    if (k == a) i = t;
    if (k == b) j = t;
  }
  printf("%d\n", (i == j) ? 1 : 0);
  return 0;
}
