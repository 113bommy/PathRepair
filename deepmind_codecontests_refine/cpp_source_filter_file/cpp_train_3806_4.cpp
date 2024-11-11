#include <bits/stdc++.h>
using namespace std;
vector<int> gr[10100], temp, cst[10100];
int U[10100], V[10100], W[10100];
int n, m, u, v, w, L, S, T;
long long dist[10100];
void dijkstra(int src) {
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  for (int i = 0; i <= n; i++) dist[i] = 1000000000000000LL;
  dist[src] = 0;
  pq.push(make_pair(dist[src], src));
  while (!pq.empty()) {
    pair<long long, int> u = pq.top();
    pq.pop();
    for (int i = 0; i < (int)gr[u.second].size(); i++) {
      int v = gr[u.second][i];
      if (dist[v] < dist[u.second]) continue;
      if (dist[v] > dist[u.second] + cst[u.second][i]) {
        dist[v] = dist[u.second] + cst[u.second][i];
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}
long long change(long long X) {
  for (int it : temp) {
    W[it] = 1 + min(X, 1000000000LL);
    X -= W[it] - 1;
  }
  for (int i = 0; i <= n; i++) cst[i].clear();
  for (int i = 0; i < m; i++) {
    cst[U[i]].push_back(W[i]);
    cst[V[i]].push_back(W[i]);
  }
  dijkstra(S);
  return dist[T];
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &L, &S, &T);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &U[i], &V[i], &W[i]);
    u = U[i], v = V[i], w = W[i];
    gr[u].push_back(v);
    gr[v].push_back(u);
    cst[u].push_back(w);
    cst[v].push_back(w);
    if (w == 0) temp.push_back(i);
  }
  long long low = -1, high = 1000000000LL * (int)temp.size(), mid;
  if (change(0) > L || change(high) < L) {
    puts("NO");
    return 0;
  }
  int cnt = 60;
  while (cnt--) {
    mid = (low + high) >> 1;
    if (change(mid) > L)
      high = mid;
    else
      low = mid;
    if (low == high) break;
  }
  for (int it : temp) {
    W[it] = 1 + min(high, 1000000000LL);
    high -= W[it] - 1;
  }
  puts("YES");
  for (int i = 0; i < m; i++) {
    printf("%d %d %d\n", U[i], V[i], W[i]);
  }
  return 0;
}
