#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 123;
const int mod = 1e9 + 7;
const long long inf = 1e18 + 9;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int n, m, sz, dp[N * 2], cnt[N];
vector<int> g[N];
vector<pair<int, int> > all;
bool used[N];
void dfs(int v) {
  used[v] = 1;
  sz++;
  for (auto to : g[v])
    if (!used[to]) dfs(to);
}
bool lucky(int x) {
  while (x) {
    if ((x % 10) != 4 && (x % 10) != 7) return 0;
    x /= 10;
  }
  return 1;
}
int main() {
  boost();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    sz = 0;
    dfs(i);
    cnt[sz]++;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) continue;
    int x = 1, sum = cnt[i];
    while (sum) {
      if (sum >= x) {
        sum -= x;
        all.push_back(make_pair(i * x, x));
      } else {
        x = sum;
        all.push_back(make_pair(i * x, x));
        break;
      }
      x <<= 1;
    }
  }
  for (int i = 0; i < N * 2; i++) dp[i] = mod;
  dp[0] = 0;
  for (int i = 0; i < (int)all.size(); i++) {
    for (int sum = n; sum >= 0; sum--) {
      dp[sum + all[i].first] =
          min(dp[sum + all[i].first], dp[sum] + all[i].second);
    }
  }
  int ans = mod;
  for (int i = 1; i <= n; i++) {
    if (lucky(i)) {
      ans = min(ans, dp[i]);
    }
  }
  if (ans == 0) ans = 1;
  if (ans == mod) ans = 0;
  cout << ans - 1;
  return 0;
}
