#include <bits/stdc++.h>
using namespace std;
struct segm {
  int l, r;
  int val;
  segm(int _l = 0, int _r = 0, int _val = 0) : l(_l), r(_r), val(_val) {}
  inline bool operator<(const segm &s) const { return l < s.l; }
};
const int maxn = 100;
segm ss[2][maxn];
int used[2][maxn];
const int len = (int)1e5;
const int boards[2] = {0, 100};
inline double getx(int y1, int y2, int y3) {
  return 1e5 * (y3 - y1) / (y2 - y1);
}
int main() {
  int h1, h2, n;
  while (scanf("%d%d%d", &h1, &h2, &n) >= 1) {
    int m[2] = {0, 0};
    for (int i = 0; i < n; i++) {
      int v, a, b;
      char c;
      scanf("%d %c%d%d", &v, &c, &a, &b);
      ss[c == 'T'][m[c == 'T']++] = segm(a, b, v);
    }
    sort(ss[0], ss[0] + m[0]);
    sort(ss[1], ss[1] + m[1]);
    int ans = 0;
    for (int iter = 0; iter < 2; iter++) {
      for (int boom = 1; boom <= n; boom++) {
        memset(used, 0, sizeof(used));
        int pos2 = h2;
        for (int i = 0, type = !(iter ^ (boom & 1)); i < boom; i++, type ^= 1)
          pos2 = 2 * boards[type] - pos2;
        int pos1 = h1;
        int res = 0;
        for (int i = 0, type = iter; i < boom; i++, type ^= 1) {
          double x = getx(pos1, pos2, boards[type]);
          int id = upper_bound(ss[type], ss[type] + m[type],
                               segm(floor(x + (1E-9)))) -
                   ss[type] - 1;
          if (id < 0 || ss[type][id].r + (1E-9) < x || used[type][id]) {
            res = -1;
            break;
          }
          res += ss[type][id].val;
          used[type][id] = 1;
          pos1 = 2 * boards[type] - pos1;
          pos2 = 2 * boards[type] - pos2;
        }
        ans = max(ans, res);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
