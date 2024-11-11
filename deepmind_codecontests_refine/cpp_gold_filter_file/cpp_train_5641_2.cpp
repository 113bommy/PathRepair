#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int b, p, f, h, c;
    int cost = 0;
    scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
    if (b / 2 >= (p + f)) {
      cost = p * h + f * c;
    } else if (b / 2 < (p + f) && b / 2 > 0) {
      if (c >= h) {
        if (f >= b / 2)
          cost = b / 2 * c;
        else
          cost = c * f + (b / 2 - f) * h;
      } else {
        if (p >= b / 2)
          cost = b / 2 * h;
        else
          cost = p * h + (b / 2 - p) * c;
      }
    } else
      cost = 0;
    printf("%d\n", cost);
  }
  return 0;
}
