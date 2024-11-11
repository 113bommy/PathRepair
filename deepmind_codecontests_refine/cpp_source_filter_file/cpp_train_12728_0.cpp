#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
using namespace std;
signed main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> G(n);
  vector<vector<pair<int, int>>> invG(n);
  for (int i = 0; i < (m); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back({c, b});
    G[b].push_back({c, a});
  }
  for (int i = 0; i < (n); i++) sort((G[i]).begin(), (G[i]).end());
  vector<vector<int>> v(k + 1);
  for (int i = 0; i < (n); i++) {
    v[G[i].size()].push_back(i);
    if (invG[i].size() == 0 || G[i].size() == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  bool ok[k + 1][k + 1][k + 1][k + 1];
  for (int i = 0; i < (k + 1); i++)
    for (int j = 0; j < (k + 1); j++)
      for (int x = 0; x < (k + 1); x++)
        for (int y = 0; y < (k + 1); y++) ok[i][j][x][y] = true;
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      for (int x = 1; x <= i; x++) {
        for (int y = 1; y <= j; y++) {
          vector<bool> use(n, 0);
          for (auto u : v[i]) {
            if (use[G[u][x - 1].second]) ok[i][j][x][y] = false;
            use[G[u][x - 1].second] = 1;
          }
          for (auto u : v[j]) {
            if (use[G[u][y - 1].second]) ok[i][j][x][y] = false;
            use[G[u][y - 1].second] = 1;
          }
        }
      }
    }
  }
  int ans = 0;
  vector<vector<int>> vec;
  vector<int> st;
  st.push_back(1);
  vec.push_back(st);
  while (true) {
    int sz = vec[0].size();
    if (sz == k) break;
    vector<vector<int>> res;
    for (auto u : vec) {
      for (int i = 1; i <= sz + 1; i++) {
        u.push_back(i);
        res.push_back(u);
        u.pop_back();
      }
    }
    vec = res;
  }
  for (auto u : vec) {
    int flg = 1;
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= k; j++) {
        if (!ok[i][j][u[i - 1]][u[j - 1]]) flg = 0;
      }
    }
    ans += flg;
  }
  cout << ans << endl;
  return 0;
}
