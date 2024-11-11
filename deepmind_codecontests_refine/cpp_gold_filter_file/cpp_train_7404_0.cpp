#include <bits/stdc++.h>
using namespace std;
vector<int> p, setSize;
int find_set(int v) {
  if (p[v] == v) return v;
  p[v] = find_set(p[v]);
  return p[v];
}
void join_set(int x, int y) {
  if (setSize[find_set(x)] > setSize[find_set(y)]) swap(x, y);
  p[find_set(x)] = p[y];
  setSize[y] += setSize[x];
}
vector<vector<int> > g;
vector<bool> visited;
vector<vector<int> > d;
void dfs(int init, int v, int tin) {
  visited[v] = true;
  d[init][v] = tin;
  for (int i = 0; i < g[v].size(); i++) {
    if (!visited[g[v][i]]) {
      dfs(init, g[v][i], tin + 1);
    }
  }
}
int ans_d = 0;
int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  p.resize(n);
  setSize.resize(n, 1);
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i < m; i++) {
    int t1, t2;
    cin >> t1 >> t2;
    t1--;
    t2--;
    g[t1].push_back(t2);
    g[t2].push_back(t1);
    join_set(t1, t2);
  }
  d.resize(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    visited.assign(n, false);
    dfs(i, i, 0);
  }
  vector<int> r(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[i] = max(r[i], d[i][j]);
    }
  }
  vector<pair<int, int> > minr(n, {INT_MAX, 0});
  for (int i = 0; i < n; i++) {
    if (minr[find_set(i)].first > r[i]) {
      minr[find_set(i)].first = r[i];
      minr[find_set(i)].second = i;
    }
  }
  int max_r = -INT_MAX;
  int start = -INT_MAX;
  for (int i = 0; i < n; i++) {
    if (minr[i].first == INT_MAX) continue;
    if (minr[i].first > max_r) {
      max_r = minr[i].first;
      start = i;
    }
  }
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    if (minr[i].first == INT_MAX) continue;
    if (start == i) {
      continue;
    }
    g[minr[i].second].push_back(minr[start].second);
    g[minr[start].second].push_back(minr[i].second);
    ans.push_back({minr[start].second, minr[i].second});
  }
  for (int i = 0; i < n; i++) {
    visited.assign(n, false);
    dfs(i, i, 0);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans_d = max(ans_d, d[i][j]);
  cout << ans_d << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  return 0;
}
