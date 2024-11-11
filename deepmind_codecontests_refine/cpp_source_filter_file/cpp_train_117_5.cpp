#include <bits/stdc++.h>
using namespace std;
struct note {
  int c, d;
} g[200100];
int cmp(note a, note b) { return a.d < b.d; }
int n, m;
long long F[2][10], ans;
void update(int id, int len, long long val, int tar) {
  for (int i = 0; i <= 9 - len; i++)
    if (~F[id][i]) F[id ^ 1][i + len] = max(F[id ^ 1][i + len], F[id][i] + val);
  for (int i = 9 - len + 1; i <= 9; i++)
    if (~F[id][i])
      F[id ^ 1][(i + len) % 10] =
          max(F[id ^ 1][(i + len) % 10], F[id][i] + val + tar);
}
int main() {
  scanf("%d", &n), memset(F[0], 0xff, sizeof F[0]), F[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    for (int j = 1; j <= m; j++) scanf("%d %d", &g[j].c, &g[j].d);
    sort(g + 1, g + 1 + m, cmp);
    for (int j = 1; j <= m; j++) F[i & 1][j] = F[i & 1 ^ 1][j];
    int mx1[2] = {-1, -1}, mx2 = -1;
    for (int j = 1; j <= m; j++) {
      if (g[j].c == 1) {
        int val = max(mx1[0], mx2);
        if (val != -1) update(i & 1 ^ 1, 2, (long long)val + g[j].d, g[j].d);
        if (mx1[0] != -1 && mx1[1] != -1)
          update(i & 1 ^ 1, 3, (long long)mx1[0] + mx1[1] + g[j].d, g[j].d);
        mx1[1] = mx1[0], mx1[0] = g[j].d;
      }
      if (g[j].c == 2) {
        if (mx1[0] != -1)
          update(i & 1 ^ 1, 2, (long long)mx1[0] + g[j].d, g[j].d);
        mx2 = g[j].d;
      }
    }
    update(i & 1 ^ 1, 1, (long long)g[m].d, g[m].d);
  }
  for (int i = 0; i < 10; i++) ans = max(ans, F[n & 1][i]);
  printf("%lld\n", ans);
  return 0;
}
