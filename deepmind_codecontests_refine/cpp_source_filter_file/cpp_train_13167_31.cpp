#include <bits/stdc++.h>
struct Edge {
  Edge(int a, int b, int64_t w) : a(a), b(b), weight(w), visited(false) {}
  int other(int n) { return a == n ? b : a; }
  int a, b;
  int64_t weight;
  bool visited;
};
struct DistanceWeight {
  DistanceWeight(int n, int e, int d, int w) : n(n), e(e), d(d), w(w) {}
  bool operator<(const DistanceWeight &dw) const {
    if (d == dw.d) return w > dw.w;
    return d > dw.d;
  }
  int n, e;
  int64_t d, w;
};
std::vector<int64_t> nodeDistances;
std::vector<std::vector<int> > nodes;
std::vector<Edge> edges;
int main() {
  int N, M;
  std::cin >> N >> M;
  nodes.resize(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    int64_t w;
    std::cin >> u >> v >> w;
    int ei = edges.size();
    edges.push_back(Edge(u - 1, v - 1, w));
    nodes[u - 1].push_back(ei);
    nodes[v - 1].push_back(ei);
  }
  int U0;
  std::cin >> U0;
  --U0;
  nodeDistances.resize(N, -1);
  nodeDistances[U0] = 0;
  std::priority_queue<DistanceWeight> queue;
  std::vector<int> &u0Node = nodes[U0];
  for (size_t i = 0; i < u0Node.size(); ++i) {
    int ei = u0Node[i];
    Edge &e = edges[ei];
    queue.push(DistanceWeight(e.other(U0), ei, e.weight, e.weight));
  }
  while (!queue.empty()) {
    DistanceWeight dw = queue.top();
    queue.pop();
    int nodeIndex = dw.n;
    if (nodeDistances[nodeIndex] >= 0) continue;
    int64_t distance = dw.d;
    nodeDistances[nodeIndex] = distance;
    Edge &incoming = edges[dw.e];
    incoming.visited = true;
    std::vector<int> &node = nodes[nodeIndex];
    for (size_t i = 0; i < node.size(); ++i) {
      int edgeIndex = node[i];
      Edge &edge = edges[edgeIndex];
      if (edge.visited) continue;
      int nextIndex = edge.other(nodeIndex);
      if (nodeDistances[nextIndex] >= 0) continue;
      queue.push(DistanceWeight(nextIndex, edgeIndex, distance + edge.weight,
                                edge.weight));
    }
  }
  int64_t totalWeight = 0;
  for (size_t i = 0; i < edges.size(); ++i) {
    Edge &edge = edges[i];
    if (edge.visited) totalWeight += edge.weight;
  }
  std::cout << totalWeight << std::endl;
  int edgeCount = 0;
  for (size_t i = 0; i < edges.size(); ++i) {
    Edge &edge = edges[i];
    if (edge.visited) {
      if (edgeCount) std::cout << ' ';
      std::cout << (i + 1);
      ++edgeCount;
    }
  }
  std::cout << std::endl;
  return 0;
}
