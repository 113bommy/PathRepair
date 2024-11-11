#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, vector<vector<int>>& v, vector<int>& visit,
         vector<int>& color) {
  int i;
  bool b = true;
  for (i = 0; i < v[u].size(); i++) {
    int child = v[u][i];
    if (visit[child] == 0) {
      visit[child] = 1;
      color[child] = 1 - color[u];
      b = dfs(child, v, visit, color);
      if (b == false) return false;
    } else {
      if (color[child] == color[u]) return false;
    }
  }
  return b;
}
int main() {
  int n, m, i, j;
  cin >> n >> m;
  vector<vector<int>> v(n + 1);
  for (i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  vector<int> visit(n + 1);
  for (i = 0; i <= n; i++) visit[i] = 0;
  vector<int> color(n + 1);
  for (i = 0; i <= n; i++) color[i] = -1;
  bool b;
  for (i = 1; i <= n; i++) {
    if (visit[i] == 0) {
      visit[i] = 1;
      color[i] = 0;
      b = dfs(i, v, visit, color);
      if (b == false) break;
    }
  }
  vector<int> p;
  vector<int> q;
  for (i = 1; i <= n; i++) {
    if (v[i].size() == 0) continue;
    if (color[i] == 0)
      p.push_back(i);
    else if (color[i] == 1)
      q.push_back(i);
  }
  if (b == false)
    cout << -1 << endl;
  else {
    cout << q.size() << endl;
    for (i = 0; i < q.size(); i++) cout << q[i] << " ";
    cout << endl;
    cout << p.size() << endl;
    for (i = 0; i < p.size(); i++) cout << p[i] << " ";
    cout << endl;
  }
}
