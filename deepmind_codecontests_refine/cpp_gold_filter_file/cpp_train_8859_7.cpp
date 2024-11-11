#include <bits/stdc++.h>
using namespace std;
struct node {
  int r, c, x, y;
  node(int r, int c, int x, int y) : r(r), c(c), x(x), y(y) {}
};
const int maxn = 2005;
char mp[maxn][maxn];
int n, m, r, c, x, y, vis[maxn][maxn];
deque<node> q;
bool check(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) {
    if (mp[x][y] != '*') return 1;
  }
  return 0;
}
int main() {
  cin >> n >> m >> r >> c >> x >> y;
  for (int i = 1; i <= n; i++) scanf(" %s", mp[i] + 1);
  q.push_front(node(r, c, x, y));
  int ans = 0;
  while (!q.empty()) {
    node now = q.front();
    q.pop_front();
    if (vis[now.r][now.c]) continue;
    vis[now.r][now.c] = 1;
    ans++;
    if (check(now.r - 1, now.c))
      q.push_front(node(now.r - 1, now.c, now.x, now.y));
    if (check(now.r + 1, now.c))
      q.push_front(node(now.r + 1, now.c, now.x, now.y));
    if (check(now.r, now.c - 1) && now.x)
      q.push_back(node(now.r, now.c - 1, now.x - 1, now.y));
    if (check(now.r, now.c + 1) && now.y)
      q.push_back(node(now.r, now.c + 1, now.x, now.y - 1));
  }
  cout << ans;
  return 0;
}
