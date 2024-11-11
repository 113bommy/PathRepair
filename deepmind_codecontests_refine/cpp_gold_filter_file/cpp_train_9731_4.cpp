#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 7;
const int oo = 1e9 + 7;
int n, m, cnt;
pair<int, int> d[maxN], trace[maxN];
bool vis[maxN];
pair<pair<int, int>, int> adj[maxN];
vector<pair<pair<int, int>, int> > edges[maxN];
void Dijkstra() {
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >,
                 greater<pair<pair<int, int>, int> > >
      pq;
  for (int i = 1; i <= n; i++) d[i] = pair<int, int>(oo, oo);
  d[1] = pair<int, int>(0, cnt);
  trace[1] = pair<int, int>(-1, 0);
  pq.push(pair<pair<int, int>, int>(d[1], 1));
  while (!pq.empty()) {
    pair<int, int> du = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (du != d[u]) continue;
    for (int i = 0; i < edges[u].size(); i++) {
      int c = edges[u][i].first.first;
      int v = edges[u][i].first.second;
      int cs = edges[u][i].second;
      if (d[v].first > d[u].first + 1) {
        d[v].first = d[u].first + 1;
        d[v].second = d[u].second;
        if (c == 0) d[v].second++;
        if (c == 1) d[v].second--;
        trace[v] = pair<int, int>(u, cs);
        pq.push(pair<pair<int, int>, int>(d[v], v));
      } else if (d[v].first == d[u].first + 1) {
        int cp = d[u].second;
        if (c == 0) cp++;
        if (c == 1) cp--;
        if (d[v].second > cp) {
          d[v].second = cp;
          trace[v] = pair<int, int>(u, cs);
          pq.push(pair<pair<int, int>, int>(d[v], v));
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[i] = pair<pair<int, int>, int>(pair<int, int>(u, v), w);
    edges[u].push_back(pair<pair<int, int>, int>(pair<int, int>(w, v), i));
    edges[v].push_back(pair<pair<int, int>, int>(pair<int, int>(w, u), i));
    if (w == 1) cnt++;
  }
  Dijkstra();
  cout << d[n].second << "\n";
  for (int i = n; i != -1; i = trace[i].first) vis[trace[i].second] = true;
  for (int i = 1; i <= m; i++) {
    int u = adj[i].first.first;
    int v = adj[i].first.second;
    int c = adj[i].second;
    if (vis[i] == true && c == 0) cout << u << " " << v << " " << 1 << "\n";
    if (vis[i] == false && c == 1) cout << u << " " << v << " " << 0 << "\n";
  }
  return 0;
}
