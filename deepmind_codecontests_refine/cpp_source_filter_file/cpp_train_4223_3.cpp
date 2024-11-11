#include <bits/stdc++.h>
using namespace std;
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
long long d, k, a, b, t;
long long full;
long long cost(long long x) {
  if (x * k >= d) return full * x - t - (x * k - d);
  return full * x - t + (d - k * x) * b;
}
int main() {
  scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t);
  full = k * a + t;
  long long l = 1, r = (d + k - 1) / k;
  while (l < r) {
    long long m = (l + r) / 2;
    if (cost(m) < cost(m + 1))
      r = m;
    else
      l = m + 1;
  }
  printf("%lld\n", cost(l));
}
