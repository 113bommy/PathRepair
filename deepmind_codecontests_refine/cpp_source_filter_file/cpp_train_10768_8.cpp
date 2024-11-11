#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
const long long inf = 1e16;
const long long kk = 1 << 50;
int a[100], b[100], c[100];
int p[100][300];
int l[100], r[100];
struct DINIC {
  const long long inf = (long long)1e16;
  int dep[20000], head[20000], cur[20000], tot;
  struct EDGE {
    int to, nxt;
    long long val;
  } g[(int)1e6 + 10];
  void add(int u, int v, long long w) {
    g[tot] = {v, head[u], w};
    head[u] = tot++;
  }
  void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
  }
  void addedge(int u, int v, long long w) {
    add(u, v, w);
    add(v, u, 0);
  }
  bool bfs(int s, int t) {
    memset(dep, 0, sizeof(dep));
    queue<int> Q;
    Q.push(s);
    dep[s] = 1;
    cur[s] = head[s];
    while (!Q.empty()) {
      s = Q.front();
      Q.pop();
      for (int i = head[s], v; ~i; i = g[i].nxt) {
        if (g[i].val > 0 && !dep[v = g[i].to]) {
          dep[v] = dep[s] + 1;
          cur[v] = head[v];
          if (v == t) return true;
          Q.push(v);
        }
      }
    }
    return false;
  }
  long long dfs(int s, int t, long long flow) {
    if (s == t || flow <= 0) return flow;
    long long rest = flow;
    for (int &i = cur[s]; ~i; i = g[i].nxt) {
      int v = g[i].to;
      if (g[i].val > 0 && dep[v] == dep[s] + 1) {
        long long tmp = dfs(v, t, min(rest, g[i].val));
        if (tmp <= 0) dep[v] = 0;
        rest -= tmp;
        g[i].val -= tmp;
        g[i ^ 1].val += tmp;
        if (rest <= 0) break;
      }
    }
    return flow - rest;
  }
  long long maxflow(int s, int t) {
    long long ans = 0;
    while (bfs(s, t)) ans += dfs(s, t, inf);
    return ans;
  }
} dinic;
void rua() {
  int n, m, cnt = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  dinic.init();
  int S = 0, T = 1;
  for (int i = 1; i <= n; i++) {
    dinic.addedge(S, cnt + 1, inf);
    scanf("%d%d", &l[i], &r[i]);
    for (int j = l[i]; j <= r[i]; j++) {
      p[i][j - l[i]] = ++cnt;
      int tmp = a[i] * j * j + b[i] * j + c[i];
      dinic.addedge(cnt, cnt + 1, kk - tmp);
    }
    p[i][r[i] - l[i] + 1] = ++cnt;
    dinic.addedge(cnt, T, inf);
  }
  for (int i = 1; i <= m; i++) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    for (int j = max(l[v], l[u] - d); j <= min(r[v], r[u] - d) + 1; j++)
      dinic.addedge(p[u][j - l[u] + d], p[v][j - l[v]], inf);
  }
  printf("%lld\n", kk * n - dinic.maxflow(S, T));
}
int main() {
  rua();
  return 0;
}
