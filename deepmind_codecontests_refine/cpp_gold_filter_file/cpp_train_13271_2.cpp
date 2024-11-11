#include <bits/stdc++.h>
long long h, w;
int main() {
  scanf("%lld%d", &h, &w);
  long long a = 1;
  while (a << 1 <= h && a << 1 <= w) a <<= 1;
  long long m = std::min(h, a * 5 / 4);
  long long n = std::min(w, a * 5 / 4);
  if (m >= n)
    printf("%lld %lld\n", m, a);
  else
    printf("%lld %lld\n", a, n);
  return 0;
}
