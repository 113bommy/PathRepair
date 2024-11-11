#include <bits/stdc++.h>
using namespace std;
inline void chkmin(int &a, int b) { a = min(a, b); }
inline void chkmax(int &a, int b) { a = max(a, b); }
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
const int MAXM = 2e5 + 10;
int S, T;
int head[MAXN], nxt[MAXM], to[MAXM], val[MAXM], ind = 1;
inline void add_edge(int u, int v, int w) {
  nxt[++ind] = head[u];
  head[u] = ind;
  to[ind] = v;
  val[ind] = w;
}
inline void add(int u, int v, int w) {
  add_edge(u, v, w);
  add_edge(v, u, 0);
}
int fread(void) {
  int ret = 0, op = 1;
  char ch = getchar();
  while ((ch > '9' || ch < '0') && (ch != '-')) ch = getchar();
  if (ch == '-')
    op = -1;
  else
    ret = ch - '0';
  ch = getchar();
  while (ch >= '0' && ch <= '9') {
    ret = (ret << 1) + (ret << 3) + ch - '0';
    ch = getchar();
  }
  return ret * op;
}
int n, m, g, a[MAXN], tot, totw, v[MAXN], loc[MAXN];
inline void init(void) {
  scanf("%d%d%d", &n, &m, &g);
  S = n + m + 1;
  T = S + 1;
  tot = n;
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (register int i = 1; i <= n; ++i) {
    v[i] = fread();
    if (a[i] == 0) add(S, i, v[i]);
    if (a[i] == 1) add(i, T, v[i]);
  }
  for (register int i = 1; i <= m; ++i) {
    int num = fread(), w = fread(), k = fread();
    totw += w;
    tot++;
    if (num == 1) {
      for (register int j = 1; j <= k; ++j) add(fread(), tot, INF);
      num = fread();
      if (num)
        add(tot, T, w + g);
      else
        add(tot, T, w);
    } else {
      for (register int j = 1; j <= k; ++j) add(tot, fread(), INF);
      num = fread();
      if (num)
        add(S, tot, w + g);
      else
        add(S, tot, w);
    }
  }
}
int d[MAXN];
inline bool BFS(void) {
  memset(d, 0, sizeof(d));
  d[S] = 1;
  queue<int> Q;
  Q.push(S);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (register int i = head[now]; i; i = nxt[i]) {
      int j = to[i];
      if (d[j] || !val[i]) continue;
      d[j] = d[now] + 1;
      Q.push(j);
      if (j == T) return true;
    }
  }
  return false;
}
int dinic(int node, int flow) {
  if (node == T) return flow;
  int rest = flow;
  for (register int i = head[node]; i && rest; i = nxt[i]) {
    int j = to[i];
    if (d[j] != d[node] + 1 || !val[i]) continue;
    int k = dinic(j, min(flow, val[i]));
    if (k == 0) d[j] = 0;
    val[i] -= k;
    rest -= k;
    val[i ^ 1] += k;
  }
  return flow - rest;
}
inline int Dinic() {
  int ret = 0;
  while (BFS()) ret += dinic(S, INF);
  return ret;
}
inline void work(void) {
  int mincut = Dinic();
  printf("%d", totw - mincut);
}
int main() {
  init();
  work();
  return 0;
}
