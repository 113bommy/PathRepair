#include <bits/stdc++.h>
int main() {
  unsigned long long a, b;
  scanf("%I64u%I64u", &a, &b);
  if (a < b) {
    puts("-1");
    return 0;
  }
  unsigned long long dif = a - b;
  unsigned long long x = 0, y = 0;
  for (int i = 0; i < 64; ++i) {
    int u = a >> i & 1, v = b >> i & 1, carry = dif >> (i + 1) & 1;
    if (v) {
      y |= 1ull << i;
    } else {
      if (carry) {
        x |= 1ull << i;
        y |= 1ull << i;
      }
    }
  }
  if (x + y == a && (x ^ y) == b) {
    printf("%I64u %I64u\n", x, y);
  } else {
    puts("-1");
  }
  return 0;
}
