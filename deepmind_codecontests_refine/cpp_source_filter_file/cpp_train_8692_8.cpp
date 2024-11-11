#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline istream& operator>>(istream& fin, pair<T1, T2>& pr) {
  fin >> pr.first >> pr.second;
  return fin;
}
template <class T0, class T1, class T2>
inline istream& operator>>(istream& fin, tuple<T0, T1, T2>& t) {
  fin >> get<0>(t) >> get<1>(t) >> get<2>(t);
  return fin;
}
template <class T>
inline istream& operator>>(istream& fin, vector<T>& a) {
  for (auto& u : a) fin >> u;
  return fin;
}
template <class T, size_t n>
inline istream& operator>>(istream& fin, array<T, n>& a) {
  for (auto& u : a) fin >> u;
  return fin;
}
template <class FwdIter>
inline auto dump(FwdIter first, FwdIter last, const char* dlm) -> void {
  copy(first, last,
       ostream_iterator<typename iterator_traits<FwdIter>::value_type>(cout,
                                                                       dlm));
}
typedef struct {
  size_t head, tail;
  int64_t len;
  bool tag;
  bool cut;
} edge_t;
inline vector<int64_t> dijkstra(const size_t root,
                                const vector<vector<size_t>>& adj,
                                const vector<edge_t>& edge) {
  const auto n = adj.size();
  const auto inf = numeric_limits<int64_t>::max() >> 3;
  vector<int64_t> dist(n, inf);
  dist[root] = 0;
  priority_queue<pair<int64_t, size_t>, vector<pair<int64_t, size_t>>,
                 greater<pair<int64_t, size_t>>>
      heap;
  for (heap.emplace(0, root); !heap.empty();) {
    const auto pr = heap.top();
    heap.pop();
    const auto node = pr.second;
    const auto inc = dist[node];
    if (inc != pr.first) continue;
    for (const auto i : adj[node])
      if (edge[i].head == node) {
        const auto& e = edge[i];
        if (e.len + inc < dist[e.tail])
          heap.emplace((dist[e.tail] = e.len + inc), e.tail);
      }
  }
  return dist;
}
size_t dfs(size_t& tic, const size_t gate, const size_t node,
           vector<size_t>& hit, const vector<vector<size_t>>& adj,
           vector<edge_t>& edge) {
  auto out = hit[node] = tic++;
  for (const auto i : adj[node])
    if (i != gate && edge[i].tag) {
      auto& e = edge[i];
      const auto other = e.head + e.tail - node;
      if (hit[other] != (size_t)-1)
        out = min(out, hit[other]);
      else {
        const auto val = dfs(tic, i, other, hit, adj, edge);
        if (hit[node] < val)
          e.cut = true;
        else
          out = min(out, val);
      }
    }
  return out;
}
void e567() {
  size_t n, m;
  array<size_t, 2> root;
  cin >> n >> m >> root;
  --root[0];
  --root[1];
  vector<vector<size_t>> adj(n);
  vector<edge_t> edge;
  edge.reserve(m);
  for (size_t u, v, i = 0; i < m; ++i) {
    int len;
    cin >> u >> v >> len;
    edge.push_back({--u, --v, len, false, false});
    adj[u].push_back(i);
    adj[v].push_back(i);
  }
  const auto dist = dijkstra(root[0], adj, edge);
  const auto min_dist = dist[root[1]];
  for (auto& e : edge) swap(e.head, e.tail);
  const auto xdist = dijkstra(root[1], adj, edge);
  for (auto& e : edge) swap(e.head, e.tail);
  for (auto& e : edge) e.tag = min_dist == dist[e.head] + e.len + xdist[e.tail];
  size_t tic = 0;
  vector<size_t> hit(n, (size_t)-1);
  dfs(tic, -1, root[0], hit, adj, edge);
  const auto inf = numeric_limits<int64_t>::max() >> 3;
  for (const auto& e : edge)
    if (e.cut)
      cout << "YES" << '\n';
    else if (dist[e.head] == inf || xdist[e.tail] == inf)
      cout << "NO" << '\n';
    else {
      const auto val = dist[e.head] + e.len + xdist[e.tail];
      if (val - min_dist + 1 < e.len)
        cout << "CAN " << val - min_dist + 1 << '\n';
      else
        cout << "NO";
    }
}
int main(const int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  e567();
  return EXIT_SUCCESS;
}
