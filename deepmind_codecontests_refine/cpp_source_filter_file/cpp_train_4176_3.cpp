#include <bits/stdc++.h>
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  long long n, m, k;
  scanf("%lld %lld %lld", &n, &m, &k);
  if (((2 * m * n) % k) == 0) {
    puts("NO");
    return 0;
  }
  long long g = gcd(2 * n, k);
  if (g == 1) {
    m = 2 * m / k;
  } else {
    n = 2 * n / g;
    m = g * m / k;
  }
  printf("YES\n0 0\n%lld 0\n0 %lld", n, m);
  return 0;
}
