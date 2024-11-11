#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
template <typename T>
using vec = vector<T>;
template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (auto& value : vec) {
    is >> value;
  }
  return is;
}
template <typename T>
void minimize(T& acc, const T& value) {
  if (value < acc) acc = value;
}
template <typename T>
void maximize(T& acc, const T& value) {
  if (value > acc) acc = value;
}
int root(std::vector<int>& data, int u) {
  int p = u;
  while (data[p] >= 0) p = data[p];
  while (data[u] >= 0) {
    int t = data[u];
    data[u] = p;
    u = t;
  }
  return p;
}
int size(std::vector<int>& data, int u) { return -data[root(data, u)]; }
const int MOD = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  auto edges = vec<tuple<int, int, int>>();
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      int w;
      cin >> w;
      if (u < v) {
        edges.emplace_back(w, u, v);
      }
    }
  }
  auto dp = vec<vec<int>>(n, vec<int>(2));
  for (int i = 0; i < n; ++i) {
    dp[i][1] = 1;
  }
  auto comp_edges = vec<int>(n);
  sort(begin(edges), end(edges));
  auto dsu = vec<int>(n, -1);
  for (auto [w, u, v] : edges) {
    u = root(dsu, u);
    v = root(dsu, v);
    if (u != v) {
      int szu = size(dsu, u);
      int szv = size(dsu, v);
      auto new_dp = vec<int>(szu + szv + 1);
      for (int i = 1; i <= szu; ++i) {
        for (int j = 1; j <= szv; ++j) {
          new_dp[i + j] = (new_dp[i + j] + dp[u][i] * dp[v][j]) % MOD;
        }
      }
      comp_edges[u] += comp_edges[v];
      dsu[u] += dsu[v];
      dsu[v] = u;
      dp[u] = new_dp;
    }
    ++comp_edges[u];
    int s = size(dsu, u);
    if (comp_edges[u] == s * (s - 1) / 2) {
      dp[u][1] = (dp[u][1] + 1) % MOD;
    }
  }
  int u = root(dsu, 0);
  for (int i = 1; i <= n; ++i) {
    cout << dp[u][i] << " ";
  }
  return 0;
}
