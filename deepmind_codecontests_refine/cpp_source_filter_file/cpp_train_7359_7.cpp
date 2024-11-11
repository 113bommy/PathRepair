#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 1e9 + 7;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b, mo) % mo;
}
const int maxn = 1e6 + 5;
const double PI = acos(-1);
long double a, b, l;
long double eps = 1e-9;
long double gt(long double x) {
  long double y = sqrtl(l * l - x * x);
  if (x > b && (a * x <= y * (x - b))) return -1;
  long double eb = hypotl(a, b - x);
  long double ea = hypotl(a - y, b);
  long double second = (l + ea + eb) / 2;
  long double area =
      sqrtl(second * (second - eb) * (second - ea) * (second - l));
  long double h = area * 2 / l;
  return h;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> a >> b >> l;
  long double re = 0;
  if (l <= a) {
    re = min(b, l);
  }
  if (l <= b) {
    re = max(re, min(a, l));
  }
  if (re) {
    cout << re << '\n';
    return 0;
  }
  long double L = 0 + 0.00001, R = l - 0.00001;
  for (int jo = 0; jo < 400; ++jo) {
    long double mid = (L + R) / 2;
    long double tmp1 = gt((R - L) / 3 + L), tmp2 = gt((L) + (R - L) / 3 * 2);
    if (tmp1 == -1 || tmp2 == -1) {
      cout << "My poor head =(" << '\n';
      return 0;
    }
    if (tmp1 > tmp2) {
      L = (R - L) / 3 + L;
    } else {
      R = (L) + (R - L) / 3 * 2;
    }
  }
  cout << fixed << setprecision(10) << min({l, gt(L)}) << '\n';
}
