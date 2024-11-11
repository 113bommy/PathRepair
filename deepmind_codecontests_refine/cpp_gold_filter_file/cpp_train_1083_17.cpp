#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
inline void outarr(Tp _begin, Tp _end, const char* _delim = " ") {
  for (Tp current = _begin; current != _end; ++current) {
    std::cout << *current << _delim;
  }
  std::cout << '\n';
}
using ll = long long;
using pii = std::pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = static_cast<const int>(1e9 + 7);
vector<pii> col[10];
int cost[10][10];
pii Diags(int x, int y) { return {x - y, x + y}; }
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, k, len;
  cin >> n >> m >> k >> len;
  vector<vector<pii>> diag(10, vector<pii>(2, {INF, -INF}));
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      col[x].emplace_back(i, j);
      auto [d1, d2] = Diags(i, j);
      diag[x][0].first = min(diag[x][0].first, d1);
      diag[x][0].second = max(diag[x][0].second, d1);
      diag[x][1].first = min(diag[x][1].first, d2);
      diag[x][1].second = max(diag[x][1].second, d2);
    }
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= i; ++j) {
      int val = 0;
      for (auto [x, y] : col[i]) {
        auto [d1, d2] = Diags(x, y);
        val = max({val, abs(diag[j][0].first - d1), abs(diag[j][0].second - d1),
                   abs(diag[j][1].first - d2), abs(diag[j][1].second - d2)});
      }
      cost[i][j] = cost[j][i] = val;
    }
  }
  vector<int> vec(len);
  for (int i = 0; i < (len); ++i) {
    cin >> vec[i];
  }
  int ans = 0;
  for (int i = 1; i < len; ++i) {
    ans = max(ans, cost[vec[i]][vec[i - 1]]);
  }
  cout << ans << "\n";
  return 0;
}
