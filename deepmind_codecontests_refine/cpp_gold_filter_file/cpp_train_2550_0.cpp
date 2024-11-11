#include <bits/stdc++.h>
const int N = 401, M = N * N, mo = 1e9 + 7;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int k, m, w, sx, sy, i, x, y, s, h, t, qx[M], qy[M], qs[M];
long long n;
bool a[N][N];
int main() {
  scanf("%I64d%d", &n, &m);
  k = 100;
  sx = sy = 2 * k;
  if (n < k) k = n;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    a[sx + x][sy + y] = 1;
  }
  h = 0;
  t = 1;
  qx[1] = sx;
  qy[1] = sy;
  qs[1] = 0;
  a[sx][sy] = 1;
  for (; h != t;) {
    h++;
    x = qx[h];
    y = qy[h];
    s = qs[h];
    if (s == k) break;
    for (i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (!a[xx][yy]) {
        a[xx][yy] = 1;
        qs[++t] = s + 1;
        qx[t] = xx;
        qy[t] = yy;
      }
    }
  }
  if (k == n || qs[t] < k) {
    printf("%d", t);
    return 0;
  }
  w = t - h + 1;
  int r = (n - k) % mo,
      ans = t + (long long)r * w % mo + 14ll * r % mo * (r + 1) % mo;
  printf("%d", ans % mo);
}
