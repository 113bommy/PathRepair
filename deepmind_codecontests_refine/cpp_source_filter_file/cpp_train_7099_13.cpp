#include <bits/stdc++.h>
int main() {
  int q, i, n, j, k, c;
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%d", &n);
    int p[n + 1], anp[n + 1];
    for (j = 1; j <= n; j++) {
      scanf("%d", &p[j]);
    }
    for (j = 1; j <= n; j++) {
      c = 1;
      k = p[j];
      while (1) {
        if (k == j) {
          break;
        } else {
          k = p[k];
          c++;
        }
      }
      anp[j] = c;
    }
    for (j = 1; j <= n; j++) {
      printf("%d", anp[j]);
    }
    printf("\n");
  }
}
