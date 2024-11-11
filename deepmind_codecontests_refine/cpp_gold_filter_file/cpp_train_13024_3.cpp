#include <bits/stdc++.h>
void kt(long long n, long long s) {
  long long x = 0;
  for (long long i = n; i > 0; i--) {
    while (s >= i) {
      x += s / i;
      s = s % i;
    }
  }
  printf("%lld", x);
}
int main() {
  long long n, s;
  scanf("%lld%lld", &n, &s);
  kt(n, s);
  return 0;
}
