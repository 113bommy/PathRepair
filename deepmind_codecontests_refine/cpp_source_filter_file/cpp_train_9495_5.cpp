#include <bits/stdc++.h>
int n, a, d;
int main() {
  scanf("%d%d%d", &n, &a, &d);
  printf("%lld %lld\n", 368131125ull * a % 1000000000 * 12000000000ll + 1,
         368131125ull * d % 1000000000 * 12000000000ll);
  return 0;
}
