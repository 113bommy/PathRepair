#include <bits/stdc++.h>
template <class T>
inline T read(const T sample) {
  T x = 0;
  int f = 1;
  char s;
  while ((s = getchar()) > '9' || s < '0')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9')
    x = (x << 1) + (x << 3) + (s ^ 48), s = getchar();
  return x * f;
}
template <class T>
inline void write(const T x) {
  if (x < 0) return (void)(putchar('-'), write(-x));
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
template <class T>
inline T Max(const T x, const T y) {
  return x > y ? x : y;
}
template <class T>
inline T Min(const T x, const T y) {
  return x < y ? x : y;
}
template <class T>
inline T fab(const T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T Gcd(const T x, const T y) {
  return y ? Gcd(y, x % y) : x;
}
const int N = 1e5 + 5;
int n, k, q[N], l, r, p, f[2][N];
int main() {
  int L, R;
  n = read(9), k = read(9);
  memset(f, 0x3f, sizeof f);
  f[0][0] = 0;
  while (k--) {
    L = read(9), R = read(9);
    l = 1, r = 0;
    for (register signed i = (0), _end = (N - 5); i <= _end; ++i)
      f[p ^ 1][i] = f[p][i];
    for (register signed i = (0), _end = (Min(n, R)); i <= _end; ++i) {
      while (l <= r && f[p][q[r]] >= f[p][i]) --r;
      q[++r] = i;
      while (l <= r && q[l] < i - (R - L)) ++l;
      f[p ^ 1][i] = Min(f[p ^ 1][i], f[p][q[l]] + 2);
    }
    l = 1, r = 0;
    for (register signed i = (R), _end = (0); i >= _end; --i) {
      while (l <= r && f[p][q[r]] >= f[p][R - i]) --r;
      while (l <= r && q[l] < L - i) ++l;
      q[++r] = R - i;
      f[p ^ 1][i] = Min(f[p ^ 1][i], f[p][q[l]] + 1);
    }
    p ^= 1;
  }
  if (f[p][n] >= 0x3f3f3f3f)
    puts("Hungry");
  else
    printf("Full\n%d\n", f[p][n]);
  return 0;
}
