#include <bits/stdc++.h>
int main() {
  int64_t n, i, j;
  scanf("%I64d", &n);
  j = (n) * (2 * 3 + (n - 1) * 3) + 1;
  printf("%I64d", j);
  return 0;
}
