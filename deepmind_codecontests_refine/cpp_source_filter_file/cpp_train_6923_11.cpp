#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200005;
set<int> s;
int n, m;
int u1[N], v1[N];
ll x1[N];
vector<int> g[N];
int sz[N];
int p[N], lvl[N];
void prec(int u) {
  for (int &v : g[u])
    if (v == p[u]) {
      swap(v, g[u].back());
      g[u].pop_back();
      break;
    }
  sz[u] = 1;
  for (int &v : g[u]) {
    p[v] = u;
    lvl[v] = lvl[u] + 1;
    prec(v);
    sz[u] += sz[v];
    if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
  }
}
int in[N], rin[N], out[N], t, nxt[N];
void dfs_hld(int u) {
  in[u] = t++;
  rin[in[u]] = u;
  for (int v : g[u]) {
    nxt[v] = (v == g[u][0] ? nxt[u] : v);
    dfs_hld(v);
  }
  out[u] = t;
}
int eid[N];
ll solve(int a, int b, ll y) {
  vector<pair<int, int>> ranges;
  auto lef_rig = [&](int l, int r) {
    for (auto it = s.lower_bound(l); it != s.end() and *it <= r; it++) {
      y /= x1[eid[*it]];
      if (y == 0) return;
    }
  };
  auto rig_lef = [&](int l, int r) {
    auto it = s.upper_bound(r);
    while (1) {
      if (it == s.begin()) return;
      it--;
      if (*it < l) return;
      y /= x1[eid[*it]];
      if (y == 0) return;
    }
  };
  auto upd = [&](int l, int r) {
    if (l <= r)
      lef_rig(l, r);
    else
      rig_lef(r, l);
  };
  while (nxt[a] != nxt[b]) {
    if (in[nxt[a]] > in[nxt[b]]) {
      upd(in[a], in[nxt[a]]);
      a = p[nxt[a]];
    } else {
      ranges.emplace_back(in[nxt[b]], in[b]);
      b = p[nxt[b]];
    }
  }
  if (in[a] < in[b]) {
    upd(in[a] + 1, in[b]);
  } else if (in[a] > in[b]) {
    upd(in[a], in[b] - 1);
  }
  while (!ranges.empty()) {
    upd(ranges.back().first, ranges.back().second);
    ranges.pop_back();
  }
  return y;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %lld", u1 + i, v1 + i, x1 + i);
    g[u1[i]].push_back(v1[i]);
    g[v1[i]].push_back(u1[i]);
  }
  prec(1);
  nxt[1] = 1;
  dfs_hld(1);
  for (int i = 1; i < n; i++) {
    if (p[v1[i]] == u1[i]) swap(u1[i], v1[i]);
    eid[in[u1[i]]] = i;
    if (x1[i] != 1) {
      s.insert(in[u1[i]]);
    }
  }
  while (m--) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int a, b;
      ll y;
      scanf("%d %d %lld", &a, &b, &y);
      printf("%lld\n", solve(a, b, y));
    } else {
      int id;
      ll c;
      scanf("%d %lld", &id, &c);
      x1[id] = c;
      if (x1[id] == 1)
        s.erase(in[u1[id]]);
      else
        s.insert(in[u1[id]]);
    }
  }
}
