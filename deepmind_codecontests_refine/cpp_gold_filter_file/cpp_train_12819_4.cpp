#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
bool mp[52][52], vis[2510];
int comp[2510];
int n, r2, c2, mn = 100000, cp = 0;
vector<int> land;
int twoDtoOne(int r, int c) { return r * n + c; }
pair<int, int> oneDtoTwo(int l) { return {l / n, l % n}; }
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  comp[u] = cp;
  for (int i = 0; i < g[u].size(); i++) dfs(g[u][i]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r1, c1;
  cin >> n >> r1 >> c1 >> r2 >> c2;
  --r1, --r2, --c1, --c2;
  g.resize(n * n + 2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      mp[i][j] = c - '0';
      if (mp[i][j] == 0) land.push_back(twoDtoOne(i, j));
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 0) {
        if (i + 1 < n && mp[i + 1][j] == 0) {
          int u = twoDtoOne(i, j), v = twoDtoOne(i + 1, j);
          g[u].push_back(v);
          g[v].push_back(u);
        }
        if (i > 0 && mp[i - 1][j] == 0) {
          int u = twoDtoOne(i, j), v = twoDtoOne(i - 1, j);
          g[u].push_back(v);
          g[v].push_back(u);
        }
        if (j + 1 < n && mp[i][j + 1] == 0) {
          int u = twoDtoOne(i, j), v = twoDtoOne(i, j + 1);
          g[u].push_back(v);
          g[v].push_back(u);
        }
        if (j > 0 && mp[i][j - 1] == 0) {
          int u = twoDtoOne(i, j), v = twoDtoOne(i, j - 1);
          g[u].push_back(v);
          g[v].push_back(u);
        }
      }
    }
  }
  for (int i = 0; i < n * n; i++) {
    if (!vis[i]) {
      dfs(i);
      cp++;
    }
  }
  if (comp[twoDtoOne(r2, c2)] == comp[twoDtoOne(r1, c1)])
    mn = 0;
  else {
    int from = twoDtoOne(r1, c1), to = twoDtoOne(r2, c2);
    for (int i = 0; i < land.size(); i++) {
      if (comp[land[i]] == comp[from]) {
        for (int j = 0; j < land.size(); j++) {
          if (comp[land[j]] == comp[to]) {
            pair<int, int> v = oneDtoTwo(land[i]), u = oneDtoTwo(land[j]);
            int dist = (v.first - u.first) * (v.first - u.first) +
                       (v.second - u.second) * (v.second - u.second);
            mn = min(mn, dist);
          }
        }
      }
    }
  }
  cout << mn << "\n";
  return 0;
}
