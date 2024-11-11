#include <bits/stdc++.h>
using namespace std;
long long fastpow(long long a, long long b,
                  long long m = (long long)(1e9 + 7)) {
  long long res = 1;
  a %= m;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
struct Edge {
  long long v, weight;
  bool operator<(Edge const& other) { return weight < other.weight; }
};
vector<long long> dijkstra(long long x, vector<vector<Edge>>& adj) {
  long long n = (long long)adj.size();
  vector<long long> distance(n + 1);
  vector<bool> processed(n + 1);
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      q;
  for (long long i = 1; i <= n; i++) {
    distance[i] = (long long)9e18;
  }
  distance[x] = 0;
  q.push({0, x});
  while (!q.empty()) {
    long long a = q.top().second;
    q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
      long long b = u.v, w = u.weight;
      if (distance[a] + w < distance[b]) {
        distance[b] = distance[a] + w;
        q.push({distance[b], b});
      }
    }
  }
  return distance;
}
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long n, k, a, b;
  cin >> n >> k;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  vector<array<long long, 2>> xs, ys, portals;
  vector<vector<Edge>> adjA(k + 5), adjB(k + 5);
  for (long long i = 0; i < k; i++) {
    cin >> a >> b;
    portals.push_back({a, b});
    xs.push_back({a, i});
    ys.push_back({b, i});
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  for (long long i = 1; i < k; i++) {
    adjA[xs[i - 1][1] + 1].push_back({xs[i][1] + 1, xs[i][0] - xs[i - 1][0]});
    adjA[xs[i][1] + 1].push_back({xs[i - 1][1] + 1, xs[i][0] - xs[i - 1][0]});
    adjB[xs[i - 1][1] + 1].push_back({xs[i][1] + 1, xs[i][0] - xs[i - 1][0]});
    adjB[xs[i][1] + 1].push_back({xs[i - 1][1] + 1, xs[i][0] - xs[i - 1][0]});
    adjA[ys[i - 1][1] + 1].push_back({ys[i][1] + 1, ys[i][0] - ys[i - 1][0]});
    adjA[ys[i][1] + 1].push_back({ys[i - 1][1] + 1, ys[i][0] - ys[i - 1][0]});
    adjB[ys[i - 1][1] + 1].push_back({ys[i][1] + 1, ys[i][0] - ys[i - 1][0]});
    adjB[ys[i][1] + 1].push_back({ys[i - 1][1] + 1, ys[i][0] - ys[i - 1][0]});
  }
  for (long long i = 0; i < k; i++) {
    long long th = i + 1;
    auto p = portals[i];
    adjA[k + 1].push_back({th, min(abs(x1 - p[0]), abs(y1 - p[1]))});
    adjA[th].push_back({k + 1, min(abs(x1 - p[0]), abs(y1 - p[1]))});
    adjA[k + 2].push_back({th, abs(x2 - p[0]) + abs(y2 - p[1])});
    adjA[th].push_back({k + 2, abs(x2 - p[0]) + abs(y2 - p[1])});
    adjB[k + 1].push_back({th, abs(x2 - p[0]) + abs(y2 - p[1])});
    adjB[th].push_back({k + 1, abs(x2 - p[0]) + abs(y2 - p[1])});
    adjB[k + 2].push_back({th, abs(x2 - p[0]) + abs(y2 - p[1])});
    adjB[th].push_back({k + 2, abs(x2 - p[0]) + abs(y2 - p[1])});
  }
  auto da = dijkstra(k + 1, adjA);
  auto db = dijkstra(k + 1, adjB);
  cout << min({abs(x1 - x2) + abs(y1 - y2), da[k + 2], db[k + 2]});
  return 0;
}
