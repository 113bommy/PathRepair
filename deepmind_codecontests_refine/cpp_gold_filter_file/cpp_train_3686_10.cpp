#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void maxa(T& a, T b) {
  a = max(a, b);
}
template <typename T>
inline void mina(T& a, T b) {
  a = min(a, b);
}
const int mxN = 2e5 + 5;
int n, q, a, b, par[mxN], ans[mxN], dist[mxN][22], st[4 * mxN], ht[mxN], T[mxN],
    sub[mxN];
set<int> graph[mxN];
vector<int> vis;
int minh(int x, int y) { return ht[x] < ht[y] ? x : y; }
int build_st(int v, int l, int r) {
  if (l == r) {
    return st[v] = vis[l];
  }
  int m = (l + r) >> 1;
  return st[v] = minh(build_st(v << 1, l, m), build_st(v << 1 | 1, m + 1, r));
}
int query_st(int v, int l, int r, int lq, int rq) {
  if (lq > rq) {
    return 0;
  }
  if (l >= lq && r <= rq) {
    return st[v];
  }
  int m = (l + r) >> 1;
  return minh(query_st(v << 1, l, m, lq, min(rq, m)),
              query_st(v << 1 | 1, m + 1, r, max(lq, m + 1), rq));
}
void pre() {
  for (int i = 1; i <= n; i++) {
    int j = i;
    int cnt = 0;
    while (j != par[j]) {
      j = par[j];
      cnt++;
      int v1 = T[i];
      int v2 = T[j];
      if (v1 > v2) {
        swap(v1, v2);
      }
      int lca = query_st(1, 1, vis.size() - 1, v1, v2);
      dist[i][cnt] = ht[i] + ht[j] - 2 * ht[lca];
    }
  }
}
void euler(int at, int p, int h) {
  T[at] = vis.size();
  vis.push_back(at);
  ht[at] = h;
  for (int i : graph[at]) {
    if (i == p) continue;
    euler(i, at, h + 1);
    vis.push_back(at);
  }
}
int dfs(int at, int p) {
  int ret = 1;
  for (int i : graph[at]) {
    if (i == p) continue;
    ret += dfs(i, at);
  }
  return sub[at] = ret;
}
int centroid(int at, int p, int s) {
  for (int i : graph[at]) {
    if (i == p) continue;
    if (sub[i] * 2 >= s) return centroid(i, at, s);
  }
  return at;
}
void build(int at, int p) {
  int s = dfs(at, p);
  int cent = centroid(at, p, s);
  if (p == -1) {
    p = cent;
  }
  par[cent] = p;
  for (auto u : graph[cent]) {
    graph[u].erase(cent);
    build(u, cent);
  }
}
void update(int x) {
  ans[x] = 0;
  int cnt = 0;
  int y = x;
  while (y != par[y]) {
    y = par[y];
    cnt++;
    mina(ans[y], dist[x][cnt]);
  }
}
int query(int x) {
  int ret = ans[x];
  int y = x;
  int cnt = 0;
  while (y != par[y]) {
    y = par[y];
    cnt++;
    mina(ret, ans[y] + dist[x][cnt]);
  }
  return ret;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) ans[i] = 1e9;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
  }
  ht[0] = 1e9;
  vis.push_back(0);
  euler(1, -1, 0);
  build_st(1, 1, vis.size() - 1);
  build(1, -1);
  pre();
  update(1);
  while (q--) {
    cin >> a >> b;
    if (a == 1)
      update(b);
    else
      cout << query(b) << "\n";
  }
}
