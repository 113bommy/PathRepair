#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long rng(long long l) {
  uniform_int_distribution<long long> uid(0, l - 1);
  return uid(rang);
}
class Matcher {
  std::vector<std::vector<long long> > G;
  std::vector<long long> dist, match;
  long long n, m;

 public:
  Matcher(long long n, long long m)
      : n(n), m(m), G(n + m + 1), match(n + m + 1), dist(n + 1) {}
  void emplace_back(long long u, long long v) {
    G[u + 1].emplace_back(v + 1 + n);
    G[v + 1 + n].emplace_back(u + 1);
  }
  bool bfs() {
    long long u;
    queue<long long> Q;
    for (unsigned i = 1; i <= n; i++)
      if (match[i] == 0) {
        dist[i] = 0;
        Q.push(i);
      } else
        dist[i] = INT_MAX;
    dist[0] = INT_MAX;
    while (!Q.empty()) {
      u = Q.front();
      Q.pop();
      if (u != 0)
        for (long long v : G[u])
          if (dist[match[v]] == INT_MAX) {
            dist[match[v]] = dist[u] + 1;
            Q.push(match[v]);
          }
    }
    return (dist[0] != INT_MAX);
  }
  bool dfs(long long u) {
    if (u == 0) return true;
    for (long long v : G[u])
      if (dist[match[v]] == dist[u] + 1)
        if (dfs(match[v])) {
          match[v] = u;
          match[u] = v;
          return true;
        }
    dist[u] = INT_MAX;
    return false;
  }
  long long MaxMatching() {
    long long matching = 0;
    while (bfs())
      for (unsigned i = 1; i <= n; i++)
        if (match[i] == 0 && dfs(i)) matching++;
    return matching;
  }
  std::vector<long long> GetMatching() {
    std::vector<long long> res(n);
    for (long long i = 0; i < n; ++i) res[i] = match[i + 1] - n - 1;
    return res;
  }
};
long long dist[200][200];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < m; ++j) dist[i][j] = INT_MAX;
  for (long long i = 0; i < n; ++i) dist[i][i] = 0;
  for (long long i = 0; i < m; ++i) {
    long long u;
    cin >> u;
    u--;
    long long v;
    cin >> v;
    v--;
    dist[u][v] = min(dist[u][v], 1ll);
    dist[v][u] = min(dist[v][u], 1ll);
  }
  for (long long k = 0; k < n; ++k)
    for (long long i = 0; i < n; ++i)
      for (long long j = 0; j < n; ++j)
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
  long long s;
  cin >> s;
  long long b;
  cin >> b;
  long long k;
  cin >> k;
  long long h;
  cin >> h;
  Matcher B(s, b);
  std::vector<long long> x(s);
  std::vector<long long> a(s);
  std::vector<long long> f(s);
  for (long long i = 0; i < s; ++i) cin >> x[i] >> a[i] >> f[i];
  std::vector<long long> y(b);
  std::vector<long long> d(b);
  for (long long i = 0; i < b; ++i) cin >> y[i] >> d[i];
  for (long long i = 0; i < s; ++i)
    for (long long j = 0; j < b; ++j)
      if (dist[x[i]][y[j]] <= f[i] && a[i] <= d[j]) B.emplace_back(i, j);
  long long u = B.MaxMatching();
  long long mi = k * u;
  for (long long i = 0; i <= u; ++i) mi = min(mi, h * (s - i) + i * k);
  cout << mi;
}
