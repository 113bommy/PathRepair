#include <bits/stdc++.h>
using namespace std;
const int maxn = 12050;
const int maxm = 240010;
int n, m, S, T, g, ans;
int a[10010];
vector<int> f;
int tot = 1, ver[maxm << 1], nxt[maxm << 1], head[maxn], cur[maxn],
    edge[maxm << 1];
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
void add(int u, int v, int w) {
  ver[++tot] = v;
  nxt[tot] = head[u];
  head[u] = tot;
  edge[tot] = w;
  ver[++tot] = u;
  nxt[tot] = head[v];
  head[v] = tot;
  edge[tot] = 0;
}
int d[maxn];
queue<int> q;
bool bfs() {
  memset(d, 0, sizeof(d));
  while (!q.empty()) q.pop();
  q.push(S);
  d[S] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = nxt[i]) {
      int y = ver[i];
      if (edge[i] && !d[y]) {
        q.push(y);
        d[y] = d[x] + 1;
        if (y == T) return 1;
      }
    }
  }
  return 0;
}
int dinic(int x, int flow) {
  if (x == T) return flow;
  int rest = flow, k;
  for (int i = cur[x]; i && rest; i = nxt[i]) {
    int y = ver[i];
    cur[x] = i;
    if (edge[i] && d[y] == d[x] + 1) {
      k = dinic(y, min(rest, edge[i]));
      if (!k) d[y] = 0;
      edge[i] -= k;
      edge[i ^ 1] += k;
      rest -= k;
    }
  }
  if (rest == flow) d[x] = 0;
  return flow - rest;
}
int main() {
  read(n), read(m), read(g);
  S = n + m + 10, T = n + m + 16;
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) {
    int x;
    read(x);
    add(S, i, (a[i] ^ 1) * x);
    add(i, T, a[i] * x);
  }
  for (int i = 1; i <= m; i++) {
    int op, wi, gi, k;
    read(op);
    read(wi);
    read(k);
    ans += wi;
    for (int j = 1; j <= k; j++) {
      int x;
      read(x);
      f.push_back(x);
    }
    for (unsigned j = 0; j < f.size(); j++) {
      if (!op)
        add(n + i, f[j], 1 << 30);
      else
        add(f[j], n + i, 1 << 30);
    }
    read(gi);
    if (!op)
      add(S, n + i, wi + g * gi);
    else
      add(n + i, T, wi + g * gi);
    f.clear();
  }
  int flow = 0;
  while (bfs()) {
    memcpy(cur, head, sizeof(head));
    while ((flow = dinic(S, 1 << 30))) ans -= flow;
  }
  printf("%d\n", ans);
  return 0;
}
