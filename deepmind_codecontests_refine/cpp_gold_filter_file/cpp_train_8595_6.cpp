#include <bits/stdc++.h>
using namespace std;
struct Path {
  long long w;
  int v;
  Path(long long _w, int _v) : w(_w), v(_v) {}
  bool operator<(const Path p) const { return w > p.w; }
};
const int MAXN = 200007;
const long long INF = 1e17;
int N, M, S;
vector<Path> G[MAXN];
long long dist[MAXN];
int from[MAXN], cnt[MAXN];
priority_queue<Path> pq;
int main() {
  scanf("%d %d %d", &N, &M, &S);
  for (int i = 0; i < M; ++i) {
    int u, v;
    long long w;
    scanf("%d %d %I64d", &u, &v, &w);
    G[u].emplace_back(w, v);
    G[v].emplace_back(w, u);
  }
  for (int u = 1; u <= N; ++u) dist[u] = INF;
  dist[S] = 0;
  for (auto p : G[S]) {
    from[p.v] = p.v;
    dist[p.v] = p.w;
    pq.emplace(p.w, p.v);
  }
  while (!pq.empty()) {
    int u = pq.top().v;
    long long w = pq.top().w;
    pq.pop();
    if (dist[u] != w) continue;
    for (auto p : G[u]) {
      long long w0 = w + p.w;
      int v = p.v;
      if (w0 < dist[v]) {
        dist[v] = w0;
        from[v] = from[u];
        pq.emplace(w0, v);
      } else if (w0 == dist[v]) {
        if (from[v] != from[u]) from[v] = v;
      }
    }
  }
  for (int u = 1; u <= N; ++u) ++cnt[from[u]];
  int ans = 0;
  for (int u = 1; u <= N; ++u) ans = max(ans, cnt[u]);
  printf("%d", ans);
}
