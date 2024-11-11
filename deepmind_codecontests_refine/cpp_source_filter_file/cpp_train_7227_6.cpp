#include <bits/stdc++.h>
int main() {
  int x, k, p, q, i, a;
  int b[5000] = {0}, c[5000] = {0};
  scanf("%d %d", &x, &k);
  for (i = 0; i < k; i++) {
    scanf("%d", &a);
    if (a == 1) {
      scanf("%d %d", &p, &q);
      b[p] = 1;
      b[q] = 1;
    } else {
      scanf("%d", &p);
      b[p] = 1;
    }
  }
  x--;
  p = 0;
  for (i = 1; i <= x; i++) {
    if (!b[i]) {
      c[p] = i;
      p++;
    }
  }
  q = 0;
  for (i = 0; i < p; i++) {
    if (c[i + 1] = c[i] + 1) {
      i++;
      q++;
    } else
      q++;
  }
  printf("%d %d\n", q, p);
  return 0;
}
