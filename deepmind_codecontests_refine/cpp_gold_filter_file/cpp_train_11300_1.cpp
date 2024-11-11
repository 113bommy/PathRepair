#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 200;
int n, m, u, v, c, cnt;
vector<int> g[N];
bool visited[N];
int dist[N];
const int fx[9] = {0, 0, 1, -1, 0, 1, 1, -1, -1};
const int fy[9] = {1, -1, 0, 0, 0, 1, -1, 1, -1};
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
void bfs(int x) {
  queue<int> q;
  dist[x] = 0;
  q.push(x);
  visited[x] = true;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (auto i : g[curr]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = true;
        dist[i] = dist[curr] + 1;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  bfs(1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[x]) {
      x = i;
    }
  }
  memset(dist, 0, sizeof(dist));
  ;
  memset(visited, false, sizeof(visited));
  ;
  bfs(x);
  cout << *max_element(dist, dist + n + 1);
}
