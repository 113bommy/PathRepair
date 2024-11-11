#include <bits/stdc++.h>
using namespace std;
const int maxn = 101, oo = ~0U >> 1;
struct pack {
  int x, y, z;
  bool operator<(const pack &o) const { return z > o.z; }
};
int n, m;
int ans = oo;
int d[maxn][maxn], w[maxn][maxn][4];
char col[maxn][maxn];
priority_queue<pack> Q;
void PUSH(int x, int y, int z) {
  if (z < d[x][y]) d[x][y] = z, Q.push((pack){x, y, z});
}
int dij(int x, int y) {
  int z, ans = 0;
  memset(d, 127, sizeof(d));
  PUSH(x, y, 0);
  while (!Q.empty()) {
    x = Q.top().x, y = Q.top().y, z = Q.top().z;
    Q.pop();
    if (z > d[x][y]) continue;
    if (x - 1 >= 0) PUSH(x - 1, y, d[x][y] + w[x][y][0]);
    if (x + 1 < n) PUSH(x + 1, y, d[x][y] + w[x][y][1]);
    if (y - 1 >= 0) PUSH(x, y - 1, d[x][y] + w[x][y][2]);
    if (y + 1 < m) PUSH(x, y + 1, d[x][y] + w[x][y][3]);
  }
  for (x = 0; x < n; ++x)
    for (y = 0; y < m; ++y)
      if (col[x][y] == 'B') ans = max(ans, d[x][y]);
  return ans;
}
int main() {
  int i, j;
  bool exist = false;
  scanf("%d%d\n", &n, &m);
  for (i = 0; i < n; ++i) scanf("%s", col[i]);
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      if (i - 1 >= 0) w[i][j][0] = col[i][j] != col[i - 1][j];
      if (i + 1 < n) w[i][j][1] = col[i][j] != col[i + 1][j];
      if (j - 1 >= 0) w[i][j][2] = col[i][j] != col[i][j - 1];
      if (j + 1 < m) w[i][j][3] = col[i][j] != col[i][j + 1];
      if (col[i][j] == 'W') exist = true;
    }
  if (exist) {
    for (i = 0; i < n; ++i)
      for (j = 0; j < m; ++j) ans = min(ans, dij(i, j));
    printf("%d", ans + 1);
  } else
    printf("0");
  return 0;
}
