#include <bits/stdc++.h>
int main() {
  long y, b, r;
  scanf("%ld %ld %ld", &y, &b, &r);
  y = (y < b - 1) ? y : (b - 1);
  y = (y < r - 2) ? y : (r - 2);
  printf("%ld\n", 3 * y + 2);
  return 0;
}
