#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const long long inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void read(T &first, Args &...args) {
  read(first);
  read(args...);
}
using namespace std;
const long long maxm = 1e6 + 10;
const long long maxn = 1e4 + 10;
struct EDGE {
  long long next, to, w, c;
} edge[maxm << 1];
long long head[maxn], tot;
long long cur[maxn];
long long n, m;
inline void addedge(long long u, long long v, long long w, long long c) {
  edge[tot] = {head[u], v, w, c};
  head[u] = tot++;
  edge[tot] = {head[v], u, 0, -c};
  head[v] = tot++;
}
bool vis[maxn];
long long dis[maxn], flow[maxn], pre[maxn], last[maxn];
bool spfa(long long s, long long t) {
  queue<long long> q;
  memset(dis, 0x3f, sizeof dis);
  memset(flow, 0x3f, sizeof flow);
  memset(vis, 0, sizeof vis);
  q.push(s);
  vis[s] = 1;
  dis[s] = 0;
  pre[t] = -1;
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    vis[u] = 0;
    for (long long i = head[u]; ~i; i = edge[i].next) {
      long long v = edge[i].to;
      if (edge[i].w > 0 && dis[v] > dis[u] + edge[i].c) {
        dis[v] = dis[u] + edge[i].c;
        pre[v] = u;
        last[v] = i;
        flow[v] = min(flow[u], edge[i].w);
        if (!vis[v]) {
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  return pre[t] != -1;
}
long long maxflow, maxcost;
void mcmf(long long s, long long t) {
  maxflow = 0, maxcost = 0;
  while (spfa(s, t)) {
    long long u = t;
    maxflow += flow[t];
    maxcost += flow[t] * dis[t];
    while (u != s) {
      edge[last[u]].w -= flow[t];
      edge[last[u] ^ 1].w += flow[t];
      u = pre[u];
    }
  }
}
struct node {
  long long s, t, c, i;
} q[maxn];
long long ans[maxn];
signed main() {
  memset(head, -1, sizeof head);
  long long n, k;
  read(n, k);
  long long s = 0, t = 2 * n + 1;
  for (long long i = 1; i <= n; ++i) {
    read(q[i].s, q[i].t, q[i].c);
    q[i].i = i;
    ans[i] = tot;
    addedge(i, i + n, 1, -q[i].c);
  }
  sort(q + 1, q + 1 + n,
       [&](const node &a, const node &b) { return a.s < b.s; });
  for (long long i = 1; i <= n; ++i) {
    if (i < n) addedge(q[i].i, q[i + 1].i, inf, 0);
    for (long long j = i + 1; j <= n; ++j) {
      if (q[i].s + q[i].t - 1 < q[j].s) {
        addedge(q[i].i + n, q[j].i, inf, 0);
        break;
      }
    }
  }
  addedge(s, q[1].i, k, 0);
  for (long long i = 1; i <= n; ++i) {
    addedge(q[i].i + n, t, inf, 0);
  }
  mcmf(s, t);
  for (long long i = 1; i <= n; ++i) {
    printf("%d ", edge[ans[i]].w == 0);
  }
}
