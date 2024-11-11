#include <bits/stdc++.h>
using namespace std;
int T, n, b;
long long a, y;
inline long long mul(long long a, long long b, long long P) {
  return (a * b % P - (long long)((double)a * b / P) * P + P) % P;
}
inline long long Log(long long x, int p, int a) {
  long long pa = p, phi = p - 1;
  for (int i = 1; i < a; ++i) pa *= p, phi *= p;
  long long g = 0, now = 1;
  while ((now - x) % p) ++g, now = now * 2 % pa;
  long long y = 1;
  for (int i = 1; i < p; ++i) y = y * 2 % pa;
  for (long long i = 1, pp = p; i < a; ++i, pp *= p) {
    while ((now - x) % (pp * p))
      g = (g + pp / p * (p - 1)) % phi, now = mul(now, y, pa);
    long long z = y;
    for (int j = 1; j < p; ++j) y = mul(y, z, pa);
  }
  return g;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &a), n = 0;
    for (long long i = a; i; i /= 10) ++n;
    b = (1 << (n + 6)) - a * 1000000 % (1 << (n + 6));
    if (b % 5 == 0) b += 1 << (n + 6);
    y = (a * 1000000 + b) >> (n + 6);
    printf("%lld\n", Log(y, 5, n + 6) + n + 6);
  }
  return 0;
}
