#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int intmax = 0x3f3f3f3f;
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
const int N = 130, M = 7;
const long long P = 1000000007;
int cnt[N];
int n, m, t;
int mod[N * 3];
struct BIT {
  unsigned long long a[2];
};
int len, l;
unsigned long long temp;
BIT move(const BIT &a, int i) {
  BIT ans;
  if (i < 0) i += m;
  if (m <= 64) {
    ans.a[0] = a.a[0] >> i;
    ans.a[0] |= ((a.a[0]) & (((long long)1 << (i)) - 1)) << (m - i);
  } else {
    if (i <= m - 64) {
      ans.a[0] = a.a[0] >> i;
      ans.a[1] = a.a[1] >> i;
      ans.a[0] |= ((a.a[1]) & (((long long)1 << (i)) - 1)) << (64 - i);
      ans.a[1] |= ((a.a[0]) & (((long long)1 << (i)) - 1)) << (m - 64 - i);
    } else if (i >= 64) {
      i = m - i;
      ans.a[0] = a.a[0] << i;
      ans.a[1] = ((a.a[1] << i) & (((long long)1 << (m - 64)) - 1));
      ans.a[0] |= a.a[1] >> (m - 64 - i);
      ans.a[1] |= a.a[0] >> (m - 64);
    } else {
      temp = ((a.a[0]) & (((long long)1 << (i)) - 1));
      ans.a[0] = a.a[0] >> i;
      ans.a[0] |= a.a[1] << (64 - i);
      ans.a[1] = temp >> (i - m + 64);
      ans.a[0] |= ((temp) & (((long long)1 << (i - m + 64)) - 1))
                  << (64 - i + (m - 64));
    }
  }
  return ans;
}
void huo(BIT &a, const BIT &b) {
  a.a[0] |= b.a[0];
  a.a[1] |= b.a[1];
}
void print(int deep) {
  while (deep--) {
    printf("  ");
  }
}
BIT table[M];
long long gao(int deep, int begin, long long way) {
  long long ans = 1, temp;
  if (deep < 7) {
    for (int i = begin; i < m; ++i) {
      if (cnt[i] == 0 || (table[deep].a[0] & ((long long)1 << (i)))) continue;
      table[deep + 1].a[0] = table[deep].a[0];
      table[deep + 1].a[1] = table[deep].a[1];
      huo(table[deep + 1], move(table[deep], i));
      huo(table[deep + 1], move(table[deep], -i));
      temp = gao(deep + 1, i + 1, cnt[i]);
      ans += temp;
    }
  }
  ans %= P;
  return ans * way % P;
}
void print(BIT d) { printf("%llx %llx\n", d.a[0], d.a[1]); }
int main() {
  while (scanf("%d%d%d", &n, &m, &t) != EOF) {
    memset(cnt, 0, sizeof(cnt));
    int a;
    for (int i = 0; i < t; ++i) {
      scanf("%d", &a);
      a %= m;
      cnt[min(a, m - a)]++;
    }
    table[0].a[0] = 1;
    table[0].a[1] = 0;
    cout << gao(0, 0, 1) << endl;
  }
  return 0;
}
