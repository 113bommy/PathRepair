#include <bits/stdc++.h>
int main() {
  int a, b, c, x;
  scanf("%d%d", &a, &b);
  x = a - b;
  if (a > b) {
    x = a - b;
    c = a - x;
  } else if (a < b) {
    x = b - a;
    c = b - x;
  } else {
    c = a;
    x = 0;
  }
  x = x / 2;
  printf("%d %d\n", c, x);
  return 0;
}
