#include <bits/stdc++.h>
int main(void) {
  int w, h, k, c, e;
  scanf("%d %d %d", &w, &h, &k);
  c = 0;
  do {
    e = (w * h) - ((w - 2) * (h - 2));
    w -= 4;
    h -= 4;
    c += e;
  } while (--k);
  printf("%d", c);
  return 0;
}
