#include <bits/stdc++.h>
using namespace std;
inline void setmin(int &x, int y) {
  if (y < x) x = y;
}
inline void setmax(int &x, int y) {
  if (y > x) x = y;
}
inline void setmin(long long &x, long long y) {
  if (y < x) x = y;
}
inline void setmax(long long &x, long long y) {
  if (y > x) x = y;
}
const int N = 3000;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;
vector<pair<int, int> > g[N];
int result = inf;
int cnt[N];
int dp[N];
void get_cnt(int u, int p) {
  cnt[u] = 0;
  for (auto &v : g[u])
    if (v.first != p) {
      get_cnt(v.first, u);
      if (v.second == 0) cnt[u]++;
      cnt[u] += cnt[v.first];
    }
}
void dfs(int u, int p, bool is_in_bad, int cnt_bad, int ans) {
  if (p == -1)
    dp[u] = 0;
  else
    dp[u] = min(dp[p] + !is_in_bad, cnt_bad);
  setmin(result, dp[u] + ans);
  for (auto &v : g[u])
    if (v.first != p)
      dfs(v.first, u, v.second == 0, cnt_bad + (v.second == 0),
          ans - (v.second == 0));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back({v, 1});
    g[v].push_back({u, 0});
  }
  for (int i = 0; i < n; i++) {
    get_cnt(i, -1);
    dfs(i, -1, false, 0, cnt[i]);
  }
  cout << result << "\n";
  return 0;
}
