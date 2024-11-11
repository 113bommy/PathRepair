#include <bits/stdc++.h>
using namespace std;
const int Maxn = 20, Maxm = 110, INF = 1e9;
int ans, n, m, f[Maxn][2], l[Maxn], r[Maxn];
char s[Maxn][Maxm];
int main() {
  for (; scanf("%d%d", &n, &m) != EOF;) {
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    m += 2;
    for (int i = 1; i <= n; i++) {
      l[i] = INF, r[i] = 0;
      for (int j = 1; j <= m; j++)
        if (s[i][j] == '1') l[i] = min(l[i], j), r[i] = max(r[i], j);
    }
    int p = 1;
    while (p <= n && l[p] == INF && r[p] == 0) p++;
    if (p == n + 1) {
      printf("%d\n", 0);
      continue;
    }
    if (p == n) {
      printf("%d\n", r[n] - 1);
      continue;
    }
    for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = INF;
    if (l[n] == INF && r[n] == 0)
      f[n][0] = 0, f[n][1] = m - 1;
    else
      f[n][0] = (r[n] - 1) * 2, f[n][1] = m - 1;
    ans = INF;
    for (int i = n - 1; i >= p; i--) {
      if (i == p) {
        ans = min(ans,
                  min(f[i + 1][0] + 1 + r[i] - 1, f[i + 1][1] + 1 + m - l[i]));
        continue;
      }
      if (l[i] == INF && r[i] == 0) {
        f[i][0] = min(f[i + 1][0] + 1, f[i + 1][1] + 1 + m - 1);
        f[i][1] = min(f[i + 1][1] + 1, f[i + 1][0] + 1 + m - 1);
      } else {
        f[i][0] =
            min(f[i + 1][0] + 1 + (r[i] - 1) * 2, f[i + 1][1] + 1 + m - 1);
        f[i][1] =
            min(f[i + 1][1] + 1 + (m - l[i]) * 2, f[i + 1][0] + 1 + m - 1);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
