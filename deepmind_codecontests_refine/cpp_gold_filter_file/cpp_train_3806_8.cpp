#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = (long long)1e14;
const double Inf = 1e20;
const double eps = 1e-9;
void gmax(int &a, int b) { a = (a > b ? a : b); }
void gmin(int &a, int b) { a = (a < b ? a : b); }
const int maxn = 1005;
const int maxm = 10050;
int edgcnt, n, m, L, s, t;
vector<pair<int, int> > adj[maxn];
bool inq[maxn];
struct edge {
  int u, v, lab, w;
  edge() { lab = -1; }
} e[maxm];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    pq;
long long f[maxn];
long long dijkstra(int p, long long v) {
  for (int i = 0; i <= n - 1; ++i) f[i] = INF;
  pq.push(make_pair(0, s));
  f[s] = 0;
  while (!pq.empty()) {
    pair<long long, int> h = pq.top();
    pq.pop();
    inq[h.second] = false;
    for (auto j : adj[h.second]) {
      long long w;
      if (e[j.second].lab >= 0) {
        if (e[j.second].lab < p)
          w = 1;
        else if (e[j.second].lab == p)
          w = v;
        else
          w = (long long)1e14;
      } else
        w = e[j.second].w;
      if (f[h.second] + w < f[j.first]) {
        f[j.first] = f[h.second] + w;
        if (!inq[j.first]) {
          inq[j.first] = true;
          pq.push(make_pair(f[j.first], j.first));
        }
      }
    }
  }
  return f[t];
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    if (!e[i].w) e[i].lab = ++edgcnt;
    adj[e[i].u].push_back(make_pair(e[i].v, i));
    adj[e[i].v].push_back(make_pair(e[i].u, i));
  }
  if (dijkstra(-1, 1) < L || dijkstra(edgcnt, 1) > L) return 0 * printf("NO\n");
  int lo = 1, hi = edgcnt, mid, ans1;
  while (lo <= hi) {
    mid = lo + hi >> 1;
    if (dijkstra(mid, 1) <= L)
      hi = mid - 1, ans1 = mid;
    else
      lo = mid + 1;
  }
  long long l = 1, r = INF, md, ans2;
  while (l <= r) {
    md = l + r >> 1;
    if (dijkstra(ans1, md) <= L)
      ans2 = md, l = md + 1;
    else
      r = md - 1;
  }
  printf("YES\n");
  for (int i = 1; i <= m; ++i) {
    printf("%d %d ", e[i].u, e[i].v);
    if (e[i].lab == -1)
      printf("%d\n", e[i].w);
    else if (e[i].lab < ans1)
      printf("1\n");
    else if (e[i].lab == ans1)
      printf("%lld\n", ans2);
    else
      printf("%lld\n", INF);
  }
  return 0;
}
