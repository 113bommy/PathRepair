#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 10, S = N - 2, T = N - 1, INF = 0x3f3f3f3f;
int n;
struct edge {
  int to, w, next;
  edge(int to = 0, int w = 0, int next = 0) : to(to), w(w), next(next) {}
} e[N];
int head[N], dep[N], vis[N], cur[N], cnt = 1;
queue<int> Q;
int bfs() {
  for (int i = 1; i <= n; ++i) dep[i] = INF, vis[i] = 0, cur[i] = head[i];
  dep[S] = INF, vis[S] = 0, cur[S] = head[S];
  dep[T] = INF, vis[T] = 0, cur[T] = head[T];
  dep[S] = 0, Q.push(S);
  while (Q.size()) {
    int u = Q.front();
    Q.pop();
    for (int i = head[u]; i; i = e[i].next) {
      if (dep[e[i].to] > dep[u] + 1 && e[i].w) {
        dep[e[i].to] = dep[u] + 1;
        Q.push(e[i].to);
      }
    }
  }
  return dep[T] != INF;
}
int dfs(int first, int w) {
  if (first == T) return w;
  int used = 0;
  for (int i = cur[first]; i; i = e[i].next) {
    cur[first] = i;
    if (dep[e[i].to] == dep[first] + 1 && e[i].w) {
      int f = dfs(e[i].to, min(w - used, e[i].w));
      if (f) used += f, e[i].w -= f, e[i ^ 1].w += f;
      if (used == w) break;
    }
  }
  return used;
}
int dinic() {
  int ans = 0;
  while (bfs()) ans += dfs(S, INF);
  return ans;
}
void add(int u, int v, int w) {
  e[++cnt] = edge(v, w, head[u]);
  head[u] = cnt;
  e[++cnt] = edge(u, 0, head[v]);
  head[v] = cnt;
}
int f[N], a[N];
vector<int> g[N], ans[N];
void seive(int n) {
  int mx = sqrt(n + 0.5);
  for (int i = 2; i <= mx; ++i)
    if (!f[i]) {
      for (int j = i * i; j <= n; j += i) f[j] = 1;
    }
}
int main() {
  seive(10100);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    if ((a[i] = rd()) & 1)
      add(S, i, 2);
    else
      add(i, T, 2);
  }
  for (int i = 1; i <= n; ++i)
    if (a[i] & 1)
      for (int j = 1; j <= n; ++j)
        if (a[j] & 1 ^ 1) {
          if (!f[a[i] + a[j]]) add(i, j, 1);
        }
  if (dinic() != n) return puts("Impossible"), 0;
  for (int i = 1; i <= n; ++i)
    if (a[i] & 1) {
      for (int t = head[i]; t; t = e[t].next) {
        if (!e[t].w && e[t].to <= n) {
          g[i].push_back(e[t].to);
          g[e[t].to].push_back(i);
        }
      }
    }
  for (int i = 1; i <= n; ++i) vis[i] = 0;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      ++cnt;
      int j = i;
      while (1) {
        vis[j] = 1;
        ans[cnt].push_back(j);
        if (vis[g[j][0]] && vis[g[j][1]]) break;
        if (vis[g[j][0]])
          j = g[j][1];
        else
          j = g[j][0];
      }
    }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; ++i) {
    printf("%d ", (int)ans[i].size());
    for (int j : ans[i]) printf("%d ", j);
    puts("");
  }
}
