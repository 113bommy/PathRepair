#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110, INF = -0x3f3f3f3f;
int n;
struct seg {
  int p, len;
} a[MAXN];
bool cmp(seg x, seg y) { return x.p < y.p; }
int f[MAXN][MAXN][2], ans;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].p, &a[i].len);
  sort(a + 1, a + n + 1, cmp);
  a[0].p = INF;
  a[0].len = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int d1 = 0; d1 < 2; d1++) {
        ans = max(ans, f[i][j][d1]);
        int r1 = a[j].p + d1 * a[j].len, maxx = INF, x, y;
        for (int k = i + 1; k <= n; k++)
          for (int d2 = 0; d2 < 2; d2++) {
            int r2 = a[k].p + d2 * a[k].len;
            if (r2 > maxx) maxx = r2, x = k, y = d2;
            f[k][x][y] = max(f[k][x][y],
                             f[i][j][d1] + min(r2 - r1, a[k].len) + maxx - r2);
          }
      }
  printf("%d", ans);
  return 0;
}
