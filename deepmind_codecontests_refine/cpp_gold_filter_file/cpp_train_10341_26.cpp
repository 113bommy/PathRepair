#include <bits/stdc++.h>
int main() {
  int a = 1, b = 2, c = 4, n, oo = 1000000009;
  scanf("%d", &n);
  for (; n > 2; n -= 2)
    c = 1LL * c * a % oo, b = (b + c) % oo, a = (a * 2 + 3) % oo;
  printf("%d\n", (1LL * b * b + 1) * 2 % oo);
  return 0;
}
