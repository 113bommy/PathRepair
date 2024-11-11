#include <bits/stdc++.h>
int main() {
  long long p, q, d, b = 1;
  scanf("%I64d%I64d", &p, &d);
  while (p > b) b *= 10;
  while (b > 1) {
    q = (p + 1) / b * b - 1;
    if (p - q <= d) {
      printf("%I64d", q);
      break;
    }
    b /= 10;
  }
  if (b < 9) printf("%I64d", p);
  return 0;
}
