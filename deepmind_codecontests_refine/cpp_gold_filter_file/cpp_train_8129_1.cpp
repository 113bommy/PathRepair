#include <bits/stdc++.h>
using namespace std;
const int z = 998244353;
const int N = 1000;
typedef struct {
  int x, y, s;
} squ;
squ s[N * N];
bool cs(squ a, squ b) { return a.s < b.s; }
int fp(int a, int x) {
  if (x == 0) {
    return 1;
  }
  if (x % 2 == 1) {
    return 1ll * a * fp(a, x - 1) % z;
  }
  int t = fp(a, x / 2);
  return 1ll * t * t % z;
}
int rev(int x) { return fp(x, z - 2); }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &s[i * m + j].s);
      s[i * m + j].x = i;
      s[i * m + j].y = j;
    }
  }
  sort(s, s + n * m, cs);
  int x, y;
  scanf("%d %d", &x, &y);
  x--, y--;
  int ls = -1;
  int sxy2 = 0, sx = 0, sy = 0, sn = 0, ssp = 0, ssq = 1;
  int txy2, tx, ty, tn, tsp, tsq;
  int p = 0, q = 1;
  for (int i = 0; i < n * m; i++) {
    if (s[i].s != ls) {
      txy2 = sxy2;
      tx = sx;
      ty = sy;
      tn = sn;
      tsp = ssp;
      tsq = ssq;
    }
    if (tn == 0) {
      p = 0;
      q = 1;
    } else {
      p = (1ll * tsq *
               ((txy2 - 2ll * s[i].x * tx % z - 2ll * s[i].y * ty % z + 2 * z +
                 1ll * tn * (s[i].x * s[i].x + s[i].y * s[i].y) % z) %
                z) +
           tsp) %
          z;
      q = 1ll * tn * tsq % z;
    }
    if (s[i].x == x && s[i].y == y) {
      break;
    }
    ssp = (1ll * ssp * q + 1ll * p * ssq) % z;
    ssq = 1ll * ssq * q % z;
    sxy2 = (sxy2 + s[i].x * s[i].x + s[i].y * s[i].y) % z;
    sx = (sx + s[i].x) % z;
    sy = (sy + s[i].y) % z;
    sn++;
    ls = s[i].s;
  }
  printf("%d\n", 1ll * p * rev(q) % z);
  return 0;
}
