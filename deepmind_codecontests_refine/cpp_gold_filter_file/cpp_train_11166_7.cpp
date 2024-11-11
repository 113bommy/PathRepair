#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
const long long inf = 1e18;
int i, j, n, m, k, qq = 1, ma = -inf, mi = inf, fr, to, w, x, y;
char ch;
vector<vector<int> > g;
vector<int> d;
vector<bool> u;
void dfs(int second) {
  u[second] = 1;
  for (auto v : g[second]) {
    if (!u[v]) dfs(v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> qq;
  while (qq--) {
    cin >> n;
    string a, b;
    cin >> a >> b;
    g.assign(20, vector<int>(0));
    d.assign(20, 0);
    int cmps = 0;
    u.assign(20, 0);
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) {
        d[a[i] - 'a'] |= (1 << (b[i] - 'a'));
        g[a[i] - 'a'].push_back(b[i] - 'a');
        g[b[i] - 'a'].push_back(a[i] - 'a');
      }
    }
    for (int i = 0; i < 20; i++) {
      if (!u[i]) dfs(i), cmps++;
    }
    vector<bool> dp(1 << 20, 0);
    dp[0] = 1;
    int ans = 0;
    for (int mask = 0; mask < (1 << 20); mask++) {
      for (int i = 0; i < 20; i++) {
        if (dp[mask]) {
          ans = max(ans, __builtin_popcount(mask));
          if ((mask & d[i]) == 0) dp[mask | (1 << i)] = 1;
        }
      }
    }
    cout << 40 - cmps - ans << '\n';
  }
}
