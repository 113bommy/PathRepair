#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, f, g, h, i;
  scanf("%d %d %d\n", &a, &b, &c);
  d = (a + b - c) / 2;
  e = (b + c - a) / 2;
  f = (a + c - b) / 2;
  g = (a + b - c) % 2;
  h = (b + c - a) % 2;
  i = (a + c - b) % 2;
  if (g == 1 || h == 1 || i == 1)
    printf("Impossible\n");
  else if (d < 0 || e < 0 || f < 0)
    printf("Impossible\n");
  else if (d == 0 && e == 0 && f == 0)
    printf("Impossible\n");
  else
    printf("%d %d %d\n", d, e, f);
  return 0;
}
