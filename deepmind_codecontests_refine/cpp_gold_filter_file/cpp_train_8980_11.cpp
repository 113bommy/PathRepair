#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
long long inv(long long a) {
  long long p = md - 2;
  long long ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % md;
    a = a * a % md;
    p >>= 1;
  }
  return ret;
}
int mp[1010][1010];
int xn[2100], yyyn[2100], dn[2100];
void range(int &x0, int &y0, int &x1, int &y1) {
  x0 = max(x0, 1);
  y0 = max(y0, 1);
  x1 = min(x1, 1000);
  y1 = min(y1, 1000);
}
int cnt(int x0, int y0, int x1, int y1) {
  range(x0, y0, x1, y1);
  return mp[x1][y1] - mp[x0 - 1][y1] - mp[x1][y0 - 1] + mp[x0 - 1][y0 - 1];
}
long long cn[2100];
void init(int m) {
  memset(cn, 0, sizeof(cn));
  cn[m] = 1;
  for (int i = m + 1; i < 2100; i++) {
    cn[i] = cn[i - 1] * i % md * inv(i - m) % md;
  }
}
long long c(int n, int m) { return cn[n]; }
int main() {
  int z;
  int n, m, r;
  int i, j, k;
  memset(mp, 0, sizeof(mp));
  cin >> n >> m >> r;
  for (i = 0; i < n; i++) {
    cin >> xn[i] >> yyyn[i] >> dn[i];
    mp[xn[i]][yyyn[i]] = 1;
  }
  for (i = 1; i <= 1000; i++) {
    for (j = 1; j <= 1000; j++) {
      mp[i][j] = mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1] + mp[i][j];
    }
  }
  long long ans = 0;
  init(m);
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      int xi = xn[i], yi = yyyn[i];
      int xj = xn[j], yj = yyyn[j];
      int dx = abs(xi - xj), dy = abs(yi - yj);
      int u, v, w;
      u = cnt(xi - r, yi - r, xi + r, yi + r);
      v = cnt(xj - r, yj - r, xj + r, yj + r);
      if (dx <= 2 * r && dy <= 2 * r) {
        int x0, y0, x1, y1;
        if (xi > xj) swap(xi, xj);
        x0 = xj - r, x1 = xi + r;
        if (yi > yj) swap(yi, yj);
        y0 = yj - r, y1 = yi + r;
        w = cnt(x0, y0, x1, y1);
      } else {
        w = 0;
      }
      u -= w;
      v -= w;
      long long sum = ((c(n, m) - c(n - w, m) + md) +
                       (c(n - w, m) - c(n - w - u, m) - c(n - w - v, m) +
                        c(n - w - u - v, m) + 2 * md)) %
                      md;
      ans = (ans + 2 * sum % md * dn[i] % md * dn[j] % md) % md;
    }
    int ni = cnt(xn[i] - r, yyyn[i] - r, xn[i] + r, yyyn[i] + r);
    ans = (ans + (c(n, m) - c(n - ni, m) + md) % md * dn[i] % md * dn[i] % md) %
          md;
  }
  cout << ans % md << endl;
  return 0;
}
