#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3fLL;
int n, m, s, t;
long long l;
struct Edge {
  int u, v;
  long long w;
} e[10001];
vector<int> v[1001];
bool visited[1001];
long long dis[1001];
int f[1001];
priority_queue<pair<long long, int> > q;
long long getlen(long long x, long long tag) {
  if (tag == 0LL || x != 0LL)
    return abs(x);
  else
    return tag;
}
long long dijkstra(long long tag) {
  memset(visited, 0, sizeof(visited));
  while (q.size()) q.pop();
  for (int i = 0; i <= 1000; i++) dis[i] = INF;
  dis[s] = 0LL;
  f[s] = -1;
  q.push(make_pair(0LL, s));
  while (!visited[t] && !q.empty()) {
    int x = q.top().second;
    q.pop();
    while (visited[x] && !q.empty()) {
      x = q.top().second;
      q.pop();
    }
    if (visited[x]) break;
    visited[x] = true;
    for (int i = 0; i < v[x].size(); i++) {
      Edge &te = e[v[x][i]];
      int y = te.u + te.v - x;
      if (!visited[y] && (dis[y] > dis[x] + getlen(te.w, tag))) {
        f[y] = v[x][i];
        dis[y] = dis[x] + getlen(te.w, tag);
        q.push(make_pair(-dis[y], y));
      }
    }
  }
  return dis[t];
}
int main() {
  scanf("%d%d%I64d%d%d", &n, &m, &l, &s, &t);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%I64d", &e[i].u, &e[i].v, &e[i].w);
    v[e[i].u].push_back(i);
    v[e[i].v].push_back(i);
  }
  if (dijkstra(INF) < l || dijkstra(1LL) > l) {
    printf("NO\n");
    return 0;
  } else {
    printf("YES\n");
    for (int i = 0; i < m; i++)
      if (e[i].w == 0) e[i].w = -1;
    long long c = dijkstra(0LL);
    while (c < l) {
      int k = t;
      while (f[k] != -1) {
        Edge &te = e[f[k]];
        if (te.w < 0) {
          te.w -= l - c;
          break;
        }
        k = te.u + te.v - k;
      }
      c = dijkstra(0LL);
    }
    for (int i = 0; i < m; i++)
      printf("%d %d %I64d\n", e[i].u, e[i].v, abs(e[i].w));
  }
  return 0;
}
