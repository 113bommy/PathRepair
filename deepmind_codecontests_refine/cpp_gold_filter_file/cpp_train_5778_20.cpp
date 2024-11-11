#include <bits/stdc++.h>
int main() {
  long long a, b, c, d, e, f, s;
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &d, &e, &f);
  if (b > f)
    s = ((a * 2 + 1) + ((a + f - 1) * 2 + 1)) * f / 2 + (a + f) * (b - f) * 2 +
        ((d * 2 + 1) + ((d + c - 1) * 2 + 1)) * c / 2;
  else
    s = ((a * 2 + 1) + ((a + b - 1) * 2 + 1)) * b / 2 + (a + b) * (f - b) * 2 +
        ((d * 2 + 1) + ((d + e - 1) * 2 + 1)) * e / 2;
  printf("%I64d", s);
  return 0;
}
