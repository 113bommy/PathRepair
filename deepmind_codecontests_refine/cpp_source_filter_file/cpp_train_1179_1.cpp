#include <bits/stdc++.h>
int main() {
  int a, b, b1;
  scanf("%d%d", &a, &b1);
  while (b1) {
    b *= 10;
    b += b1 % 10;
    b1 /= 10;
  }
  printf("%d\n", a + b);
}
