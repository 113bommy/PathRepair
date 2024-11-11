#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 29;
const int inf = 1e9;
int n, m, k, u, v, s, t, d[maxn];
vector<int> adj[maxn];
bool mark[maxn];
queue<int> q;
void bfs() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (d[v] == inf) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}
void dfs(int u, int m) {
  mark[u] = 1;
  for (int v : adj[u]) {
    if (!mark[v] && d[u] + d[v] + 1 <= m) {
      dfs(v, m);
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    d[i] = inf;
  }
  for (int i = 0; i < k; i++) {
    cin >> u;
    u--;
    q.push(u);
    d[u] = 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> s >> t;
  s--;
  t--;
  if (d[t] == inf) {
    d[t] = 0;
    q.push(t);
  }
  bfs();
  int l = 0, r = 1e9;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    memset(mark, 0, sizeof mark);
    dfs(s, mid);
    if (mark[t] == 1) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (r == 1e9) {
    cout << -1;
    return 0;
  }
  cout << r;
}
