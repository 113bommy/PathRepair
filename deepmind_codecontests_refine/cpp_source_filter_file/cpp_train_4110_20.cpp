#include <bits/stdc++.h>
int main() {
  int a, b, c, d, x, y, m, v;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  x = (3 * a) / 10;
  y = a - (a * c) / 250;
  m = (x >= y) ? x : y;
  x = (3 * b) / 10;
  y = b - (b * d) / 250;
  v = (x >= y) ? x : y;
  if (m > v)
    printf("Misha\n");
  else if (m < v)
    printf("Vashya\n");
  else if (m == v)
    printf("Tie\n");
  return 0;
}
