#include <bits/stdc++.h>
using namespace std;
const long long N = 2e2 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9,
                inf = 1e18 + 7;
const long long infll = 1e18 + 7;
long long n, m, ans = inf;
vector<pair<long long, long long>> a[N];
long long adj[N][N];
long long dist[N][N];
vector<pair<pair<long long, long long>, long long>> edge;
void floyd() {
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      dist[i][j] = adj[i][j];
    }
  }
  for (long long k = 1; k <= n; k++) {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i == j)
        adj[i][j] = 0;
      else
        adj[i][j] = inf;
    }
  }
  for (long long i = 1; i <= m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    w *= 2;
    adj[u][v] = adj[v][u] = w;
    edge.push_back({{u, v}, w});
  }
  floyd();
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      a[i].push_back({dist[i][j], j});
    }
    sort(a[i].rbegin(), a[i].rend());
    ans = min(ans, a[i][0].first);
  }
  for (auto cac : edge) {
    long long u = cac.first.first, v = cac.first.second, w = cac.second;
    if (a[u][0].second == a[v][0].second) continue;
    long long k = a[u][0].second;
    ans = min(ans, min(dist[u][k], dist[v][k] + w));
    for (auto cac2 : a[u]) {
      if (dist[v][k] < dist[v][cac2.second]) {
        long long x = (dist[v][k] + dist[u][cac2.second] + w) / 2;
        ans = min(ans, x);
        k = cac2.second;
      }
    }
    ans = min(ans, min(dist[v][k], dist[u][k] + w));
  }
  cout << fixed << setprecision(9) << ans / 2.0;
}
