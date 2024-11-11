#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int maxn = 1000 + 7, maxm = 2e6 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
int casn, n, m, k;
int num[6][1200];
int mp[1200][1200];
int vis[1200];
vector<int> g[maxn];
int dfs(int now) {
  if (vis[now]) return vis[now];
  int mx = 1;
  for (auto& i : g[now]) mx = max(1 + dfs(i), mx);
  return vis[now] = mx;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) cin >> num[i][j];
  }
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int z = j + 1; z <= n; ++z) mp[num[i][j]][num[i][z]]++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j)
      if (mp[i][j] >= k) g[i].push_back(j);
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      ans = max(ans, dfs(i));
    }
  }
  for (int i = 1; i <= n; ++i) ans = max(ans, vis[i]);
  cout << ans << '\n';
  return 0;
}
