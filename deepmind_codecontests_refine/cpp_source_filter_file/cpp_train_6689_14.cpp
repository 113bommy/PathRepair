#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long n = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = n * 10 + ch - '0';
    ch = getchar();
  }
  return n * f;
}
long long sl(long long x, long long y) {
  if (y == x) return 0;
  if (y == x + 1) return 1;
  if (y & 1) {
    if (x & 1)
      return 0;
    else
      return 1;
  }
  if (x <= y / 4) return sl(x, y / 4);
  if (x > (y / 4) * 2) return (y - x) & 1;
  return 1;
}
long long sh(long long x, long long y) {
  if (x * 2 > y) return 1;
  return sl(x, y / 2);
}
long long ss[200001], ff[200001];
signed main() {
  long long n, x, y;
  n = read();
  for (long long i = 1; i <= n; i++) {
    x = read();
    y = read();
    ss[i] = sl(x, y);
    ff[i] = sh(x, y);
  }
  long long f = 1, s = 0;
  for (long long i = 1; i <= n; i++) {
    if (f == 1 && s == 1) break;
    if (f == 0 && s == 0) break;
    if (s == 1) ss[i] ^= 1, ff[i] ^= 1;
    f = ff[i];
    s = ss[i];
  }
  printf("%d %d\n", s, f);
  return 0;
}
