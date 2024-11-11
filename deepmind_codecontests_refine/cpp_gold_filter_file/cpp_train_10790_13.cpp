#include <bits/stdc++.h>
int main(void) {
  int l, r, a;
  scanf("%d %d %d", &l, &r, &a);
  int x;
  if (l == r)
    printf("%d", l + r + (a / 2) + (a / 2));
  else if (l > r) {
    if ((r + a) == l) {
      x = 2 * l;
      printf("%d", x);
    } else if ((r + a) > l) {
      int q = r + a - l;
      x = l + l + (q / 2) + (q / 2);
      printf("%d", x);
    } else if ((r + a) < l) {
      x = r + a + r + a;
      printf("%d", x);
    }
  } else if (l < r) {
    if ((l + a) == r) {
      x = 2 * r;
      printf("%d", x);
    } else if ((l + a) > r) {
      int q = l + a - r;
      x = r + r + (q / 2) + (q / 2);
      printf("%d", x);
    } else if ((l + a) < r) {
      x = l + a + l + a;
      printf("%d", x);
    }
  }
  return 0;
}
