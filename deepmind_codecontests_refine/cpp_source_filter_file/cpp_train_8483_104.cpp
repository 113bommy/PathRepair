#include <bits/stdc++.h>
int main() {
  int a, b, x, y;
  scanf("%d %d", &a, &b);
  if (a > b) {
    x = b;
    y = (a - b) / 2;
  } else if (b > a) {
    x = a;
    y = (b - a) / 2;
  }
  printf("%d %d\n", x, y);
  return 0;
}
