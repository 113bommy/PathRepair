#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    res = (res << 3) + (res << 1) + ch - '0';
    ch = getchar();
  }
  return res * f;
}
namespace qiqi {
const int N = 2e3 + 5, M = 2e5 + 5;
long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m, s, t, ecnt, head[N], p[N], siz[N][N];
long long v[N], sum[N][N], dis[2][N], dp[2][N][N];
bool vis[N];
struct Edge {
  int v, w, nxt;
} e[M];
inline void add(int u, int v, int w) {
  e[++ecnt] = (Edge){v, w, head[u]};
  head[u] = ecnt;
}
struct Node {
  int p;
  long long k;
  inline bool friend operator<(Node a, Node b) { return a.k > b.k; }
};
priority_queue<Node> q;
inline int Siz(int x1, int y1, int x2, int y2) {
  return siz[x2][y2] - siz[x2][y1 - 1] - siz[x1 - 1][y2] + siz[x1 - 1][y1 - 1];
}
inline long long Sum(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
inline void Dij(int s, int k) {
  memset(vis, 0, sizeof(vis));
  memset(dis[k], INF, sizeof(dis[k]));
  q.push((Node){s, dis[k][s] = 0});
  while (!q.empty()) {
    int u = q.top().p;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
      if (dis[k][v] > dis[k][u] + e[i].w)
        q.push((Node){v, dis[k][v] = dis[k][u] + e[i].w});
  }
  for (int i = (1); i <= (n); ++i) v[i] = dis[k][i];
  sort(v + 1, v + n + 1);
  v[0] = unique(v + 1, v + n + 1) - v - 1;
  for (int i = (1); i <= (n); ++i)
    dis[k][i] = upper_bound(v + 1, v + v[0] + 1, dis[k][i]) - v - 1;
}
void main() {
  int x, y, k;
  n = read();
  m = read();
  s = read();
  t = read();
  for (int i = (1); i <= (n); ++i) p[i] = read();
  for (int i = (1); i <= (m); ++i) {
    x = read();
    y = read();
    k = read();
    add(x, y, k);
    add(y, x, k);
  }
  Dij(s, 0);
  Dij(t, 1);
  for (int i = (1); i <= (n); ++i) {
    ++siz[dis[0][i]][dis[1][i]];
    sum[dis[0][i]][dis[1][i]] += p[i];
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      siz[i][j] += siz[i][j - 1];
      sum[i][j] += sum[i][j - 1];
    }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      siz[i][j] += siz[i - 1][j];
      sum[i][j] += sum[i - 1][j];
    }
  for (int i = (n); i >= (1); --i)
    for (int j = (n); j >= (1); --j) {
      dp[0][i][j] = Siz(i, j, i, n) ? max(dp[0][i + 1][j], dp[1][i + 1][j]) +
                                          Sum(i, j, i, n)
                                    : dp[0][i + 1][j];
      dp[1][i][j] = Siz(i, j, n, j) ? min(dp[0][i][j + 1], dp[1][i][j + 1]) -
                                          Sum(i, j, n, j)
                                    : dp[1][i][j + 1];
    }
  puts(dp[0][1][1] ? (dp[0][1][1] > 0 ? "Break a heart" : "Cry") : "Flowers");
}
}  // namespace qiqi
int main() {
  qiqi::main();
  return 0;
}
