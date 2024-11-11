#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T _sq(T a) {
  return a * a;
}
template <class T>
inline T _sqrt(T a) {
  return (T)sqrt((double)a);
}
template <class T, class X>
inline T _pow(T a, X y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= a;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = abs(a);
  b = abs(b);
  T g, x1, y1;
  if (!b) {
    x = 1;
    y = 0;
    g = a;
    return g;
  }
  g = _extended(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class X>
inline T togglebit(T a, X i) {
  T t = 1;
  return (a ^ (t << i));
}
template <class T>
void pv(T v) {
  int vl = v.size();
  for (int i = 0; i <= vl - 1; i++) cout << v[i] << " ";
  cout << endl;
}
template <class T, class X>
inline T _bigmod(T n, X m) {
  unsigned long long ret = 1, a = n % 1000000007;
  while (m) {
    if (m & 1) ret = (ret * a) % 1000000007;
    m >>= 1;
    a = (a * a) % 1000000007;
  }
  ret %= 1000000007;
  return (T)ret;
}
template <class T>
inline T _modinv(T n) {
  return _bigmod(n, 1000000007 - 2);
}
int n, a[(50 + 3)], p, v;
double fac[(50 + 3)], dp[(50 + 3)][(50 + 3)][(50 + 3)];
void precal() {
  fac[0] = 1.0;
  for (int i = 1; i <= 50; i++) fac[i] = fac[i - 1] * (double)i;
}
double func(int pos, int sum, int taken, int gt) {
  if (sum < 0) return 0.0;
  if (pos == n) {
    if (sum) return 0.0;
    return 1.0 / fac[n] * fac[taken] * fac[n - taken - 1] * (double)taken;
  }
  double &ret = dp[pos][sum][taken];
  if (ret == ret) return ret;
  ret = 0.0;
  ret += func(pos + 1, sum, taken, gt);
  if (pos != gt) ret += func(pos + 1, sum - a[pos], taken + 1, gt);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  precal();
  cin >> n;
  int tot = 0.0;
  for (int i = 0; i <= n - 1; i++) cin >> a[i], tot += a[i];
  cin >> p;
  double ans = 0.0;
  if (tot <= p) {
    ans = n;
  } else
    for (int i = 1; i <= p; i++) {
      for (int j = 0; j <= n - 1; j++) {
        if (i + a[j] > p) {
          memset(dp, -1, sizeof dp);
          ans += func(0, i, 0, j);
        }
      }
    }
  printf("%.8lf\n", ans);
  return 0;
}
