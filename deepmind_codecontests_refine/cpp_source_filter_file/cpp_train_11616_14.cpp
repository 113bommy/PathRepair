#include <bits/stdc++.h>
using namespace std;
struct Timer {
  chrono::time_point<chrono::high_resolution_clock> start, end;
  chrono::duration<float> dur;
  Timer() { start = chrono::high_resolution_clock::now(); }
  ~Timer() {
    end = chrono::high_resolution_clock::now();
    dur = end - start;
    cout << "\nTime Elapsed : " << dur.count() << " s\n";
  }
};
long long int sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) {
  return a + sum(args...);
}
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};
struct Graph {
  int n;
  vector<vector<int>> adj;
  vector<long long int> a, dp;
  long long int ans;
  Graph(int n) {
    this->n = n;
    adj.resize(n + 1);
    a.resize(n + 1);
    dp.resize(n + 1);
    ans = -9e18;
  }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  void dfs1(int u, int p) {
    dp[u] = a[u];
    for (auto v : adj[u]) {
      if (v != p) {
        dfs1(v, u);
        dp[u] += dp[v];
      }
    }
  }
  void dfs2(int u, int p) {
    vector<long long int> tmp;
    for (auto v : adj[u]) {
      if (v != p) {
        dfs2(v, u);
        tmp.push_back(dp[v]);
      }
    }
    sort(tmp.rbegin(), tmp.rend());
    if (!tmp.empty()) {
      dp[u] = max(dp[u], tmp[0]);
      if (tmp.size() >= 2) ans = max(ans, tmp[0] + tmp[1]);
    }
  }
  void solve() {
    dfs1(1, -1);
    dfs2(1, -1);
    if (ans == -1)
      cout << "Impossible\n";
    else
      cout << ans << "\n";
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testCases = 1;
  while (testCases--) {
    int n;
    cin >> n;
    Graph g(n);
    for (int i = 1; i <= n; i++) cin >> g.a[i];
    for (int i = 1; i <= n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g.add_edge(u, v);
    }
    g.solve();
  }
}
