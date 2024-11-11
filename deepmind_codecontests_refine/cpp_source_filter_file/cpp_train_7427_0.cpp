#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
inline void print(long long *f, long long len) {
  for (long long i = 0; i < len; i++) printf("%lld ", f[i]);
  puts("");
}
long long vis[2020][2020];
long long x, y;
long long nx, ny;
long long dis[2020][2020];
long long check(long long x, long long y) {
  long long l = max(x - dis[x][y], 1ll), r = min(x + dis[x][y], n);
  for (long long i = l, iend = r; i <= iend; ++i) {
    long long nw = dis[x][y] - abs(x - i);
    if (y - nw > 0 && vis[i][y - nw] == 0) {
      nx = i;
      ny = y - nw;
      return 0;
    }
    if (y + nw > 0 && vis[i][y + nw] == 0) {
      nx = i;
      ny = y + nw;
      return 0;
    }
  }
  return 1;
}
signed main() {
  n = read(), m = read(), k = read();
  for (long long i = 1, iend = k; i <= iend; ++i) {
    x = read(), y = read();
    if (!vis[x][y]) {
      vis[x][y] = 1;
      printf("%lld %lld\n", x, y);
      continue;
    }
    for (long long i = -1, iend = 1; i <= iend; ++i) {
      for (long long j = -1, jend = 1; j <= jend; ++j) {
        if (x + i >= n || y + j >= m || x - i <= 0 || y - j <= 0) continue;
        dis[x][y] = max(dis[x][y], dis[x + i][y + j] - abs(i) - abs(j));
      }
    }
    while (check(x, y)) ++dis[x][y];
    vis[nx][ny] = 1;
    printf("%lld %lld\n", nx, ny);
  }
}
