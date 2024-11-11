#include <bits/stdc++.h>
template <typename T>
inline T max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T min(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline bool repr(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T>
inline bool repl(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline T gcd(T a, T b) {
  T t;
  if (a < b) {
    while (a) {
      t = a;
      a = b % a;
      b = t;
    }
    return b;
  } else {
    while (b) {
      t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
struct Cg {
  __attribute__((always_inline)) inline char operator()() { return getchar(); }
};
struct Cp {
  __attribute__((always_inline)) inline void operator()(char x) { putchar(x); }
};
__attribute__((always_inline)) inline bool IS(char x) {
  return x == 10 || x == 13 || x == ' ';
}
template <typename T>
struct Fr {
  T P;
  __attribute__((always_inline)) inline Fr &operator,(int &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator int() {
    int x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(long long &x) {
    x = 0;
    unsigned char t = P();
    while ((t < '0' || t > '9') && t != '-') t = P();
    bool f = 0;
    if (t == '-') t = P(), f = 1;
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    if (f) x = -x;
    return *this;
  }
  __attribute__((always_inline)) inline operator long long() {
    long long x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(char &x) {
    for (x = P(); IS(x); x = P())
      ;
    return *this;
  }
  __attribute__((always_inline)) inline operator char() {
    char x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(char *x) {
    char t = P();
    for (; IS(t); t = P())
      ;
    if (~t) {
      for (; !IS(t) && ~t; t = P()) *x++ = t;
    }
    *x++ = 0;
    return *this;
  }
  __attribute__((always_inline)) inline Fr &operator,(double &x) {
    x = 0;
    unsigned char t = P();
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
  __attribute__((always_inline)) inline operator double() {
    double x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(long double &x) {
    x = 0;
    unsigned char t = P();
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
  __attribute__((always_inline)) inline operator long double() {
    long double x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(unsigned int &x) {
    x = 0;
    unsigned char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  __attribute__((always_inline)) inline operator unsigned int() {
    unsigned int x;
    *this, x;
    return x;
  }
  __attribute__((always_inline)) inline Fr &operator,(unsigned long long &x) {
    x = 0;
    unsigned char t = P();
    while (t < '0' || t > '9') t = P();
    x = t - '0';
    for (t = P(); t >= '0' && t <= '9'; t = P()) x = x * 10 + t - '0';
    return *this;
  }
  __attribute__((always_inline)) inline operator unsigned long long() {
    unsigned long long x;
    *this, x;
    return x;
  }
};
Fr<Cg> in;
template <typename T>
struct Fw {
  T P;
  __attribute__((always_inline)) inline Fw &operator,(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(int x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(unsigned int x) {
    if (x) {
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(unsigned int x) {
    if (x) {
      unsigned char s[10], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(long long x) {
    if (x) {
      if (x < 0) P('-'), x = -x;
      unsigned char s[19], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(unsigned long long x) {
    if (x) {
      unsigned char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(unsigned long long x) {
    if (x) {
      unsigned char s[20], c = 0;
      while (x) s[c++] = x % 10 + '0', x /= 10;
      while (c--) P(s[c]);
    } else
      P('0');
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(char x) {
    P(x);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(char x) {
    P(x);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator,(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(const char *x) {
    while (*x) P(*x++);
    return *this;
  }
  __attribute__((always_inline)) inline Fw &operator()(double x, int y) {
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
  __attribute__((always_inline)) inline Fw &operator()(long double x, int y) {
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
inline bool possible_sum(long long n, long long k) {
  return k * k / 2 <= n % (k * k + 1) &&
         n % (k * k + 1) <= (k + 1) * (k + 1) / 2;
}
inline std::pair<long long, bool> estid(long long x, long long k) {
  long long t = k * k + 1;
  if (x % t < k * k / 2) return std::make_pair(x - x / t, 1);
  if (x % t > (k + 1) * (k + 1) / 2) return std::make_pair(x - x / t - 1, 1);
  return std::make_pair(x - x / t, 0);
}
inline bool chk(long long, long long);
inline bool chkrange2(long long l, long long r, long long k) {
  if (l * 2 / k != r * 2 / k) {
    long long t = (l * 2 / k + 1) * k / 2;
    if (t * 2 / k == l * 2 / k) t++;
    if (chkrange2(l, t - 1, k)) return 1;
    return chkrange2(t, r, k);
  }
  long long t = (l * 2 / k - k + 1) / 2;
  auto ei = estid(t, k);
  if (ei.second && ei.first % k != 1) return 0;
  if (!ei.second && ei.first % k != 1 && (ei.first - 1) % k != 1) return 0;
  for (long long i = l; i <= r; i++)
    if (chk(i, k)) return 1;
  return 0;
}
inline bool chkrange(long long l, long long r, long long k) {
  if (l > r) return 0;
  long long t = k * k + 1;
  if (l / t != r / t) {
    long long v = (l / t + 1) * t;
    if (chkrange(l, v - 1, k)) return 1;
    return chkrange(v, r, k);
  }
  long long v = l - l % t;
  repr(l, v + (k * k / 2));
  repl(r, v + ((k + 1) * (k + 1) / 2));
  if (l > r) return 0;
  return chkrange2(l, r, k);
}
inline long long realid(long long n, long long k) {
  long long t = k * k + 1;
  long long ei = n - n / t;
  ei -= chkrange(n - n % t + k * k / 2, n, k);
  return ei;
}
inline bool chk(long long n, long long k) {
  if (n < k * (k + 1) / 2) return 0;
  if (!possible_sum(n, k)) return 0;
  long long t = (n * 2 / k - k + 1) / 2;
  long long ot = n - (t * 2 + k - 1) * k / 2;
  if (ot > k) return 0;
  auto ei = estid(t, k);
  if (ei.second && ei.first % k != 1) return 0;
  if (!ei.second && ei.first % k != 1 && (ei.first - 1) % k != 1) return 0;
  static std::map<std::pair<long long, long long>, bool> ff;
  if (ff.count(std::make_pair(n, k))) return ff[std::make_pair(n, k)];
  if (!ei.second) {
    if (realid(t, k) % k != 1) return ff[std::make_pair(n, k)] = 0;
  }
  if (ot) {
    if (chkrange(t, t + k - ot - 1, k)) return ff[std::make_pair(n, k)] = 0;
    if (chkrange(t + k - ot + 1, t + k, k)) return ff[std::make_pair(n, k)] = 0;
    if (!chk(t + k - ot, k)) return ff[std::make_pair(n, k)] = 0;
  } else {
    if (chkrange(t, t + k - 1, k)) return ff[std::make_pair(n, k)] = 0;
  }
  return ff[std::make_pair(n, k)] = 1;
}
inline long long getid(long long n, long long k) {
  if (chk(n, k)) {
    return (n + k * k) / (k * k + 1) * (k + 1);
  }
  long long t = realid(n, k);
  return t + (t - 1) / k;
}
int main() {
  for (int T = in; T--;) {
    long long a, b;
    in, a, b;
    out, getid(a, b), '\n';
  }
}
