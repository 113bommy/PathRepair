#include <bits/stdc++.h>
using namespace std;
const int maxn = 405;
const int maxm = 5005;
const int INF = 1000000000;
const int mod = 1000000;
struct EDGE {
  int cap, cost, v, next;
} edge[mod];
int head[maxn], E, q[mod];
bool used[maxn];
int pre[maxn], cur[maxn], dis[maxn];
void add_edge(int s, int t, int cap, int cost) {
  edge[E].cap = cap;
  edge[E].cost = cost;
  edge[E].next = head[s];
  edge[E].v = t;
  head[s] = E++;
  edge[E].cap = 0;
  edge[E].cost = -cost;
  edge[E].next = head[t];
  edge[E].v = s;
  head[t] = E++;
}
int min(int a, int b) { return (a == -1 || b < a) ? b : a; }
int SPFA(int s, int t, int n) {
  int f = -1, r = 0;
  int i, v;
  q[r] = s;
  for (i = 0; i < n; i++) dis[i] = INF;
  dis[s] = 0;
  pre[s] = s;
  cur[s] = -1;
  memset(used, false, sizeof(bool) * n);
  used[s] = true;
  while (f != r) {
    f++;
    if (f >= mod) f -= mod;
    s = q[f];
    used[s] = false;
    for (i = head[s]; i != -1; i = edge[i].next) {
      v = edge[i].v;
      if (edge[i].cap > 0 && dis[s] + edge[i].cost < dis[v]) {
        dis[v] = dis[s] + edge[i].cost;
        pre[v] = s;
        cur[v] = i;
        if (!used[v]) {
          used[v] = true;
          r++;
          if (r >= mod) r -= mod;
          q[r] = v;
        }
      }
    }
  }
  return dis[t];
}
int MinCost(int s, int t, int n) {
  int ans = 0;
  int u, v, cap;
  int cost;
  while (1) {
    cost = SPFA(s, t, n);
    if (cost == INF) break;
    u = v = t;
    cap = -1;
    for (u = t; u != s; u = pre[u]) {
      cap = min(cap, edge[cur[u]].cap);
    }
    ans += cost * cap;
    u = v = t;
    for (u = t; u != s; u = pre[u]) {
      edge[cur[u]].cap -= cap;
      edge[cur[u] ^ 1].cap += cap;
    }
  }
  return ans;
}
int dx[maxn];
int dy[maxn];
int c[maxm];
int x[maxm];
int y[maxm];
int main() {
  int n, m, g, k, z;
  int i, j;
  int s, t;
  while (scanf("%d%d%d%d", &n, &m, &k, &g) != -1) {
    memset(dx, 0, sizeof(int) * n);
    memset(dy, 0, sizeof(int) * m);
    for (i = 0; i < k; i++) {
      scanf("%d%d", &x[i], &y[i]);
      dx[--x[i]]++;
      dy[--y[i]]++;
    }
    int ans = 0;
    for (i = 0; i < n; i++) ans += dx[i] % g != 0;
    for (i = 0; i < m; i++) ans += dy[i] % g != 0;
    printf("%d\n", ans);
    memset(c, -1, sizeof(int) * k);
    s = n + m;
    t = s + 1;
    for (; g >= 1; g--) {
      E = 0;
      memset(head, -1, sizeof(int) * (t + 1));
      for (i = 0; i < k; i++)
        if (c[i] == -1) add_edge(x[i], y[i] + n, 1, 0);
      for (i = 0; i < n; i++) {
        add_edge(s, i, dx[i] / g, 0);
        if (dx[i] % g) add_edge(s, i, 1, 1);
      }
      for (i = 0; i < m; i++) {
        add_edge(i + n, t, dy[i] / g, 0);
        if (dy[i] % g) add_edge(i + n, t, 1, 1);
      }
      MinCost(s, t, t + 1);
      for (i = 0, z = 0; i < k; i++)
        if (c[i] == -1) {
          if (edge[z].cap == 0) {
            c[i] = g;
            dx[x[i]]--;
            dy[y[i]]--;
          }
          z += 2;
        }
    }
    for (i = 0; i < k; i++) {
      if (i) printf(" ");
      printf("%d", c[i]);
    }
    puts("");
  }
  return 0;
}
