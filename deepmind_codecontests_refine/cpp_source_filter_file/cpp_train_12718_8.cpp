#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using std::cin;
using std::cout;
using std::string;
using LL = long long;
using db = double;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
const int MAXN = 2e5 + 10;
std::vector<int> G[MAXN];
int sz[MAXN];
int f[MAXN];
void dfs(int u, int pre = 0) {
  sz[u] = 1;
  for (auto v : G[u]) {
    if (v == pre) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
void dp(int u, int pre = 0) {
  f[u] = sz[u];
  for (auto v : G[u]) {
    if (v == pre) continue;
    dp(v, u);
    f[u] += f[v];
  }
}
int ans;
void calc(int u, int pre = 0) {
  ans = std::max(ans, f[u]);
  for (auto v : G[u]) {
    if (v == pre) continue;
    f[u] -= f[v] + sz[v];
    sz[u] -= sz[v];
    f[v] += f[u] + sz[u];
    sz[v] += sz[u];
    calc(v, u);
    f[v] -= f[u] + sz[u];
    sz[v] -= sz[u];
    f[u] += f[v] + sz[v];
    sz[u] += sz[v];
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1, x, y; i < n; ++i) {
    cin >> x >> y;
    G[x].push_back(y), G[y].push_back(x);
  }
  dfs(1);
  dp(1);
  calc(1);
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
