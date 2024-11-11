#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> &v) {
  for (auto x : v) cout << x << " ";
  cout << "\n";
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int t;
  t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > edges(n), edges_rev(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      edges_rev[u].push_back(v);
      edges[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
      cin >> p[i];
      p[i]--;
    }
    vector<int> visited(n, 0);
    vector<int> dis(n, 0);
    int root = p[k - 1];
    queue<int> q;
    q.push(root);
    visited[root] = 1;
    while (!q.empty()) {
      int u = q.front();
      for (auto x : edges[u]) {
        if (visited[x] == 0) {
          visited[x] = 1;
          q.push(x);
          dis[x] = dis[u] + 1;
        }
      }
      q.pop();
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < k - 1; i++) {
      int u = p[i];
      int sh = n;
      int c = 0;
      for (auto x : edges_rev[u]) {
        if (dis[x] < sh) {
          c = 1;
          sh = dis[x];
        } else if (dis[x] == sh)
          c++;
      }
      if (sh == dis[p[i + 1]]) {
        mx += (c - 1);
      } else {
        mn++;
        mx += c;
      }
    }
    cout << mn << " " << mx << "\n";
  }
}
