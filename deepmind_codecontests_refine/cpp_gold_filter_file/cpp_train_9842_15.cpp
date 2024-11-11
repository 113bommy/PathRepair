#include <bits/stdc++.h>
using namespace std;
inline int sqr(int x) { return x * x; }
inline int cube(int x) { return x * x * x; }
inline long long sqrLL(long long x) { return x * x; }
inline long long cubeLL(long long x) { return x * x * x; }
const long long LLINF = 9223372036854775807LL;
const long long LLINF17 = 100000000000000000LL;
const int INF = 2147483647;
const int INF9 = 1000000000;
const long long MOD = 1000000007;
const double eps = 1e-7;
const double PI = acos(-1.0);
template <typename T>
void check(T &a, const T &b) {
  if (a >= b) {
    a %= b;
  }
}
template <typename T>
void read(T &x) {
  register T c = getchar_unlocked();
  x = 0;
  int t = 0;
  if (c == '-') t = 1, c = getchar_unlocked();
  for (; (c < 48 || c > 57); c = getchar_unlocked())
    ;
  for (; c > 47 && c < 58; c = getchar_unlocked()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (t) x = -x;
}
template <typename T>
T gcd(T u, T v) {
  if (u == v) return u;
  if (u == 0) return v;
  if (v == 0) return u;
  if (~u & 1) {
    if (v & 1)
      return gcd(u >> 1, v);
    else
      return gcd(u >> 1, v >> 1) << 1;
  }
  if (~v & 1) return gcd(u, v >> 1);
  if (u > v) return gcd((u - v) >> 1, v);
  return gcd((v - u) >> 1, u);
}
template <typename T>
T mod(T x, T m) {
  if (x >= m)
    return x % m;
  else
    return x;
}
long long mulmod(long long a, long long b, long long m) {
  long long q = (long long)(((long double)a * (long double)b) / (long double)m);
  long long r = a * b - q * m;
  if (r > m) r %= m;
  if (r < 0) r += m;
  return r;
}
template <typename T, typename S>
T expo(T e, S n) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = x * p;
    p = p * p;
    n >>= 1;
  }
  return x;
}
template <typename T>
T power(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mod(x * p, m);
    p = mod(p * p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T powerL(T e, T n, T m) {
  T x = 1, p = e;
  while (n) {
    if (n & 1) x = mulmod(x, p, m);
    p = mulmod(p, p, m);
    n >>= 1;
  }
  return x;
}
template <typename T>
T InverseEuler(T a, T m) {
  return (a == 1 ? 1 : powerL(a, m - 2, m));
}
map<int, int> m;
int main() {
  double d, h, v, e;
  cin >> d >> h >> v >> e;
  d /= 2;
  double pi = PI;
  double area = pi * d * d;
  double ans = v / area;
  ans -= e;
  if (ans <= 0) {
    cout << "NO";
  } else {
    if ((double(h) / ans) > 10000)
      cout << "NO";
    else {
      cout << "YES" << endl;
      printf("%.9f", (double(h) / ans));
    }
  }
  return 0;
}
