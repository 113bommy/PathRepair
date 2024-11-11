#include <bits/stdc++.h>
int cnt[15], n, m, x, y, ans1, ans2, ans3, ans;
int exgcd(int a, int b) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int t, tmp = exgcd(b, a % b);
  t = x;
  x = y;
  y = t - (a / b) * y;
  return tmp;
}
int update(int i, int x, int y) {
  if (i > x || x > y) return 1 << 30;
  int res = abs(i * cnt[3] - x * cnt[4]) + abs(x * cnt[4] - y * cnt[5]);
  if (res < ans) ans = res, ans1 = i, ans2 = x, ans3 = y;
  return res;
}
int main() {
  int t1 = clock();
  scanf("%d%d", &n, &m);
  ans = 1 << 30;
  for (int i = 1; i <= n; ++i) scanf("%d", &x), ++cnt[x];
  for (int i = 0; i <= m; ++i)
    if (cnt[3] * i <= m) {
      if (cnt[3] * i == m) {
        update(i, 0, 0);
        continue;
      }
      int gcd, a = cnt[4], b = cnt[5], c = m - cnt[3] * i;
      gcd = exgcd(a, b);
      if (c % gcd != 0) continue;
      x *= c / gcd;
      y *= c / gcd;
      int s = x / (b / gcd);
      x -= (b / gcd) * s;
      y += (a / gcd) * s;
      while (x >= 0) x -= b / gcd, y += a / gcd;
      while (x < 0) x += b / gcd, y -= a / gcd;
      while (x >= 0 && y >= 0) {
        if (x > y) break;
        if (m > 10000 &&
            update(i, x + (b / gcd) * 50, y - (a / gcd) * 50) <
                update(i, x, y) &&
            update(i, x + (b / gcd) * 150, y - (a / gcd) * 150) <
                update(i, x, y)) {
          x += (b / gcd) * 30, y -= (a / gcd) * 30;
          continue;
        }
        if (m > 10000 &&
            update(i, x - (b / gcd) * 50, y + (a / gcd) * 50) <
                update(i, x, y) &&
            update(i, x, y) <
                update(i, x + (b / gcd) * 150, y - (a / gcd) * 150)) {
          x += (b / gcd) * 30, y -= (a / gcd) * 30;
          continue;
        }
        update(i, x, y), x += b / gcd, y -= a / gcd;
      }
      if (clock() - t1 > 1500) break;
    }
  for (int i = m; i >= 0; --i)
    if (cnt[3] * i <= m) {
      if (cnt[3] * i == m) {
        update(i, 0, 0);
        continue;
      }
      int gcd, a = cnt[4], b = cnt[5], c = m - cnt[3] * i;
      gcd = exgcd(a, b);
      if (c % gcd != 0) continue;
      x *= c / gcd;
      y *= c / gcd;
      int s = (x - i) / (b / gcd);
      x -= (b / gcd) * s;
      y += (a / gcd) * s;
      while (x >= i) x -= b / gcd, y += a / gcd;
      while (x < i) x += b / gcd, y -= a / gcd;
      while (x >= 0 && y >= 0) {
        if (x > y) break;
        if (m > 10000 &&
            update(i, x + (b / gcd) * 50, y - (a / gcd) * 50) <
                update(i, x, y) &&
            update(i, x + (b / gcd) * 150, y - (a / gcd) * 150) <
                update(i, x, y)) {
          x += (b / gcd) * 30, y -= (a / gcd) * 30;
          continue;
        }
        if (m > 10000 &&
            update(i, x - (b / gcd) * 50, y + (a / gcd) * 50) <
                update(i, x, y) &&
            update(i, x, y) <
                update(i, x + (b / gcd) * 150, y - (a / gcd) * 150)) {
          x += (b / gcd) * 30, y -= (a / gcd) * 30;
          continue;
        }
        update(i, x, y), x += b / gcd, y -= a / gcd;
      }
      if (clock() - t1 > 3000) break;
    }
  if (ans != (1 << 30))
    printf("%d %d %d\n", ans1, ans2, ans3);
  else
    printf("-1\n");
  return 0;
}
