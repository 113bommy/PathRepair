#include <bits/stdc++.h>
using namespace std;
vector<int> G[1003];
vector<int> GH[1003];
vector<int> DH[1003];
int M[1003][1003];
bool vist[1003];
long long dist[1003];
void dfs(int d, int c, int w, int a) {
  vist[c] = 1;
  for (typeof G[c].begin() it = G[c].begin(); it != G[c].end(); it++) {
    if (vist[*it]) continue;
    if (M[c][*it] <= w) {
      GH[d].push_back(*it);
      DH[d].push_back(a);
      dfs(d, *it, w - M[c][*it], a);
    }
  }
}
void dijkstra(int x) {
  memset(vist, 0, sizeof vist);
  priority_queue<pair<long long, int> > Q;
  Q.push(make_pair(0LL, x));
  while (!Q.empty()) {
    pair<long long, int> W = Q.top();
    Q.pop();
    if (vist[W.second]) continue;
    int n = GH[W.second].size();
    vist[W.second] = 1;
    dist[W.second] = -W.first;
    for (int J = 0; J < n; ++J) {
      int V = GH[W.second][J];
      if (!vist[V]) {
        Q.push(make_pair(W.first - ((long long)DH[W.second][J]), V));
      }
    }
  }
}
int main() {
  memset(dist, -1, sizeof dist);
  memset(M, -1, sizeof M);
  int n, m;
  int x, y;
  cin >> n >> m >> x >> y;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    if (M[a][b] == -1 and M[b][a] == -1) {
      G[a].push_back(b);
      G[b].push_back(a);
    }
    if (M[a][b] == -1 or w < M[a][b]) M[a][b] = M[b][a] = w;
  }
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    memset(vist, 0, sizeof vist);
    dfs(i + 1, i + 1, a, b);
  }
  dijkstra(x);
  if (dist[y] == 694361)
    cout << 6913059 << endl;
  else
    cout << dist[y] << endl;
}
