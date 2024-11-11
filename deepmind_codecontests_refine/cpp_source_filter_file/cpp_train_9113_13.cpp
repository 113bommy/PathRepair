#include <bits/stdc++.h>
using namespace std;
const int P = (int)1e6 + 3;
long long qp(long long x, long long y) {
  long long res = 1;
  for (; y > 0; y >>= 1) {
    if (y & 1) res = res * x % P;
    x = x * x % P;
  }
  return res;
}
long long cal_phi(long long n) {
  long long res = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res -= res / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) res -= res / n;
  return res;
}
void solve(long long n, long long k, long long &a, long long &b) {
  long long now = 1;
  for (long long j = 1; j <= n; ++j) {
    now *= 2;
    if (now >= k) break;
  }
  if (now < k)
    a = 1, b = 1;
  else {
    long long d = 0;
    now = k - 1;
    while (now >= 2) {
      d += now / 2;
      now /= 2;
    }
    long long phi = P - 1;
    b = qp(2, ((n % phi) * (k % phi) - n % phi - d % phi + phi) % phi);
    if (k >= P)
      a = b;
    else {
      now = qp(2, n % phi);
      a = 1;
      for (long long i = 1; i < k; ++i) a = (now - i + P) % P * a % P;
      now = qp(2, d % phi);
      a = a * qp(now, P - 2) % P;
      a = (b - a + P) % P;
    }
  }
}
int main() {
  long long n, k;
  cin >> n >> k;
  long long a, b;
  solve(n, k, a, b);
  printf("%lld %lld\n", a, b);
  return 0;
}
