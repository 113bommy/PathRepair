#include <bits/stdc++.h>
using namespace std;
template <typename T>
void __read(T &a) {
  cin >> a;
}
template <typename T, typename... Args>
void __read(T &a, Args &...args) {
  cin >> a;
  __read(args...);
}
constexpr long long M7 = 1000000007ll;
constexpr long long M9 = 1000000009ll;
constexpr long long MFFT = 998244353ll;
template <class T>
void outv(T &a) {
  for (auto &x : a) cout << x << ' ';
}
static mt19937 rnd(static_cast<unsigned>(
    chrono::steady_clock::now().time_since_epoch().count()));
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n, d;
  __read(n, d);
  vector<long long> a(n - 1);
  for (long long i = 1; i + 1 < n; ++i) {
    cin >> a[i];
  }
  vector<pair<long long, long long>> c(n);
  for (auto &[x, y] : c) {
    cin >> x >> y;
  }
  vector<vector<long long>> m(n, vector<long long>(n));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) {
      if (i != j) {
        m[i][j] = d * (abs(c[i].first - c[j].first) +
                       abs(c[i].second - c[j].second)) -
                  a[i];
      }
    }
  }
  vector<long long> dist(n, M7 * M7);
  dist[0] = 0;
  vector<long long> was(n);
  for (long long i = 0; i < n; ++i) {
    long long v = -1;
    for (long long j = 0; j < n; ++j) {
      if (!was[j] && (v == -1 || dist[v] > dist[j])) {
        v = j;
      }
    }
    was[v] = 1;
    for (long long u = 0; u < n; ++u) {
      dist[u] = min(dist[u], dist[v] + m[v][u]);
    }
  }
  cout << dist[n - 1];
  return 0;
}
