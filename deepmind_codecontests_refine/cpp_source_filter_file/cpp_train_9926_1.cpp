#include <bits/stdc++.h>
using namespace std;
const int N = 203600;
const long long INF = 1LL << 28;
struct Edge {
  int first, second;
  long long w;
  Edge() {}
  Edge(int first, int second, long long w)
      : first(first), second(second), w(w) {}
  bool operator<(const Edge &edge) const { return w < edge.w; }
};
struct Node {
  int first;
  long long d;
  Node(long long d, int first) : d(d), first(first) {}
  bool operator>(const Node &node) const { return d > node.d; }
};
vector<int> adj[N];
vector<long long> w[N];
void ae(int first, int second, long long w) {
  adj[first].push_back(second);
  ::w[first].push_back(w);
  adj[second].push_back(first);
  ::w[second].push_back(w);
}
int n, m;
int a[N];
long long d[N], p[N];
void Dijkstra() {
  priority_queue<Node, vector<Node>, greater<Node> > pq;
  for (int i = (0); i < (int)(n); i++) d[i] = INF;
  for (int j = (0); j < (int)(m); j++) {
    int first = a[j];
    d[first] = 0;
    p[first] = first;
    pq.push(Node(0, first));
  }
  while (!pq.empty()) {
    int first = pq.top().first;
    long long c = pq.top().d;
    pq.pop();
    if (d[first] < c) continue;
    for (int j = (0); j < (int)(adj[first].size()); j++) {
      int second = adj[first][j];
      long long ne = c + w[first][j];
      if (d[second] > ne) {
        d[second] = ne;
        p[second] = p[first];
        pq.push(Node(ne, second));
      }
    }
  }
}
vector<Edge> edge;
int Find(int first) {
  if (p[first] == first) return first;
  return p[first] = Find(p[first]);
}
long long Krustal() {
  for (int first = (0); first < (int)(n); first++) {
    for (int j = (0); j < (int)(adj[first].size()); j++) {
      int second = adj[first][j];
      long long w = d[first] + d[second] + ::w[first][j];
      if (first < second) {
        edge.push_back(Edge(first, second, w));
      }
    }
  }
  sort((edge).begin(), (edge).end());
  long long res = 0LL;
  for (int i = (0); i < (int)(edge.size()); i++) {
    int first = edge[i].first, second = edge[i].second;
    long long w = edge[i].w;
    if (Find(first) != Find(second)) {
      p[Find(first)] = Find(second);
      res += w;
    }
  }
  return res;
}
int main() {
  cin >> n >> m;
  bool flag = false;
  while (m--) {
    int first, second;
    long long w;
    cin >> first >> second >> w;
    --first;
    --second;
    ae(first, second, w);
  }
  cin >> m;
  for (int j = (0); j < (int)(m); j++) {
    cin >> a[j];
    --a[j];
    flag |= (a[j] == 0);
  }
  Dijkstra();
  long long res = Krustal();
  if (!flag) {
    res += d[0];
  }
  cout << res << endl;
  return 0;
}
