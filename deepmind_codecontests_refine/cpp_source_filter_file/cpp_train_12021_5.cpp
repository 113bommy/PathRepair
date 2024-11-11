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
  if (x > y) return x;
  return y;
}
template <class T>
inline T Min(const T x, const T y) {
  if (x < y) return x;
  return y;
}
template <class T>
inline T fab(const T x) {
  return x > 0 ? x : -x;
}
template <class T>
inline T gcd(const T x, const T y) {
  return y ? gcd(y, x % y) : x;
}
template <class T>
inline T lcm(const T x, const T y) {
  return x / gcd(x, y) * y;
}
template <class T>
inline T Swap(T &x, T &y) {
  x ^= y ^= x ^= y;
}
const int maxn = 1005;
const double eps = 1e-6;
int n, l, x[maxn], b[maxn], pre[maxn], sta[maxn], tp;
double f[maxn];
void Find(int x) {
  if (x == 0) return;
  Find(pre[x]);
  sta[++tp] = x;
}
bool ok(double num) {
  for (register signed i = (1), _end = (n); i <= _end; ++i) {
    f[i] = 1.0 * b[i] * num - sqrt(fab(x[i] - l));
    pre[i] = 0;
    for (register signed j = (1), _end = (i - 1); j <= _end; ++j)
      if (f[i] < f[j] + 1.0 * b[i] * num - sqrt(fab(x[i] - x[j] - l))) {
        f[i] = f[j] + 1.0 * b[i] * num - sqrt(fab(x[i] - x[j] - l));
        pre[i] = j;
      }
  }
  tp = 0;
  Find(n);
  return f[n] < 0;
}
void work() {
  double l = 0, r = 1e5, mid;
  while (r - l > eps) {
    mid = (l + r) / 2;
    if (ok(mid))
      l = mid;
    else
      r = mid;
  }
}
int main() {
  n = read(9), l = read(9);
  for (register signed i = (1), _end = (n); i <= _end; ++i)
    x[i] = read(9), b[i] = read(9);
  work();
  for (register signed i = (1), _end = (tp); i <= _end; ++i)
    write(sta[i]), putchar(' ');
  puts("");
  return 0;
}
