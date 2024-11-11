#include <bits/stdc++.h>
int main() {
  int h1, h2, a, b, t, c;
  scanf("%d%d%d%d", &h1, &h2, &a, &b);
  if (a <= b) {
    if ((h2 - h1) <= 8 * a)
      printf("0\n");
    else
      printf("-1\n");
  } else {
    if (8 * a >= (h2 - h1))
      printf("0\n");
    else {
      t = 0;
      c = h2 - h1 + (8 * a - 12 * b);
      while (c > (12 * a)) {
        c = c - (12 * a - 12 * b);
        t++;
      }
      printf("%d", t + 1);
    }
  }
  return 0;
}
