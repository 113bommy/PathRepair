#include <bits/stdc++.h>
int main() {
  int a, b, n = 0;
  scanf("%d%d", &a, &b);
  while (a <= b) {
    a *= 3;
    b *= 2;
    n++;
  }
  printf("%d", n);
  return 0;
}
