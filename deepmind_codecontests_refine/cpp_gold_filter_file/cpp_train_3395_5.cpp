#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct edge2 {
  int x, y, g;
} a[N * 10];
struct edge {
  int to, next, f;
} e[N * 50];
int head[N], tot = 1;
int dis[N], q[N];
int n, m, s, t, S, T;
void add(int x, int y, int f) {
  e[++tot] = (edge){y, head[x], f};
  head[x] = tot;
  e[++tot] = (edge){x, head[y], 0};
  head[y] = tot;
}
bool bfs(int s, int t) {
  for (int i = (int)(1); i <= (int)(T); i++) dis[i] = -1;
  int tt = 1;
  dis[q[1] = s] = 0;
  for (int h = (int)(1); h <= (int)(tt); h++)
    for (int i = head[q[h]]; i; i = e[i].next)
      if (dis[e[i].to] == -1 && e[i].f)
        dis[e[i].to] = dis[q[h]] + 1, q[++tt] = e[i].to;
  return dis[t] != -1;
}
int dfs(int x, int t, int flow) {
  if (x == t) return flow;
  int k, rest = flow;
  for (int i = head[x]; i; i = e[i].next)
    if (dis[e[i].to] == dis[x] + 1 && e[i].f) {
      k = dfs(e[i].to, t, min(rest, e[i].f));
      e[i].f -= k;
      e[i ^ 1].f += k;
      rest -= k;
    }
  if (rest) dis[x] = -1;
  return flow - rest;
}
int ans, be[N];
int Ans[N * 10], in[N];
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = (int)(1); i <= (int)(m); i++) {
    scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].g);
    if (a[i].x == s && a[i].y == t)
      ans++;
    else if (!a[i].g)
      add(a[i].x, a[i].y, (1 << 30));
    else {
      add(a[i].x, a[i].y, 1);
      add(a[i].y, a[i].x, (1 << 30));
    }
  }
  S = n + 1;
  T = S + 1;
  for (; bfs(s, t); ans += dfs(s, t, (1 << 30)))
    ;
  printf("%d\n", ans);
  for (int i = (int)(1); i <= (int)(n); i++) be[i] = (dis[i] != -1);
  memset(head, 0, sizeof(head));
  tot = 1;
  for (int i = (int)(1); i <= (int)(m); i++)
    if (a[i].g) {
      Ans[i] = tot + 1;
      add(a[i].x, a[i].y, 10000);
      ++in[a[i].y];
      --in[a[i].x];
    }
  for (int i = (int)(1); i <= (int)(n); i++)
    if (in[i] > 0)
      add(S, i, in[i]);
    else if (in[i] < 0)
      add(i, T, -in[i]);
  add(t, s, (1 << 30));
  for (; bfs(S, T); dfs(S, T, (1 << 30)))
    ;
  for (int i = (int)(1); i <= (int)(m); i++)
    if (a[i].x == s && a[i].y == t)
      puts("1 1");
    else if (!a[i].g)
      puts("0 1");
    else {
      int W = 10001 - e[Ans[i]].f;
      printf("%d %d\n", W, be[a[i].x] > be[a[i].y] ? W : (1 << 30));
    }
}
