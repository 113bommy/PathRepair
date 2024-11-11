#include <bits/stdc++.h>
unsigned int a, b, c, d, n;
std::bitset<100000100> is_prime;
inline unsigned int f(unsigned int x) {
  return (((a * x + b) * x + c) * x + d);
}
inline unsigned int Count(unsigned int p) {
  unsigned int ans = 0, nn = n;
  while (nn /= p) ans += nn;
  return ans;
}
int main() {
  scanf("%u%u%u%u%u", &n, &a, &b, &c, &d);
  unsigned int ans = Count(2) * f(2) + Count(3) * f(3) + Count(5) * f(5);
  for (unsigned long long i = 25, d = 4; i <= n; i += 5 * d) {
    d = 6 - d;
    is_prime[i / 3] = 1;
  }
  for (unsigned int i = 7, delta = 2; i <= n; i += delta) {
    delta = 6 - delta;
    if (is_prime[i / 3] == 0) {
      ans += Count(i) * f(i);
      for (unsigned long long j = (unsigned long long)i * i, d = 6 - delta;
           j <= n; j += i * d) {
        d = 6 - d;
        is_prime[j / 3] = 1;
      }
    }
  }
  printf("%u\n", ans);
  return 0;
}
