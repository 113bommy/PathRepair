#include <bits/stdc++.h>
#pragma GCC optimize("O3")
long long pow(long long a, long long b) {
  if (b == 0 || a == 1) return 1;
  if (b % 2 == 0) {
    long long k = pow(a, b / 2);
    return (k * k);
  } else {
    long long k = pow(a, b / 2);
    return k * k * a;
  }
}
long long powmod(long long a, long long b, long long mod) {
  if (b == 0 || a == 1) {
    if (mod == 1)
      return 0;
    else
      return 1;
  }
  if (b % 2 == 0) {
    long long k = powmod(a, b / 2, mod);
    return (k * k) % mod;
  } else {
    long long k = powmod(a, b / 2, mod);
    return ((k * k) % mod * a) % mod;
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
long long prime(long long p) {
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0 && i < p) return 0;
  }
  return 1;
}
long long sqr(long long i) { return i * i; }
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a;
  cin >> a;
  for (long long i = 1; i <= 10; i++) {
    long long y = a + i;
    y = abs(y);
    while (y != 0) {
      if (y % 10 == 8) {
        cout << i;
        return 0;
      }
      y /= 10;
    }
  }
  return 0;
}
