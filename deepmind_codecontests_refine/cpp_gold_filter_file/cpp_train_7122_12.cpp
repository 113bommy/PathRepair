#include <bits/stdc++.h>
int ar[100000];
int main() {
  int i, j, m, n, total = 0, a, b, c;
  scanf("%d %d", &n, &m);
  if (m == 0 || n == 1)
    printf("0");
  else {
    for (j = 1; j <= m; j++) {
      scanf("%d %d %d", &a, &b, &c);
      ar[a] += c;
      ar[b] -= c;
    }
    for (i = 1; i <= n; i++) {
      if (ar[i] < 0) total += ar[i];
    }
    total = -1 * total;
    printf("%d", total);
  }
  return 0;
}
