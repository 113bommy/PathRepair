#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
template <class T>
void read(T &x) {
  char c, mi = 0;
  while (c = getchar(), c <= 32)
    ;
  if (c == '-')
    mi = 1, x = 0;
  else if (c < 48 || c > 57)
    return void(x = c);
  else
    x = c - 48;
  while (c = getchar(), c > 32) x = 10 * x + c - 48;
  if (mi == 1) x = -x;
}
template <class T>
void read(T &x, T &y) {
  read(x);
  read(y);
}
template <class T>
void read(T &x, T &y, T &z) {
  read(x, y);
  read(z);
}
template <class T>
void reada(T *a, int n) {
  for (int i = 0; i < n; ++i) read(a[i]);
}
template <class T>
void write(T x) {
  static char s[20];
  char pt = 0, mi = (x < 0);
  if (mi == 1) x = -x;
  while (!pt || x > 0) {
    s[++pt] = (char)(x % 10 + '0');
    x /= 10;
  }
  if (mi == 1) putchar('-');
  while (pt > 0) putchar(s[pt--]);
}
template <class T>
void write(T x, T y) {
  write(x);
  putchar(' ');
  write(y);
}
template <class T>
void write(T x, T y, T z) {
  write(x, y);
  putchar(' ');
  write(z);
}
template <class T>
void writeln(T x) {
  write(x);
  puts("");
}
template <class T>
void writea(T *a, int n) {
  for (int i = 0; i < n; ++i) {
    write(a[i]);
    putchar(i + 1 == n ? '\n' : ' ');
  }
}
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T qpom(T a, T b, T mod = 1000000007) {
  T r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return r;
}
template <class T>
T qpow(T a, T b) {
  T r = 1;
  while (b > 0) {
    if (b & 1) r *= a;
    a *= a;
    b /= 2;
  }
  return r;
}
template <class T>
T imin(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T imax(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline void rmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
inline void rmax(T &a, const T &b) {
  if (a < b) a = b;
}
template <class T>
T sqr(const T &a) {
  return a * a;
}
int n, m, deg[200010];
int a[200010], b[200010];
int main() {
  read(n);
  reada(a + 1, n);
  read(m);
  reada(b + 1, m);
  for (int i = 1; i <= m; ++i) {
    ++deg[b[i]];
  }
  if (n == 2) {
    cout << (deg[1] + deg[2] - 1) * 1LL * (a[2] - a[1]) << '\n';
    exit(0);
  }
  deg[1] *= 2;
  deg[n] *= 2;
  if (*max_element(deg + 1, deg + 1 + n) ==
      *min_element(deg + 1, deg + 1 + n)) {
    bool ok = true;
    for (int i = 1; i + 1 <= n; ++i) {
      ok &= a[i + 1] - a[i] == a[2] - a[1];
    }
    if (ok == false) {
      puts("-1");
      exit(0);
    }
    cout << 1LL * deg[1] * (a[n] - a[1]) - (a[n] - a[n - 1]) << '\n';
    exit(0);
  }
  long long ans = 0;
  for (int i = 1; i + 1 <= n; ++i) {
    ans += imin(deg[i], deg[i + 1]) * 1LL * (a[i + 1] - a[i]);
  }
  cout << ans << '\n';
  getchar();
  getchar();
  return 0;
}
