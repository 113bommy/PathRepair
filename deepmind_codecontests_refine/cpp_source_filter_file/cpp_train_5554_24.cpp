#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int intmax = 0x3f3f3f3f;
const long long lldmax = 0x3f3f3f3f3f3f3f3fll;
double eps = 1e-6;
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
inline int rand(int a, int b) {
  if (a >= b) return a;
  return rand() % (b - a) + a;
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
inline int dblcmp(T a, const T b) {
  a -= b;
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
template <class T>
inline int sgn(T a) {
  return a > eps ? 1 : (a < -eps ? -1 : 0);
}
struct vec2 {
  double x, y;
  vec2(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  vec2 operator+(const vec2 &b) const { return vec2(x + b.x, y + b.y); }
  vec2 operator-(const vec2 &b) const { return vec2(x - b.x, y - b.y); }
  vec2 operator*(const double &b) const { return vec2(x * b, y * b); }
  vec2 operator/(const double &b) const { return vec2(x / b, y / b); }
  double operator*(const vec2 &b) const { return x * b.x + y * b.y; }
  double operator^(const vec2 &b) const { return x * b.y - y * b.x; }
  double len() { return sqrt(x * x + y * y); }
  vec2 unit() { return *this / len(); }
  vec2 rotate(double r) {
    vec2 t(sin(r), cos(r));
    return vec2(*this ^ t, *this * t);
  }
  bool operator<(const vec2 &b) const {
    if (dblcmp(x, b.x) != 0)
      return dblcmp(x, b.x) < 0;
    else
      return dblcmp(y, b.y) < 0;
  }
};
vec2 ps, ss;
double sr, sv, pr, pv;
double maxa, base, maxc;
double angle(vec2 a, vec2 b) { return a * b / a.len() / b.len(); }
double cal(vec2 t) {
  double a = angle(ps, t);
  if (dblcmp(a, maxc) >= 0) {
    return (t - ps).len() / pv;
  } else {
    return (base + (acos(a) - maxa) * pr) / pv;
  }
}
int main() {
  while (scanf("%lf%lf%lf", &ss.x, &ss.y, &sv) != EOF) {
    scanf("%lf%lf%lf%lf", &ps.x, &ps.y, &pv, &pr);
    sr = ss.len();
    maxa = acos(pr / ps.len()) + acos(pr / ss.len());
    maxc = cos(maxa);
    base = sqrt(ps * ps - pr * pr) + sqrt(ss * ss - pr * pr);
    double l = 0, dis = 1e10, m;
    while (dis >= 1e-9) {
      m = l + dis;
      if (cal(ss.rotate(m * sv / sr)) >= m + eps) l += dis;
      dis /= 2;
    }
    printf("%.9lf\n", l);
  }
  return 0;
}
