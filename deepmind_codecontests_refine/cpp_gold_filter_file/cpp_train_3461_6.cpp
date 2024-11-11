#include <bits/stdc++.h>
using namespace std;
inline bool read(long long &num) {
  char in;
  bool IsN = false;
  in = getchar();
  if (in == EOF) return false;
  while (in != '-' && (in < '0' || in > '9')) in = getchar();
  if (in == '-') {
    IsN = true;
    num = 0;
  } else
    num = in - '0';
  while (in = getchar(), in >= '0' && in <= '9') {
    num *= 10, num += in - '0';
  }
  if (IsN) num = -num;
  return true;
};
const long long INF = 5e18 + 7;
const long long mod = 998244353;
const long long maxx = 1e6 + 70;
const double eps = 1e-9;
const double pi = acos(-1);
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
};
long long num[maxx];
vector<long long> v[maxx];
long long n, m, l, r;
long long a[maxx];
long long fac[maxx];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return fac[n] * a[n - m] % mod * a[m] % mod;
}
int main() {
  long long i, j, k;
  long long id, x, y, p, q, z, t;
  long long l1, l2, r1, r2;
  a[0] = 1;
  a[1] = 1;
  fac[0] = 1;
  fac[1] = 1;
  for (long long i = 2; i <= maxx - 1; i++) {
    fac[i] = fac[i - 1] * i % mod;
    a[i] = a[i - 1] * qpow(i, mod - 2) % mod;
  }
  cin >> n >> k;
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + C(n / i - 1, k - 1)) % mod;
  cout << ans << endl;
  return 0;
}
