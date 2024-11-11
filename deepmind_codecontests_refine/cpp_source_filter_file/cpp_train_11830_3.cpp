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
const int N = 100007;
struct da {
  int pos, id;
  long long tm;
  inline bool operator<(const da &v) const {
    if (pos != v.pos) return pos < v.pos;
    if (tm != v.tm) return tm < v.tm;
    return id < v.id;
  }
};
struct da2 {
  int pos, id;
  long long tm;
  inline bool operator<(const da2 &v) const { return tm > v.tm; }
};
int n, k, m, s[N], a[N], b[N];
long long t[N];
std::set<da> f;
std::priority_queue<da2> q;
int main() {
  in, n, k, m;
  for (int i = 1, iend = k; i <= iend; i++) {
    int x = in;
    f.insert((da){x, i, 0});
  }
  for (int i = 1, iend = m; i <= iend; i++) in, t[i], a[i], b[i];
  long long tn = 0;
  for (int i = 1, iend = m; i <= iend; i++) {
    if (!f.size()) repr(tn, q.top().tm);
    repr(tn, t[i]);
    while (q.size() && q.top().tm <= tn) {
      f.insert((da){q.top().pos, q.top().id, q.top().tm});
      q.pop();
    }
    std::set<da>::iterator x, y;
    x = f.lower_bound((da){a[i], -1, -1});
    y = x;
    if (x != f.begin()) {
      int t = (--y)->pos;
      y = f.lower_bound((da){t, -1, -1});
    }
    if (x == f.end()) x = y;
    da xa = *x, ya = *y;
    xa.pos = abs(xa.pos - a[i]);
    ya.pos = abs(ya.pos - a[i]);
    if (xa < ya)
      xa = *x;
    else
      xa = *y;
    f.erase(xa);
    out, xa.id, ' ', abs(xa.pos - a[i]) + tn - t[i], '\n';
    xa.tm = tn + abs(xa.pos - a[i]) + abs(a[i] - b[i]);
    xa.pos = b[i];
    q.push((da2){xa.pos, xa.id, xa.tm});
  }
}
