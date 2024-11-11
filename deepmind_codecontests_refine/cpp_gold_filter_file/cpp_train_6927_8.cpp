#include <bits/stdc++.h>
using namespace std;
const int MX = 5000 + 10, MD = 1e9 + 7;
long long n, m, a[MX], ans, tmp, color[MX], col = 1, cpcnt, cpsize, dist[MX];
vector<int> adj[MX], radj[MX], topol, cp[MX];
bool mark[MX];
void dfs(int v) {
  mark[v] = 1;
  for (auto u : adj[v])
    if (!mark[u]) dfs(u);
  topol.push_back(v);
}
void sfd(int v) {
  color[v] = col;
  for (auto u : radj[v])
    if (!color[u]) sfd(u);
}
long long bfs(int v) {
  fill(dist, dist + MX, 1e12);
  queue<int> q;
  dist[v] = 0;
  q.push(v);
  int flag = 0, len = 0;
  while (q.size() && !flag) {
    int u = q.front();
    q.pop();
    for (auto pa : adj[u]) {
      if (pa == v) {
        if (flag == 0 || len > dist[u]) len = dist[u];
        flag = 1;
        break;
      }
      if (dist[pa] > dist[u] + 1) {
        dist[pa] = dist[u] + 1;
        q.push(pa);
      }
    }
  }
  return len;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  for (int i = 0; i < n; i++)
    if (!mark[i]) dfs(i);
  reverse(topol.begin(), topol.end());
  for (auto v : topol)
    if (!color[v]) sfd(v), col++;
  for (int i = 0; i < n; i++) cp[color[i]].push_back(i);
  for (int i = 1; i < col; i++) {
    int flag = 1;
    for (auto v : cp[i])
      for (int u : adj[v])
        if (color[u] != i) {
          flag = 0;
          break;
        }
    if (flag) {
      long long length = 1e12;
      for (auto pa : cp[i]) {
        tmp = bfs(pa);
        length = min(tmp, length);
      }
      if (length) {
        cpcnt++;
        cpsize += length + 1;
      }
    }
  }
  cout << 998 * cpsize + n + cpcnt;
}
