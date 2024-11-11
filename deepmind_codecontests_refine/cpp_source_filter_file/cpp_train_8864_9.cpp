#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[500005][20];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    f[x][0] = max(f[x][0], y);
  }
  for (int i = 1; i < 500005; i++) f[i][0] = max(f[i - 1][0], f[i][0]);
  for (int i = 1; i < 20; i++)
    for (int j = 1; j < 500005; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int x1 = x, ans = 0;
    for (int i = 19; i >= 0; i--)
      if (f[x1][i] < y) x1 = f[x1][i], ans += (1 << i);
    if (f[x1][0] >= y)
      printf("%d\n", ans + 1);
    else
      printf("-1\n");
  }
}
