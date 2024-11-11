#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF = 0x3f3f3f3f;
const long long mod = 998244353;
const long long maxn = 1e6 + 5;
long long p = mod;
inline long long qpow(long long a, long long b) {
  long long base = a % p;
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * base) % p;
    base = base * base % p;
    b >>= 1;
  }
  return ans % mod;
}
inline long long C(long long n, long long m) {
  if (n < m) return 0;
  if (m > n - m) m = n - m;
  long long a = 1, b = 1;
  for (int i = 0; i < m; i++) {
    a = a * (n - i) % p;
    b = b * (i + 1) % p;
  }
  return a * qpow(b, p - 2) % p;
}
inline long long Lucas(long long n, long long m) {
  if (m == 0) return 1;
  return Lucas(n / p, m / p) * C(n % p, m % p) % p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 0;
    return 0;
  }
  long long ans = (n - 2) % mod * qpow(2, n - 3) % mod * C(m, n - 1) % mod;
  cout << ans;
  return 0;
}
