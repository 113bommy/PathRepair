#include <bits/stdc++.h>
using namespace std;
template <class T>
T Mul(T x, T y, T P) {
  T F1 = 0;
  while (y) {
    if (y & 1) {
      F1 += x;
      if (F1 < 0 || F1 >= P) F1 -= P;
    }
    x <<= 1;
    if (x < 0 || x >= P) x -= P;
    y >>= 1;
  }
  return F1;
}
template <class T>
T Pow(T x, T y, T P) {
  T F1 = 1;
  x %= P;
  while (y) {
    if (y & 1) {
      F1 = Mul(F1, x, P);
    }
    x = Mul(x, x, P);
    y >>= 1;
  }
  return F1;
}
template <class T>
T Gcd(T x, T y) {
  if (y == 0) return x;
  T z;
  while (z = x % y) {
    x = y, y = z;
  }
  return y;
}
template <class T>
void UpdateMin(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdateMax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
template <class T>
T Sqr(const T x) {
  return x * x;
}
template <class T>
T Abs(const T x) {
  return x < 0 ? -x : x;
}
class ReadBuffer {
 private:
  char buff[20000000];
  char *buf;

 public:
  void init(int size = 20000000) {
    fread(buff, 1, size, stdin);
    buf = buff;
  }
  template <class T>
  bool readInteger(T &x) {
    x = 0;
    while (*buf && isspace(*buf)) ++buf;
    if (*buf == 0) return false;
    static bool flag;
    flag = 0;
    if (*buf == '-')
      flag = true;
    else
      x = *buf - '0';
    while (isdigit(*++buf)) x = x * 10 + *buf - '0';
    if (flag) x = -x;
    return true;
  }
  template <class T>
  bool readFloat(T &x) {
    long double nowpos = 0.1;
    x = 0;
    while (*buf && isspace(*buf)) ++buf;
    if (*buf == 0) return false;
    static bool flag, decimal;
    decimal = flag = 0;
    if (*buf == '-')
      flag = true, ++buf;
    else if (*buf == '.')
      decimal = true;
    while (isdigit(*buf) || *buf == '.') {
      if (*buf == '.')
        decimal = true;
      else {
        if (decimal) {
          x += nowpos * (*buf - '0');
          nowpos *= 0.1;
        } else {
          x = x * 10 + *buf - '0';
        }
      }
      ++buf;
    }
    return true;
  }
  bool readChar(char c) {
    if (*buf == 0) return 0;
    return c = *buf++, 1;
  }
  bool readString(char *s) {
    while (*buf && isspace(*buf)) ++buf;
    if (!*buf) return false;
    while (!isspace(*buf)) *s++ = *buf++;
    *s++ = 0;
    return true;
  }
  int countSpacetonext() {
    int total = 0;
    while (*buf && *buf == ' ') ++total, ++buf;
    return total;
  }
  bool splitBycharactor(char *s, char Split = '\n') {
    while (*buf && *buf != Split) *s++ = *buf++;
    *s++ = 0;
    return *buf != 0;
  }
};
struct EDGE {
  int T;
  EDGE *Nxt;
};
struct point {
  long double x, y;
  point() {}
  point(long double x, long double y) : x(x), y(y) {}
  point operator+(const point &a) const { return point(x + a.x, y + a.y); }
  point operator-(const point &a) const { return point(x - a.x, y - a.y); }
  long double getAngle() const { return atan2(y, x); }
};
struct Line {
  int a, b, c;
  long double angle;
  void read() {
    scanf("%d%d%d", &a, &b, &c);
    angle = point(-b, a).getAngle();
  }
  bool onOri() const { return c == 0; }
  point getIntersect(const Line that) const {
    long double fa = c * that.b - that.c * b;
    long double fb = a * that.c - that.a * c;
    long double fc = a * that.b - that.a * b;
    return point(fa / fc, fb / fc);
  }
  point getVec() const { return point(a, b); }
  point getDir() const { return point(-b, a); }
} L[2001];
inline long double Dot(const point &a, const point &b) {
  return a.x * b.x + a.y * b.y;
}
inline int Sign(const long double &x) { return x < 0 ? -1 : x > 0; }
int n;
const long double EPS = 1e-12;
inline long double repair(long double x, const long double eps = EPS) {
  while (x < eps) x += 3.1415926535897932384626433832795;
  while (x >= 3.1415926535897932384626433832795 - eps)
    x -= 3.1415926535897932384626433832795;
  return x;
}
int main() {
  point O(0, 0);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    L[i].read();
  }
  long long ans = 0;
  for (int i = 1; i <= (n); ++i) {
    if (L[i].onOri()) {
      for (int j = 1; j <= (n); ++j)
        if (j != i) {
          if (L[j].onOri()) {
            ans += n - 2;
          }
        }
    } else {
      vector<long double> Angles;
      for (int j = 1; j <= (n); ++j)
        if (j != i) {
          point I = L[i].getIntersect(L[j]);
          Angles.push_back(repair(L[j].angle - (O - I).getAngle()));
        }
      sort(Angles.begin(), Angles.end());
      int cnt = 0;
      const long double eps = EPS;
      for (int i = 0; i < (int(Angles.size())); ++i) {
        if (i == 0 || Angles[i - 1] + eps >= Angles[i]) {
          ++cnt;
        } else {
          ans += cnt * (cnt - 1) / 2;
          cnt = 1;
        }
      }
      ans += cnt * (cnt - 1) / 2;
    }
  }
  cout << ans / 3 << endl;
  return 0;
}
