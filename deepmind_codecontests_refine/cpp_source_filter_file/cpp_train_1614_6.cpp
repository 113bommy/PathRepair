#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
int a, b, c, le;
long long cal(long long x, long long y, long long z) {
  long long maxx = x + y + z + le;
  long long res = 0;
  for (long long thr = x; thr <= x + le; thr++) {
    if (y + z > thr) continue;
    long long surplus = min(thr, maxx - thr) - b - c;
    res += (surplus + 2) * (surplus + 1) / 2;
  }
  return res;
}
void solve() {
  cin >> a >> b >> c >> le;
  long long sum = 1LL * (le + 3) * (le + 2) * (le + 1) / 6;
  sum -= cal(a, b, c);
  sum -= cal(b, c, a);
  sum -= cal(c, a, b);
  cout << sum << endl;
}
int main() {
  solve();
  return 0;
}
