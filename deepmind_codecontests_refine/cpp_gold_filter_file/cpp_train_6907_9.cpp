#include <bits/stdc++.h>
using namespace std;
long long INF = 10000000000000;
bool visited[100005];
long long dis[100005];
int path[100005];
vector<pair<long, int> > G[100005];
void dijkstra(int source) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      Q;
  Q.push(make_pair(0, source));
  dis[source] = 0;
  while (!Q.empty()) {
    int v = Q.top().second;
    long long d = Q.top().first;
    Q.pop();
    visited[v] = 1;
    for (int i = 0; i < G[v].size(); i++) {
      if (visited[G[v][i].second]) continue;
      if (d + G[v][i].first < dis[G[v][i].second]) {
        dis[G[v][i].second] = d + G[v][i].first;
        path[G[v][i].second] = v;
      }
      Q.push(make_pair(d + G[v][i].first, G[v][i].second));
    }
  }
}
void init() {
  for (int i = 0; i < 100005; i++) {
    dis[i] = INF;
    visited[i] = false;
    G[i].clear();
    path[i] = -1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  init();
  vector<int> Sol;
  int N, M, u, v, w;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(make_pair(w, v));
    G[v].push_back(make_pair(w, u));
  }
  dijkstra(0);
  N--;
  while (path[N] != -1) {
    Sol.push_back(N + 1);
    N = path[N];
  }
  if (!Sol.size()) {
    cout << -1 << endl;
    return 0;
  }
  Sol.push_back(1);
  for (int i = Sol.size() - 1; i >= 0; i--) cout << Sol[i] << " ";
  cout << endl;
}
