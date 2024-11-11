#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10000];
int color[10000];
int good = true;
int comp[10000];
int dist[10000];
int compBest[100000];
void dfs(int v, int c) {
  comp[v] = c;
  for (int u : adj[v]) {
    if (color[u] == color[v]) {
      good = false;
      return;
    } else if (color[u] == 0) {
      color[u] = 3 - color[v];
      dfs(u, c);
    }
  }
}
int bfs(int v) {
  memset(dist, -1, sizeof dist);
  dist[v] = 0;
  queue<int> q;
  q.push(v);
  int mDist = 0;
  while (!q.empty()) {
    int u = q.front();
    mDist = max(mDist, dist[u]);
    q.pop();
    for (int k : adj[u]) {
      if (dist[k] == -1) {
        dist[k] = dist[u] + 1;
        q.push(k);
      }
    }
  }
  return mDist;
}
int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  int compC = 0;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0) {
      color[i] = 2;
      dfs(0, compC++);
    }
  }
  memset(dist, -1, sizeof dist);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int val = bfs(i);
    compBest[comp[i]] = max(compBest[comp[i]], val);
  }
  for (int i = 0; i < compC; ++i) {
    res += compBest[i];
  }
  if (good == false) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
  return 0;
}
