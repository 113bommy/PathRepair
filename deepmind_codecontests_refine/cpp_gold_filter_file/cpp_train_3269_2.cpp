#include <bits/stdc++.h>
using namespace std;
int n, m, k, d;
vector<vector<int>> graph;
vector<int> p;
vector<int> h1, h2;
vector<bool> was;
vector<bool> isP;
void input() {
  cin >> n >> m >> d;
  graph = vector<vector<int>>(n);
  p = vector<int>(m);
  isP = vector<bool>(n, false);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < p.size(); ++i) {
    isP[p[i]] = true;
  }
  int a, b;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  h1 = vector<int>(n, -1);
  h2 = vector<int>(n, -1);
  was = vector<bool>(n, false);
}
void dfs1(int v) {
  was[v] = true;
  int to;
  vector<int> d;
  for (int i = 0; i < graph[v].size(); ++i) {
    to = graph[v][i];
    if (!was[to]) {
      dfs1(to);
      d.push_back(h1[to]);
    }
  }
  if (d.size() == 0) {
    if (isP[v]) h1[v] = 0;
    return;
  }
  int m = -100;
  for (int i = 0; i < d.size(); ++i) {
    m = max(m, d[i]);
  }
  if (m < 0) {
    if (isP[v]) h1[v] = 0;
    return;
  } else {
    h1[v] = m + 1;
  }
}
int ans = 0;
void dfs2(int v) {
  if (v == 2) {
    int t = 0;
    t++;
  }
  was[v] = true;
  priority_queue<int> q;
  int lastto;
  int to;
  for (int i = 0; i < graph[v].size(); ++i) {
    to = graph[v][i];
    if (!was[to]) {
      q.push(h1[to]);
      lastto = to;
    }
  }
  int m = -1;
  if (isP[v]) m = 0;
  h2[v] = max(h2[v], m);
  if (q.size() == 0) {
    return;
  }
  if (q.size() == 1) {
    if (h2[v] != -1) {
      h2[lastto] = h2[v] + 1;
      dfs2(lastto);
      q.pop();
      return;
    }
    dfs2(lastto);
    return;
  }
  int m1 = q.top();
  q.pop();
  int m2 = q.top();
  int now;
  for (int i = 0; i < graph[v].size(); ++i) {
    to = graph[v][i];
    if (!was[to]) {
      if (to == 3) {
        int t = 0;
        t++;
      }
      if (h1[to] == m1) {
        now = m2 + 1;
      } else {
        now = m1 + 1;
      }
      if (now == 0) {
        if (h2[v] != -1) {
          h2[to] = h2[v] + 1;
        }
      } else {
        h2[to] = max(h2[v], now) + 1;
      }
      dfs2(to);
    }
  }
}
void solve() {
  dfs1(0);
  was = vector<bool>(n, false);
  if (h1[0] <= d) ans++;
  dfs2(0);
  for (int i = 1; i < n; ++i) {
    if (max(h1[i], h2[i]) <= d) ans++;
  }
  cout << ans;
}
int main() {
  input();
  solve();
  return 0;
}
