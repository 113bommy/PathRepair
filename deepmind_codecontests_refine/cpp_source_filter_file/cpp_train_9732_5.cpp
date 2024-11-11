#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct edge {
  int x, y, next, flag;
} e[N * 2];
int first[N], tot = -1, vis[N], pre[N][2], dis[N], num[N];
queue<int> p;
bool g[N * 2], g1[N * 2];
void add(int x, int y, int flag) {
  e[++tot] = (edge){x, y, first[x], flag};
  first[x] = tot;
}
void spfa() {
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  memset(num, 0x3f3f3f3f, sizeof(num));
  dis[1] = 0;
  num[1] = 0;
  vis[1] = 1;
  p.push(1);
  while (!p.empty()) {
    int x = p.front();
    p.pop();
    vis[x] = 0;
    for (int i = first[x]; i >= 0; i = e[i].next) {
      int y = e[i].y;
      int z = e[i].flag ^ 1;
      if (dis[y] == dis[x] + 1 && num[y] > num[x] + z) {
        num[y] = num[x] + z;
        pre[y][0] = x;
        pre[y][1] = i;
        if (!vis[y]) vis[y] = 1, p.push(y);
      } else if (dis[y] > dis[x] + 1) {
        dis[y] = dis[x] + 1;
        num[y] = num[x] + z;
        pre[y][0] = x;
        pre[y][1] = i;
        if (!vis[y]) vis[y] = 1, p.push(y);
      }
    }
  }
}
int main() {
  int n, m;
  memset(first, -1, sizeof(first));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
    add(y, x, z);
  }
  spfa();
  int now = n;
  memset(g, false, sizeof(g));
  memset(g1, false, sizeof(g1));
  while (now != 1) {
    g[pre[now][1]] = g[pre[now][1] ^ 1] = true;
    if (!e[pre[now][1]].flag) g1[pre[now][1]] = g1[pre[now][1] ^ 1] = true;
    now = pre[now][0];
  }
  int ans[N][4], nn = 0;
  for (int i = 0; i <= tot; i += 2) {
    if (!g[i] || !g[i ^ 1] && e[i].flag) {
      ans[++nn][1] = e[i].x;
      ans[nn][2] = e[i].y;
      ans[nn][3] = 0;
    }
    if (g1[i] || !g1[i ^ 1]) {
      ans[++nn][1] = e[i].x;
      ans[nn][2] = e[i].y;
      ans[nn][3] = 1;
    }
  }
  printf("%d\n", nn);
  for (int i = 1; i <= nn; ++i)
    printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
  return 0;
}
