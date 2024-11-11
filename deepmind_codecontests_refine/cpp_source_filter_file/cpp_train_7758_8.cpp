#include <bits/stdc++.h>
class Edge {
 protected:
  int id, startVertex, finishVertex;

 public:
  Edge() : id(-1), startVertex(-1), finishVertex(-1) {}
  Edge(int _id, int _startVertex, int _finishVertex)
      : id(_id), startVertex(_startVertex), finishVertex(_finishVertex) {}
  int getID() const;
  int getStartVertex() const;
  int getFinishVertex() const;
};
int Edge::getID() const { return id; }
int Edge::getStartVertex() const { return startVertex; }
int Edge::getFinishVertex() const { return finishVertex; }
template <typename CapacityType>
class FlowEdge;
template <typename CapacityType>
std::istream &operator>>(std::istream &in, FlowEdge<CapacityType> &flowEdge);
template <typename CapacityType>
class FlowEdge : public Edge {
 protected:
  CapacityType capacity, flow;
  FlowEdge *reversedEdge;

 public:
  FlowEdge()
      : Edge(),
        capacity(CapacityType()),
        flow(CapacityType()),
        reversedEdge(NULL) {}
  FlowEdge(int _id, int _startVertex = 0, int _finishVertex = 0,
           CapacityType _capacity = CapacityType(),
           CapacityType _flow = CapacityType())
      : Edge(_id, _startVertex, _finishVertex),
        capacity(_capacity),
        flow(_flow),
        reversedEdge(NULL) {}
  FlowEdge(FlowEdge *_reversedEdge)
      : Edge(-1, _reversedEdge->getFinishVertex(),
             _reversedEdge->getStartVertex()),
        capacity(CapacityType()),
        flow(CapacityType()),
        reversedEdge(_reversedEdge) {}
  FlowEdge<CapacityType> *getReversedEdge() const;
  CapacityType getCapacity() const;
  CapacityType getFlow() const;
  void setReversedEdge(FlowEdge<CapacityType> *_reversedEdge);
  void incFlow(CapacityType d);
  friend std::istream &operator>>
      <>(std::istream &in, FlowEdge<CapacityType> &flowEdge);
};
template <typename CapacityType>
std::istream &operator>>(std::istream &in, FlowEdge<CapacityType> &flowEdge) {
  int from, to, capacity;
  in >> from >> to >> capacity;
  from--;
  to--;
  flowEdge.startVertex = from;
  flowEdge.finishVertex = to;
  flowEdge.capacity = capacity;
  return in;
}
template <typename CapacityType>
CapacityType FlowEdge<CapacityType>::getCapacity() const {
  return capacity;
}
template <typename CapacityType>
CapacityType FlowEdge<CapacityType>::getFlow() const {
  return flow;
}
template <typename CapacityType>
FlowEdge<CapacityType> *FlowEdge<CapacityType>::getReversedEdge() const {
  return reversedEdge;
}
template <typename CapacityType>
void FlowEdge<CapacityType>::setReversedEdge(
    FlowEdge<CapacityType> *_reversedEdge) {
  reversedEdge = _reversedEdge;
}
template <typename CapacityType>
void FlowEdge<CapacityType>::incFlow(CapacityType d) {
  flow += d;
  reversedEdge->flow -= d;
}
class Graph {
 protected:
  std::vector<std::vector<Edge *>> e;

 public:
  Graph() {}
  int getV() const;
};
namespace BFSGraph {
template <class Graph, class IsValidEdgeFunction>
void bfs(Graph const &graph, int start, std::vector<int> &distanceToVertex,
         IsValidEdgeFunction const &isValidEdge);
};
template <class Graph, class IsValidEdgeFunction>
void BFSGraph::bfs(Graph const &graph, int start,
                   std::vector<int> &distanceToVertex,
                   IsValidEdgeFunction const &isValidEdge) {
  distanceToVertex.resize(graph.getV());
  for (int i = 0; i < (int)distanceToVertex.size(); ++i) {
    distanceToVertex[i] = -1;
  }
  std::queue<int> vertexQueue;
  vertexQueue.push(start);
  distanceToVertex[start] = 0;
  while (!vertexQueue.empty()) {
    int v = vertexQueue.front();
    vertexQueue.pop();
    for (int i = 0; i < (int)graph.e[v].size(); ++i) {
      int to = graph.e[v][i]->getFinishVertex();
      if (distanceToVertex[to] == -1 && isValidEdge(graph.e[v][i])) {
        distanceToVertex[to] = distanceToVertex[v] + 1;
        vertexQueue.push(to);
      }
    }
  }
}
template <typename CapacityType>
class Net;
template <typename CapacityType>
std::istream &operator>>(std::istream &in, Net<CapacityType> &g);
template <typename CapacityType>
std::ostream &operator<<(std::ostream &out, Net<CapacityType> &g);
template <typename CapacityType>
class Net : public Graph {
 public:
  CapacityType flow;
  std::vector<std::vector<FlowEdge<CapacityType> *>> e;
  Net() : Graph(), flow(), e(0) {}
  size_t getV() const;
  friend std::istream &operator>><>(std::istream &in, Net<CapacityType> &g);
  friend std::ostream &operator<<<>(std::ostream &out, Net<CapacityType> &g);
  template <class Graph, class IsValidEdgeFunction>
  friend void BFSGraph::bfs(Graph const &graph, int start,
                            std::vector<int> &distanceToVertex,
                            IsValidEdgeFunction const &isValidEdge);
  friend class FlowSolver;
  friend class DinicFlowSolver;
  friend class PreflowPushFlowSolver;
};
template <typename CapacityType>
size_t Net<CapacityType>::getV() const {
  return e.size();
}
template <typename CapacityType>
std::istream &operator>>(std::istream &in, Net<CapacityType> &g) {
  int n, m;
  in >> n >> m;
  g.e.resize(n);
  for (int i = 0; i < m; ++i) {
    FlowEdge<CapacityType> *directEdge = new FlowEdge<CapacityType>(i);
    in >> (*directEdge);
    FlowEdge<CapacityType> *reversedEdge =
        new FlowEdge<CapacityType>(directEdge);
    directEdge->setReversedEdge(reversedEdge);
    g.e[directEdge->getStartVertex()].push_back(directEdge);
    g.e[reversedEdge->getStartVertex()].push_back(reversedEdge);
  }
  return in;
}
template <typename CapacityType>
std::ostream &operator<<(std::ostream &out, Net<CapacityType> &g) {
  out << g.flow << "\n";
  int maxNum = 0;
  for (int i = 0; i < (int)g.e.size(); ++i) {
    maxNum += g.e[i].size();
  }
  maxNum /= 2;
  std::vector<CapacityType> ans(maxNum);
  for (int i = 0; i < (int)g.e.size(); ++i) {
    for (int j = 0; j < (int)g.e[i].size(); ++j) {
      if (g.e[i][j]->getID() != -1) {
        ans[g.e[i][j]->getID()] = g.e[i][j]->getFlow();
      }
    }
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    out << ans[i] << "\n";
  }
  return out;
}
class FlowSolver {
 protected:
  Net<long long> &graph;

 public:
  FlowSolver(Net<long long> &_graph) : graph(_graph) {}
  virtual void solve(int source, int sink) = 0;
};
class PreflowPushFlowSolver : public FlowSolver {
 private:
  std::vector<int> height, heightCount;
  std::vector<long long> excess;
  std::queue<int> vertexQueue;
  std::vector<int> indexOfCurrentEdge;
  void relable(int v);
  void push(FlowEdge<long long> *edge);
  void discharge(int v);

 public:
  PreflowPushFlowSolver(Net<long long> &_graph) : FlowSolver(_graph) {}
  virtual void solve(int source, int sink);
};
void PreflowPushFlowSolver::relable(int v) {
  int newHeight = graph.getV() * 2;
  for (int i = 0; i < (int)graph.e[v].size(); ++i) {
    FlowEdge<long long> *edge = graph.e[v][i];
    if (edge->getCapacity() > edge->getFlow()) {
      newHeight = std::min(height[edge->getFinishVertex()] + 1, newHeight);
    }
  }
  heightCount[height[v]]--;
  int gapC = graph.getV();
  if (heightCount[height[v]] == 0) gapC = height[v];
  height[v] = newHeight;
  heightCount[height[v]]++;
  if (gapC < (int)graph.getV()) {
    for (int i = 0; i < (int)height.size(); ++i) {
      if (height[i] > gapC && height[i] < (int)graph.getV()) {
        heightCount[height[i]]--;
        height[i] = graph.getV();
        heightCount[height[i]]++;
      }
    }
  }
}
void PreflowPushFlowSolver::push(FlowEdge<long long> *edge) {
  long long flow = std::min(excess[edge->getStartVertex()],
                            edge->getCapacity() - edge->getFlow());
  edge->incFlow(flow);
  excess[edge->getStartVertex()] -= flow;
  int u = edge->getFinishVertex();
  excess[u] += flow;
  if (excess[u] > 0LL && excess[u] <= flow) {
    vertexQueue.push(u);
  }
}
void PreflowPushFlowSolver::discharge(int v) {
  while (excess[v] > 0) {
    if (indexOfCurrentEdge[v] == (int)graph.e[v].size()) {
      relable(v);
      indexOfCurrentEdge[v] = 0;
    } else {
      FlowEdge<long long> *edge = graph.e[v][indexOfCurrentEdge[v]];
      if (edge->getCapacity() - edge->getFlow() > 0LL &&
          height[edge->getFinishVertex()] == height[v] - 1) {
        push(edge);
      } else {
        indexOfCurrentEdge[v]++;
      }
    }
  }
}
void PreflowPushFlowSolver::solve(int source, int sink) {
  height = std::vector<int>(graph.getV(), 0);
  heightCount = std::vector<int>(graph.getV() * 2, 0);
  heightCount[graph.getV()] = 1;
  heightCount[0] = graph.getV() - 1;
  height[source] = graph.getV();
  excess = std::vector<long long>(graph.getV(), 0LL);
  for (int i = 0; i < (int)graph.e[source].size(); ++i) {
    FlowEdge<long long> *edge = graph.e[source][i];
    edge->incFlow(edge->getCapacity());
    excess[edge->getFinishVertex()] += edge->getCapacity();
    excess[source] -= edge->getCapacity();
  }
  for (int i = 0; i < (int)graph.e[sink].size(); ++i) {
    excess[sink] -= graph.e[sink][i]->getReversedEdge()->getCapacity();
  }
  for (int i = 0; i < (int)graph.getV(); ++i) {
    if (excess[i] > 0) {
      vertexQueue.push(i);
    }
  }
  indexOfCurrentEdge = std::vector<int>(graph.getV(), 0);
  while (!vertexQueue.empty()) {
    int v = vertexQueue.front();
    vertexQueue.pop();
    discharge(v);
  }
  graph.flow = -excess[source];
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<pair<int, int>>> g;
  g.resize(n);
  int a, b, c;
  vector<int> reb(n, 0);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back(make_pair(b, c));
    reb[b]++;
  }
  vector<int> cnt(n);
  vector<bool> used(n);
  long double l = 0;
  long double r = 2e11;
  while (r - l > 1e-10) {
    long double m = (l + r) / 2.0;
    Net<long long> net;
    net.e.resize(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < (int)g[i].size(); ++j) {
        FlowEdge<long long> *directEdge = new FlowEdge<long long>(
            (cnt++), i, g[i][j].first, floor((g[i][j].second * 1.0) / m));
        FlowEdge<long long> *reversedEdge = new FlowEdge<long long>(directEdge);
        directEdge->setReversedEdge(reversedEdge);
        net.e[directEdge->getStartVertex()].push_back(directEdge);
        net.e[reversedEdge->getStartVertex()].push_back(reversedEdge);
      }
    }
    PreflowPushFlowSolver a(net);
    a.solve(0, n - 1);
    if (net.flow >= x) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << fixed << setprecision(8);
  cout << (l * x) << "\n";
  return 0;
}
