#include <bits/stdc++.h>
using namespace std;
long double PI = 3.14159265359;
long double DEL = 1e-10;
int mod = 1000000007;
long long fpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void sieve(long long n) {
  bool prime[1000006];
  memset(prime, true, sizeof(prime));
  long long rootn = (long long)sqrt(n);
  for (long long p = 2; p <= rootn; p++)
    if (prime[p] == true)
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
  prime[1] = 0;
}
const long long N = 300050;
long long cnt, sum, mid, mx, mn, ans, a[N], b[N];
long long n, m, d, i, j, k, l, p, q, r, t, w, x, y, z;
bool f, f1, f2;
string s;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  for (long long tt = 1; tt <= t; ++tt) {
    cin >> n;
    cout << n;
    cout << "\n";
    for (long long i = n; i > 0; i--) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
