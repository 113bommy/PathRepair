#include <bits/stdc++.h>
using namespace std;
class FenwickTree {
 public:
  FenwickTree(int _n = 10) : n(_n), data(_n, 0) {}
  void reset(int _n) {
    n = _n;
    data.resize(n);
    data.assign(n, 0);
  }
  void put(int x, int v) {
    for (; x < n; x |= x + 1) {
      data[x] += v;
    }
  }
  int get(int x) {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
      res += data[x];
    }
    return res;
  }

 private:
  int n;
  vector<int> data;
};
class Solution {
 public:
  void init(int n, vector<pair<int, int>>& edges) {
    N = n;
    graph.clear();
    graph.resize(N);
    pars.clear();
    h = 0;
    while (1 << h < N) {
      ++h;
    }
    pars.resize(N, vector<int>(h + 1, -1));
    depth.clear();
    depth.resize(N, 0);
    in.clear();
    in.resize(N, 0);
    out.clear();
    out.resize(N, 0);
    used.clear();
    used.resize(N, false);
    for (auto& p : edges) {
      int u = p.first;
      int v = p.second;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    int clock = 0;
    dfs(0, -1, 0, clock);
    ft.reset(N * 2 + 1000);
  }
  int count(vector<int>& nodes, int m, int r) {
    for (auto& v : nodes) {
      ft.put(in[v], 1);
      ft.put(out[v], -1);
      used[v] = true;
    }
    vector<pair<int, int>> Q;
    for (auto v : nodes) {
      int dis = distanceBetween(v, r);
      --dis;
      Q.emplace_back(dis, v);
    }
    sort(Q.begin(), Q.end());
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    int vn = 0;
    for (auto& p : Q) {
      int v = p.second;
      int h = p.first;
      assert(vn >= h);
      for (int i = m; i > 0; --i) {
        dp[i] = addM(dp[i - 1], mulM(dp[i], max(0, i - h)));
      }
      dp[0] = 0;
      ++vn;
    }
    for (auto& v : nodes) {
      ft.put(in[v], -1);
      ft.put(out[v], 1);
      used[v] = false;
    }
    long long res = 0;
    for (int i = 1; i <= m; ++i) {
      res = addM(res, dp[i]);
    }
    return res;
  }

 private:
  int N;
  int h;
  vector<vector<int>> graph;
  vector<vector<int>> pars;
  vector<int> depth;
  vector<int> in;
  vector<int> out;
  vector<bool> used;
  FenwickTree ft;
  void dfs(int u, int p, int d, int& clock) {
    in[u] = clock++;
    depth[u] = d;
    pars[u][0] = p;
    for (int i = 1; i <= h; ++i) {
      if (pars[u][i - 1] == -1) {
        continue;
      }
      pars[u][i] = pars[pars[u][i - 1]][i - 1];
    }
    for (auto v : graph[u]) {
      if (v == p) {
        continue;
      }
      dfs(v, u, d + 1, clock);
    }
    out[u] = clock++;
  }
  bool isAncestor(int u, int p) { return in[p] < in[u] && out[u] < out[p]; }
  int lca(int u, int v) {
    if (u == v) {
      return u;
    }
    if (u == -1 || v == -1) {
      return u == -1 ? v : u;
    }
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    if (isAncestor(v, u)) {
      return u;
    }
    for (int i = h; i >= 0; --i) {
      int p = pars[v][i];
      if (p == -1) {
        continue;
      }
      if (depth[p] >= depth[u]) {
        v = p;
      }
    }
    for (int i = h; i >= 0; --i) {
      if (pars[u][i] != pars[v][i]) {
        u = pars[u][i];
        v = pars[v][i];
      }
    }
    return pars[u][0];
  }
  int distance(int u) { return ft.get(in[u]); }
  int distanceBetween(int u, int v) {
    int p = lca(u, v);
    int res = distance(u) + distance(v) - 2 * distance(p) + (used[p] ? 1 : 0);
    return res;
  }
  const static int M = 1e9 + 7;
  long long normalize(long long a) {
    a %= M;
    if (a < 0) {
      a += M;
    }
    return a;
  }
  long long addM(long long a, long long b) {
    a += b;
    while (a >= M) {
      a -= M;
    }
    while (a < 0) {
      a += M;
    }
    return a;
  }
  long long mulM(long long a, long long b) { return normalize(a * b); }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> edges;
  edges.reserve(n);
  for (int i = 0, u = 0, v = 0; i < n - 1; ++i) {
    cin >> u >> v;
    edges.emplace_back(u - 1, v - 1);
  }
  sol.init(n, edges);
  while (q-- > 0) {
    int k, m, r;
    cin >> k >> m >> r;
    --r;
    vector<int> nodes(k);
    for (int i = 0; i < k; ++i) {
      cin >> nodes[i];
      --nodes[i];
    }
    cout << sol.count(nodes, m, r) << "\n";
  }
  return 0;
}
