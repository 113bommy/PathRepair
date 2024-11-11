#include <bits/stdc++.h>
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
using namespace std;
vector<vector<int> > g;
vector<pair<int, int> > ed;
bool visited[1005];
int parent[1005];
pair<int, int> dfs(int node) {
  visited[node] = 1;
  pair<int, int> res(0, node);
  for (int i = 0; i < g[node].size(); i++) {
    if (!visited[g[node][i]]) {
      parent[g[node][i]] = node;
      res = max(res, dfs(g[node][i]));
    }
  }
  res.first++;
  return res;
}
pair<int, int> dfs2(int node, int parent) {
  pair<int, int> res(0, node);
  for (int i = 0; i < g[node].size(); i++) {
    if (parent != g[node][i]) {
      res = max(res, dfs2(g[node][i], node));
    }
  }
  res.first++;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b;
  vector<int> v;
  pair<int, int> r, r1;
  cin >> n >> m;
  g.assign(n + 1, v);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  m = n - 1 - m;
  vector<pair<int, int> > pos;
  memset(visited, (0), sizeof(visited));
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      r = dfs2(i, i);
      r = dfs2(r.second, r.second);
      pos.push_back(make_pair(-r.first, r.second));
    }
  }
  int y = 1;
  sort(pos.begin(), pos.end());
  for (int i = 0; i < m; i++) {
    memset(visited, (0), sizeof(visited));
    r = dfs(pos[0].second);
    memset(visited, (0), sizeof(visited));
    memset(parent, (-1), sizeof(parent));
    r = dfs(r.second);
    r.first /= 2;
    while (r.first--) {
      r.second = parent[r.second];
    }
    int j = pos[i + 1].second;
    r1 = dfs(j);
    memset(visited, (0), sizeof(visited));
    memset(parent, (-1), sizeof(parent));
    r1 = dfs(r1.second);
    r1.first /= 2;
    while (r1.first--) {
      r1.second = parent[r1.second];
    }
    ed.push_back(make_pair(r1.second + 1, r.second + 1));
    g[r1.second].push_back(r.second);
    g[r.second].push_back(r1.second);
  }
  memset(visited, (0), sizeof(visited));
  r = dfs(0);
  memset(visited, (0), sizeof(visited));
  r = dfs(r.second);
  cout << r.first - 1 << endl;
  for (int i = 0; i < ed.size(); i++)
    cout << ed[i].first << ' ' << ed[i].second << '\n';
  return 0;
}
