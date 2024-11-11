#include <bits/stdc++.h>
long test, a, b, count;
void gcd(long a, long b) {
  if (b == 0) return;
  if (a > b) count += (a / b);
  gcd(b, a % b);
}
int main() {
  scanf("%ld", &test);
  while (test--) {
    scanf("%ld %ld", &a, &b);
    count = 0;
    if (a) gcd(a, b);
    printf("%ld\n", count);
  }
  return 0;
}
