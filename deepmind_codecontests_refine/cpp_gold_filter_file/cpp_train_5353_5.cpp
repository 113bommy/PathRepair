#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
const unsigned short inf = ~0;
int s, boy[505];
long long dis[505][505];
vector<int> e[505];
unsigned short f[505][505][505], best[505][505];
int sz[505];
void dfs(int x, int par) {
  for (auto c : e[x])
    if (c != par) dfs(c, x);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    if (dis[x][i] > m) continue;
    sz[x] = 1;
    f[x][i][1] = !boy[i];
    for (int y : e[x])
      if (y != par) {
        for (int k = min(s, sz[x] + sz[y]);; k--) {
          int tmp = inf;
          for (int j = max(k - sz[x], 0); j <= min(k, sz[y]); j++) {
            tmp = min(tmp, f[x][i][k - j] + best[y][j]);
          }
          for (int j = max(k - sz[x], 0) + 1; j <= min(k, sz[y]); j++) {
            tmp = min(tmp, f[x][i][k - j + 1] + f[y][i][j] - !boy[i]);
          }
          f[x][i][k] = tmp;
          if (!k) break;
        }
        sz[x] += sz[y];
      }
  }
  for (int(i) = 1; (i) <= (int)(s); (i)++) {
    best[x][i] = inf;
    for (int(j) = 1; (j) <= (int)(n); (j)++) {
      best[x][i] = min(best[x][i], f[x][j][i]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d", boy + i);
    s += boy[i];
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(n); (j)++) dis[i][j] = i == j ? 0 : 1e9;
  for (int i = 0, u, v, w; i < n - 1; i++) {
    scanf("%d%d%d", &u, &v, &w);
    e[u].push_back(v);
    e[v].push_back(u);
    dis[u][v] = dis[v][u] = w;
  }
  for (int(k) = 1; (k) <= (int)(n); (k)++)
    for (int(i) = 1; (i) <= (int)(n); (i)++)
      for (int(j) = 1; (j) <= (int)(n); (j)++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  memset(best, 0xff, sizeof best);
  memset(f, 0xff, sizeof f);
  dfs(1, 0);
  printf("%d\n", best[1][s] == inf ? -1 : best[1][s]);
  return 0;
}
