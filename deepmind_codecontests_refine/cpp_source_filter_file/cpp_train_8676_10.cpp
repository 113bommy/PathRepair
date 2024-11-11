#include <bits/stdc++.h>
using namespace std;
const unsigned _mod = 998244353;
const unsigned mod = 1e9 + 7;
const long long infi = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
long long ksm(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % mod;
    y >>= 1ll;
    x = x * x % mod;
  }
  return ret;
}
long long qpow(long long x, long long y, long long m) {
  long long ret = 1;
  while (y) {
    if (y & 1ll) ret = ret * x % m;
    y >>= 1ll;
    x = x * x % m;
  }
  return ret;
}
long long _gcd(long long x, long long y) { return y ? _gcd(y, x % y) : x; }
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
pair<pair<int, int>, int> a[200010];
long long n, k, c, x, y, m, z, g, t, b, l;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> k >> c >> x >> y >> m, t = 0;
    while (k--) {
      if (g <= 2e5) a[++g] = make_pair(pair<int, int>(t, c), l);
      b = (c * x + y) % m;
      if (b < c && k) t++;
      c = b;
      z = max(z, t);
    }
    l++;
  }
  cout << z << '\n';
  if (g <= 2e5) {
    sort(a, a + g);
    for (register int i = 1; i <= g; ++i)
      cout << a[i].first.second << " " << a[i].second + 1 << '\n';
  }
  return 0;
}
