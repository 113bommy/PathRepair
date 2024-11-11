#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y, z;
  node(int x, int y, int z) : x(x), y(y), z(z) {}
};
char a[22][22][22];
char c[22][22][22];
char dx[] = {0, 0, 1, -1, 0, 0};
char dy[] = {1, -1, 0, 0, 0, 0};
char dz[] = {0, 0, 0, 0, -1, 1};
int main() {
  int n, m, k;
  scanf("%d %d %d", &k, &n, &m);
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++) scanf("%s", a[i][j] + 1);
  int sx, sy;
  scanf("%d %d", &sx, &sy);
  queue<node> q;
  q.push(node(sx, sy, 1));
  c[1][sx][sy] = 1;
  int ans = 0;
  while (!q.empty()) {
    node f = q.front();
    q.pop();
    ans++;
    for (int i = 0; i < 6; i++) {
      int nx = f.x + dx[i];
      int ny = f.y + dy[i];
      int nz = f.z + dz[i];
      if (!c[nz][nx][ny] && a[nz][nx][ny] && a[nz][nx][ny] != '#') {
        c[nz][nx][ny] = 1;
        q.push(node(nx, ny, nz));
      }
    }
  }
  printf("%d", ans);
  return 0;
}
