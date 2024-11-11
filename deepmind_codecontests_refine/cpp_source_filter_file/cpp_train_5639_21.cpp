#include <bits/stdc++.h>
int main() {
  int n, a = 0, b = 0, x = 0, y = 0, z = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    x = b - a;
    scanf("%d", &b);
    y = x + b;
    if (y >= z) {
      z = y;
    }
  }
  printf("%d\n", z);
  return 0;
}
