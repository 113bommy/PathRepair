#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, del[N];
struct P {
  int x, y, id;
  inline P(int x = 0, int y = 0, int id = 0) : x(x), y(y), id(id) {}
} px[N], py[N];
inline bool Cmpx(P u, P v) { return u.x < v.x; }
inline bool Cmpy(P u, P v) { return u.y < v.y; }
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, xx, yy, x, y; i <= n; ++i)
    scanf("%d%d%d%d", &xx, &yy, &x, &y), px[i] = py[i] = P(x + xx, y + yy, i);
  sort(px + 1, px + n + 1, Cmpx);
  sort(py + 1, py + n + 1, Cmpy);
  long long ans = 4e18;
  for (int dl = 0; dl <= k; ++dl)
    for (int dr = 0; dr + dl <= k; ++dr)
      for (int du = 0; du + dr + dl <= k; ++dr)
        for (int dd = 0; dd + du + dr + dl <= k; ++dd) {
          int lp = 1, dp = 1, rp = n, up = n;
          for (int i = 1; i <= dl; ++i) {
            while (del[px[lp].id]) ++lp;
            del[px[lp].id] = 1;
          }
          for (int i = 1; i <= dr; ++i) {
            while (del[px[rp].id]) --rp;
            del[px[rp].id] = 1;
          }
          for (int i = 1; i <= dd; ++i) {
            while (del[py[dp].id]) ++dp;
            del[py[dp].id] = 1;
          }
          for (int i = 1; i <= du; ++i) {
            while (del[py[up].id]) --up;
            del[py[up].id] = 1;
          }
          while (del[px[lp].id]) ++lp;
          while (del[px[rp].id]) --rp;
          while (del[py[dp].id]) ++dp;
          while (del[py[up].id]) --up;
          int dx = px[rp].x - px[lp].x;
          int dy = py[up].y - py[dp].y;
          if (dx & 1) ++dx;
          if (dy & 1) ++dy;
          ans = min(ans, 1ll * max(dx, 2) * max(dy, 2));
          for (int i = 1; i <= lp; ++i) del[px[i].id] = 0;
          for (int i = rp; i <= n; ++i) del[px[i].id] = 0;
          for (int i = 1; i <= dp; ++i) del[py[i].id] = 0;
          for (int i = up; i <= n; ++i) del[py[i].id] = 0;
        }
  printf("%lld\n", ans / 4);
  return 0;
}
