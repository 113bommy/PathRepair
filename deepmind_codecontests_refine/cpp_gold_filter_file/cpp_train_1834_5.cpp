#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e15 + 15;
int n, m, q;
int a[N], b[N], c[N];
vector<int> v[N];
long long pot[N];
long long dist[N];
priority_queue<pair<long long, int> > pq;
bool visited[N];
void solve() {
  for (int i = 1; i <= n; ++i) {
    dist[i] = inf;
  }
  dist[1] = 0;
  while (!pq.empty()) {
    pq.pop();
  }
  pq.push({0, 1});
  while (!pq.empty()) {
    int node = pq.top().second;
    visited[node] = 1;
    long long cost = -pq.top().first;
    pq.pop();
    if (dist[node] < cost) {
      continue;
    }
    for (int edge : v[node]) {
      int next = b[edge];
      if (dist[next] > cost + c[edge]) {
        dist[next] = cost + c[edge];
        pq.push({-cost - c[edge], next});
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    long long tmp = dist[a[i]] - dist[b[i]] + c[i];
    tmp = min(tmp, 1LL << 30);
    c[i] = tmp;
  }
  for (int i = 1; i <= n; ++i) {
    pot[i] += dist[i];
  }
}
int newdist[N];
vector<int> g[N];
int done[N];
int when;
void update() {
  for (int i = 1; i <= n; ++i) {
    newdist[i] = n;
  }
  newdist[1] = 0;
  for (int i = 0; i <= n; ++i) {
    g[i].clear();
  }
  ++when;
  g[0].emplace_back(1);
  for (int level = 0; level < n; ++level) {
    for (int j = 0; j < g[level].size(); ++j) {
      int node = g[level][j];
      if (done[node] == when) {
        continue;
      }
      done[node] = when;
      for (int edge : v[node]) {
        int next = b[edge];
        if (newdist[next] > level + c[edge]) {
          newdist[next] = level + c[edge];
          g[level + c[edge]].emplace_back(next);
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    c[i] += newdist[a[i]] - newdist[b[i]];
  }
  for (int i = 1; i <= n; ++i) {
    pot[i] += newdist[i];
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d", a + i, b + i, c + i);
    v[a[i]].emplace_back(i);
  }
  solve();
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int finish;
      scanf("%d", &finish);
      if (visited[finish]) {
        printf("%lld\n", pot[finish]);
      } else {
        printf("-1\n");
      }
    } else {
      int siz, idx;
      scanf("%d", &siz);
      while (siz--) {
        scanf("%d", &idx);
        ++c[idx];
      }
      update();
    }
  }
}
