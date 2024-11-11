#include <bits/stdc++.h>
int main() {
  int a, b, n, q, i, neg = 0, pos = 0;
  scanf("%d %d", &n, &q);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    if (a == -1) {
      neg++;
    } else {
      pos++;
    }
  }
  for (i = 1; i <= q; i++) {
    scanf("%d %d", &a, &b);
    if (a == b || (b - a + 1) % 2 != 0) {
      printf("0\n");
    } else {
      a = (b - a + 1) / 2;
      if (a <= neg || a <= pos) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }
}
