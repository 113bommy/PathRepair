#include <bits/stdc++.h>
using namespace std;
int n, s, m;
vector<vector<pair<int, int> > > adjList;
vector<vector<int> > dist;
void calcdist() {
  dist.assign(n, vector<int>(n, (1 << 29)));
  for (int i = 0; i < n; ++i) dist[i][i] = 0;
  for (int i = 0; i < n; ++i)
    for (pair<int, int> p : adjList[i]) {
      int v, w;
      tie(v, w) = p;
      dist[i][v] = dist[v][i] = w;
    }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
void combine(vector<int>& res, const vector<int>& arr) {
  int n = res.size();
  for (int i = n - 1; i >= 0; --i) {
    int m = 0;
    for (int j = 0; j <= i; ++j) m = max(m, min(res[j], arr[i - j]));
    res[i] = m;
  }
}
vector<vector<int> > memo;
int solve(int u, int m) {
  if (memo[u][m] != -1) return memo[u][m];
  if (m == 0) return 0;
  vector<int> res(m + 1, 0);
  res[0] = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (adjList[i].size() != 1 || i == u) continue;
    vector<int> t(m + 1, 0);
    t[0] = INT_MAX;
    for (int j = 1; j <= m; ++j) t[j] = dist[u][i] + solve(i, m - j);
    combine(res, t);
  }
  return memo[u][m] = res[m];
}
vector<int> cc;
void dfs(int u, int p, int c) {
  cc[u] = c;
  for (auto vw : adjList[u]) {
    int v, w;
    tie(v, w) = vw;
    if (v == p || v == s) continue;
    dfs(v, u, c);
  }
}
void dfs() {
  cc.assign(n, -1);
  cc[s] = s;
  for (auto p : adjList[s]) {
    int v, w;
    tie(v, w) = p;
    dfs(v, s, v);
  }
}
int solve1(int u, int mu) {
  vector<int> res(mu + 1, 0);
  res[0] = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (adjList[i].size() != 1 || cc[i] != cc[u]) continue;
    vector<int> t(mu + 1, 0);
    t[0] = INT_MAX;
    for (int j = 1; j <= mu; ++j) t[j] = dist[s][i] + solve(i, m - j);
    combine(res, t);
  }
  return res[mu];
}
int main() {
  cin >> n;
  adjList.assign(n, vector<pair<int, int> >());
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adjList[u].push_back(pair<int, int>(v, w));
    adjList[v].push_back(pair<int, int>(u, w));
  }
  cin >> s >> m;
  s--;
  dfs();
  vector<int> cnt(n, 0);
  for (int i = 0; i < m; ++i) {
    int xj;
    cin >> xj;
    xj--;
    cnt[cc[xj]]++;
  }
  calcdist();
  memo.assign(n, vector<int>(m + 1, -1));
  int res = INT_MAX;
  for (auto p : adjList[s]) {
    int v, w;
    tie(v, w) = p;
    res = min(res, solve1(v, cnt[v]));
  }
  cout << res << endl;
}
