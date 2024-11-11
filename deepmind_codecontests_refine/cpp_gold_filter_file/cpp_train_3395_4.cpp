#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = 1000, INF = (1 << 30) - 1;
int n, m, st0, td0;
struct side0 {
  int x, y, g;
  side0(int X = 0, int Y = 0, int G = 0) {
    x = X;
    y = Y;
    g = G;
  }
} a[M + 9];
void into() {
  scanf("%d%d%d%d", &n, &m, &st0, &td0);
  for (int i = 1; i <= m; ++i) {
    int x, y, g;
    scanf("%d%d%d", &x, &y, &g);
    a[i] = side0(x, y, g);
  }
}
int st, td, cn;
int df[N + 9];
struct side {
  int y, next, f;
} e[M * 10 + 9];
int lin[N + 9], cs;
void Ins(int x, int y, int f) {
  e[++cs].y = y;
  e[cs].f = f;
  e[cs].next = lin[x];
  lin[x] = cs;
}
void Ins_flow(int x, int y, int f) {
  Ins(x, y, f);
  Ins(y, x, 0);
}
int dis[N + 9];
queue<int> q;
bool Bfs_dis(int st, int td) {
  for (int i = 1; i <= cn; ++i) dis[i] = 0;
  for (; !q.empty(); q.pop())
    ;
  dis[st] = 1;
  q.push(st);
  for (; !q.empty();) {
    int t = q.front();
    q.pop();
    for (int i = lin[t]; i; i = e[i].next)
      if (e[i].f && !dis[e[i].y]) {
        dis[e[i].y] = dis[t] + 1;
        if (e[i].y == td) return 1;
        q.push(e[i].y);
      }
  }
  return dis[td];
}
int cur[N + 9];
int Dfs_flow(int k, int td, int f) {
  if (k == td || !f) return f;
  int res = 0;
  for (int &i = cur[k]; i; i = e[i].next)
    if (e[i].f && dis[k] + 1 == dis[e[i].y]) {
      int t = Dfs_flow(e[i].y, td, min(f, e[i].f));
      if (!t) dis[e[i].y] = 0;
      f -= t;
      res += t;
      e[i].f -= t;
      e[i ^ 1].f += t;
      if (!f) return res;
    }
  return res;
}
int Max_flow(int st, int td) {
  int res = 0;
  for (; Bfs_dis(st, td); res += Dfs_flow(st, td, INF))
    for (int i = 1; i <= cn; ++i) cur[i] = lin[i];
  return res;
}
int vis[N + 9];
void Dfs_vis(int k) {
  vis[k] = 1;
  for (int i = lin[k]; i; i = e[i].next)
    if (e[i].f && !vis[e[i].y]) Dfs_vis(e[i].y);
}
int cut[M + 9];
void Get_cut() {
  cs = 1;
  cn = n;
  for (int i = 1; i <= m; ++i) Ins_flow(a[i].x, a[i].y, a[i].g ? 1 : INF);
  for (int i = 1; i <= m; ++i)
    if (a[i].g) Ins_flow(a[i].y, a[i].x, INF);
  Max_flow(st0, td0);
  Dfs_vis(st0);
  for (int i = 1; i <= m; ++i)
    if (vis[a[i].x] && !vis[a[i].y]) cut[i] = 1;
  for (int i = 2; i <= cs; ++i) e[i].f = 0;
}
int ans[M + 9][2];
void Get_ans() {
  for (int i = 1; i <= m; ++i)
    if (a[i].g) {
      --df[a[i].x];
      ++df[a[i].y];
      e[i << 1].f = cut[i] ? m : INF;
    }
  st = n + 1;
  td = cn = n + 2;
  for (int i = 1; i <= n; ++i) {
    if (!df[i]) continue;
    df[i] > 0 ? Ins_flow(st, i, df[i]) : Ins_flow(i, td, -df[i]);
  }
  Ins_flow(td0, st0, INF);
  Max_flow(st, td);
  for (int i = 1; i <= m; ++i)
    if (cut[i])
      ans[i][0] = ans[i][1] = 1 + e[i << 1 | 1].f;
    else if (a[i].g) {
      ans[i][0] = 2 + e[i << 1 | 1].f;
      ans[i][1] = 1 + e[i << 1 | 1].f;
    } else
      ans[i][0] = 1, ans[i][1] = 0;
}
void work() {
  Get_cut();
  Get_ans();
}
void outo() {
  int cnt = 0;
  for (int i = 1; i <= m; ++i) cnt += cut[i];
  printf("%d\n", cnt);
  for (int i = 1; i <= m; ++i) printf("%d %d\n", ans[i][1], ans[i][0]);
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
