#include <bits/stdc++.h>
using namespace std;
struct E {
  int wz;
  int to;
  int w;
  int nx;
} E[600010];
struct node {
  int dian;
  long long w;
  bool operator<(const node &t) const { return w > t.w; }
};
int m, n, k, ct, fg[600010], head[600010], lax[600010], jg[600010];
long long dis[600010];
priority_queue<node> q;
void addE(int x, int y, int wz, int w) {
  E[ct].to = y;
  E[ct].w = w;
  E[ct].wz = wz;
  E[ct].nx = head[x];
  head[x] = ct++;
}
void dij() {
  for (int i = 1; i <= n; i++) dis[i] = 0x3f3f3f3f3f3f3f3f, lax[i] = -1;
  dis[1] = 0ll;
  q.push((node){1, 0ll});
  fg[1] = 1;
  while (!q.empty()) {
    node xz = q.top();
    q.pop();
    fg[xz.dian] = 0;
    for (int i = head[xz.dian]; i != -1; i = E[i].nx) {
      int nx = E[i].to;
      if (dis[nx] > dis[xz.dian] + (long long)E[i].w) {
        dis[nx] = dis[xz.dian] + (long long)E[i].w;
        if (!fg[nx]) q.push((node){nx, dis[nx]}), fg[nx] = 1;
        lax[nx] = xz.dian;
      }
    }
  }
}
int num;
void bfs() {
  queue<int> q;
  q.push(1);
  if (num == n || num == k) return;
  while (!q.empty()) {
    int xz = q.front();
    q.pop();
    for (int i = head[xz]; i != -1; i = E[i].nx) {
      if (lax[E[i].to] == xz) {
        jg[num++] = E[i].wz;
        q.push(E[i].to);
        if (num == n || num == k) return;
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int x, y, w;
  for (int i = 1; i <= n; i++) head[i] = -1, fg[i] = 0;
  ct = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &w);
    addE(x, y, i, w);
    addE(y, x, i, w);
  }
  num = 0;
  dij();
  bfs();
  printf("%d\n", num);
  for (int i = 0; i < num; i++) printf("%d ", jg[i]);
  return 0;
}
