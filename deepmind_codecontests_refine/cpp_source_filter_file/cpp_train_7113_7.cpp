#include <bits/stdc++.h>
using namespace std;
long long gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
bool isprime(long long n) {
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long n, k;
bool f(long long x) {
  long long t = 1;
  long long res = 0;
  while (x / t) {
    res += x / t;
    t *= k;
  }
  return res >= n;
}
int main() {
  cin >> n >> k;
  long long l = 0, r = 1e9, m;
  while (l < r) {
    m = (l + r) / 2;
    if (f(m))
      r = m - 1;
    else
      l = m + 1;
  }
  cout << l << endl;
  return 0;
}
