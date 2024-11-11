#include <bits/stdc++.h>
using namespace std;
vector<int> g[100005];
int visited[100005], parent[100005];
int n, m, x;
int bfs(int t) {
  int count, i, k;
  int max = -1;
  queue<pair<int, int> > q;
  q.push(pair<int, int>(t, 0));
  visited[t] = 1;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    x = p.first;
    count = p.second;
    k = g[x].size();
    for (i = 0; i < k; i++) {
      if (!visited[g[x][i]]) {
        visited[g[x][i]] = 1;
        q.push(pair<int, int>(g[x][i], count + 1));
      }
    }
  }
  return count;
}
int main() {
  long long int i, u, v;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bfs(u);
  memset(visited, 0, sizeof(visited));
  cout << bfs(x);
}
