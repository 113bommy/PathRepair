#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int NIL = -1;
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};
class Edge {
 public:
  int u, v, cost, capacity, flow;
  Edge() {}
  Edge(const int u, const int v, const int cost, const int capacity) {
    this->u = u;
    this->v = v;
    this->cost = cost;
    this->capacity = capacity;
    this->flow = 0;
  }
};
vector<vector<int>> G;
vector<Edge> Edges;
int V, E, Source, Sink;
vector<int> Father, Distance;
queue<int> Q;
vector<bool> InQ;
int Solution;
inline int NonEdge(const int e) {
  if (e < E) return e + E;
  return e - E;
}
void InitializeBellmanFord(const int start) {
  Father = vector<int>(V, NIL);
  Distance = vector<int>(V, oo);
  InQ = vector<bool>(V, false);
  Distance[start] = 0;
  Q.push(start);
  InQ[start] = true;
}
bool BellmanFord(const int start, const int end) {
  for (InitializeBellmanFord(start); !Q.empty(); Q.pop()) {
    int x = Q.front();
    InQ[x] = false;
    if (x == end) continue;
    for (auto &e : G[x]) {
      int y = Edges[e].v;
      if (Edges[e].flow < Edges[e].capacity &&
          Distance[x] + Edges[e].cost < Distance[y]) {
        Father[y] = e;
        Distance[y] = Distance[x] + Edges[e].cost;
        if (!InQ[y]) {
          Q.push(y);
          InQ[y] = true;
        }
      }
    }
  }
  return (Father[end] != NIL);
}
void InitializeNetwork(const int source, const int sink) {
  Source = source;
  Sink = sink;
  for (int i = 0; i < E; ++i) {
    Edges.push_back(Edge(Edges[i].v, Edges[i].u, -Edges[i].cost, 0));
    G[Edges[i].v].push_back(NonEdge(i));
  }
}
void MinCostMaxFlow(int &maxFlow, int &flowCost) {
  maxFlow = flowCost = 0;
  while (BellmanFord(Source, Sink)) {
    int flow = oo;
    for (int x = Sink; x != Source; x = Edges[Father[x]].u)
      flow = min(flow, Edges[Father[x]].capacity - Edges[Father[x]].flow);
    for (int x = Sink; x != Source; x = Edges[Father[x]].u) {
      Edges[Father[x]].flow += flow;
      Edges[NonEdge(Father[x])].flow -= flow;
    }
    maxFlow += flow;
    flowCost += flow * Distance[Sink];
  }
}
void Solve() {
  int maxFlow, flowCost;
  MinCostMaxFlow(maxFlow, flowCost);
  Solution = flowCost;
}
inline void AddEdge(const int u, const int v, const int cost,
                    const int capacity) {
  Edges.push_back(Edge(u, v, cost, capacity));
  G[u].push_back(E++);
}
void Read() {
  vector<vector<int>> board;
  int n, m;
  cin >> n >> m;
  board = vector<vector<int>>(n, vector<int>(m, 0));
  V = n * m + 2;
  G = vector<vector<int>>(V, vector<int>());
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      cin >> board[x][y];
      if ((x + y) & 1)
        AddEdge(m * x + y, n * m + 1, 0, 1);
      else
        AddEdge(n * m, m * x + y, 0, 1);
    }
  }
  for (int x = 0; x < n; ++x) {
    for (int y = x & 1; y < m; y += 2) {
      for (int d = 0; d < 4; ++d) {
        int nx = x + DX[d], ny = y + DY[d];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
          AddEdge(m * x + y, m * nx + ny,
                  static_cast<int>(board[x][y] != board[nx][ny]), 1);
      }
    }
  }
  InitializeNetwork(n * m, n * m + 1);
}
void Print() { cout << Solution << "\n"; }
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
