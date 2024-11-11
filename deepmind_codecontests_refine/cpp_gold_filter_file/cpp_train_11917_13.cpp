#include <bits/stdc++.h>
int main() {
  int a, b, c, d = 1;
  scanf("%d", &a);
  b = 1;
  c = a;
  while (b <= c) {
    c = c - b;
    b = b + (d + 1);
    d = d + 1;
  }
  printf("%d", d - 1);
  return 0;
}
