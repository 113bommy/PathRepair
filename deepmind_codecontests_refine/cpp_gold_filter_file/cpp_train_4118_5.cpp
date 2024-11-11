#include <bits/stdc++.h>
long long int add(long long int a, long long int b) {
  return a + b - (a + b >= 1000000007) * 1000000007;
}
long long int sub(long long int a, long long int b) {
  return a - b + (a - b < 0) * 1000000007;
}
long long int mult(long long int a, long long int b) {
  return (1LL * a * b) % 1000000007;
}
inline long long int gcd(long long int a, long long int b) {
  long long int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int k;
  cin >> k;
  long long int q = (1000000007 - 1) / 2;
  long long int d = 2;
  for (long long int i = 0; i < k; i++) {
    long long int x;
    cin >> x;
    q = powmod(q, x);
    d = powmod(d, x);
  }
  d = d * powmod(2, 1000000007 - 2) % 1000000007;
  q = (q * 2 + 1) % 1000000007 * powmod(3, 1000000007 - 2) % 1000000007;
  long long int p = q * d % 1000000007;
  cout << p << "/" << d;
}
