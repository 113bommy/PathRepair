#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
const int MAXM = 2505;
const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, x, ans, mp[MAXN][MAXN], dis[MAXM], vis[MAXM];
struct Node {
  int to, dist;
  Node(int x, int y) { to = x, dist = y; }
};
vector<Node> v[MAXM];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline int check(int x, int y) { return x > 0 && x <= n && y > 0 && y <= m; }
inline int calc(int x, int y) { return (x - 1) * m + y; }
void bfs(int s) {
  int mmax = 0;
  deque<int> q;
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 1, q.push_back(s);
  while (!q.empty()) {
    x = q.front(), q.pop_front();
    if (mp[(x - 1) / m + 1][x - ((x - 1) / m) * m]) mmax = max(mmax, dis[x]);
    for (int i = 0; i < v[x].size(); i++)
      if (!vis[v[x][i].to]) {
        dis[v[x][i].to] = dis[x] + v[x][i].dist, vis[v[x][i].to] = 1;
        if (v[x][i].dist)
          q.push_back(v[x][i].to);
        else
          q.push_front(v[x][i].to);
      }
  }
  ans = min(ans, mmax);
}
int main() {
  n = read(), m = read(), ans = INF;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char ch = getchar();
      while (!isalpha(ch)) ch = getchar();
      mp[i][j] = (ch == 'B');
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k < 4; k++) {
        int ddx = i + dx[k], ddy = j + dy[k];
        if (!check(ddx, ddy)) continue;
        v[calc(i, j)].push_back(Node(calc(ddx, ddy), mp[i][j] != mp[ddx][ddy]));
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) bfs(calc(i, j));
  printf("%d\n", ans);
  return 0;
}
