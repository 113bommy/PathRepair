#include <bits/stdc++.h>
using namespace std;
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R, class M>
ostream& operator<<(ostream& os, tuple<L, R, M> P) {
  return os << "(" << get<0>(P) << "," << get<1>(P) << "," << get<2>(P) << ")";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "{ ";
  for (auto v : V) os << v << " ";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int maxn = (int)85;
const long double EPS = 1e-9;
const int INF = (int)1e9 + 9;
const int mod = (int)1e9 + 7;
int n, k, m, dp[maxn][maxn][maxn][maxn];
vector<pair<int, int>> g[maxn];
int solve(int left, int right, int cur, int visited) {
  if (left > right) return INT_MAX;
  if (visited >= k) return 0;
  int ret = dp[left][right][cur][visited];
  if (ret != -1) {
    return ret;
  }
  ret = INF;
  for (auto [to, cost] : g[cur]) {
    if (to < left || to > right) continue;
    if (to < cur) {
      ret = min(ret, cost + solve(left, cur - 1, to, visited + 1));
    } else {
      ret = min(ret, cost + solve(cur + 1, right, to, visited + 1));
    }
  }
  return dp[left][right][cur][visited] = ret;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--;
    v--;
    g[u].push_back({v, c});
  }
  memset(dp, -1, sizeof dp);
  ;
  int ans = INF;
  for (int i = 0; i < n; i++) {
    ans = min(ans, solve(0, n - 1, i, 1));
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
  return 0;
}
