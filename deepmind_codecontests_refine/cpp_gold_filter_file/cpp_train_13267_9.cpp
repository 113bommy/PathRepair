#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct counting_iterator : public iterator<random_access_iterator_tag, bool> {
  T value = 0;
  counting_iterator(const T &value) : value(value) {}
  counting_iterator(const counting_iterator &it) : value(it.value) {}
  counting_iterator() {}
  typename iterator_traits<counting_iterator>::difference_type operator-(
      const counting_iterator &it) const {
    return value - it.value;
  }
  counting_iterator &operator++() { return *this += 1; }
  counting_iterator &operator--() { return *this += -1; }
  counting_iterator &operator+=(
      typename iterator_traits<counting_iterator>::difference_type n) {
    value += n;
    return *this;
  }
  bool operator!=(const counting_iterator &it) const {
    return value != it.value;
  }
  T &operator*() { return value; }
};
template <typename T>
using cnt_it = counting_iterator<T>;
template <class T>
struct graph {
  struct edge {
    int from, to;
    T cost;
  };
  int n;
  vector<edge> edges;
  vector<vector<int>> adj;
  function<bool(int)> ignore;
  graph(int n) : n(n), adj(n) {}
  int link(int u, int v, T w = 1) {
    int id = (int)edges.size();
    adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
    return id;
  }
  int orient(int u, int v, T w = 1) {
    int id = (int)edges.size();
    adj[u].push_back(id), edges.push_back({u, v, w});
    return id;
  }
  graph transposed() const {
    graph res(n);
    for (auto &e : edges) res.orient(e.to, e.from, e.cost);
    res.ignore = ignore;
    return res;
  }
  int degree(int u) { return (int)adj[u].size(); }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int n;
  cin >> n;
  graph<int> g(n);
  vector<int> lim(n);
  for (auto i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w, --u, --v;
    g.link(u, v, w);
  }
  for (auto u = 0; u < n; ++u) {
    cin >> lim[u];
  }
  int tot = accumulate(lim.begin(), lim.end(), 0);
  auto good = [&](int th) {
    42;
    vector<int> vis(n);
    int lsum, cnt;
    function<void(int)> dfs = [&](int u) {
      vis[u] = true;
      lsum += lim[u];
      ++cnt;
      for (auto id : g.adj[u]) {
        auto &e = g.edges[id];
        if (e.cost < th) {
          int v = u ^ e.from ^ e.to;
          if (!vis[v]) {
            dfs(v);
          }
        }
      }
    };
    for (auto u = 0; u < n; ++u) {
      if (!vis[u]) {
        lsum = 0, cnt = 0;
        dfs(u);
        42;
        if (cnt > tot - lsum) {
          return false;
        }
      }
    }
    return true;
  };
  cout << max(*partition_point(cnt_it<int>(0), cnt_it<int>(20000), good) - 1, 0)
       << "\n";
  return 0;
}
