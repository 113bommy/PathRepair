#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n, m, k, ext[MAX], first[MAX], nextt[MAX * 2], u[MAX * 2], v[MAX * 2], cnt,
    dis[2][MAX], ans, mx[MAX];
bool vis[MAX], isExt[MAX];
void add(int a, int b) {
  u[cnt] = a, v[cnt] = b;
  nextt[cnt] = first[u[cnt]];
  first[u[cnt]] = cnt;
  ++cnt;
}
struct point {
  int x, y;
};
point p[MAX];
bool cmp(point a, point b) { return a.x < b.x; }
void bfs(int start, int op) {
  dis[op][start] = dis[op][0] = -1;
  memset(vis, false, sizeof(vis));
  deque<pair<int, int> > list1;
  list1.push_back({start, 0});
  while (!list1.empty()) {
    pair<int, int> now = list1.front();
    list1.pop_front();
    if (vis[now.first]) continue;
    vis[now.first] = true;
    dis[op][now.first] = dis[op][now.second] + 1;
    for (int num = first[now.first]; num != -1; num = nextt[num])
      if (!vis[v[num]]) list1.push_back({v[num], now.first});
  }
}
void solve() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) scanf("%d", &ext[i]), isExt[ext[i]] = true;
  memset(dis, 0x3f, sizeof(dis));
  memset(first, -1, sizeof(first));
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  bfs(1, 0);
  bfs(n, 1);
  for (int i = 1; i <= k; ++i) p[i].x = dis[0][ext[i]], p[i].y = dis[1][ext[i]];
  sort(p + 1, p + 1 + k, cmp);
  for (int i = k; i >= 1; --i) mx[i] = max(mx[i + 1], p[i].y);
  for (int i = 1; i < k; ++i) ans = max(ans, p[i].x + mx[i + 1] + 1);
  printf("%d\n", min(ans, dis[0][n]));
}
int main(void) {
  solve();
  return 0;
}
