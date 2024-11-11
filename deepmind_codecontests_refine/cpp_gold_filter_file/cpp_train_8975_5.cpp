#include <bits/stdc++.h>
using namespace std;
const int M = 220000;
vector<int> e1[M], e2[M];
int p[M], dis[M];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    e1[u].push_back(v);
    e2[v].push_back(u);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) cin >> p[i];
  queue<int> q;
  q.push(p[k - 1]);
  dis[p[k - 1]] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : e2[u]) {
      if (dis[v] == 0) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  int mi = 0, mx = 0;
  for (int i = 0; i < k - 1; i++) {
    if (dis[p[i]] != dis[p[i + 1]] + 1) ++mi;
    for (int v : e1[p[i]]) {
      if (v != p[i + 1] && dis[p[i]] == dis[v] + 1) {
        ++mx;
        break;
      }
    }
  }
  cout << mi << ' ' << mx << endl;
  return 0;
}
