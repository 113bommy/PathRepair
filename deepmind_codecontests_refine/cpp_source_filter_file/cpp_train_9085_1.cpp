#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
const long long INF = 1e18;
const int MOD = 998244353;
int n, m;
vector<pair<long long, long long>> edges1[20 * M], edges2[M << 1];
long long dis[20 * M];
long long c2 = 1e7;
void dij(int x, vector<pair<long long, long long>> adj[], int k) {
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  pq.push({0, x});
  for (int i = 1; i < k + 1; i++) dis[i] = INF;
  dis[x] = 0;
  while (!pq.empty()) {
    int v = pq.top().second;
    long long w = pq.top().first;
    pq.pop();
    if (w > dis[v]) continue;
    for (pair<long long, long long> u : adj[v])
      if (dis[u.first] > dis[v] + u.second) {
        dis[u.first] = dis[v] + u.second;
        pq.push({dis[u.first], u.first});
      }
  }
}
void ad(vector<pair<long long, long long>> adj[], int v, int u, long long w) {
  adj[v].push_back({u, w});
}
void go() {
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < 20; i++) {
      if (i & 1)
        ad(edges1, b + n * i, a + n * i, 1);
      else
        ad(edges1, a + n * i, b + n * i, 1);
    }
    ad(edges2, a, b, 1);
    ad(edges2, b + n, a + n, 1);
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < 19; j++)
      ad(edges1, i + n * j, i + n * (j + 1), 1LL << j);
    ad(edges2, i, i + n, c2);
    ad(edges2, i + n, i, c2);
  }
  dij(1, edges1, 20 * n);
  long long ans = INF;
  for (int i = 1; i < 21; i++) ans = min(ans, dis[i * n]);
  if (ans != INF) {
    cout << ans << "\n";
    return;
  }
  dij(1, edges2, 2 * n);
  ans = min(dis[n], dis[n << 1]);
  int dos = ans / c2;
  long long p2 = 1;
  while (dos--) p2 = (p2 << 1) % MOD;
  cout << (p2 + ans % c2) % MOD << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tst = 1;
  while (tst--) go();
  return 0;
}
