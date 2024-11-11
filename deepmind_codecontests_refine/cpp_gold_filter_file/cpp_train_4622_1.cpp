#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
struct tnode {
  int x, y;
  int sub;
} station[101];
int n;
int cost;
int f[101];
bool vis[101];
bool cmp(tnode a, tnode b) {
  return (abs(a.x - station[n].x) + abs(a.y - station[n].y) >
          abs(b.x - station[n].x) + abs(b.y - station[n].y));
}
void Memory_dfs(int x) {
  if (x == n) {
    f[x] = 0;
    return;
  }
  if (f[x] != -1) return;
  f[x] = -station[x].sub;
  int tem = inf;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    Memory_dfs(i);
    vis[i] = 0;
    tem = min(tem, (abs(station[i].x - station[x].x) +
                    abs(station[i].y - station[x].y)) *
                           cost +
                       f[i]);
  }
  f[x] += tem;
}
int main() {
  memset(f, 255, sizeof(f));
  memset(vis, 0, sizeof(vis));
  scanf("%d%d", &n, &cost);
  for (int i = 2; i < n; i++) scanf("%d", &station[i].sub);
  station[1].sub = 0;
  for (int i = 1; i <= n; i++) scanf("%d%d", &station[i].x, &station[i].y);
  sort(&station[2], &station[n], cmp);
  vis[1] = 1;
  Memory_dfs(1);
  printf("%d\n", f[1]);
  return 0;
}
