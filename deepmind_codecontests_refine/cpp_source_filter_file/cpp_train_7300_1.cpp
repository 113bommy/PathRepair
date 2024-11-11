#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &a) {
  T x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  a = x * f;
}
template <typename T>
void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10) return (void)putchar(x + '0');
  write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void writeln(T x) {
  write(x);
  putchar('\n');
}
template <typename T>
void writes(T x) {
  write(x);
  putchar(' ');
}
template <typename T, typename... Args>
void read(T &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename T, typename... Args>
void writes(T t, Args... args) {
  writes(t);
  writes(args...);
}
template <typename T, typename... Args>
void writeln(T t, Args... args) {
  writes(t);
  writes(args...);
  putchar('\n');
}
long long n, a[405];
signed main() {
  read(n);
  for (long long i = 1; i <= n; i++) read(a[i]);
  long long ans = 0x7f7f7f7f7f7f7f;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      long long cnt1 = 0, cnt2 = 0, res = -1, w = a[i] - 1;
      for (long long k = i + 1; k <= j; k++) cnt1 += (w / a[k]), w %= a[k];
      res = w = a[i] + a[j] - w - 1;
      for (long long k = 1; k <= n; k++) cnt2 += (w / a[k]), w %= a[k];
      if (cnt1 < cnt2) ans = min(ans, res);
    }
  }
  writeln(ans == 0x7f7f7f7f7f7f7f ? -1 : ans);
  return 0;
}
