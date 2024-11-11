#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  srand(time(0));
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    g[a - 1].push_back(i + 1);
  }
  vector<int> in(n), out(n);
  vector<vector<int>> l(n);
  int t = 0, mxh = 0;
  function<void(int)> Tdfs = [&](int u) {
    in[u] = t;
    t++;
    for (auto v : g[u]) {
      Tdfs(v);
    }
    out[u] = t;
    t++;
  };
  Tdfs(0);
  auto bfs = [&]() {
    queue<int> q;
    q.push(0);
    vector<int> h(n);
    l[h[0]].push_back(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        q.push(v);
        h[v] = h[u] + 1;
        mxh = h[v];
        l[h[v]].push_back(v);
      }
    }
  };
  bfs();
  mxh++;
  string s;
  cin >> s;
  map<pair<int, int>, bool> ans;
  vector<vector<int>> qes(n);
  vector<pair<int, int>> que;
  for (int i = 0; i < m; i++) {
    int v, h;
    cin >> v >> h;
    v--, h--;
    qes[h].push_back(v);
    que.push_back({v, h});
  }
  auto solve = [&](int h) {
    int n = l[h].size();
    vector<vector<bool>> dp(n, vector<bool>(26));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 26; j++) {
        if (s[l[h][i]] - 'a' == j) {
          if (i == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = !dp[i - 1][j];
          }
        } else {
          if (i == 0) {
            dp[i][j] = 0;
          } else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }
    for (int i = 0; i < l[h].size(); i++) {
      l[h][i] = in[l[h][i]];
    }
    for (int i = 0; i < qes[h].size(); i++) {
      int c = 0;
      auto p1 = lower_bound(l[h].begin(), l[h].end(), in[qes[h][i]]);
      auto p2 = lower_bound(l[h].begin(), l[h].end(), out[qes[h][i]]);
      int it1 = p1 - l[h].begin();
      int it2 = p2 - l[h].begin();
      for (int i = 0; i < 26; i++) {
        bool a = (it1 == 0 ? 0 : dp[it1 - 1][i]);
        bool b = (it2 == 0 ? 0 : dp[it2 - 1][i]);
        bool x = (a != b);
        c += x;
      }
      if (c > 1) {
        ans[{h, qes[h][i]}] = 1;
      } else {
        ans[{h, qes[h][i]}] = 0;
      }
    }
  };
  for (int i = 0; i < mxh; i++) {
    solve(i);
  }
  for (int i = 0; i < m; i++) {
    if (!ans[{que[i].second, que[i].first}]) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
