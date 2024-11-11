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
const int P = 1000000007;
int n, d[51], f[2][51][51][51][51][2];
int main() {
  in, n;
  for (int i = 1, iend = n; i <= iend; i++) in, d[i];
  int u = 0, v;
  if (d[1] == 2)
    f[0][0][1][0][0][0] = 1;
  else
    f[0][0][0][0][0][1] = 1;
  for (int i = 2, iend = n; i <= iend; i++) {
    for (int a = 0, aend = i - 1; a <= aend; a++)
      for (int b = 0, bend = i - 1 - a; b <= bend; b++)
        for (int x = 0, xend = i - 1 - a - b; x <= xend; x++)
          for (int y = 0, yend = i - 1 - a - b - x; y <= yend; y++)
            for (int c = 0, cend = min(i - 1 - a - b - x - y, 1); c <= cend;
                 c++)
              if (v = f[u][a][b][x][y][c]) {
                if (a) {
                  if (d[i] == 2)
                    f[u ^ 1][a - 1][b][x + 1][y][c] =
                        (f[u ^ 1][a - 1][b][x + 1][y][c] +
                         (long long)(v) * (a)) %
                        P;
                  else
                    f[u ^ 1][a - 1][b][x][y + 1][c] =
                        (f[u ^ 1][a - 1][b][x][y + 1][c] +
                         (long long)(v) * (a)) %
                        P;
                  if (x) {
                    if (d[i] == 2)
                      f[u ^ 1][a - 1][b][x - 1][y][c] =
                          (f[u ^ 1][a - 1][b][x - 1][y][c] +
                           (long long)(v) * (a * x)) %
                          P;
                    else {
                      f[u ^ 1][a - 1][b][x][y][c] =
                          (f[u ^ 1][a - 1][b][x][y][c] +
                           (long long)(v) * (a * x)) %
                          P;
                      if (x > 1)
                        f[u ^ 1][a - 1][b][x - 2][y][c] =
                            (f[u ^ 1][a - 1][b][x - 2][y][c] +
                             (long long)(v) * (a * x * (x - 1) / 2)) %
                            P;
                    }
                  }
                  if (y) {
                    if (d[i] == 2)
                      f[u ^ 1][a - 1][b][x + 1][y - 1][c] =
                          (f[u ^ 1][a - 1][b][x + 1][y - 1][c] +
                           (long long)(v) * (a * y)) %
                          P;
                    else {
                      f[u ^ 1][a - 1][b][x + 2][y - 1][c] =
                          (f[u ^ 1][a - 1][b][x + 2][y - 1][c] +
                           (long long)(v) * (a * y)) %
                          P;
                      if (y > 1)
                        f[u ^ 1][a - 1][b][x + 2][y - 2][c] =
                            (f[u ^ 1][a - 1][b][x + 2][y - 2][c] +
                             (long long)(v) * (a * y * (y - 1) / 2)) %
                            P;
                    }
                  }
                  if (x && y && d[i] == 3)
                    f[u ^ 1][a - 1][b][x][y - 1][c] =
                        (f[u ^ 1][a - 1][b][x][y - 1][c] +
                         (long long)(v) * (a * x * y)) %
                        P;
                }
                if (b) {
                  if (d[i] == 2)
                    f[u ^ 1][a + 1][b - 1][x + 1][y][c] =
                        (f[u ^ 1][a + 1][b - 1][x + 1][y][c] +
                         (long long)(v) * (b)) %
                        P;
                  else
                    f[u ^ 1][a + 1][b - 1][x][y + 1][c] =
                        (f[u ^ 1][a + 1][b - 1][x][y + 1][c] +
                         (long long)(v) * (b)) %
                        P;
                  if (x) {
                    if (d[i] == 2)
                      f[u ^ 1][a + 1][b - 1][x - 1][y][c] =
                          (f[u ^ 1][a + 1][b - 1][x - 1][y][c] +
                           (long long)(v) * (b * x)) %
                          P;
                    else {
                      f[u ^ 1][a + 1][b - 1][x][y][c] =
                          (f[u ^ 1][a + 1][b - 1][x][y][c] +
                           (long long)(v) * (b * x)) %
                          P;
                      if (x > 1)
                        f[u ^ 1][a + 1][b - 1][x - 2][y][c] =
                            (f[u ^ 1][a + 1][b - 1][x - 2][y][c] +
                             (long long)(v) * (b * x * (x - 1) / 2)) %
                            P;
                    }
                  }
                  if (y) {
                    if (d[i] == 2)
                      f[u ^ 1][a + 1][b - 1][x + 1][y - 1][c] =
                          (f[u ^ 1][a + 1][b - 1][x + 1][y - 1][c] +
                           (long long)(v) * (b * y)) %
                          P;
                    else {
                      f[u ^ 1][a + 1][b - 1][x + 2][y - 1][c] =
                          (f[u ^ 1][a + 1][b - 1][x + 2][y - 1][c] +
                           (long long)(v) * (b * y)) %
                          P;
                      if (y > 1)
                        f[u ^ 1][a + 1][b - 1][x + 2][y - 2][c] =
                            (f[u ^ 1][a + 1][b - 1][x + 2][y - 2][c] +
                             (long long)(v) * (b * y * (y - 1) / 2)) %
                            P;
                    }
                  }
                  if (x && y && d[i] == 3)
                    f[u ^ 1][a + 1][b - 1][x][y - 1][c] =
                        (f[u ^ 1][a + 1][b - 1][x][y - 1][c] +
                         (long long)(v) * (b * x * y)) %
                        P;
                }
                if (c) {
                  if (d[i] == 2)
                    f[u ^ 1][a][b + 1][x + 1][y][c - 1] =
                        (f[u ^ 1][a][b + 1][x + 1][y][c - 1] +
                         (long long)(v) * (1)) %
                        P;
                  else
                    f[u ^ 1][a][b + 1][x][y + 1][c - 1] =
                        (f[u ^ 1][a][b + 1][x][y + 1][c - 1] +
                         (long long)(v) * (1)) %
                        P;
                  if (x) {
                    if (d[i] == 2)
                      f[u ^ 1][a][b + 1][x - 1][y][c - 1] =
                          (f[u ^ 1][a][b + 1][x - 1][y][c - 1] +
                           (long long)(v) * (x)) %
                          P;
                    else {
                      f[u ^ 1][a][b + 1][x][y][c - 1] =
                          (f[u ^ 1][a][b + 1][x][y][c - 1] +
                           (long long)(v) * (x)) %
                          P;
                      if (x > 1)
                        f[u ^ 1][a][b + 1][x - 2][y][c - 1] =
                            (f[u ^ 1][a][b + 1][x - 2][y][c - 1] +
                             (long long)(v) * (x * (x - 1) / 2)) %
                            P;
                    }
                  }
                  if (y) {
                    if (d[i] == 2)
                      f[u ^ 1][a][b + 1][x + 1][y - 1][c - 1] =
                          (f[u ^ 1][a][b + 1][x + 1][y - 1][c - 1] +
                           (long long)(v) * (y)) %
                          P;
                    else {
                      f[u ^ 1][a][b + 1][x + 2][y - 1][c - 1] =
                          (f[u ^ 1][a][b + 1][x + 2][y - 1][c - 1] +
                           (long long)(v) * (y)) %
                          P;
                      if (y > 1)
                        f[u ^ 1][a][b + 1][x + 2][y - 2][c - 1] =
                            (f[u ^ 1][a][b + 1][x + 2][y - 2][c - 1] +
                             (long long)(v) * (y * (y - 1) / 2)) %
                            P;
                    }
                  }
                  if (x && y && d[i] == 3)
                    f[u ^ 1][a][b + 1][x][y - 1][c - 1] =
                        (f[u ^ 1][a][b + 1][x][y - 1][c - 1] +
                         (long long)(v) * (x * y)) %
                        P;
                }
                if (!a && !b && !c) {
                  if (x) {
                    if (d[i] == 2)
                      f[u ^ 1][x - 1][y][1][0][0] =
                          (f[u ^ 1][x - 1][y][1][0][0] + (long long)(v) * (x)) %
                          P;
                    else
                      f[u ^ 1][x - 1][y][0][1][0] =
                          (f[u ^ 1][x - 1][y][0][1][0] + (long long)(v) * (x)) %
                          P;
                  }
                  if (y) {
                    if (d[i] == 2)
                      f[u ^ 1][x + 1][y - 1][1][0][0] =
                          (f[u ^ 1][x + 1][y - 1][1][0][0] +
                           (long long)(v) * (y)) %
                          P;
                    else
                      f[u ^ 1][x + 1][y - 1][0][1][0] =
                          (f[u ^ 1][x + 1][y - 1][0][1][0] +
                           (long long)(v) * (y)) %
                          P;
                  }
                }
                f[u][a][b][x][y][c] = 0;
              }
    u ^= 1;
  }
  out, f[u][0][0][0][0][0], '\n';
}
