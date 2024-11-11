#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int a[maxn][maxn], vis[maxn][maxn];
int dir[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
string road;
int n, m, k;
int x, y, u, v;
void DFS(int sx, int sy) {
  vis[sx][sy] = 1;
  for (int i = 0; i < 4; i++) {
    int x = sx + dir[i][0];
    int y = sy + dir[i][1];
    if (x < 1 || y < 1 || x > n || y > m) continue;
    if (vis[x][y]) continue;
    vis[x][y] = 1;
    if (dir[i][0] == 1 && dir[i][1] == 0) {
      road += 'D';
      DFS(x, y);
    } else if (dir[i][0] == -1 && dir[i][1] == 0) {
      road += 'U';
      DFS(x, y);
    } else if (dir[i][0] == 0 && dir[i][1] == 1) {
      road += 'R';
      DFS(x, y);
    } else if (dir[i][0] == 0 && dir[i][1] == -1) {
      road += 'L';
      DFS(x, y);
    }
  }
  return;
}
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
  }
  for (int j = 1; j <= k; j++) {
    scanf("%d%d", &u, &v);
  }
  for (int i = 1; i < n; i++) {
    road += 'L';
  }
  for (int j = 1; j < m; j++) {
    road += 'D';
  }
  DFS(1, 1);
  printf("%d\n", road.size());
  cout << road << endl;
  return 0;
}
