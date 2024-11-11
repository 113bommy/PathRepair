#include <bits/stdc++.h>
using namespace std;
int getnum() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 210, M = 100010, INF = 1000000010;
int n, k;
int S, T;
int cnt = 1;
int head[N];
struct edge {
  int v, nxt, w, c;
} vec[M];
int A[N];
int C[N];
int P[N];
int dis[N];
int fifo[N];
bool inq[N];
bool vis[N];
void get_read() {
  n = getnum();
  k = getnum();
  for (int i = 1; i <= n; ++i) A[i] = getnum();
  for (int i = 1; i <= n; ++i) C[i] = getnum();
}
void debug() { cout << "!" << endl; }
void addedge(int u, int v, int w, int c) {
  vec[++cnt] = (edge){v, head[u], w, c};
  head[u] = cnt;
}
void add(int u, int v, int w, int c) {
  addedge(u, v, w, c);
  addedge(v, u, 0, -c);
}
bool spfa() {
  for (int i = 1; i <= T; ++i) dis[i] = INF;
  int f = 0, r = 1;
  fifo[1] = T;
  dis[T] = 0;
  inq[T] = true;
  while (f != r) {
    int u = fifo[f = (f + 1) % (T + 1)];
    for (int i = head[u]; i; i = vec[i].nxt) {
      if (!vec[i ^ 1].w) continue;
      int v = vec[i].v;
      if (dis[v] > dis[u] - vec[i].c) {
        dis[v] = dis[u] - vec[i].c;
        if (!inq[v]) {
          inq[v] = true;
          fifo[r = (r + 1) % (T + 1)] = v;
        }
      }
    }
    inq[u] = false;
  }
  return dis[S] != INF;
}
int dfs(int u, int exp) {
  if (!exp || u == T) return exp;
  int flow = 0;
  vis[u] = true;
  for (int i = head[u]; i; i = vec[i].nxt) {
    int v = vec[i].v;
    if (!vis[v] && vec[i].w > 0 && dis[v] == dis[u] - vec[i].c) {
      int tmp = dfs(v, min(exp, vec[i].w));
      exp -= tmp;
      flow += tmp;
      vec[i].w -= tmp;
      vec[i ^ 1].w += tmp;
      if (!exp) break;
    }
  }
  return flow;
}
int zkw() {
  int ret = 0;
  while (spfa()) {
    do {
      memset(vis, 0, sizeof(vis));
      ret += dis[S] * dfs(S, INF);
    } while (vis[T]);
  }
  return ret;
}
void get_work() {
  S = n + n + 1;
  T = n + n + 2;
  for (int i = 1; i <= n; ++i) {
    add(S, i, 1, C[i]);
    add(i, i + n, 1, 0);
    add(i + n, T, 1, 0);
    if (i < n) add(i, i + 1, k - 1, 0);
    if (P[A[i]]) add(i - 1, P[A[i]] + n, 1, -C[i]);
    P[A[i]] = i;
  }
  printf("%d", zkw());
}
int main() {
  get_read();
  get_work();
  return 0;
}
