#include <bits/stdc++.h>
const long long N = 1e6 + 10;
const long long M = 1e6 + 10;
const long long INF = 0x3f3f3f3f;
struct Edge {
  long long v, w, nxt;
  Edge() : v(0), w(0), nxt(0) {}
  Edge(long long _v, long long _w, long long _nxt) : v(_v), w(_w), nxt(_nxt) {}
} e[M << 1];
long long head[N], edge_cnt = 1, cur[N];
long long d[N];
void AddEdge(long long u, long long v, long long w) {
  e[++edge_cnt] = Edge(v, w, head[u]);
  head[u] = edge_cnt;
}
void AddEdge(long long u, long long v, long long l, long long r) {
  AddEdge(u, v, r - l);
  AddEdge(v, u, 0);
  d[u] -= l;
  d[v] += l;
}
bool Bfs(long long s, long long t) {
  memset(d, 0, sizeof(d));
  memcpy(cur, head, sizeof(head));
  std::queue<long long> q;
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (long long i = head[u]; i; i = e[i].nxt) {
      long long v = e[i].v, w = e[i].w;
      if (d[v] || !w) continue;
      q.push(v);
      d[v] = d[u] + 1;
    }
  }
  return d[t] > 0;
}
long long Dfs(long long u, long long flow, long long t) {
  if (u == t) return flow;
  long long res = flow;
  for (long long i = cur[u]; i && res; i = e[i].nxt) {
    long long v = e[i].v, w = e[i].w;
    if (d[v] != d[u] + 1 || !w) continue;
    long long now = Dfs(v, std::min(res, w), t);
    if (!now) {
      d[v] = 0;
    } else {
      e[i].w -= now;
      e[i ^ 1].w += now;
      res -= now;
    }
  }
  return flow - res;
}
long long Dinic(long long s, long long t) {
  long long res = 0;
  while (Bfs(s, t)) res += Dfs(s, INF, t);
  return res;
}
std::map<long long, long long> xx, yy;
long long cnt[N], minn[N], row[N];
signed main() {
  long long n, m, r, b, flag = false, idx = 0;
  scanf("%lld%lld%lld%lld", &n, &m, &r, &b);
  if (r > b) std::swap(r, b), flag = true;
  for (long long i = 1, x, y; i <= n; ++i) {
    scanf("%lld%lld", &x, &y);
    if (!xx[x]) xx[x] = ++idx, minn[idx] = INF, row[idx] = true;
    ++cnt[xx[x]];
    if (!yy[y]) yy[y] = ++idx, minn[idx] = INF;
    ++cnt[yy[y]];
    AddEdge(xx[x], yy[y], 1);
    AddEdge(yy[y], xx[x], 0);
  }
  long long s = idx + 1, t = s + 1, S = t + 1, T = S + 1;
  for (long long i = 1, t, l, d; i <= m; ++i) {
    scanf("%lld%lld%lld", &t, &l, &d);
    if (t == 1) {
      l = xx[l];
      if (l) minn[l] = std::min(minn[l], d);
    } else {
      l = yy[l];
      if (l) minn[l] = std::min(minn[l], d);
    }
  }
  for (long long i = 1; i <= idx; ++i) {
    long long x = std::min(cnt[i], minn[i]);
    long long l = (cnt[i] - x + 1) >> 1, r = (cnt[i] + x) >> 1;
    if (l > r) {
      printf("-1\n");
      return 0;
    }
    if (row[i])
      AddEdge(s, i, l, r);
    else
      AddEdge(i, t, l, r);
  }
  long long sum = 0;
  for (long long i = 1; i <= t; ++i) {
    if (d[i] > 0)
      AddEdge(S, i, d[i]), AddEdge(i, S, 0), sum += d[i];
    else if (d[i] < 0)
      AddEdge(i, T, -d[i]), AddEdge(T, i, 0);
  }
  AddEdge(t, s, 0, INF);
  long long flow = Dinic(S, T);
  if (flow != sum) {
    printf("-1\n");
  } else {
    Dinic(s, t);
    printf("%lld\n", 1ll * flow * r + 1ll * (n - flow) * b);
    for (long long i = 1; i <= n; ++i) {
      if (e[i * 2 + 1].w ^ flag)
        printf("r");
      else
        printf("b");
    }
  }
  return 0;
}
