#include <bits/stdc++.h>
using namespace std;
long long quickpow(long long a, long long n, long long m) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return ans;
}
bool is_prime(long long p) {
  if (p < 2) return false;
  for (long long i = 2; i * i <= p; i++) {
    if (i < p && p % i == 0) return false;
  }
  return true;
}
bool is_root(long long a, long long p) {
  if (a % p == 0) return false;
  for (long long i = 1; i * i <= p - 1; i++) {
    if ((p - 1) % i == 0) {
      if (i < p - 1 && quickpow(a, i, p) == 1) return false;
      if ((p - 1) / i < p - 1 && quickpow(a, (p - 1) / i, p) == 1) return false;
    }
  }
  return true;
}
int main() {
  long long N, X;
  scanf("%lld %lld", &N, &X);
  if (!is_prime(N + 1)) {
    printf("-1\n");
    return 0;
  }
  for (long long d = X - 1; d > 1; d--) {
    if (is_root(d, N + 1)) {
      printf("%lld\n", d);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
