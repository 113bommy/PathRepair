#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
char G[15][15];
bool vis[15][15][15][15];
int main() {
  int r, c, n, p;
  scanf("%d%d%d%d", &r, &c, &n, &p);
  int tot = r * c;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) G[i][j] = '*';
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    G[x][y] = '#';
  }
  int ans = 0;
  for (int i = 0; i < tot; i++) {
    int x = i / c, y = i % c;
    for (int j = i; j < tot; j++) {
      int cnt = 0;
      int xx = j / c, yy = j % c;
      if (!vis[min(x, xx)][min(y, yy)][max(x, xx)][max(y, yy)]) {
        for (int k = min(x, xx); k <= max(x, xx); k++)
          for (int t = min(y, yy); t <= max(y, yy); t++)
            if (G[k][t] == '#') cnt++;
        if (cnt == p) ans++;
        vis[min(x, xx)][min(y, yy)][max(x, xx)][max(y, yy)] = 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
