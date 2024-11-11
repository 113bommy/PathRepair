#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, len, tot, cnt, x, y, cur;
bool a[N][N], g[N][N];
pair<int, int> st[N * N];
bool vis[N][N];
double lee[N * N];
queue<pair<int, int> > q;
bool dfs(int s, int t) {
  q.push(pair<int, int>(s, t));
  vis[s][t] = 1;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    int cnt = 0, tot = 0;
    for (int dx = -3; dx <= 3; ++dx)
      for (int dy = -3; dy <= 3; ++dy) {
        int u = x + dx, v = y + dy;
        if (u > 0 && u <= n && v > 0 && v <= n && !vis[u][v]) {
          ++tot;
          if (a[u][v]) ++cnt;
        }
      }
    if (x == s && y == t && cnt < tot * 0.5) return 0;
    st[++len] = pair<int, int>(x, y);
    g[x][y] = 1;
    if (cnt < tot * 0.5) {
      continue;
    }
    for (int dx = -3; dx <= 3; ++dx)
      for (int dy = -3; dy <= 3; ++dy) {
        int u = x + dx, v = y + dy;
        if (u > 0 && u <= n && v > 0 && v <= n && !vis[u][v])
          if (a[u][v]) {
            q.push(pair<int, int>(u, v));
            vis[u][v] = 1;
          }
      }
  }
  return 1;
}
inline double sqr(double x) { return x * x; }
inline double dist(int x1, int x2, int y1, int y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
double calc(int x, int y) {
  double ans = 0;
  for (int i = 1; i <= len; ++i) ans += dist(x, st[i].first, y, st[i].second);
  return ans;
}
inline bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return dist(x, a.first, y, a.second) > dist(x, b.first, y, b.second);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      char ch = getchar();
      while (ch != '1' && ch != '0') ch = getchar();
      a[i][j] = ch == '1';
    }
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!vis[i][j] && a[i][j]) {
        len = 0;
        if (dfs(i, j)) {
          if (len < 120) continue;
          ++tot;
          x = i, y = j;
          double mx = 0;
          for (int l = 1; l <= len; ++l) {
            double dis = dist(st[l].first, x, st[l].second, y);
            if (dis > mx) {
              mx = dis;
            }
          }
          int z = sqr(mx / 2) * 3.14;
          if ((double)len / z > 0.85) ++cnt;
        }
      }
  printf("%d %d\n", cnt, tot - cnt);
}
