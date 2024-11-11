#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > adj[105];
int val[105];
int x[105];
int y[105];
void moddijkstra(int v) {
  int dist[v + 1];
  for (int i = 0; i < v + 1; i++) dist[i] = 1e8;
  int start = v;
  dist[start] = 0;
  set<pair<int, int> > s;
  s.insert({0, start});
  int ik = 0;
  while (!s.empty()) {
    ik++;
    if (ik > 100) break;
    pair<int, int> p = *s.begin();
    s.erase(s.begin());
    int x = p.second;
    int wei = p.first;
    for (int i = 0; i < (int)adj[x].size(); i++) {
      int w = adj[x][i].first;
      int e = adj[x][i].second;
      if (dist[x] + w < dist[e]) {
        if (dist[e] != 1e8) s.erase(s.find(make_pair(dist[e], e)));
        dist[e] = dist[x] + w;
        s.insert({dist[e], e});
      }
    }
  }
  cout << dist[1] << " ";
}
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 2; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (i != j) {
        adj[i].push_back(
            make_pair((d * (abs(x[i] - x[j]) + abs(y[i] - y[j]))) - val[j], j));
      }
    }
  }
  moddijkstra(n);
}
