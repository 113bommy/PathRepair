#include <bits/stdc++.h>
int main() {
  int a, b, c, t, h;
  scanf("%d %d %d", &a, &b, &c);
  h = (c + 1) >> 1;
  t = h % b ? h % b : b;
  printf("%d %d ", (h - 1) / b + 1, t);
  printf(c % 2 == 0 ? "R" : "L");
  return 0;
}
