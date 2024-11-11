#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int> > graph(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int start = 1;
  int mxDegree = graph[start].size();
  for (int i = 2; i <= n; i++) {
    if (mxDegree < graph[i].size()) {
      start = i;
      mxDegree = graph[i].size();
    }
  }
  vector<int> visited(n + 1, 0);
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while (q.size() > 0) {
    for (int i = 0; i < graph[q.front()].size(); i++) {
      if (visited[graph[q.front()][i]] == 0) {
        q.push(graph[q.front()][i]);
        visited[graph[q.front()][i]] = 1;
        cout << q.front() << " " << graph[q.front()][i] << endl;
      }
    }
    q.pop();
  }
  return 0;
}
