#include <bits/stdc++.h>
using namespace std;
vector<int> adj[5009];
int o, e;
int vis[5009];
bool f;
int dp[5009][5009];
vector<pair<pair<int, int>, int>> ts;
vector<int> typo;
void dfs(int s, int lvl) {
  vis[s] = lvl;
  typo.push_back(s);
  if (lvl % 2 == 0) {
    e += 1;
  } else {
    o += 1;
  }
  for (int i = 0; i < adj[s].size(); i++) {
    if (vis[adj[s][i]] == -1) {
      dfs(adj[s][i], lvl ^ 1);
    }
    if (vis[adj[s][i]] == lvl) {
      f = false;
    }
  }
}
int solve(int s, int p) {
  if (p < 0) {
    return false;
  }
  if (s == 0 && p == 0) {
    return true;
  } else if (s == 0 && p != 0) {
    return false;
  }
  if (dp[s][p] != -1) {
    return dp[s][p];
  }
  pair<pair<int, int>, int> k;
  k = ts[s - 1];
  dp[s][p] = solve(s - 1, p - k.first.first) | solve(s - 1, p - k.first.second);
  return dp[s][p];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    memset(vis, -1, sizeof(vis));
    f = true;
    int n, m, x, y, n1, n2, n3;
    cin >> n >> m >> n1 >> n2 >> n3;
    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<vector<int>> als;
    memset(dp, -1, sizeof(dp));
    int ans[n + 1];
    for (int i = 1; i <= n; i++) {
      if (vis[i] == -1) {
        o = 0;
        e = 0;
        typo.clear();
        dfs(i, 1);
        ts.push_back({{o, e}, i});
        als.push_back(typo);
      }
    }
    if (f == false) {
      cout << "No" << endl;
      return 0;
    }
    int k = ts.size();
    if (solve(k, n2)) {
      pair<pair<int, int>, int> z;
      for (int i = k; i >= 1; i--) {
        z = ts[i - 1];
        if (solve(i - 1, n2 - z.first.first)) {
          for (int j = 0; j < als[i - 1].size(); j++) {
            if (vis[als[i - 1][j]] == 1) {
              ans[als[i - 1][j]] = 2;
            } else {
              if (n1 > 0) {
                ans[als[i - 1][j]] = 1;
                n1 = n1 - 1;
              } else {
                ans[als[i - 1][j]] = 3;
              }
            }
          }
          n2 = n2 - z.first.first;
        } else {
          for (int j = 0; j < als[i - 1].size(); j++) {
            if (vis[als[i - 1][j]] == 1) {
              if (n1 > 0) {
                ans[als[i - 1][j]] = 1;
                n1 = n1 - 1;
              } else {
                ans[als[i - 1][j]] = 3;
              }
            } else {
              ans[als[i - 1][j]] = 2;
            }
          }
          n2 = n2 - z.first.second;
        }
      }
      cout << "Yes" << endl;
      for (int i = 1; i <= n; i++) {
        cout << ans[i];
      }
      cout << endl;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
}
