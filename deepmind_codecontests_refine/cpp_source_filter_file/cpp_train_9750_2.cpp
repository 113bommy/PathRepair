#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
namespace _c {
const double pi = acos(-1.0);
namespace min {
const int i8 = -128;
const int i16 = -32768;
const int i = -2147483647 - 1;
const long long l = -9223372036854775807LL - 1;
}  // namespace min
namespace max {
const int i8 = 127;
const int i16 = 32767;
const int i = 2147483647;
const long long l = 9223372036854775807LL;
}  // namespace max
}  // namespace _c
namespace _f {
template <typename T>
inline const T gcd(T m, T n) {
  while (n != 0) {
    T t = m % n;
    m = n;
    n = t;
  }
  return m;
}
template <typename T>
inline const T abs(const T &a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T pow(T a, T b) {
  T res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
template <typename T>
inline T pow(T a, T b, const T &m) {
  a %= m;
  T res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res % m;
}
}  // namespace _f
namespace io {
template <typename T>
inline T read() {
  register T res = 0, neg = 1;
  char g = getchar();
  for (; !isdigit(g); g = getchar()) {
    if (g == '-') {
      neg = -1;
    }
  }
  for (; isdigit(g); g = getchar()) {
    res = res * 10 + g - '0';
  }
  return res * neg;
}
template <typename T>
inline void read(T &t) {
  t = read<T>();
}
template <typename T>
inline void readln(const T first, const T last) {
  for (register T it = first; it != last; it++) {
    read(*it);
  }
}
template <typename T>
inline void _write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    _write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T>
inline void write(const T &x, const char &sep = ' ') {
  _write(x);
  putchar(sep);
}
template <typename T>
inline void writeln(const T &x) {
  write(x, '\n');
}
template <typename T>
inline void writeln(const T first, const T last, const char &sep = ' ',
                    const char &ends = '\n') {
  for (register T it = first; it != last; it++) {
    write(*it, sep);
  }
  putchar(ends);
}
}  // namespace io
constexpr int MAX_N = 125000;
constexpr int N = MAX_N * 4 + 5;
template <typename Tp>
inline void chkmin(Tp &x, const Tp &y) {
  if (x > y) {
    x = y;
  }
}
template <typename Tp>
inline void chkmax(Tp &x, const Tp &y) {
  if (x < y) {
    x = y;
  }
}
int n, m;
int a[N], b[N], ans[N], kmp[N];
char s[N], t[N];
int i[7] = {0, 0, 0, 0, 0, 5};
inline void KMP(int C) {
  for (int i = 2, j = 0; i <= m; i++) {
    while (j && b[i] != b[j + 1]) {
      j = kmp[j];
    }
    if (b[i] == b[j + 1]) {
      j++;
    }
    kmp[i] = j;
  }
  for (int i = 1, j = 0; i <= n; i++) {
    while (j && a[i] != b[j + 1]) {
      j = kmp[j];
    }
    if (a[i] == b[j + 1]) {
      j++;
    }
    if (j == m) {
      chkmax(ans[i], C);
      j = kmp[j];
    }
  }
}
int main() {
  memset(ans, 0x3f, sizeof(ans));
  scanf("%s %s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (i[0] = 0; i[0] < 6; i[0]++) {
    for (i[1] = 1; i[1] < 6; i[1]++) {
      for (i[2] = 2; i[2] < 6; i[2]++) {
        for (i[3] = 3; i[3] < 6; i[3]++) {
          for (i[4] = 4; i[4] < 6; i[4]++) {
            for (int j = 1; j <= n; j++) {
              a[j] = i[s[j] - 'a'];
            }
            for (int j = 1; j <= m; j++) {
              b[j] = i[t[j] - 'a'];
            }
            KMP((i[0] > 0) + (i[1] > 1) + (i[2] > 2) + (i[3] > 3) + (i[4] > 4));
          }
        }
      }
    }
  }
  io::writeln(ans + m, ans + n + 1);
}
