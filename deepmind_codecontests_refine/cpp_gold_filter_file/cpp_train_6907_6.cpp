#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e18;
const int N = 1e5 + 5;
long long sp[N];
int par[N];
vector<pair<int, long long>> adj[N];
void dijkstra(int source, int n);
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  dijkstra(0, n);
  if (sp[n - 1] == OO)
    puts("-1");
  else {
    int u = n - 1;
    vector<int> path;
    while (u != -1) {
      path.push_back(u);
      u = par[u];
    }
    reverse((path).begin(), (path).end());
    for (auto& u : path) {
      printf("%d ", u + 1);
    }
  }
  return 0;
}
void dijkstra(int source, int n) {
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  pq.push({0, source});
  fill(sp, sp + n, OO);
  sp[source] = 0;
  par[source] = -1;
  while (!pq.empty()) {
    int u = pq.top().second;
    long long c = pq.top().first;
    pq.pop();
    if (sp[u] < c) continue;
    for (auto& v : adj[u]) {
      if (c + v.second < sp[v.first]) {
        sp[v.first] = c + v.second;
        par[v.first] = u;
        pq.push({sp[v.first], v.first});
      }
    }
  }
}
