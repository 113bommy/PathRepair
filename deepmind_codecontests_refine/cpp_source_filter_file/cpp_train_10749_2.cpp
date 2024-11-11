#include <bits/stdc++.h>
using namespace std;
template <typename G1, typename G2 = G1, typename G3 = G1>
struct triple {
  G1 first;
  G2 second;
  G3 T;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    const int alph = 20;
    vector<int> c(alph);
    vector<vector<int>> g(alph);
    for (int i = 0; i < n; i++) {
      int x = a[i] - 'a';
      int y = b[i] - 'a';
      c[x] ^= (1 << y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<bool> seen(alph);
    function<void(int)> dfs = [&](int cur) {
      seen[cur] = true;
      for (auto v : g[cur])
        if (!seen[v]) dfs(v);
    };
    int cc = 0;
    for (int i = 0; i < alph; i++)
      if (!seen[i]) dfs(i), cc++;
    vector<bool> dp(1 << alph);
    dp[0] = true;
    int mx = 0;
    for (int i = 0; i < (1 << alph); i++)
      if (dp[i]) {
        mx = max(mx, __builtin_popcount(i));
        for (int j = 0; j < alph; j++)
          if ((~i >> j & 1) && (c[j] & i) == 0) dp[i | (1 << j)] = true;
      }
    cout << 2 * alph - cc - mx << '\n';
  }
  return 0;
}
