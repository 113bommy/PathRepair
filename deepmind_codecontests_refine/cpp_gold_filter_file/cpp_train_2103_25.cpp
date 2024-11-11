#include <bits/stdc++.h>
int main() {
  int n, a, b, c, d, k, x, y;
  scanf("%d", &n);
  while (n > 0) {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    if (a < c)
      x = 1;
    else if (a % c == 0)
      x = a / c;
    else {
      x = a / c;
      x++;
    }
    if (b < d)
      y = 1;
    else if (b % d == 0)
      y = b / d;
    else {
      y = b / d;
      y++;
    }
    if (x + y > k)
      printf("-1\n");
    else
      printf("%d\t%d\n", x, y);
    n--;
  }
  return 0;
}
