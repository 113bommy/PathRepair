#include <bits/stdc++.h>
using namespace std;
int n, m;
int ct, odd;
void dfs(vector<vector<int> > graph, int x, vector<bool> &visited) {
  visited[x] = true;
  ct++;
  if (graph[x].size() == 1 || graph[x].size() == 0) odd = 1;
  int next;
  for (int i = 0; i < graph[x].size(); i++) {
    next = graph[x][i];
    if (!visited[next]) dfs(graph, next, visited);
  }
}
int main() {
  int x, y;
  cin >> n >> m;
  vector<vector<int> > graph(n + 1, vector<int>());
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  vector<bool> visited(n + 1, false);
  int ans = 0;
  ct = 0;
  odd = 0;
  for (int i = 1; i < n + 1; i++) {
    if (!visited[i]) {
      ct = 0;
      odd = 0;
      dfs(graph, i, visited);
      if (ct % 2 == 0)
        ans += ct;
      else {
        if (odd == 0)
          ans += ct - 1;
        else
          ans += ct;
      }
    }
  }
  if (ans % 2 == 0)
    cout << n - ans;
  else
    cout << n - (ans - 1);
  return 0;
}
