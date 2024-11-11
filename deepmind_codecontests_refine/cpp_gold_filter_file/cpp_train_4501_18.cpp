#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int read() {
  int x = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * w;
}
long long qpow(long long a, long long n) {
  long long x = 1;
  while (n) {
    if (n & 1) {
      x = (x * a) % mod;
    }
    n >>= 1;
    a = (a * a) % mod;
  }
  return x % mod;
}
long long ny(long long x) { return qpow(x, mod - 2); }
long long C(int a, int b) {
  long long a1 = 1;
  for (int i = a; i >= a - b + 1; i--) {
    a1 *= i;
    a1 %= mod;
  }
  long long a2 = 1;
  for (int i = 1; i <= b; i++) {
    a2 *= i;
    a2 %= mod;
  }
  long long ni = ny(a2);
  return (ni * a1) % mod;
}
int main() {
  int n, m;
  cin >> n >> m;
  long long c1 = C(m, n - 1);
  long long c2 = C(n - 2, 1);
  long long p = 1;
  for (int i = 1; i <= n - 3; i++) {
    p *= 2;
    p %= mod;
  }
  cout << ((c1 * c2) % mod * p) % mod;
  return 0;
}
