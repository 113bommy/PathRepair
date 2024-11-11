#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  int sum;
  sum = x + y;
  int rem;
  rem = (x * y) / 2;
  printf("%d", (rem + 1));
  return 0;
}
