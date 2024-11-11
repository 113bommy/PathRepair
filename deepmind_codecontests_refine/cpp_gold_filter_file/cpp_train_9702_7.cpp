#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int intmax = 0x3f3f3f3f;
double eps = 1e-8;
template <class T>
inline void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void checkmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T lowbit(T n) {
  return (n ^ (n - 1)) & n;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
template <class T>
inline T checkmod(T n, T m) {
  return (n % m + m) % m;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <class T>
inline T euclid(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclid(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclid(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclid(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <class T>
inline vector<pair<T, int> > factorize(T n) {
  vector<pair<T, int> > R;
  for (T i = 2; n > 1;) {
    if (n % i == 0) {
      int C = 0;
      for (; n % i == 0; C++, n /= i)
        ;
      R.push_back(make_pair(i, C));
    }
    i++;
    if (i > n / i) i = n;
  }
  if (n > 1) R.push_back(make_pair(n, 1));
  return R;
}
template <class T>
inline bool isPrimeNumber(T n) {
  if (n <= 1) return false;
  for (T i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
template <class T>
inline T eularFunction(T n) {
  vector<pair<T, int> > R = factorize(n);
  T r = n;
  for (int i = 0; i < R.size(); i++) r = r / R[i].first * (R[i].first - 1);
  return r;
}
template <class T>
inline int dblcmp(T a, T b) {
  a -= b;
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
long long mabs(long long a) { return a > 0 ? a : -a; }
int main() {
  long long a, b, x1, x2, y1, y2, add;
  add = 1;
  add <<= 40;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  add = 1;
  add <<= 40;
  add -= add % (2 * a);
  long long d1 = (x1 + y1 + add) / (2 * a) - (x2 + y2 + add) / (2 * a);
  add = 1;
  add <<= 40;
  add -= add % (2 * b);
  long long d2 = (x1 - y1 + add) / (2 * b) - (x2 - y2 + add) / (2 * b);
  long long ans = max(mabs(d1), mabs(d2));
  cout << ans << endl;
  return 0;
}
