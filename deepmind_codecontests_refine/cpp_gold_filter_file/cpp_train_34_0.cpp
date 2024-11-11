#include <bits/stdc++.h>
using namespace std;
const int N = 3000 + 3;
struct Edge {
  int to, nxt;
} e[N << 1];
int n, cnt;
int hd[N], top, q[N], tail, cur[N], c[N], pos[N], belong[N], dep[N], dis[N];
bool vis[N], used[N];
long double ans;
inline void addedge(int x, int y) {
  e[++top].to = y;
  e[top].nxt = hd[x];
  hd[x] = top;
  e[++top].to = x;
  e[top].nxt = hd[y];
  hd[y] = top;
}
inline void find_cycle(void) {
  int tail, now;
  for (int i = 1; i <= n; ++i) cur[i] = hd[i];
  for (vis[q[tail = 1] = 1] = 1; tail;)
    for (int& p = cur[now = q[tail]]; ~p; p = e[p].nxt)
      if (!used[p >> 1]) {
        used[p >> 1] = 1;
        if (vis[e[p].to]) {
          do c[++cnt] = q[tail--];
          while (c[cnt] != e[p].to);
          return;
        }
        vis[q[++tail] = e[p].to] = 1;
        p = e[p].nxt;
        break;
      } else if (!~e[p].nxt) {
        --tail;
        break;
      }
}
inline void init(void) {
  find_cycle();
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= cnt; ++i) vis[c[i]] = 1;
  for (int i = 1, l, r, now, p; i <= cnt; ++i) {
    pos[c[i]] = i;
    for (q[l = r = 1] = c[i]; l <= r; ++l) {
      belong[now = q[l]] = c[i];
      for (p = hd[now]; ~p; p = e[p].nxt)
        if (!vis[e[p].to])
          vis[q[++r] = e[p].to] = 1, dep[e[p].to] = dep[now] + 1;
    }
  }
}
inline void solve(int x) {
  memset(vis, 0, sizeof vis);
  memset(dis, 0, sizeof dis);
  int l, r, now, p;
  for (vis[q[l = r = 1] = x] = 1; l <= r; ++l) {
    now = q[l];
    ans += 1.0 / (dis[now] + 1);
    for (p = hd[now]; ~p; p = e[p].nxt)
      if (!(pos[now] && pos[e[p].to]))
        if (!vis[e[p].to])
          vis[q[++r] = e[p].to] = 1, dis[e[p].to] = dis[now] + 1;
  }
}
inline void calc(int x, int y) {
  int a = dep[x] + dep[y], b = abs(pos[belong[x]] - pos[belong[y]]) - 1,
      c = cnt - 2 - b;
  ans += 1.0 / (a + b + 2) + 1.0 / (a + c + 2) - 1.0 / (a + cnt);
}
int main(int argc, char** argv) {
  int x, y;
  memset(hd, -1, sizeof hd);
  top = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &x, &y), addedge(x + 1, y + 1);
  init();
  for (int i = 1; i <= n; ++i) {
    solve(i);
    for (int j = 1; j <= n; ++j)
      if (belong[i] != belong[j]) calc(i, j);
  }
  printf("%.10lf\n", (double)ans);
  return 0;
}
