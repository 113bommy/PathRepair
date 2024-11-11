#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 1000005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int f[32][2][2][2], g[32][2][2][2];
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
long long get(int X, int Y, int k) {
  if (X < 0 || Y < 0 || k < 0) return 0;
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  f[31][1][1][1] = 1;
  g[31][1][1][1] = 0;
  for (int i = 31; i >= 1; i--)
    for (int j = 0; j < 32; j++) {
      int xi = (X >> (i - 1)) & 1, yi = (Y >> (i - 1)) & 1,
          ki = (k >> (i - 1)) & 1;
      int p = (j >> 4) & 1, q = (j >> 3) & 1, x = (j >> 2) & 1,
          y = (j >> 1) & 1, t = j & 1;
      if (x && p && !xi) continue;
      if (y && q && !yi) continue;
      if ((x ^ y) && t && !ki) continue;
      int _p = p & (xi == x), _q = q & (yi == y), _t = t & (ki == x ^ y);
      f[i - 1][_p][_q][_t] = upd(f[i - 1][_p][_q][_t], f[i][p][q][t]);
      g[i - 1][_p][_q][_t] = upd(
          g[i - 1][_p][_q][_t],
          (1ll * f[i][p][q][t] * ((x ^ y) << (i - 1)) + g[i][p][q][t]) % mods);
    }
  long long ans = 0;
  for (int p = 0; p <= 1; p++)
    for (int q = 0; q <= 1; q++)
      for (int t = 0; t <= 1; t++) ans += f[0][p][q][t] + g[0][p][q][t];
  return ans % mods;
}
signed main() {
  int Case = read();
  while (Case--) {
    int x1 = read() - 1, y1 = read() - 1, x2 = read() - 1, y2 = read() - 1,
        k = read() - 1;
    printf("%lld\n", (mods + mods + get(x2, y2, k) - get(x1 - 1, y2, k) -
                      get(x2, y1 - 1, k) + get(x1 - 1, y1 - 1, k)) %
                         mods);
  }
  return 0;
}
