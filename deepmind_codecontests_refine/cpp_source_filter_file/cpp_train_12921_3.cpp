#include <bits/stdc++.h>
using namespace std;
bool Dbg;
const int mod = 998244353, MAXN = 1e5 + 7, inft = 1e9 + 7;
const long long infl = 1e18 + 1;
const long double eps = 1e-7;
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
inline T abs(T x) {
  return x >= 0 ? x : -x;
}
template <typename A, typename B>
inline A max(A a, B b) {
  return a > b ? a : b;
}
template <typename A, typename B>
inline A min(A a, B b) {
  return a < b ? a : b;
}
template <typename A, typename B>
inline void chmax(A &x, B y) {
  if (x < y) x = y;
}
template <typename A, typename B>
inline void chmin(A &x, B y) {
  if (x > y) x = y;
}
template <typename A, typename B>
inline void amod(A &x, B y) {
  x += y;
  if (x >= mod) x -= mod;
}
template <typename A, typename B>
inline A gcd(A a, B b) {
  if (a < b) swap(a, b);
  if (!b) return a;
  while (A t = a % b) a = b, b = t;
  return b;
}
template <typename A, typename B>
inline A lcm(A a, B b) {
  return a / gcd(a, b) * b;
}
template <typename A, typename B>
inline A Pow(A a, B b, int mod) {
  A ret;
  for (ret = 1; b; b >>= 1) {
    if (b & 1) ret = ret * 1ll * a % mod;
    a = a * 1ll * a % mod;
  }
  return ret % mod;
}
struct IO {
  struct Cg {
    inline int operator()() { return getchar(); }
  };
  struct Cp {
    inline void operator()(int x) { putchar(x); }
  };
  template <typename T>
  struct Fr {
    int f;
    T P;
    inline Fr &operator,(int &x) {
      x = 0;
      int t = P();
      while ((t < '0' || t > '9') && t != '-') t = P();
      f = 1;
      if (t == '-') t = P(), f = -1;
      x = t - '0';
      for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
      x *= f;
      return *this;
    }
    inline operator int() {
      int x;
      *this, x;
      return x;
    }
    inline Fr &operator,(long long &x) {
      x = 0;
      int t = P();
      while ((t < '0' || t > '9') && t != '-') t = P();
      f = 1;
      if (t == '-') t = P(), f = -1;
      x = t - '0';
      for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
      x *= f;
      return *this;
    }
    inline operator long long() {
      long long x;
      *this, x;
      return x;
    }
    inline Fr &operator,(char &x) {
      for (x = P(); (x == 10 || x == 13 || x == ' '); x = P())
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
      for (; (t == 10 || t == 13 || t == ' '); t = P())
        ;
      if (~t) {
        for (; !(t == 10 || t == 13 || t == ' ') && ~t; t = P()) *x++ = t;
      }
      *x++ = 0;
      return *this;
    }
    inline Fr &operator,(double &x) {
      x = 0;
      int t = P();
      while ((t < '0' || t > '9') && t != '-') t = P();
      f = 1;
      if (t == '-') t = P(), f = -1;
      x = t - '0';
      for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
      if (t == '.') {
        double u = 0.1;
        for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1)
          x += u * (t - '0');
      }
      if (f == -1) x = -x;
      ;
      return *this;
    }
    inline operator double() {
      double x;
      *this, x;
      return x;
    }
    inline Fr &operator,(long double &x) {
      x = 0;
      int t = P();
      while ((t < '0' || t > '9') && t != '-') t = P();
      f = 1;
      if (t == '-') t = P(), f = -1;
      x = t - '0';
      for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
      if (t == '.') {
        double u = 0.1;
        for (t = P(); t >= '0' && t <= '9'; t = P(), u *= 0.1)
          x += u * (t - '0');
      }
      if (f == -1) x = -x;
      ;
      return *this;
    }
    inline operator long double() {
      long double x;
      *this, x;
      return x;
    }
    inline Fr &operator,(unsigned int &x) {
      x = 0;
      int t = P();
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
      int t = P();
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
    int c, s[24];
    T P;
    inline Fw &operator,(int x) {
      if (x) {
        if (x < 0) P('-'), x = -x;
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator()(int x) {
      if (x) {
        if (x < 0) P('-'), x = -x;
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator,(unsigned int x) {
      if (x) {
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator()(unsigned int x) {
      if (x) {
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator,(long long x) {
      if (x) {
        if (x < 0) P('-'), x = -x;
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator()(long long x) {
      if (x) {
        if (x < 0) P('-'), x = -x;
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator,(unsigned long long x) {
      if (x) {
        c = 0;
        while (x) s[c++] = x % 10 + '0', x /= 10;
        while (c--) P(s[c]);
      } else
        P('0');
      return *this;
    }
    inline Fw &operator()(unsigned long long x) {
      if (x) {
        c = 0;
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
} io;
int a[MAXN << 1];
int n, x, s = 1;
bitset<MAXN * 2> f;
int main() {
  io.in, n;
  for (int i = (1), iend = (n); i <= iend; ++i) io.in, a[i];
  for (int i = (1), iend = (n); i <= iend; ++i) {
    int ANSS = 0;
    io.in, x;
    if (!f[x]) {
      while (a[s] ^ x) f[a[s]] = 1, ++ANSS, ++s;
      ++ANSS, f[x] = 1, ++s;
    }
    io.out, ANSS;
  }
  return 0;
}
