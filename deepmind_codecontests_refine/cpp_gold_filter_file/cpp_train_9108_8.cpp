#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long n, x, y, minx = 2147483647, miny = 2147483647, maxx = -2147483647,
                   maxy = -2147483647;
signed main() {
  n = read();
  while (n--)
    minx = min(minx, x = read()), miny = min(miny, y = read()),
    maxx = max(maxx, x), maxy = max(maxy, y);
  if (maxx == minx || maxy == miny) return cout << -1, 0;
  cout << (maxx - minx) * (maxy - miny);
  return 0;
}
