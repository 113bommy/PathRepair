#include <bits/stdc++.h>
using namespace std;
long long int c = 0;
void bfs(map<long long int, vector<long long int> > &map, vector<bool> &visited,
         long long int x) {
  queue<long long int> q;
  q.push(x);
  visited[x] = true;
  while (!q.empty()) {
    long long int y = q.front();
    q.pop();
    for (long long int i : map[y]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}
int main() {
  long long int x, y, n, m;
  cin >> n >> m;
  map<long long int, vector<long long int> > map;
  std::vector<bool> visited(n + 1, false), visitedf(n + 1, false);
  for (long long int i = 0; i < m; i++) {
    cin >> x >> y;
    map[x].push_back(y);
    map[y].push_back(x);
  }
  if (m != n - 1) {
    cout << "no";
    return 0;
  }
  bfs(map, visited, map.begin()->first);
  for (long long int i = 1; i <= n; i++) {
    if (!visited[i]) {
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
}
