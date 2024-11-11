#include <bits/stdc++.h>
using namespace std;
const int inf = ~0u >> 1, mo = 1e9 + 7;
template <typename T>
inline void admo(int &a, const T &b) {
  a = (a + b >= mo ? a + b - mo : a + b);
}
template <typename T>
inline void sumo(int &a, const T &b) {
  a = (a - b < 0 ? a - b + mo : a - b);
}
template <typename T, typename S>
inline bool upmx(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmn(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T gcd(T a, T b) {
  while (b) a %= b, swap(a, b);
  return a;
}
inline int Pow(int a, int b, int p = mo) {
  int r = 1;
  for (; b; b >>= 1, a = 1ll * a * a % p)
    if (b & 1) r = 1ll * r * a % p;
  return r;
}
struct Cg {
  inline char operator()() { return getchar(); }
};
struct Cp {
  inline void operator()(char x) { putchar(x); }
};
inline bool IS(char x) { return x == 10 || x == 13 || x == ' '; }
template <typename T>
struct Fr {
  T P;
  inline Fr &operator,(int &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  inline operator int() {
    int x;
    *this, x;
    return x;
  }
  inline Fr &operator,(long long &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  inline operator long long() {
    long long x;
    *this, x;
    return x;
  }
  inline Fr &operator,(char &x) {
    for (x = P(); IS(x); x = P())
      ;
    return *this;
  }
  inline operator char() {
    char x;
    *this, x;
    return x;
  }
  inline Fr &operator,(char *x) {
    char t = P();
    for (; IS(t); t = P())
      ;
    if (~t) {
      for (; !IS(t) && ~t; t = P()) *x++ = t;
    }
    *x++ = 0;
    return *this;
  }
  inline Fr &operator,(double &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  inline operator double() {
    double x;
    *this, x;
    return x;
  }
  inline Fr &operator,(long double &x) {
    x = 0;
    char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (t == '.') {
      double u = 0.1;
      for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1) x += u * (t - '0');
    }
    if (f) x = -x;
    return *this;
  }
  inline operator long double() {
    long double x;
    *this, x;
    return x;
  }
  inline Fr &operator,(unsigned int &x) {
    x = 0;
    char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  inline operator unsigned int() {
    unsigned int x;
    *this, x;
    return x;
  }
  inline Fr &operator,(unsigned long long &x) {
    x = 0;
    char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  inline operator unsigned long long() {
    unsigned long long x;
    *this, x;
    return x;
  }
};
Fr<Cg> in;
template <typename T>
struct Fw {
  T P;
  inline Fw &operator,(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned int x) {
    if (x) {
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(unsigned int x) {
    if (x) {
      char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(unsigned long long x) {
    if (x) {
      char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator()(unsigned long long x) {
    if (x) {
      char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  inline Fw &operator,(char x) {
    P(x);
    return *this;
  }
  inline Fw &operator()(char x) {
    P(x);
    return *this;
  }
  inline Fw &operator,(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  inline Fw &operator()(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  inline Fw &operator()(double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
  inline Fw &operator()(long double x, int y) {
    if (y) {
      double t = 0.5;
      for (int i = y; i--;) t *= 0.1;
      if (x >= 0)
        x += t;
      else
        x -= t, P('-');
      *this, (long long)(abs(x));
      P('.');
      if (x < 0) x = -x;
      while (y--) {
        x *= 10;
        x -= floor(x * 0.1) * 10;
        P(((int)x) % 10 + '0');
      }
    } else if (x >= 0)
      *this, (long long)(x + 0.5);
    else
      *this, (long long)(x - 0.5);
    ;
    return *this;
  }
};
Fw<Cp> out;
void NO() {
  puts("No");
  exit(0);
}
struct P {
  int x, y;
  P(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  P operator-(const P &t) const { return P(x - t.x, y - t.y); }
  void read() { in, x, y; }
};
const int N = 12;
P a[N], b[N];
int n, m, d[N];
long long C(P a, P b) { return a.x * b.y - a.y * b.x; }
bool isc(P a, P b, P c, P d) {
  return C(b - a, c - a) * C(b - a, d - a) <= 0 &&
         C(d - c, b - c) * C(d - c, a - c) <= 0;
}
int main() {
  in, n, m;
  if (n != m) NO();
  for (int i = (1), i_end = (n); i <= i_end; ++i) a[i].read();
  for (int i = (1), i_end = (n); i <= i_end; ++i) b[i].read();
  for (int i = (1), i_end = (n); i <= i_end; ++i) d[i] = i;
  do {
    int fl = 1;
    for (int i = (1), i_end = (n); i <= i_end; ++i) {
      int u = d[i];
      for (int j = (i + 1), j_end = (n); j <= j_end; ++j) {
        int v = d[j];
        if (isc(a[i], b[u], a[j], b[v])) {
          fl = 0;
          break;
        }
      }
      if (!fl) break;
    }
    if (fl) {
      out, "Yes\n";
      return 0;
    }
  } while (next_permutation(d + 1, d + n + 1));
  NO();
}
