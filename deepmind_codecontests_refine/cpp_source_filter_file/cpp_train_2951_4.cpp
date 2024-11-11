#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
struct Graph {
  vector<int> edges[100010];
  vector<int> redges[100010];
  int d[100010];
  bool visited[100010];
  int V = 100010;
  void add_edge(int from, int to) {
    edges[from].push_back(to);
    redges[to].push_back(from);
  }
  void bfs() {
    fill(visited, visited + V + 1, 0);
    for (int i = 1; i < V; i++)
      if (!visited[i]) bfs(i);
  }
  void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    d[s] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int next : edges[v]) {
        if (!visited[next]) {
          visited[next] = 1;
          d[next] = d[v] + 1;
          q.push(next);
        } else {
          ans.push_back(abs(d[next] - d[v] - 1));
          if (ans.back() == 0) ans.pop_back();
        }
      }
      for (int next : redges[v]) {
        if (!visited[next]) {
          visited[next] = 1;
          d[next] = d[v] - 1;
          q.push(next);
        } else {
          ans.push_back(abs(d[next] - d[v] + 1));
          if (ans.back() == 0) ans.pop_back();
        }
      }
    }
  }
};
int gcd(int m, int n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
Graph g;
int main() {
  int n, m;
  cin >> n >> m;
  g.V = n;
  int u, v;
  while (m--) {
    scanf("%d%d", &u, &v);
    g.add_edge(u, v);
  }
  g.bfs();
  if (ans.size() == 0) {
    cout << n << endl;
    return 0;
  }
  int sol = ans[0];
  for (int i : ans) sol = gcd(sol, i);
  cout << sol << endl;
  return 0;
}
