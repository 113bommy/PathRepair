#include <bits/stdc++.h>
using namespace std;
const int maxn = 1050;
struct node {
  int x, y;
} e[maxn];
int x, y, n, d;
int vis[maxn][maxn];
int dfs(int x, int y) {
  if ((x - 200) * (x - 200) + (y - 200) * (y - 200) >= d * d) return 1;
  if (vis[x][y] != -1) return vis[x][y];
  for (int i = 0; i < n; ++i) {
    if (!dfs(x + e[i].x, y + e[i].y)) return vis[x][y] = 1;
  }
  return vis[x][y] = 0;
}
int main() {
  cin >> x >> y;
  x += 200;
  y += 200;
  cin >> n >> d;
  memset(vis, -1, sizeof vis);
  for (int i = 0; i < n; ++i) {
    cin >> e[i].x >> e[i].y;
  }
  if (dfs(x, y))
    cout << "Anton" << endl;
  else
    cout << "Dasha" << endl;
  return 0;
}
