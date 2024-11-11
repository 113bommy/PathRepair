#include <bits/stdc++.h>
using namespace std;
long long int nc3(long long int n) {
  n = n * (n - 1) * (n - 2);
  return n / 6;
}
vector<int> V[100005];
int cc = 1;
long long int red[100005], blue[100005], color[100005];
int size[100005], vis[100005];
bool bipartite[100005];
int reverse(int color) {
  if (color == 0) {
    blue[cc]++;
    return 1;
  }
  red[cc]++;
  return 0;
}
bool bfs(int node) {
  vis[node] = 1;
  color[node] = 0;
  red[cc]++;
  size[cc]++;
  queue<int> Q;
  while (!Q.empty()) Q.pop();
  Q.push(node);
  while (!Q.empty()) {
    node = Q.front();
    for (int i = 0; i < V[node].size(); i++) {
      int v = V[node][i];
      if (color[v] == color[node]) {
        return false;
      }
      if (vis[v] == 0) {
        size[cc]++;
        Q.push(v);
        vis[v] = 1;
        color[v] = reverse(color[node]);
      }
    }
    Q.pop();
  }
  return true;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << 3 << " " << nc3(n) << "\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) V[i].clear();
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  memset(bipartite, false, sizeof bipartite);
  memset(color, -1, sizeof color);
  for (int i = 1; i <= n; i++)
    if (vis[i] == 0) {
      bipartite[cc] = bfs(i);
      cc++;
    }
  for (int i = 1; i <= cc; i++)
    if (!bipartite[i] && size[i] > 2) {
      cout << "0 1\n";
      return 0;
    }
  long long int ans = 0;
  int edges = -1;
  for (int i = 1; i <= cc; i++)
    if (bipartite[i] && size[i] > 2) {
      edges = 1;
      ans += (red[i] * (red[i] - 1)) / 2 + (blue[i] * (blue[i] - 1)) / 2;
    }
  if (edges != -1) {
    cout << edges << " " << ans << "\n";
    return 0;
  }
  cout << 2 << " " << m * (n - 2) << "\n";
  return 0;
}
