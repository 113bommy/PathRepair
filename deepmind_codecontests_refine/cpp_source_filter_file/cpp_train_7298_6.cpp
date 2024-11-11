#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
const double PI = acos(-1.0);
const double angcst = PI / 180.0;
const long long mod = 998244353;
long long max_3(long long a, long long b, long long c) {
  if (a > b && a > c) return a;
  if (b > c) return b;
  return c;
}
long long min_3(long long a, long long b, long long c) {
  if (a < b && a < c) return a;
  if (b < c) return b;
  return c;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long qmul(long long a, long long b) {
  long long r = 0;
  while (b) {
    if (b & 1) r = (r + a) % mod;
    b >>= 1;
    a = (a + a) % mod;
  }
  return r;
}
long long qpow(long long a, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % mod;
    n >>= 1;
    a = (a * a) % mod;
  }
  return r;
}
long long qpow(long long a, long long n, long long p) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % p;
    n >>= 1;
    a = (a * a) % p;
  }
  return r;
}
struct point {
  double x, y;
} p[100050];
int n;
bool check(double y) {
  double l = -1e10, r = 1e10, tmp;
  for (int i = 1; i <= n; i++) {
    tmp = sqrt((2 * y - p[i].y) * p[i].y);
    l = max(l, p[i].x - tmp);
    r = min(r, p[i].x + tmp);
  }
  return r >= l;
}
void solve() {
  int aa[2] = {0};
  cin >> n;
  double mxy = 0;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
    if (p[i].y > 0)
      aa[0]++;
    else
      aa[1]++, p[i].y = -p[i].y;
    mxy = max(mxy, p[i].y);
  }
  if (aa[0] && aa[1]) {
    cout << "-1\n";
    return;
  }
  double l = mxy / 2.0, r = 1e14, mid;
  for (int i = 1; i <= 444; i++) {
    mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << setprecision(6) << r << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  { solve(); }
  return 0;
}
