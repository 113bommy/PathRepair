#include <bits/stdc++.h>
using namespace std;
bool isPrime(int64_t N) {
  for (int64_t i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}
const int64_t pi = 3.1415926535897932;
const int64_t N = 1e5 + 1;
int64_t gcd(int64_t a, int64_t b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int64_t power(int64_t a, int64_t b, int64_t p) {
  if (a == 0) return 0;
  int64_t res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
signed main() {
  int64_t t;
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    int64_t n, r;
    cin >> n >> r;
    if (r > n)
      cout << n * (n + 1) / 2 - (n - 1) << "\n";
    else {
      cout << r * (r + 1) / 2 << "\n";
    }
  }
}
