#include <bits/stdc++.h>
int main() {
  int x, y, i, j, p = 0, q, a[1100], b[1100];
  scanf("%d %d", &x, &y);
  for (i = 1; i <= y; i++) scanf("%d", &a[i]);
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= y; j++) {
      if (a[j] == i) {
        p++;
        b[i] = p;
      }
    }
    p = 0;
  }
  q = b[1];
  for (j = 2; j <= x; j++) {
    if (q > b[j]) q = b[j];
  }
  printf("%d", q);
  return 0;
}
