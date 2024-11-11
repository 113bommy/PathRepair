#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, a[MAXN], dp[MAXN];
int g1[MAXN], g2[MAXN];
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename _T>
inline void read(_T &x) {
  int f = 1;
  x = 0;
  char s = gc();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = gc();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = gc();
  }
  x *= f;
}
template <typename _T>
void write(_T x) {
  if (x < 0) {
    putchar('-');
    x = (~x) + 1;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename _T>
inline _T Min(_T x, _T y) {
  return x > y ? x : y;
}
template <typename _T>
inline _T Max(_T x, _T y) {
  return x < y ? x : y;
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]), dp[1] = Max(dp[1], a[i]);
  for (int i = 1; i < n; i++) {
    int len1 = Min(n - i, i), len2 = Min(n - i, i - 1);
    g1[len1] = Max(g1[len1], Max(a[i], a[i + 1]));
    g2[len2] = Max(g2[len2], Min(a[i], Max(a[i - 1], a[i + 1])));
  }
  for (int i = n / 2; i; i--) {
    dp[i << 1] = Max(dp[(i + 1) << 1], g1[i]);
    dp[i << 1 | 1] = Max(dp[(i + 1) << 1 | 1], g2[i]);
  }
  for (int i = n; i; i--) {
    write(dp[i]);
    putchar(' ');
  }
  return 0;
}
