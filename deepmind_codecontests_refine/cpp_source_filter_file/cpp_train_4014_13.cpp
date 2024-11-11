#include <bits/stdc++.h>
using namespace std;
const int N = 30;
const int M = 410;
struct P {
  int x, y;
} a[N];
int vis[M][M];
int x, y, n, d;
bool dfs(int tx, int ty) {
  if (vis[tx][ty] != -1) return vis[tx][ty];
  if ((tx - 200) * (tx - 200) + (ty - 200) * (ty - 200) >= d * d) return 1;
  for (int i = 1; i <= n; i++)
    if (!dfs(tx + a[i].x, ty + a[i].y)) {
      vis[tx][ty] = 1;
      return 1;
    }
  vis[tx][ty] = 0;
  return 0;
}
int main() {
  scanf("%d%d%d%d", &x, &y, &n, &d);
  x += 200;
  y += 200;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  memset(vis, -1, sizeof(vis));
  if (dfs(x, y))
    puts("Anton");
  else
    puts("Dasha");
  return 0;
}
