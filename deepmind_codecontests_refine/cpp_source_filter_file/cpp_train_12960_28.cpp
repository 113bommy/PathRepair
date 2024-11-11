#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int INF = 1e9;
int n, ans = 0;
int f[N][N][2];
struct Node {
  int p, l;
} a[N];
const bool cmp(const Node &x, const Node &y) { return x.p < y.p; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].p, &a[i].l);
  }
  sort(a + 1, a + 1 + n, cmp);
  a[0].p = -INF;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k < 2; k++) {
        ans = max(ans, f[i][j][k]);
        int pre, nxt, mx = -1, x, y;
        pre = a[j].p + a[j].l * k;
        for (int l = i + 1; l <= n; l++)
          for (int d = 0; d < 2; d++) {
            nxt = a[l].p + a[j].l * d;
            if (nxt > mx) {
              mx = nxt;
              x = l;
              y = d;
            }
            f[l][x][y] =
                max(f[l][x][y], f[i][j][k] + min(nxt - pre, a[l].l) + mx - nxt);
          }
      }
  printf("%d\n", ans);
  return 0;
}
