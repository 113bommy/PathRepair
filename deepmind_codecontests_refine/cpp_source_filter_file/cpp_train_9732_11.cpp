#include <bits/stdc++.h>
const int N = 1e5;
using namespace std;
int n, m, sum, cnt;
int head[N], d[N], f[N], p[N];
bool vis[N << 1];
struct Edge {
  int u, v, s, nxt;
} e[N << 1];
void ad(int u, int v, int s) {
  e[cnt].u = u;
  e[cnt].v = v;
  e[cnt].s = s;
  e[cnt].nxt = head[u];
  head[u] = cnt++;
}
void add(int u, int v, int s) {
  ad(u, v, s);
  ad(v, u, s);
}
void bfs(int s = 1) {
  memset(d, 0x3f, sizeof d);
  priority_queue<pair<int, int> > q;
  d[s] = 0;
  f[s] = sum;
  p[s] = -1;
  q.push(make_pair(-d[s], s));
  while (!q.empty()) {
    pair<int, int> tp = q.top();
    q.pop();
    int u = tp.second;
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; ~i; i = e[i].nxt) {
      int v = e[i].v;
      if (vis[v]) continue;
      if (d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        if (e[i].s)
          f[v] = f[u] - 1;
        else
          f[v] = f[u] + 1;
        q.push(make_pair(-d[v], v));
        p[v] = i;
      } else if (d[v] == d[u] + 1) {
        int tmp = f[u];
        if (e[i].s)
          tmp--;
        else
          tmp++;
        if (tmp < f[v]) {
          f[v] = tmp;
          p[v] = i;
        }
      }
    }
  }
}
void fp(int s = p[n]) {
  if (s == -1) return;
  vis[s] = 1;
  fp(p[e[s].u]);
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v, s;
  memset(head, -1, sizeof head);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &s);
    add(u, v, s);
    sum += s;
  }
  bfs();
  memset(vis, 0, sizeof vis);
  fp();
  printf("%d\n", f[n]);
  for (int i = 0; i < 2 * m; i += 2) {
    if (!e[i].s && (vis[i] || vis[i + 1])) {
      printf("%d %d 1\n", e[i].u, e[i].v);
    } else if (e[i].s && !vis[i] && !vis[i + 1]) {
      printf("%d %d 0\n", e[i].u, e[i].v);
    }
  }
  return 0;
}
