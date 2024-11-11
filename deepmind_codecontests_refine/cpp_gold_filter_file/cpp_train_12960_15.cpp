#include <bits/stdc++.h>
using namespace std;
struct Seg {
  int x, l;
} p[105];
int n, f[105][105][2], ans;
int main(void) {
  int i, j, a, b, k, L, R, mx, pos, dir;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d%d", &p[i].x, &p[i].l);
  sort(p + 1, p + n + 1, [](Seg a, Seg b) { return a.x < b.x; });
  for (p[0].x = -0x3f3f3f3f, i = 0; i <= n; ++i) {
    for (j = 0; j <= i; ++j)
      for (a = 0; a < 2; ++a) {
        for (L = p[j].x + p[j].l * a, mx = p[0].x, pos = 0,
            ans = max(ans, f[i][j][a]), k = i + 1;
             k <= n; ++k) {
          for (b = 0; b < 2; ++b) {
            if ((R = p[k].x + p[k].l * b) > mx) mx = R, pos = k, dir = b;
            f[k][pos][dir] =
                max(f[k][pos][dir], f[i][j][a] + min(p[k].l, R - L) + mx - R);
          }
        }
      }
  }
  printf("%d\n", ans);
  return 0;
}
