#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline void ina(_T a[], int n) {
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
}
template <class _T>
inline void outa(_T a[], int n) {
  int i;
  for (i = 0; i < n - 1; i++) cout << a[i], cout << " ";
  if (i) printf("%d", i);
  cout << "\n";
}
const double EPS = 1e-9;
const int SIZE = 1e6;
template <class _T>
inline _T pow(_T a, _T b, _T m) {
  a %= m;
  _T ans = 1 % m;
  while (b) {
    if (b & 1) ans *= a, ans %= m;
    a *= a;
    a %= m;
    b >>= 1;
  }
  return ans;
}
template <class _T>
inline _T pow(_T a, _T b) {
  _T ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}
template <class _T>
inline _T add(_T a, _T b, _T m) {
  return a >= m - b ? a - (m - b) : a + b;
}
template <class _T>
inline _T multiply(_T a, _T b, _T m) {
  _T ans = 0;
  if (b > a) swap(a, b);
  while (b) {
    if (b & 1) ans = add(ans, a, m);
    b >>= 1;
    a = add(a, a, m);
  }
  return ans;
}
template <class _T>
inline _T bigpow(_T a, _T b, _T m) {
  a %= m;
  _T ans = 1 % m;
  while (b) {
    if (b & 1) ans = multiply(ans, a, m);
    a = multiply(a, a, m);
    b >>= 1;
  }
  return ans;
}
template <class _T>
inline _T modinvers(_T a, _T m) {
  return m > 2000000000LL ? bigpow(a, m - 2, m) : pow(a, m - 2, m);
}
template <class _T>
_T _egcd(_T a, _T b, _T &x, _T &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  _T _g = _egcd(b, a % b, x, y);
  _T xt = x;
  x = y, y = xt - (a / b) * y;
  return _g;
}
template <class _T>
inline _T fmodinvers(_T a, _T m) {
  _T x, y;
  _egcd(a, m, x, y);
  x %= m;
  if (x < 0) x += m;
  return x;
}
template <class _T>
inline _T _lcm(_T a, _T b) {
  return (a * b) / __gcd(a, b);
}
template <class _T>
inline _T naturalSum(_T n) {
  return (n * (n + 1)) / 2;
}
template <class _T>
inline _T sqrSum(_T n) {
  return (n * (n + 1) * (2 * n + 1)) / 6;
}
template <class _T>
inline _T cubeSum(_T n) {
  return (((n * (n + 1)) / 2) * ((n * (n + 1)) / 2));
}
template <class _T>
inline _T naturalSum(_T n, _T m) {
  return ((n * (n + 1)) / 2) % m;
}
long long MOD_INV_OF_6;
template <class _T>
inline _T sqrSum(_T n, _T m) {
  n %= m;
  return (((((n * (n + 1)) % m) * (((2 * n) % m + 1) % m)) % m) *
          MOD_INV_OF_6) %
         m;
}
template <class _T>
inline _T cubeSum(_T n, _T m) {
  return ((((n * (n + 1)) / 2) % m) * (((n * (n + 1)) / 2) % m)) % m;
}
int main() {
  long n, i;
  cin >> n;
  if (n & 1)
    printf("1");
  else
    printf("2");
  return 0;
}
