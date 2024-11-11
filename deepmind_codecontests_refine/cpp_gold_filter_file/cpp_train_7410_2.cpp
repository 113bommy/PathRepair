#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int d[N];
int n, ok = 1, vis[N];
vector<pair<int, int> > G[N];
int check() {
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!d[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : G[u]) {
      vis[v.second] = 1;
      if (--d[v.first] == 0) q.push(v.first);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (d[i]) return 0;
  }
  return 1;
}
int main() {
  int m, u, v;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    d[v]++;
    G[u].push_back(make_pair(v, i));
  }
  if (check()) {
    puts("1");
    for (int i = 1; i <= m; i++) {
      cout << "1 " << endl;
    }
    return 0;
  }
  cout << 2 << endl;
  for (int i = 1; i <= n; i++) {
    for (auto tmp : G[i]) {
      int id = tmp.second;
      int to = tmp.first;
      if (!vis[id]) {
        if (i < to)
          vis[id] = 1;
        else
          vis[id] = 2;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << vis[i] << " ";
  }
  return 0;
}
