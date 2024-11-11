#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long ext_gcd(long long A, long long B, long long* X, long long* Y) {
  long long x2, y2, x1, y1, x, y, r2, r1, q, r;
  x2 = 1;
  y2 = 0;
  x1 = 0;
  y1 = 1;
  for (r2 = A, r1 = B; r1 != 0;
       r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y) {
    q = r2 / r1;
    r = r2 % r1;
    x = x2 - (q * x1);
    y = y2 - (q * y1);
  }
  *X = x2;
  *Y = y2;
  return r2;
}
inline long long modInv(long long a, long long m) {
  long long x, y;
  ext_gcd(a, m, &x, &y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
const long long inf = 2147383647;
const long long mod = 1000000007;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
int n, t, m;
pair<int, int> ar[100005];
bool f(double x) {
  double sum = 0.0;
  for (int i = 1; i <= n; i++) {
    double tmp = (x * ar[i].first - (double)ar[i].second) / (double)m;
    tmp = max(tmp, 0.0);
    sum += tmp;
  }
  if (sum < x) return true;
  if (((sum - x) + eps < 0 ? -(sum - x) : (sum - x)) < eps) return true;
  return false;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i].first);
    scanf("%d", &ar[i].second);
  }
  double lf = 0.0, ri = 1e10, md;
  double mark = ri, ans;
  for (int i = 1; i <= 500; i++) {
    md = (lf + ri) / 2;
    if (f(md)) {
      ans = md;
      lf = md;
    } else
      ri = md;
  }
  if (((ans - mark) + eps < 0 ? -(ans - mark) : (ans - mark)) < eps)
    cout << -1 << "\n";
  else
    printf("%lf\n", ans);
  return 0;
}
