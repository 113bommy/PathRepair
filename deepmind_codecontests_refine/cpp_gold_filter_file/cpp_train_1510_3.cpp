#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxh = 1e5 + 10;
struct point {
  int x, y;
} p[2005];
long long d[maxh], f[2 * maxh];
void getf() {
  f[0] = f[1] = 1;
  for (int i = 2; i < 2 * maxh; i++) f[i] = f[i - 1] * i % mod;
}
long long C(int x, int y) {
  long long a = f[x - y] * f[y] % mod, b = mod - 2, ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return f[x] * ans % mod;
}
long long c(point a, point b) {
  int y = b.y - a.y;
  int x = b.x - a.x;
  if (x < y) return C(x + y, x);
  return C(x + y, y);
}
bool cmp(point a, point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int main() {
  int h, w, n, i, a, b;
  getf();
  scanf("%d%d%d", &h, &w, &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    p[i].x = a;
    p[i].y = b;
  }
  p[n].x = h, p[n].y = w;
  sort(p, p + n, cmp);
  point o = {1, 1};
  for (i = 0; i <= n; i++) {
    d[i] = c(o, p[i]);
    for (a = 0; a < i; a++) {
      if (p[a].x <= p[i].x && p[a].y <= p[i].y)
        d[i] -= c(p[a], p[i]) * d[a] % mod;
      d[i] = (d[i] + mod) % mod;
    }
  }
  printf("%I64d\n", (d[n] + mod) % mod);
}
