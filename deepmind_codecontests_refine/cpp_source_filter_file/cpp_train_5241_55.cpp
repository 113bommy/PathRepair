#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 10) + 1;
int n;
int pts[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx4[] = {-1, 0, 0, 1};
int dy4[] = {0, -1, 1, 0};
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void read() {
  scanf("%d", &n);
  for (int y = 0; y < (n); y++)
    for (int x = 0; x < (n); x++) scanf("%d", &pts[y][x]);
}
inline bool ok(int x, int y) { return 0 <= x and x < n and 0 <= y and y < n; }
void dfs(int x, int y, vector<pair<int, int> > &res, vector<int> &dist) {
  if (not ok(x, y) or (vis[y][x] or not pts[y][x])) return;
  vis[y][x] = true;
  res.push_back(pair<int, int>(x, y));
  for (int i = 0; i < (4); i++) {
    dfs(x + dx4[i], y + dy4[i], res, dist);
  }
  int cnt = 0;
  for (int i = 0; i < (8); i++) {
    int nx = x + dx8[i];
    int ny = y + dy8[i];
    if (ok(nx, ny) and pts[ny][nx]) cnt++;
  }
  dist[cnt]++;
}
double sq(double x) { return x * x; }
void compute() {
  for (int y = 0; y < (n); y++)
    for (int x = 0; x < (n); x++) vis[y][x] = false;
  int squares = 0;
  int circles = 0;
  for (int y = 0; y < (n); y++)
    for (int x = 0; x < (n); x++) {
      if (pts[y][x] and not vis[y][x]) {
        vector<pair<int, int> > p;
        vector<int> dist(9);
        dfs(x, y, p, dist);
        int all = 0;
        for (int i = 0; i < (8); i++) all += dist[i];
        double var = 0;
        for (int i = 0; i < (8); i++) {
          var += sq(double(dist[i]) / all - (1.0l) / all);
        }
        if (0) printf("var:%lf\n", var);
        if (0) {
          printf("dist:[");
          for (int i = 0; i < (9); i++) printf("%lf, ", double(dist[i]) / all);
          printf("]\n");
        }
        if (var > 0.5)
          squares++;
        else
          circles++;
      }
    }
  printf("%d %d\n", circles, squares);
}
int main() {
  read();
  compute();
  return 0;
}
