#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
  int tp;
  int index;
};
int timer = 0;
vector<vector<Edge> > gr;
vector<pair<int, int> > seg;
vector<int> tin;
vector<int> val;
vector<int> euler;
void dfs(int vertex, int last, int W) {
  tin[vertex] = timer++;
  val[vertex] = W;
  euler.push_back(vertex);
  for (auto ed : gr[vertex]) {
    if (ed.to == last) continue;
    int index = ed.index;
    seg[index].first = timer;
    dfs(ed.to, vertex, W ^ ed.tp);
    seg[index].second = timer - 1;
  }
}
int mx = -1;
int opt;
void dfs2(int vertex, int last, int d) {
  if (d > mx) {
    mx = d;
    opt = vertex;
  }
  for (auto ed : gr[vertex]) {
    int to = ed.to;
    if (to == last) continue;
    dfs2(to, vertex, d + 1);
  }
}
pair<int, int> find_diameter() {
  dfs2(0, -1, 0);
  int kek = opt;
  mx = -1;
  dfs2(kek, -1, 0);
  return make_pair(kek, opt);
}
int n;
vector<int> dist;
void dfs3(int vertex, int last, int d) {
  dist[vertex] = d;
  for (auto ed : gr[vertex]) {
    int to = ed.to;
    if (to == last) continue;
    dfs3(to, vertex, d + 1);
  }
}
struct Vertex {
  int max[2];
  bool need_push;
};
vector<Vertex> rmq;
void build(int i, int l, int r) {
  if (r - l == 1) {
    int W = euler[l];
    rmq[i].need_push = false;
    rmq[i].max[val[W]] = dist[W];
    rmq[i].max[1 - val[W]] = -1;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * i + 1, l, mid);
  build(2 * i + 2, mid, r);
  rmq[i].need_push = false;
  for (int j = 0; j < 2; ++j) {
    rmq[i].max[j] = max(rmq[2 * i + 1].max[j], rmq[2 * i + 2].max[j]);
  }
}
void push(int i, int l, int r) {
  if (r - l <= 1) return;
  if (!rmq[i].need_push) return;
  rmq[i].need_push = false;
  for (int j = 2 * i + 1; j <= 2 * i + 2; ++j) {
    rmq[j].need_push ^= 1;
    swap(rmq[j].max[0], rmq[j].max[1]);
  }
}
void upd(int i, int l, int r, int l1, int r1) {
  push(i, l, r);
  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    swap(rmq[i].max[0], rmq[i].max[1]);
    rmq[i].need_push = true;
    return;
  }
  int mid = (l + r) / 2;
  upd(2 * i + 1, l, mid, l1, min(r1, mid));
  upd(2 * i + 2, mid, r, max(l1, mid), r1);
  for (int j = 0; j < 2; ++j) {
    rmq[i].max[j] = max(rmq[2 * i + 1].max[j], rmq[2 * i + 2].max[j]);
  }
}
int get_val(int i, int l, int r, int index) {
  push(i, l, r);
  if (r - l == 1) {
    if (rmq[i].max[0] == -1) return 1;
    return 0;
  }
  int mid = (l + r) / 2;
  if (index < mid) return get_val(2 * i + 1, l, mid, index);
  return get_val(2 * i + 2, mid, r, index);
}
vector<int> solve(int vertex, vector<int> queries) {
  vector<int> ans;
  dist.assign(n, -1);
  dfs3(vertex, -1, 0);
  rmq.assign(4 * n, {});
  build(0, 0, n);
  for (auto first : queries) {
    upd(0, 0, n, seg[first].first, seg[first].second + 1);
    int T = get_val(0, 0, n, vertex);
    ans.push_back(rmq[0].max[T]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  gr.assign(n, {});
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    gr[u].push_back({v, w, i});
    gr[v].push_back({u, w, i});
  }
  seg.assign(n - 1, make_pair(-1, -1));
  tin.assign(n, -1);
  val.assign(n, -1);
  dfs(0, -1, 0);
  pair<int, int> p = find_diameter();
  vector<int> queries;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int first;
    cin >> first;
    first--;
    queries.push_back(first);
  }
  auto a = solve(p.first, queries);
  auto b = solve(p.second, queries);
  for (int i = 0; i < q; ++i) cout << max(a[i], b[i]) << '\n';
}
