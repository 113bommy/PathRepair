#include <bits/stdc++.h>
int main() {
  long long a, b, div;
  scanf("%I64d %I64d", &a, &b);
  while (a != 0 && b != 0) {
    if (a >= 2 * b) {
      div = (a - 2 * b) / (2 * b) + 1;
      a = a - div * 2 * b;
    } else if (b >= 2 * a) {
      div = (b - 2 * a) / (2 * a) + 1;
      b = b - div * 2 * a;
    } else
      break;
  }
  printf("%I64d %I64d\n", a, b);
}
