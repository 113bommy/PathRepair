#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
using lg = int64_t;
using ulg = uint64_t;
struct Edge {
  int id;
  int u, v;
  bool processed;
  int dir;
};
vector<vector<int>> oriented;
vector<vector<Edge*>> nonOriented;
vector<Edge> nonOrientedEdges;
vector<bool> visited;
void dfsMax(int from, int& count) {
  if (visited[from]) return;
  visited[from] = true;
  count++;
  for (int t : oriented[from]) dfsMax(t, count);
  for (Edge* d : nonOriented[from]) {
    if (d->processed) continue;
    if (from == d->u) {
      d->dir = 0;
    } else if (from == d->v) {
      d->dir = 1;
    } else
      throw std::exception();
    d->processed = true;
    dfsMax((from == d->u) ? d->v : d->u, count);
  }
}
void dfsMin(int from, int& count) {
  if (visited[from]) return;
  visited[from] = true;
  count++;
  for (int t : oriented[from]) dfsMax(t, count);
  for (Edge* d : nonOriented[from]) {
    if (d->processed) continue;
    if (from == d->u) {
      d->dir = 1;
    } else if (from == d->v) {
      d->dir = 0;
    } else
      throw std::exception();
    d->processed = true;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int n, m, s;
  cin >> n >> m >> s;
  oriented = vector<vector<int>>(n + 1, vector<int>());
  nonOriented = vector<vector<Edge*>>(n + 1, vector<Edge*>());
  visited = vector<bool>(n + 1, false);
  nonOrientedEdges.push_back(Edge());
  nonOrientedEdges.reserve(300005);
  for (int i = 0; i < m; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      oriented[u].push_back(v);
    } else {
      nonOrientedEdges.push_back(
          Edge{(int)nonOrientedEdges.size(), u, v, false, -1});
      Edge* ptr = &nonOrientedEdges[nonOrientedEdges.size() - 1];
      nonOriented[u].push_back(ptr);
      nonOriented[v].push_back(ptr);
    }
  }
  int cnt = 0;
  dfsMax(s, cnt);
  cout << cnt << endl;
  for (int i = 1; i < nonOrientedEdges.size(); i++)
    cout << ((nonOrientedEdges[i].dir == 0) ? '+' : '-');
  cout << endl;
  for (int i = 0; i < visited.size(); i++) visited[i] = false;
  for (int i = 0; i < nonOrientedEdges.size(); i++)
    nonOrientedEdges[i].processed = false;
  cnt = 0;
  dfsMin(s, cnt);
  cout << cnt << endl;
  for (int i = 1; i < nonOrientedEdges.size(); i++)
    cout << ((nonOrientedEdges[i].dir == 0) ? '+' : '-');
  cout << endl;
  return 0;
}
