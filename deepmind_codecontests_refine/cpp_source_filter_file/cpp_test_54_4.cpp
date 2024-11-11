#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast,unroll-loops")
#pragma GCC target("avx2")
std::mt19937 rnd(237);
using namespace std;
const int N = 2e5, mod = 1e9 + 7;
int n, m, type[N], cmp[N], cmp_p = 0;
vector<array<int, 2>> g1[N], g2[N];
long long dfs(int v) {
  cmp[cmp_p++] = v;
  long long ans = (type[v] ? 0 : 1);
  for (auto &[u, c] : g1[v]) {
    if (~type[u]) {
      if (type[v] && type[u] != c) return -2e9;
      if (!type[v] && type[u] == c) return -2e9;
    } else {
      type[u] = (type[v] ? c : 1 - c);
      ans += dfs(u);
    }
  }
  for (auto &[u, c] : g2[v]) {
    if (~type[u]) {
      if (type[u] == 1 && type[v] != c) return -2e9;
      if (type[u] == 0 && type[v] == c) return -2e9;
    } else {
      type[u] = (type[v] == c ? 1 : 0);
      ans += dfs(u);
    }
  }
  return ans;
}
void solve() {
  cin >> n >> m;
  fill(type, type + n, -1);
  cmp_p = 0;
  for (int i = 0; i < n; ++i) {
    g1[i].clear();
    g2[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    --u, --v;
    if (s == "crewmate") {
      g1[u].push_back({v, 1});
      g2[v].push_back({u, 1});
    } else {
      g1[u].push_back({v, 0});
      g2[v].push_back({u, 0});
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (type[i] == -1) {
      long long mx = -1;
      type[i] = 1;
      cmp_p = 0;
      mx = max(mx, dfs(i));
      for (int j = 0; j < cmp_p; ++j) {
        type[cmp[j]] = -1;
      }
      type[i] = 0;
      cmp_p = 0;
      mx = max(mx, dfs(i));
      ans += mx;
    }
  }
  cout << (ans < 0 ? -1 : ans);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
}
