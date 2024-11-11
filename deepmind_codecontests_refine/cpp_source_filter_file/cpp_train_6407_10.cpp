#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int> > &graph, int i, vector<int> &mark) {
  mark[i] = 1;
  for (int j = 0; j < graph[i].size(); j++)
    if (mark[graph[i][j]] == 0) dfs(graph, graph[i][j], mark);
}
int main() {
  int n, m, x, y;
  cin >> n >> m;
  vector<int> mark(n, 0);
  vector<int> row;
  vector<vector<int> > graph(n, row);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    graph[x - 1].push_back(y - 1);
    graph[y - 1].push_back(x - 1);
  }
  if (m == n - 1) {
    dfs(graph, 0, mark);
    for (int i = 0; i < n; i++)
      if (mark[i] == 0) {
        cout << "NO" << endl;
        ;
        return 0;
      }
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
