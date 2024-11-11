#include <bits/stdc++.h>
int main() {
  int k, c[35], i, r, ck;
  while (scanf("%d", &k) == 1) {
    ck = 0;
    for (i = 0; i < k; i++) {
      scanf("%d", &c[i]);
      if (c[i] > ck) ck = c[i];
    }
    if (ck > 25) {
      r = ck - 25;
      printf("%d\n", r);
    } else
      printf("%d\n", 0);
  }
  return 0;
}
