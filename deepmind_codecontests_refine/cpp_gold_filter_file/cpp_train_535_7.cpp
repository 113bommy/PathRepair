#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
const int Z = 100;
const int N = Z * Z;
const int M = Z * Z * Z * 3;
int px[N], py[N];
int head[N], to[M], ct[M], w[M], nt[M];
int d[N], vis[N];
int pre[N], id[N];
int s, t, tot;
void add(int u, int v, int flow, int cost) {
  to[tot] = v;
  ct[tot] = cost;
  w[tot] = flow;
  nt[tot] = head[u];
  head[u] = tot++;
  to[tot] = u;
  ct[tot] = -cost;
  w[tot] = 0;
  nt[tot] = head[v];
  head[v] = tot++;
}
void init() {
  memset(head, -1, sizeof(head));
  tot = 0;
}
int spfa(int s, int t) {
  queue<int> q;
  memset(d, inf, sizeof(d));
  memset(vis, 0, sizeof(vis));
  memset(pre, -1, sizeof(pre));
  d[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = nt[i]) {
      if (w[i] > 0 && d[to[i]] > d[u] + ct[i]) {
        d[to[i]] = d[u] + ct[i];
        pre[to[i]] = u;
        id[to[i]] = i;
        if (!vis[to[i]]) {
          vis[to[i]] = 1;
          q.push(to[i]);
        }
      }
    }
  }
  return d[t] < inf;
}
int MaxFlow(int s, int t) {
  int Mi = inf;
  int sum = 0;
  int tt = 0;
  while (spfa(s, t)) {
    Mi = inf;
    for (int i = t; i != s; i = pre[i]) Mi = min(Mi, w[id[i]]);
    for (int i = t; i != s; i = pre[i]) {
      w[id[i]] -= Mi;
      w[id[i] ^ 1] += Mi;
    }
    tt += Mi;
    sum += d[t] * Mi;
  }
  return sum;
}
int main() {
  init();
  int n, m, k, c, d;
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  int s = 0, t = n * 100 + 1;
  for (int i = 1; i <= 100; ++i) add(i, t, 100, 0);
  for (int i = 1, v; i <= k; ++i) {
    scanf("%d", &v);
    add(s, (v - 1) * 100 + 1, 1, 0);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < 100; ++j) {
      add((i - 1) * 100 + j, (i - 1) * 100 + j + 1, 100, c);
    }
  }
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    for (int j = 1; j < 100; ++j) {
      int idx = (u - 1) * 100 + j;
      int idy = (v - 1) * 100 + j + 1;
      for (int k = 1; k <= 13; ++k) {
        add(idx, idy, 1, c + (k * k - (k - 1) * (k - 1)) * d);
      }
    }
    for (int j = 1; j < 100; ++j) {
      int idx = (v - 1) * 100 + j;
      int idy = (u - 1) * 100 + j + 1;
      for (int k = 1; k <= 13; ++k) {
        add(idx, idy, 1, c + (k * k - (k - 1) * (k - 1)) * d);
      }
    }
  }
  printf("%d\n", MaxFlow(s, t));
  return 0;
}
