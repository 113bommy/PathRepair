#include <bits/stdc++.h>
using namespace std;
int ts, kk = 1, _DB = 1;
inline int LEN(string a) { return a.length(); }
inline int LEN(char a[]) { return strlen(a); }
template <class T>
inline T _abs(T n) {
  return (n < 0 ? -n : n);
}
template <class T>
inline T _max(T a, T b) {
  return (a > b ? a : b);
}
template <class T>
inline T _min(T a, T b) {
  return (a < b ? a : b);
}
template <class T>
inline T _sq(T x) {
  return x * x;
}
template <class T>
inline T _sqrt(T x) {
  return (T)sqrt((double)x);
}
template <class T>
inline T _pow(T x, T y) {
  T z = 1;
  for (int i = 1; i <= y; i++) {
    z *= x;
  }
  return z;
}
template <class T>
inline T _gcd(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  if (!b) return a;
  return _gcd(b, a % b);
}
template <class T>
inline T _lcm(T a, T b) {
  a = _abs(a);
  b = _abs(b);
  return (a / _gcd(a, b)) * b;
}
template <class T>
inline T _extended(T a, T b, T &x, T &y) {
  a = _abs(a);
  b = _abs(b);
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
template <class T>
inline T getbit(T x, T i) {
  T t = 1;
  return (x & (t << i));
}
template <class T>
inline T setbit(T x, T i) {
  T t = 1;
  return (x | (t << i));
}
template <class T>
inline T resetbit(T x, T i) {
  T t = 1;
  return (x & (~(t << i)));
}
template <class T>
inline T _bigmod(T n, T m) {
  T ans = 1, mult = n % 1000000007;
  while (m) {
    if (m & 1) ans = (ans * mult) % 1000000007;
    m >>= 1;
    mult = (mult * mult) % 1000000007;
  }
  ans %= 1000000007;
  return ans;
}
template <class T>
inline T _modinv(T x) {
  return _bigmod(x, (T)(1000000007 - 2)) % 1000000007;
}
vector<pair<int, int> > vv[2];
int main() {
  int n, col, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> col >> x;
    vv[col].push_back(make_pair(x, i));
  }
  while (!vv[0].empty() && !vv[1].empty()) {
    int mn = _min(vv[0].back().first, vv[1].back().first);
    for (int i = 0; i <= 1; i++)
      cout << vv[i].back().second << " ", vv[i].back().first -= mn;
    cout << mn << endl;
    if (vv[0].back().first < vv[0].back().first ||
        (vv[0].back().first == vv[0].back().first &&
         vv[0].size() > vv[1].size()))
      vv[0].pop_back();
    else
      vv[1].pop_back();
  }
  return 0;
}
