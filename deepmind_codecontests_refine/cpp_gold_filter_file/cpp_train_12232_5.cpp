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
  static char buf[20];
  if (x < 0) x = -x, putchar('-');
  int len = 0;
  for (; x; x /= 10) buf[len++] = x % 10 + '0';
  if (!len)
    putchar('0');
  else
    while (len) putchar(buf[--len]);
}
inline void writesp(long long x) {
  write(x);
  putchar(' ');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
struct vct {
  int x, y;
  friend bool operator<(vct a, vct b) {
    return a.x != b.x ? a.x < b.x : a.y > b.y;
  }
  friend vct operator-(vct a, vct b) { return (vct){a.x - b.x, a.y - b.y}; }
  friend long long operator*(vct a, vct b) {
    return (long long)a.x * b.y - (long long)a.y * b.x;
  }
} a[200010], b[200010], st[200010];
int n, m, x, y;
int main() {
  n = read();
  m = read();
  x = read();
  y = read();
  for (int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
  for (int i = 1; i <= m; i++) b[i].x = read(), b[i].y = read();
  int mxx = 0, mxy = 0;
  for (int i = 1; i <= m; i++) {
    mxx = std::max(mxx, b[i].x);
    mxy = std::max(mxy, b[i].y);
  }
  std::sort(b + 1, b + m + 1);
  b[m + 1] = (vct){mxx, 0};
  int tp = 0;
  st[0] = (vct){0, mxy};
  for (int i = 1; i <= m + 1; i++) {
    while (tp && (b[i] - st[tp]) * (st[tp] - st[tp - 1]) <= 0) --tp;
    st[++tp] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    int pos = std::upper_bound(st + 1, st + tp, a[i]) - st;
    if ((st[pos] - a[i]) * (a[i] - st[pos - 1]) >= 0) {
      puts("Max");
      return 0;
    }
  }
  puts("Min");
  return 0;
}
