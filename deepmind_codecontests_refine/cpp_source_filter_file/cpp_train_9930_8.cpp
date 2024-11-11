#include <bits/stdc++.h>
using namespace std;
enum class Topology { STAR, BUS, RING, UNKOWN };
class Node;
class Node {
 public:
  explicit Node(int name) : name(name) {}
  int name;
  vector<shared_ptr<Node> > edges;
};
bool testRing(const vector<shared_ptr<Node> > &graph) {
  const int n = graph.size() - 1;
  vector<bool> visited(n + 1, false);
  visited[0] = true;
  shared_ptr<Node> first, node;
  first = node = graph[1];
  while (true) {
    visited[node->name] = true;
    if (node->edges.size() != 2) return false;
    if (all_of(node->edges.begin(), node->edges.end(),
               [&](shared_ptr<Node> n) { return visited[n->name]; }))
      break;
    if (visited[node->edges[0]->name])
      node = node->edges[1];
    else
      node = node->edges[0];
    if (node == first) break;
  }
  return all_of(visited.begin(), visited.end(), [](bool b) { return b; });
}
bool testBus(const vector<shared_ptr<Node> > &graph) {
  const int n = graph.size() - 1;
  vector<int> visited(n + 1, false);
  visited[0] = true;
  shared_ptr<Node> first, last;
  auto lambda = [](shared_ptr<Node> n) { return n->edges.size() == 1; };
  auto pos = find_if(graph.begin() + 1, graph.end(), lambda);
  if (pos == graph.end()) return false;
  first = *pos;
  pos = find_if(pos + 1, graph.end(), lambda);
  if (pos == graph.end()) return false;
  last = *pos;
  shared_ptr<Node> node = first;
  while (true) {
    visited[node->name] = true;
    if (node == last) break;
    if (node->edges.size() != 1 && node->edges.size() != 2) return false;
    if (all_of(node->edges.begin(), node->edges.end(),
               [&](shared_ptr<Node> n) { return visited[n->name]; }))
      break;
    if (visited[node->edges[0]->name])
      node = node->edges[1];
    else
      node = node->edges[0];
  }
  return all_of(visited.begin(), visited.end(), [](bool b) { return b; });
}
bool testStar(vector<shared_ptr<Node> > &graph) {
  const int n = graph.size() - 1;
  vector<bool> visited(n + 1, false);
  visited[0] = true;
  auto pos =
      find_if(graph.begin() + 1, graph.end(), [&](shared_ptr<Node> node) {
        return node->edges.size() == (unsigned int)(n - 1);
      });
  if (pos == graph.end()) return false;
  shared_ptr<Node> star = *pos;
  visited[star->name] = true;
  for (shared_ptr<Node> node : star->edges) {
    if (node->edges.size() != 1) return false;
    visited[node->name] = true;
  }
  return all_of(visited.begin(), visited.end(), [](bool b) { return b; });
}
Topology solve(vector<shared_ptr<Node> > &graph) {
  if (testRing(graph)) return Topology::RING;
  if (testBus(graph)) return Topology::BUS;
  if (testStar(graph)) return Topology::STAR;
  return Topology::UNKOWN;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<shared_ptr<Node> > graph(n + 1);
  for (int i = 1; i <= n; ++i) graph[i] = make_shared<Node>(i);
  for (int i = 1; i <= m; ++i) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1]->edges.push_back(graph[v2]);
    graph[v2]->edges.push_back(graph[v1]);
  }
  switch (solve(graph)) {
    case Topology::BUS:
      cout << "bus topology" << endl;
      break;
    case Topology::STAR:
      cout << "star topology" << endl;
      break;
    case Topology::RING:
      cout << "ring topology" << endl;
      break;
    case Topology::UNKOWN:
      cout << "unkown topology" << endl;
      break;
  }
}
