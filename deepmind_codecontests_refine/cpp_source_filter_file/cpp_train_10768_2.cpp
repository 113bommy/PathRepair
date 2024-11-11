#include <bits/stdc++.h>
using namespace std;
namespace flow {
class FlowNetwork {
  struct Edge {
    int v;
    int cap;
    int flow;
    Edge* back;
    Edge(int _v, int _cap) : v(_v), cap(_cap), flow(0) {}
  };

 public:
  int N;
  vector<list<Edge>> adj;
  int S, T;
  vector<long long> extra;
  queue<int> unprocessed;
  vector<int> height;
  int raises;

 private:
  void _push(Edge& e, int f) {
    if (e.v != S && e.v != T && extra[e.v] == 0 && f > 0) {
      unprocessed.push(e.v);
    }
    e.flow += f;
    e.back->flow -= f;
    extra[e.v] += f;
    extra[e.back->v] -= f;
  }
  void _raise(int u) {
    height[u] = 2 * N;
    for (Edge& e : adj[u]) {
      if (e.flow < e.cap) height[u] = min(height[u], height[e.v] + 1);
    }
    ++raises;
  }
  void _bfs(int s, vector<bool>& visited) {
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (Edge& e : adj[u]) {
        if (!visited[e.v] && e.back->flow < e.back->cap) {
          height[e.v] = height[u] + 1;
          visited[e.v] = true;
          Q.push(e.v);
        }
      }
    }
  }
  void _relabel() {
    vector<bool> visited(N);
    visited[S] = visited[T] = true;
    _bfs(T, visited);
    _bfs(S, visited);
  }
  void _process(int u) {
    while (extra[u] > 0) {
      for (Edge& e : adj[u]) {
        if (e.flow == e.cap || height[e.v] != height[u] - 1) continue;
        _push(e, min(extra[u], (long long)(e.cap - e.flow)));
        if (!extra[u]) return;
      }
      if (raises >= N / 2) {
        raises = 0;
        _relabel();
      } else {
        _raise(u);
      }
    }
  }

 public:
  FlowNetwork(int _N) : N(_N) {
    adj = vector<list<Edge>>(N);
    extra = vector<long long>(N);
    height = vector<int>(N);
  }
  void addEdge(int u, int v, int cap) {
    adj[u].push_back(Edge(v, cap));
    adj[v].push_back(Edge(u, 0));
    adj[u].back().back = &adj[v].back();
    adj[v].back().back = &adj[u].back();
  }
  long long computeFlow(int s, int t) {
    S = s;
    T = t;
    for (Edge& e : adj[S]) {
      _push(e, e.cap);
    }
    for (int i = 0; i < (N); ++i) height[i] = 0;
    height[S] = N;
    raises = 0;
    while (!unprocessed.empty()) {
      int v = unprocessed.front();
      unprocessed.pop();
      _process(v);
    }
    return extra[T];
  }
  vector<pair<int, int>> cut() {
    _relabel();
    vector<pair<int, int>> result;
    for (int i = 0; i < (N); ++i)
      for (Edge& e : adj[i]) {
        if (height[i] >= N && height[e.v] < N && e.cap > 0)
          result.push_back(pair<int, int>(i, e.v));
      }
    return result;
  }
};
}  // namespace flow
int A[100], B[100], C[100], L[100], R[100];
int N;
const int INF = 2000000000;
const int BIG = 100000000;
int main() {
  int M;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < (N); ++i) scanf("%d%d%d", &A[i], &B[i], &C[i]);
  for (int i = 0; i < (N); ++i) scanf("%d%d", &L[i], &R[i]);
  int S = 0, T = 1;
  flow::FlowNetwork net(205 * N);
  for (int i = 0; i < (N); ++i) {
    for (int j = -101; j <= 101; ++j) {
      int v = 205 * i + 103 + j;
      if (j == -101) net.addEdge(S, v, INF);
      if (j < 101) {
        int value = (j >= L[i] && j <= R[i])
                        ? BIG - (A[i] * j * j + B[i] * j + C[i])
                        : INF;
        net.addEdge(v, v + 1, value);
      } else
        net.addEdge(v, T, INF);
    }
  }
  for (int i = 0; i < (M); ++i) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    --u, --v;
    d = -d;
    for (int j = -101; j <= 101; ++j) {
      if (j + d > 100 || j + d < -100) continue;
      net.addEdge(205 * u + 103 + j, 205 * v + 103 + j + d, INF);
    }
  }
  printf("%d\n", (int)(N * (long long)BIG - net.computeFlow(S, T)));
}
