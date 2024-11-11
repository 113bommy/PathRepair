#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long from, to, w;
  edge(long long from, long long to, long long w) : from(from), to(to), w(w) {}
  bool operator<(const edge& e) const { return w > e.w; }
};
const long long OO = 1e12;
int nodes, edges;
vector<long long> vdist, vprev;
vector<vector<edge>> adjlist;
void dijkstra(int node) {
  vdist[node] = 0;
  priority_queue<edge> q;
  q.push(edge(-1, node, 0));
  while (q.size()) {
    edge e = q.top();
    q.pop();
    if (e.w > vdist[e.to]) {
      continue;
    }
    vprev[e.to] = e.from;
    for (int x = 0; x < adjlist[e.to].size(); x++) {
      edge ne = adjlist[e.to][x];
      long long d = (vdist[ne.from] + ne.w);
      if (vdist[ne.to] > d) {
        ne.w = vdist[ne.to] = d;
        q.push(ne);
      }
    }
  }
}
int main() {
  cin >> nodes >> edges;
  long long a, b, c;
  adjlist.assign(nodes + 1, vector<edge>());
  vdist.assign(nodes + 1, OO);
  vprev.assign(nodes + 1, -1);
  for (int x = 0; x < edges; x++) {
    cin >> a >> b >> c;
    adjlist[a].push_back(edge(a, b, c));
    adjlist[b].push_back(edge(b, a, c));
  }
  dijkstra(1);
  vector<int> path;
  if (vprev[nodes] == -1) {
    cout << -1;
    return 0;
  }
  for (int x = nodes; x != 1;) {
    path.push_back(x);
    x = vprev[x];
  }
  reverse(path.begin(), path.end());
  cout << 1 << " ";
  for (int x = 0; x < path.size(); x++) {
    cout << path[x] << " ";
  }
  return 0;
}
