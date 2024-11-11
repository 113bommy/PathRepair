#include <bits/stdc++.h>
using namespace std;
template <class C>
constexpr int sz(const C &c) {
  return int(c.size());
}
using ll = long long;
constexpr const char nl = '\n', sp = ' ';
template <class T>
struct StaticWeightedGraph {
  vector<int> ST, TO, A, B;
  vector<T> C, WEIGHT;
  StaticWeightedGraph(int V) : ST(V + 1, 0) {}
  void reserveDiEdges(int maxEdges) {
    TO.reserve(maxEdges);
    A.reserve(maxEdges);
    B.reserve(maxEdges);
  }
  void addDiEdge(int from, int to, T weight) {
    ST[from]++;
    A.push_back(from);
    B.push_back(to);
    C.push_back(weight);
  }
  void addBiEdge(int v, int w, T weight) {
    addDiEdge(v, w, weight);
    addDiEdge(w, v, weight);
  }
  void build() {
    partial_sum(ST.begin(), ST.end(), ST.begin());
    TO = B;
    WEIGHT = C;
    for (int e = 0; e < int(A.size()); e++) {
      TO[--ST[A[e]]] = B[e];
      WEIGHT[ST[A[e]]] = C[e];
    }
  }
  struct Iterator {
    const StaticWeightedGraph &G;
    int i;
    Iterator(const StaticWeightedGraph &G, int i) : G(G), i(i) {}
    Iterator &operator++() {
      i++;
      return *this;
    }
    pair<int, T> operator*() const { return make_pair(G.TO[i], G.WEIGHT[i]); }
    bool operator!=(const Iterator &it) const { return i != it.i; }
  };
  struct Adj {
    const StaticWeightedGraph &G;
    int v;
    Adj(const StaticWeightedGraph &G, int v) : G(G), v(v) {}
    const Iterator begin() const { return Iterator(G, G.ST[v]); }
    const Iterator end() const { return Iterator(G, G.ST[v + 1]); }
  };
  const Adj operator[](int v) const { return Adj(*this, v); }
  int size() const { return int(ST.size()) - 1; }
};
template <class T>
struct DijkstraSSSP {
  using Edge = tuple<int, int, T>;
  vector<T> dist;
  vector<int> par;
  T INF;
  template <class WeightedGraph>
  DijkstraSSSP(const WeightedGraph &G, const vector<int> &srcs,
               T INF = numeric_limits<T>::max())
      : dist(G.size(), INF), par(G.size(), -1), INF(INF) {
    std::priority_queue<pair<T, int>, vector<pair<T, int>>,
                        greater<pair<T, int>>>
        PQ;
    for (int s : srcs) PQ.emplace(dist[s] = T(), s);
    while (!PQ.empty()) {
      T d = PQ.top().first;
      int v = PQ.top().second;
      PQ.pop();
      if (d > dist[v]) continue;
      for (auto &&e : G[v])
        if (dist[e.first] > dist[v] + e.second)
          PQ.emplace(dist[e.first] = dist[par[e.first] = v] + e.second,
                     e.first);
    }
  }
  template <class WeightedGraph>
  DijkstraSSSP(const WeightedGraph &G, int s, T INF = numeric_limits<T>::max())
      : DijkstraSSSP(G, vector<int>{s}, INF) {}
  vector<Edge> getPath(int v) {
    vector<Edge> path;
    for (; par[v] != -1; v = par[v])
      path.emplace_back(par[v], v, dist[v] - dist[par[v]]);
    reverse(path.begin(), path.end());
    return path;
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  int SX, SY, FX, FY;
  cin >> SX >> SY >> FX >> FY;
  vector<tuple<int, int, int>> A;
  A.emplace_back(SX, SY, 0);
  for (int i = 1; i <= M; i++) {
    int x, y;
    cin >> x >> y;
    A.emplace_back(x, y, i);
  }
  StaticWeightedGraph<ll> G(M + 1);
  for (int h = 0; h < 2; h++) {
    sort(A.begin(), A.end(),
         [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
           return h == 0 ? (get<0>(a) < get<0>(b)) : (get<1>(a) < get<1>(b));
         });
    for (int i = 0; i < M; i++) {
      ll weight = h == 0 ? (get<0>(A[i + 1]) - get<0>(A[i]))
                         : (get<1>(A[i + 1]) - get<1>(A[i]));
      G.addBiEdge(get<2>(A[i]), get<2>(A[i + 1]), weight);
    }
  }
  sort(A.begin(), A.end(),
       [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
         return get<2>(a) < get<2>(b);
       });
  G.build();
  DijkstraSSSP<ll> sssp(G, 0);
  ll ans = sssp.INF;
  for (int i = 0; i <= M; i++)
    ans = min(ans,
              sssp.dist[i] + abs(FX - get<0>(A[i])) + abs(FY - get<1>(A[i])));
  cout << ans << nl;
  return 0;
}
