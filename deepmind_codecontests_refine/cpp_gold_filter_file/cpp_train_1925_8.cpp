#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool In(T &a) {
  return (bool)(cin >> a);
}
template <class T1, class T2>
inline bool In(T1 &a, T2 &b) {
  return (bool)(cin >> a >> b);
}
template <class T1, class T2, class T3>
inline bool In(T1 &a, T2 &b, T3 &c) {
  return (bool)(cin >> a >> b >> c);
}
template <class T1, class T2, class T3, class T4>
inline bool In(T1 &a, T2 &b, T3 &c, T4 &d) {
  return (bool)(cin >> a >> b >> c >> d);
}
inline bool Line(string &a) { return (bool)(getline(cin, a)); }
template <class _T>
inline void ina(_T a[], int n) {
  int i;
  for (int i = 0; i < n; i++) In(a[i]);
}
template <class T>
inline bool Pr(T a) {
  return (bool)(cout << a);
}
template <class T1, class T2>
inline bool Pr(T1 a, T2 b) {
  return (bool)(cout << a << " " << b);
}
template <class T1, class T2, class T3>
inline bool Pr(T1 a, T2 b, T3 c) {
  return (bool)(cout << a << " " << b << " " << c);
}
template <class T1, class T2, class T3, class T4>
inline bool Pr(T1 a, T2 b, T3 c, T4 d) {
  return (bool)(cout << a << " " << b << " " << c << " " << d);
}
template <class T>
inline void Cr(T a) {
  cerr << a << endl;
}
template <class T1, class T2>
inline void Cr(T1 a, T2 b) {
  cerr << a << " " << b << endl;
}
int TEST_CASE = 0;
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
template <class T>
inline T SQ(T a) {
  return a * a;
}
template <class T>
inline string int2String(T a) {
  ostringstream str;
  str << a;
  return str.str();
}
long long SQRT(long long n) {
  long long e = sqrt(n * 1.0);
  long long l = max(0LL, e - 2), r = min(n, e + 2);
  long long ans = 0;
  while (l <= r) {
    long long m = ((l + r) >> 1);
    if (m * m <= n)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  return ans;
}
long long CBRT(long long n) {
  long long e = cbrt(n * 1.0);
  long long l = max(0LL, e - 2), r = min(n, e + 2);
  long long ans = 0;
  while (l <= r) {
    long long m = ((l + r) >> 1);
    if (m * m * m <= n)
      ans = m, l = m + 1;
    else
      r = m - 1;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  vector<pair<int, int> > res;
  for (int i = 1; i <= n; i++) {
    int p1, p2;
    for (int j = i; j <= n; j++) {
      if (a[i] == b[j]) {
        p1 = i;
        p2 = j;
        while (p2 > p1) {
          swap(b[p2], b[p2 - 1]);
          res.push_back(make_pair(p2 - 1, p2));
          p2--;
        }
        break;
      }
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    cout << res[i].first << " " << res[i].second << endl;
  return 0;
}
