#include <bits/stdc++.h>
inline long long read() {
  long long x = 0;
  char c = getchar(), f = 1;
  for (; c < '0' || '9' < c; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
inline void write(long long x) {
  static int buf[20], len;
  len = 0;
  if (x < 0) x = -x, putchar('-');
  for (; x; x /= 10) buf[len++] = x % 10;
  if (!len)
    putchar('0');
  else
    while (len) putchar(buf[--len] + '0');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
inline void writesp(long long x) {
  write(x);
  putchar(' ');
}
int a[100010], b[100010], c[100010], d[100010];
std::map<int, int> cnt;
int n, m, p, q;
int main() {
  n = read();
  p = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  m = read();
  q = read();
  for (int i = 1; i <= m; i++) b[i] = read();
  int ans = 0;
  for (int i = 1; i <= n; i++) ++cnt[a[i]];
  for (int i = 1; i <= m; i++) ++cnt[b[i]];
  for (auto i : cnt) ans = std::max(ans, i.second);
  for (int k = 1; k < 30; k++) {
    cnt.clear();
    for (int i = 1; i <= n; i++) ++cnt[a[i] & ((1 << k) - 1)];
    for (int i = 1; i <= m; i++) ++cnt[(b[i] + (1 << k >> 1)) & ((1 << k) - 1)];
    for (auto i : cnt) ans = std::max(ans, i.second);
  }
  writeln(ans);
  return 0;
}
