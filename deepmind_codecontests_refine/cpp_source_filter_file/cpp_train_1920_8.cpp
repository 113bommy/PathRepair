#include <bits/stdc++.h>
using namespace std;
struct lazysegtree {
  vector<int> lz, st;
  int n;
  lazysegtree(int n) : n(n) {
    lz.assign(4 * n + 5, 0);
    st.assign(4 * n + 5, 0);
  }
  void push(int id, int l, int r) {
    st[id] += lz[id];
    if (l != r) {
      lz[id << 1] += lz[id];
      lz[id << 1 | 1] += lz[id];
    }
    lz[id] = 0;
  }
  void modify(int L, int R, int val, int id, int l, int r) {
    push(id, l, r);
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      lz[id] += val;
      push(id, l, r);
      return;
    }
    int mid = (l + r) / 2;
    modify(L, R, val, id << 1, l, mid);
    modify(L, R, val, id << 1 | 1, mid + 1, r);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
  }
  int getmax(int L, int R, int id, int l, int r) {
    push(id, l, r);
    if (L < l || r < L) return 0;
    if (L <= l && r <= R) return st[id];
    int mid = (l + r) / 2;
    return max(getmax(L, R, id << 1, l, mid),
               getmax(L, R, id << 1 | 1, mid + 1, r));
  }
  void modify(int L, int R, int val) { modify(L, R, val, 1, 1, n); }
  int getmax(int L, int R) {
    if (L > R) return INT_MIN;
    return getmax(L, R, 1, 1, n);
  }
};
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N;
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> M;
  vector<pair<int, int>> ask(M);
  for (auto& [x, y] : ask) {
    cin >> x >> y;
    --x;
    --y;
  }
  vector<int> tin(N), tout(N), depth(N);
  vector<array<int, 20>> par(N);
  int nTime = 0;
  function<void(int, int)> prep = [&](int u, int p) {
    tin[u] = ++nTime;
    for (int i = 1; i < 20; ++i) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto& v : adj[u]) {
      if (v == p) continue;
      depth[v] = depth[u] + 1;
      par[v][0] = u;
      prep(v, u);
    }
    tout[u] = nTime;
  };
  const auto isAnc = [&](int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
  };
  const auto lift = [&](int u, int d) -> int {
    for (int i = 19; i >= 0; --i) {
      if (d >> i & 1) u = par[u][i];
    }
    return u;
  };
  const auto lca = [&](int x, int y) -> int {
    if (depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for (int i = 19; i >= 0; --i) {
      if (diff >> i & 1) x = par[x][i];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; --i) {
      if (par[x][i] != par[y][i]) {
        tie(x, y) = make_pair(par[x][i], par[y][i]);
      }
    }
    return par[x][0];
  };
  const auto distintree = [&](int x, int y) -> int {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
  };
  prep(0, 0);
  vector<pair<int, int>> insub[N], outsub[N];
  for (int i = 0; i < M; ++i) {
    int u, v;
    tie(u, v) = ask[i];
    if (depth[u] > depth[v]) swap(u, v);
    int d = distintree(u, v);
    int w = lift(v, d / 2);
    insub[v].emplace_back(w, i);
    outsub[u].emplace_back(w, i);
  }
  vector<int> ans(M);
  lazysegtree tr(N);
  for (int i = 0; i < N; ++i) {
    tr.modify(tin[i], tin[i], depth[i]);
  }
  function<void(int, int)> reroot = [&](int u, int p) {
    const auto maxoutside = [&](int l, int r) -> int {
      return max(tr.getmax(1, l - 1), tr.getmax(r + 1, N));
    };
    for (auto& [w, idx] : insub[u]) {
      ans[idx] = max(ans[idx], tr.getmax(tin[w], tout[w]));
    }
    for (auto& [w, idx] : outsub[u]) {
      ans[idx] = max(ans[idx], maxoutside(tin[w], tout[w]));
    }
    for (auto& v : adj[u]) {
      if (v == p) continue;
      tr.modify(tin[v], tout[v], -2);
      tr.modify(1, N, 1);
      reroot(v, u);
      tr.modify(tin[v], tout[v], 2);
      tr.modify(1, N, -1);
    }
  };
  reroot(0, 0);
  for (int i = 0; i < M; ++i) {
    cout << ans[i] << '\n';
  }
}
