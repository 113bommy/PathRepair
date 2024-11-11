#include <bits/stdc++.h>
int main(void) {
  int a, b, x, y;
  scanf("%d %d", &a, &b);
  x = (a > b) ? a : b;
  y = (a < b) ? a : b;
  printf("%d %d\n", y, ((x - y) / 2));
  return 0;
}
