#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 179;
const int WEEK = 52;
const int INF = N;
int T;
vector<int> g[N];
vector<int> gT[N];
bool work[N][WEEK];
int n, m, d;
vector<int> order;
vector<set<int>> comps;
vector<int> root;
vector<set<pair<int, int>>> g2;
vector<bool> used2;
vector<vector<int>> left123;
vector<set<int>> poss;
bool connect[N][WEEK];
bool connect2[N][WEEK];
vector<int> cost[WEEK];
int col[N];
bool used[N];
void dfs3(int we) {
  used2[we] = 1;
  for (auto el : comps[we]) {
    for (int ds = 0; ds < d; ds++) {
      if (!connect2[el][ds]) continue;
      for (auto el2 : g[el]) {
        if (col[el2] == we) continue;
        for (int de = 0; de < d; de++) {
          if (!connect[el2][de]) continue;
          g2[we].insert({col[el2], (ds + 1 + de) % d});
        }
      }
    }
  }
}
bool proc[N][WEEK];
void dfs4(int we, int r) {
  if (proc[we][r]) return;
  proc[we][1] = 1;
  for (auto el : g2[we]) {
    left123[el.first][(r + el.second) % d]++;
    dfs4(el.first, (r + el.second) % d);
  }
}
void dfs(int we) {
  used[we] = 1;
  for (auto el : g[we]) {
    if (used[el]) continue;
    dfs(el);
  }
  order.push_back(we);
}
void dfs2(int we) {
  used[we] = 0;
  comps[comps.size() - 1].insert(we);
  col[we] = comps.size() - 1;
  for (auto el : gT[we]) {
    if (col[el]) continue;
    dfs2(el);
  }
}
signed main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    gT[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    string t;
    cin >> t;
    for (int j = 0; j < t.size(); j++) {
      if (t[j] == '1') work[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) dfs(i);
  }
  comps.resize(1);
  reverse(order.begin(), order.end());
  for (auto el : order) {
    if (col[el] == 0) {
      comps.push_back({});
      dfs2(el);
    }
  }
  for (int i = 0; i < d; i++) {
    cost[i].resize(comps.size());
  }
  root.resize(comps.size());
  for (int i = 1; i < comps.size(); i++) {
    root[i] = *comps[i].begin();
    connect[root[i]][0] = 1;
    queue<pair<int, int>> q;
    q.push({root[i], 0});
    while (q.size() != 0) {
      auto we = q.front();
      q.pop();
      for (auto el : gT[we.first]) {
        if (col[el] != i) continue;
        if (connect[el][(we.second + 1) % d]) continue;
        connect[el][(we.second + 1) % d] = 1;
        q.push({el, (we.second + 1) % d});
      }
    }
    connect2[root[i]][0] = 1;
    q.push({root[i], 0});
    while (q.size() != 0) {
      auto we = q.front();
      q.pop();
      for (auto el : g[we.first]) {
        if (col[el] != i) continue;
        if (connect2[el][(we.second + 1) % d]) continue;
        connect2[el][(we.second + 1) % d] = 1;
        q.push({el, (we.second + 1) % d});
      }
    }
    for (int st = 0; st < d; st++) {
      for (auto el : comps[i]) {
        bool ok = 0;
        for (int z = 0; z < d; z++) {
          if (connect2[el][z] && work[el][(z + st) % d]) ok = 1;
        }
        cost[st][i] += ok;
      }
    }
  }
  int mx = 0;
  vector<vector<int>> dp(comps.size(), vector<int>(d, -INF));
  dp[col[1]][0] = cost[0][col[1]];
  mx = max(mx, dp[col[1]][0]);
  queue<pair<int, int>> q;
  left123.resize(comps.size(), vector<int>(d));
  used2.resize(comps.size());
  g2.resize(comps.size());
  for (int i = 1; i < comps.size(); i++) {
    dfs3(i);
  }
  dfs4(col[1], 0);
  q.push({col[1], 0});
  while (q.size() != 0) {
    auto we = q.front();
    mx = max(mx, dp[we.first][we.second]);
    q.pop();
    for (auto el : g2[we.first]) {
      int r = (we.second + el.second) % d;
      left123[el.first][r]--;
      dp[el.first][r] =
          max(dp[el.first][r], dp[we.first][we.second] + cost[r][el.first]);
      if (left123[el.first][r] == 0) {
        q.push({el.first, r});
      }
    }
  }
  cout << mx << endl;
  return 0;
}
