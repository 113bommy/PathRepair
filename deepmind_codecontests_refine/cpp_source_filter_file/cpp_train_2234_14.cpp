#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long x) {
  if (x <= 1) return false;
  for (long long i = 2; i <= x / i; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long pow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return res;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long mi = (a % 2 == 0) ? a / 2 : (a + 1) / 2;
  long long mx = a;
  for (long long i = 0; i < a; i += b) {
    if (i >= mi && i <= mx) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
