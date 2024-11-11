#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("03")
const int N = 2e5 + 5;
const long long INF = 1e18;
int n, u, v, check[N], child[N];
long long a[N], ans, dist[N], sum[N], prefSum[N], sufSum[N];
vector<int> adj[N];
struct line {
  long long a, b;
  mutable long long p;
  bool type;
  bool operator<(const line& tmp) const {
    if (tmp.type == 0) {
      return a < tmp.a || (a == tmp.a && b < tmp.b);
    } else {
      return p < tmp.p;
    }
  }
};
struct Convexhull : multiset<line> {
  long long div(long long x, long long y) {
    return x / y - ((x ^ y) < 0 && x % y);
  }
  bool inters(iterator x, iterator y) {
    if (y == end()) {
      x->p = INF;
      return 0;
    }
    if (x->a == y->a) {
      x->p = (x->b > y->b ? INF : -INF);
    } else {
      x->p = div(y->b - x->b, x->a - y->a);
    }
    return x->p >= y->p;
  }
  void add(long long s, long long c) {
    auto it = insert({s, c, 0, 0});
    auto it0 = it, it1 = it;
    it1++;
    while (inters(it, it1)) {
      it1 = erase(it1);
    }
    if (it0 != begin() && inters(--it0, it)) {
      inters(it0, it = erase(it));
    }
    while ((it = it0) != begin() && (--it0)->p >= it->p) {
      inters(it0, erase(it));
    }
  }
  long long get(long long x) {
    if (empty()) return -INF;
    auto tmp = *lower_bound({0, 0, x, 1});
    return tmp.a * x + tmp.b;
  }
} convex;
void build(int u, int p) {
  child[u] = 1;
  for (int v : adj[u]) {
    if (v != p && check[v] == 0) {
      build(v, u);
      child[u] += child[v];
    }
  }
}
int findCen(int u, int p, int sz) {
  for (int v : adj[u]) {
    if (v != p && check[v] == 0 && child[v] * 2 > sz) {
      return findCen(v, u, sz);
    }
  }
  return u;
}
void dfs1(int u, int p) {
  dist[u] = dist[p] + 1;
  sum[u] = sum[p] + a[u];
  sufSum[u] = sufSum[p] + (dist[u] + 1) * a[u];
  ans = max(ans, sufSum[u]);
  ans = max(ans, sufSum[u] + convex.get(sum[u]));
  for (int v : adj[u]) {
    if (v != p && check[v] == 0) {
      dfs1(v, u);
    }
  }
}
void dfs2(int u, int p) {
  if (u != p) {
    sum[u] = sum[p] + a[u];
    prefSum[u] = prefSum[p] + sum[u];
  }
  ans = max(ans, prefSum[u] + a[u] * (dist[u] + 1));
  convex.add(dist[u], prefSum[u]);
  for (int v : adj[u]) {
    if (v != p && check[v] == 0) {
      dfs2(v, u);
    }
  }
}
void solve(int u) {
  convex.clear();
  sum[u] = prefSum[u] = sufSum[u] = a[u];
  dist[u] = 0;
  for (int v : adj[u]) {
    if (check[v] == 0) {
      dfs1(v, u);
      sum[v] = prefSum[v] = a[v];
      dfs2(v, v);
    }
  }
}
void centroid(int root) {
  build(root, root);
  int u = findCen(root, root, child[root]);
  check[u] = 1;
  ans = max(ans, a[u]);
  solve(u);
  reverse(adj[u].begin(), adj[u].end());
  solve(u);
  for (int v : adj[u]) {
    if (check[v] == 0) {
      centroid(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  centroid(1);
  cout << ans;
}
