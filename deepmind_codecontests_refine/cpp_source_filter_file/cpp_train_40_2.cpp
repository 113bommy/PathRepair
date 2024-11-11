#include <bits/stdc++.h>
int main() {
  int a, b, h = 0, r = 0;
  scanf("%d %d", &a, &b);
  while (a > 0) {
    h += a;
    r += a % b;
    a = a / b;
    if (r >= b) {
      h++;
      r -= b;
    }
  }
  printf("%d\n", h);
}
