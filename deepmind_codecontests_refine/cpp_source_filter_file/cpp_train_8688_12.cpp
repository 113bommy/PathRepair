#include <bits/stdc++.h>
using namespace std;
const int MAX = 210;
const int INF = 1 << 30;
int h, t, R;
int n, m;
map<pair<int, int>, int> comp;
vector<int> adj[2 * MAX * MAX];
vector<int> top_sort;
int vis[2 * MAX * MAX];
int proc[2 * MAX * MAX];
int dist[2 * MAX * MAX];
int bfs(int s) {
  for (int i = 1; i < 2 * MAX * MAX; i++) dist[i] = INF;
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < adj[v].size(); i++) {
      int u = adj[v][i];
      if (dist[u] == INF) {
        q.push(u);
        dist[u] = dist[v] + 1;
      }
    }
  }
  return dist[comp[pair<int, int>(0, 0)]];
}
int dfs(int v) {
  proc[v] = true;
  vis[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (proc[u]) {
      return true;
    }
    if (!vis[u])
      if (dfs(u)) return true;
  }
  top_sort.push_back(v);
  vis[v] = true;
  proc[v] = false;
  return false;
}
bool cicle() {
  for (int i = 1; i < 2 * MAX * MAX; i++) {
    if (!vis[i]) {
      if (dfs(i)) return true;
    }
  }
  return false;
}
int main() {
  cin >> h >> t >> R;
  int k = 1;
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++) {
      comp[pair<int, int>(i, j)] = k++;
    }
  int a, b;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    for (int x = i; x <= R; x++) {
      for (int y = 0; y <= R; y++) {
        if (x + y <= R)
          adj[comp[pair<int, int>(x, y)]].push_back(
              comp[pair<int, int>(x + a - i, y + b)]);
      }
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    for (int x = 0; x <= R; x++)
      for (int y = i; y <= R; y++) {
        if (x + y <= R)
          adj[comp[pair<int, int>(x, y)]].push_back(
              comp[pair<int, int>(x + a, y + b - i)]);
      }
  }
  int s = comp[pair<int, int>(h, t)];
  int a1 = bfs(s);
  if (a1 < INF) {
    cout << "Ivan\n";
    cout << a1 << "\n";
  } else if (cicle())
    cout << "Draw\n";
  else {
    for (int i = 1; i < 2 * MAX * MAX; i++) dist[i] = -INF;
    dist[s] = 0;
    reverse(top_sort.begin(), top_sort.end());
    int a2 = -INF;
    for (int i = 1; i < top_sort.size(); i++) {
      int v = top_sort[i];
      for (int j = 0; j < adj[v].size(); j++) {
        int u = adj[v][j];
        dist[u] = max(dist[u], dist[v] + 1);
      }
    }
    int maior = 0;
    for (int i = 0; i <= R; i++)
      for (int j = 0; j <= R; j++)
        if (i + j > R) maior = max(dist[comp[pair<int, int>(i, j)]], maior);
    cout << "Zmey\n";
    cout << maior << "\n";
  }
}
