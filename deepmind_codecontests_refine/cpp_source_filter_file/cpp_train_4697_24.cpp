#include <bits/stdc++.h>
int main() {
  int a, b, c, x = 0;
  scanf("%d%d%d", &a, &b, &c);
  if ((a + b) < c) {
    x = x + (c - (a + b)) + 1;
  }
  if ((b + c) < a) {
    x = x + (a - (b + c)) + 1;
  }
  if ((a + c) < b) {
    x = x + (b - (a + c)) + 1;
  }
  printf("%d", x);
  return 0;
}
