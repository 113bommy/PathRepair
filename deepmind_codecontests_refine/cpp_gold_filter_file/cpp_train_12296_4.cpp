#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int inf = 0x3f3f3f3f;
int n, m, s, l, r[N], f[N][3001], ans = inf;
char col[N];
int main() {
  scanf("%d %d %d", &n, &s, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
  scanf("%s", col + 1);
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++) f[i][r[i]] = abs(i - s);
  for (int j = 1; j <= m + 50; j++)
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++)
        if (col[i] != col[k] && r[i] < r[k])
          f[k][j + r[k]] = min(f[k][j + r[k]], f[i][j] + abs(i - k));
  for (int i = 1; i <= n; i++)
    for (int j = m; j <= m + 50; j++) ans = min(ans, f[i][j]);
  if (ans == inf)
    puts("-1");
  else
    printf("%d\n", ans);
}
