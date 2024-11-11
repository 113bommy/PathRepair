#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T, typename TT>
inline ostream &operator<<(ostream &os, const pair<T, TT> &t) {
  return os << t.first << " " << t.second;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &t) {
  for (auto i : t) os << i << " ";
  return os;
}
template <typename T>
inline istream &operator>>(istream &is, vector<T> &v) {
  for (T &t : v) is >> t;
  return is;
}
template <typename T1, typename T2>
inline istream &operator>>(istream &is, pair<T1, T2> &t) {
  is >> t.first >> t.second;
  return is;
}
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> w(n);
  cin >> w;
  long long ans = *max_element(w.begin(), w.end());
  vector<vector<pair<long long, long long>>> v(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
    ans = max(ans, w[a] + w[b] - c);
  }
  vector<long long> dp(n);
  function<void(long long, long long)> dfs = [&](long long u, long long p) {
    pair<long long, long long> mx = {0, 0};
    dp[u] = w[u];
    for (auto x : v[u]) {
      if (x.first != p) {
        dfs(x.first, u);
        mx = max({mx,
                  {mx.first, dp[x.first] - x.second},
                  {dp[x.first] - x.second, mx.first}});
        dp[u] = max(dp[u], dp[x.first] - x.second + w[u]);
      }
    };
    ans = max(ans, w[u] + mx.first + mx.second);
  };
  dfs(0, -1);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
