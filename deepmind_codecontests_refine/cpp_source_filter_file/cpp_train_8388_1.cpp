#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<pair<int, int>, vector<pair<int, int> >,
                       greater<pair<int, int> > >
    pq;
long long mod = 1000 * 1000 * 1000 + 7;
vector<vector<int> > graph;
int e, ver;
vector<int> vis;
void bfs(int s) {
  e = 0;
  ver = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 1;
    for (int i = (0); i < (graph[u].size()); i++) {
      int v = graph[u][i];
      if (vis[v] == -1 || vis[v] == 0) {
        e++;
        if (vis[v] == -1) {
          q.push(v);
          ver++;
          vis[v] = 0;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  vis.resize(n + 1, -1);
  for (int i = (0); i < (m); i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = (1); i < (n + 1); i++) {
    if (vis[i] == -1) {
      bfs(i);
    }
    if (!(e == ver * (ver - 1) / 2)) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
