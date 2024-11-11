#include <bits/stdc++.h>
int n, m, w3, w4, w5, now, d1, d2, g, x, y, t, ans = 1 << 28, c[8];
inline int abs(int a) { return a > 0 ? a : -a; }
inline int min(int a, int b) { return a < b ? a : b; }
void exgcd(int &g, int a, int b, int &x, int &y) {
  if (!b) {
    g = a, x = 1, y = 0;
    return;
  }
  exgcd(g, b, a % b, x, y);
  int t = x;
  x = y;
  y = t - a / b * y;
}
inline void updata(int s3, int s4, int s5, int x, int y, int z) {
  int res = abs(s3 - s4) + abs(s4 - s5);
  if (res < ans) ans = res, w3 = x, w4 = y, w5 = z;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &x), c[x]++;
  for (int i = 0; i * (c[4] + c[5]) <= m; i++) {
    now = m - i * c[4];
    exgcd(g, c[3], c[5], x, y);
    if (now % g) continue;
    x *= now / g, y *= now / g;
    d1 = c[5] / g, d2 = c[3] / g;
    if (x < 0) {
      t = -x / d1;
      x += t * d1, y -= t * d2;
      if (x < 0) x += d1, y -= d2;
    }
    if (x > i) {
      t = (x - i) / d1;
      x -= t * d1, y += t * d2;
      if (x > i) x -= d1, y += d2;
    }
    if (y < i) {
      t = (i - y) / d2;
      y += t * d2, x -= t * d1;
      if (y < i) y += d2, x -= d1;
    }
    if (x < 0) continue;
    int s3 = x * c[3], s4 = i * c[4], s5 = y * c[5];
    if (s3 <= s4 && s5 <= s4 || s3 >= s4 && s5 >= s4)
      updata(s3, s4, s5, x, i, y);
    if (s3 < s4) {
      int t1 = min((s4 - s3) / (c[3] * d1), (i - x) / d1);
      int t2 = min((s5 - s4) / (c[5] * d2), (y - i) / d2);
      t = min(t1, t2);
      x += t * d1, s3 += t * c[3] * d1, y -= t * d2, s5 -= t * c[5] * d2;
      updata(s3, s4, s5, x, i, y);
      if (s3 < s4 && x + d1 <= i && y - d2 >= i)
        x += d1, s3 += c[3] * d1, y -= d2, s5 -= c[5] * d2,
            updata(s3, s4, s5, x, i, y);
    }
    if (s3 > s4) {
      int t1 = min((s3 - s4) / (c[3] * d1), x / d1),
          t2 = (s4 - s5) / (c[5] * d2);
      t = min(t1, t2);
      x -= t * d1, s3 -= t * c[3] * d1, y += t * d2, s5 += t * c[5] * d2;
      updata(s3, s4, s5, x, i, y);
      if (s3 > s4 && x - d1 >= 0)
        x -= d1, s3 -= c[3] * d1, y += d2, s5 += c[5] * d2,
            updata(s3, s4, s5, x, i, y);
    }
  }
  if (ans == 1 << 28)
    puts("-1");
  else
    printf("%d %d %d\n", w3, w4, w5);
  return 0;
}
