#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 100010;
const long long INFL = 1e18;
int n, m, w[N], color[N], color1[N], color2[N],
    cnt1 = INF, cnt2 = INF, cnt11 = INF, cnt22 = INF, ans = INF;
vector<vector<pair<int, int> > > G;
vector<pair<int, int> > E;
vector<int> comp[3];
bool invalid = 0;
void dfs(int u) {
  comp[color[u]].push_back(u);
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first, c = G[u][i].second;
    if (!color[v] && !c)
      color[v] = color[u], dfs(v);
    else if (!color[v] && c)
      color[v] = 3 - color[u], dfs(v);
    else if (color[v] && !c && color[v] != color[u])
      invalid = 1;
    else if (color[v] && c && color[v] != 3 - color[u])
      invalid = 1;
  }
}
void solveRed() {
  memset(color, 0, sizeof color);
  G.assign(n + 1, vector<pair<int, int> >());
  for (int i = 0; i < m; i++) {
    int u = E[i].first, v = E[i].second, c = w[i];
    if (!c)
      G[u].push_back(pair<int, int>(v, 1)),
          G[v].push_back(pair<int, int>(u, 1));
    else
      G[u].push_back(pair<int, int>(v, 0)),
          G[v].push_back(pair<int, int>(u, 0));
  }
  invalid = 0;
  cnt1 = 0;
  for (int i = 1; i <= n; i++)
    if (!color[i]) {
      for (int j = 1; j <= 2; j++) comp[j].clear();
      color[i] = 1;
      dfs(i);
      int cntC = comp[2].size(), cntN = comp[1].size();
      int u, v;
      if (cntC < cntN)
        u = 2, v = 1;
      else
        u = 1, v = 2;
      for (int j = 0; j < comp[u].size(); j++) color1[comp[u][j]] = 2;
      for (int j = 0; j < comp[v].size(); j++) color1[comp[v][j]] = 1;
      cnt1 += min(cntC, cntN);
    }
  if (invalid) cnt2 = INF;
}
void solveBlue() {
  memset(color, 0, sizeof color);
  G.assign(n + 1, vector<pair<int, int> >());
  for (int i = 0; i < m; i++) {
    int u = E[i].first, v = E[i].second, c = w[i];
    if (c)
      G[u].push_back(pair<int, int>(v, 1)),
          G[v].push_back(pair<int, int>(u, 1));
    else
      G[u].push_back(pair<int, int>(v, 0)),
          G[v].push_back(pair<int, int>(u, 0));
  }
  invalid = 0;
  cnt2 = 0;
  for (int i = 1; i <= n; i++)
    if (!color[i]) {
      for (int j = 1; j <= 2; j++) comp[j].clear();
      color[i] = 1;
      dfs(i);
      int cntC = comp[2].size(), cntN = comp[1].size();
      int u, v;
      if (cntC < cntN)
        u = 2, v = 1;
      else
        u = 1, v = 2;
      for (int j = 0; j < comp[u].size(); j++) color2[comp[u][j]] = 2;
      for (int j = 0; j < comp[v].size(); j++) color2[comp[v][j]] = 1;
      cnt2 += min(cntC, cntN);
    }
  if (invalid) cnt2 = INF;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    E.push_back(pair<int, int>(u, v));
    w[i] = (c == 'R' ? 1 : 0);
  }
  solveBlue();
  solveRed();
  ans = min(ans, cnt1);
  ans = min(ans, cnt2);
  if (ans == INF) return cout << "-1\n", 0;
  cout << ans << endl;
  if (ans == cnt1) {
    for (int i = 1; i <= n; i++)
      if (color1[i] == 2) cout << i << ' ';
  } else if (ans == cnt2) {
    for (int i = 1; i <= n; i++)
      if (color2[i] == 2) cout << i << ' ';
  }
}
