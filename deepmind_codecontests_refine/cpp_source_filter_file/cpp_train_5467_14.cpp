#include <bits/stdc++.h>
const int N = 500005, mu = 1e9 + 7;
void reduce(int &x) { x += x >> 31 & mu; }
int k, n, m, sx, sy, tx, ty, ans, cnt, a[N], tg[N];
char s[N];
void tran(int &x, int &y, char c) {
  if (c == 'U') x--;
  if (c == 'D') x++;
  if (c == 'L') y--;
  if (c == 'R') y++;
}
int main() {
  scanf("%d%d%d", &k, &n, &m);
  scanf("%s", s + 1);
  sx = 1, sy = 1, tx = n, ty = m;
  for (int i = 1; i <= k && sx <= tx && sy <= ty; i++) {
    tran(sx, sy, s[i]);
    tran(tx, ty, s[i]);
    int t = 0;
    if (!sx) t = ty - sy + 1, sx = 1;
    if (tx > n) t = ty - sy + 1, tx = n;
    if (!sy) t = tx - sx + 1, sy = 1;
    if (ty > m) t = tx - sx + 1, ty = m;
    reduce(ans += (long long)i * t % mu - mu);
  }
  for (int i = 1; i <= k && sx <= tx && sy <= ty; i++) {
    tran(sx, sy, s[i]);
    tran(tx, ty, s[i]);
    int t = 0;
    if (!sx) t = ty - sy + 1, sx = 1, a[++cnt] = i, tg[cnt] = 0;
    if (tx > n) t = ty - sy + 1, tx = n, a[++cnt] = i, tg[cnt] = 0;
    if (!sy) t = tx - sx + 1, sy = 1, a[++cnt] = i, tg[cnt] = 1;
    if (ty > m) t = tx - sx + 1, ty = m, a[++cnt] = i, tg[cnt] = 1;
    reduce(ans += (long long)(i + k) * t % mu - mu);
  }
  int x = tx - sx + 1, y = ty - sy + 1;
  if (x && y && !cnt) return puts("-1"), 0;
  for (int now = 2 * k; x && y; reduce(now += k)) {
    for (int i = 1; i <= cnt && x && y; i++) {
      if (tg[i] == 0) reduce(ans += (long long)(now + a[i]) * y % mu - mu), x--;
      if (tg[i] == 1) reduce(ans += (long long)(now + a[i]) * x % mu - mu), y--;
    }
  }
  printf("%d\n", ans);
}
