#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
const int dir_4[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int dir_8[8][2] = {{1, 0},  {1, 1},   {0, 1},  {-1, 1},
                         {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
struct graph {
  int n, m;
  int u[10002], v[10002];
  long long w[10002];
  vector<pair<long long, long long>> G[1002];
  long long dist[1002];
  int pre[1002];
  bool used[1002];
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      que;
  void solve(int s, int t) {
    for (int i = 0; i < 1002; i++) G[i].clear();
    for (int i = 0; i < m; i++) {
      G[u[i]].push_back(pair<long long, long long>(v[i], w[i]));
      G[v[i]].push_back(pair<long long, long long>(u[i], w[i]));
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = INF;
      used[i] = false;
      pre[i] = -1;
    }
    dist[s] = 0;
    que.push(pair<long long, long long>(0, s));
    while (!que.empty()) {
      pair<long long, long long> p = que.top();
      que.pop();
      if (!used[p.second]) {
        used[p.second] = true;
        for (int i = 0; i < G[p.second].size(); i++) {
          pair<long long, long long> ed = G[p.second][i];
          if (dist[ed.first] > dist[p.second] + ed.second) {
            dist[ed.first] = dist[p.second] + ed.second;
            pre[ed.first] = p.second;
            que.push(pair<long long, long long>(dist[ed.first], ed.first));
          }
        }
      }
    }
  }
} G[2];
int main() {
  long long n, m, l, s, t;
  long long u[10002], v[10002], w[10002];
  scanf("%I64d%I64d%I64d%I64d%I64d", &n, &m, &l, &s, &t);
  for (int i = 0; i < m; i++) {
    scanf("%I64d%I64d%I64d", &u[i], &v[i], &w[i]);
  }
  for (int i = 0; i < 2; i++) {
    G[i].n = n;
    G[i].m = m;
    for (int j = 0; j < m; j++) {
      G[i].u[j] = u[j];
      G[i].v[j] = v[j];
      G[i].w[j] = w[j];
      if (w[j] == 0) {
        if (i == 0)
          G[i].w[j] = 1;
        else
          G[i].w[j] = INF;
      }
    }
    G[i].solve(s, t);
  }
  if (G[1].dist[t] < l || l < G[0].dist[t]) {
    puts("NO");
    return 0;
  }
  puts("YES");
  bool used[10002];
  for (int i = 0; i < 10002; i++) used[i] = false;
  map<pair<long long, long long>, int> M;
  for (int i = 0; i < m; i++) {
    M[pair<long long, long long>(min(u[i], v[i]), max(u[i], v[i]))] = i;
  }
  int loc = t;
  while (loc != s) {
    used[M[pair<long long, long long>(min(loc, G[0].pre[loc]),
                                      max(loc, G[0].pre[loc]))]] = true;
    loc = G[0].pre[loc];
  }
  for (int i = 0; i < m; i++) {
    if (w[i] == 0 && !used[i]) {
      w[i] = INF;
      G[0].w[i] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    if (w[i] == 0) {
      G[0].w[i] += l - G[0].dist[t];
      G[0].solve(s, t);
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d %d %I64d\n", G[0].u[i], G[0].v[i], G[0].w[i]);
  }
}
