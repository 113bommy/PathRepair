#include <bits/stdc++.h>
using namespace std;
const int seed = 131;
const long long LLMAX = 2e18;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 1e6 + 10;
const int hmod1 = 0x48E2DCE7;
const int hmod2 = 0x60000005;
inline long long sqr(long long x) { return x * x; }
inline int sqr(int x) { return x * x; }
inline double sqr(double x) { return x * x; }
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long d;
  (b == 0 ? (x = 1, y = 0, d = a)
          : (d = exgcd(b, a % b, y, x), y -= a / b * x));
  return d;
}
long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return sum;
}
inline int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return (x > 0 ? 1 : -1);
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long r, b, k;
    cin >> r >> b >> k;
    if (r > b) swap(r, b);
    if (b / r <= k && (b - gcd(r, b)) / r + 1 < k)
      cout << "OBEY" << endl;
    else
      cout << "REBEL" << endl;
  }
  return 0;
}
