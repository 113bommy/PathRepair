#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n, m, c, s[N], t[N], ans[N], lazy[N];
pair<int, int> seg[N];
vector<int> g[N];
vector<pair<int, int> > query[N];
void shift(int, int, int);
pair<int, int> Min(pair<int, int> x, pair<int, int> y) {
  if (y < x) swap(x, y);
  if (x.first == y.first) x.second += y.second;
  return x;
}
void build(int id = 1, int L = 1, int R = n + 1) {
  seg[id].second = R - L;
  if (R <= L + 1) return;
  int mid = (L + R + 1) >> 1;
  build(id * 2 + 0, L, mid);
  build(id * 2 + 1, mid, R);
}
void add(int id, int L, int R, int l, int r, int val) {
  if (R <= l || r <= L) return;
  if (l <= L && R <= r) {
    lazy[id] += val;
    seg[id].first += val;
    return;
  }
  int mid = (L + R + 1) >> 1;
  shift(id, L, R);
  add(id * 2 + 0, L, mid, l, r, val);
  add(id * 2 + 1, mid, R, l, r, val);
  seg[id] = Min(seg[id * 2 + 0], seg[id * 2 + 1]);
}
void shift(int id, int L, int R) {
  int mid = (L + R + 1) >> 1;
  add(id * 2 + 0, L, mid, L, mid, lazy[id]);
  add(id * 2 + 1, mid, R, mid, R, lazy[id]);
  lazy[id] = 0;
}
void DFS(int x, int par) {
  for (int i = 0; i < query[x].size(); i++)
    add(1, 1, n + 1, query[x][i].first, query[x][i].second, 1);
  for (int i = 0; i < g[x].size(); i++)
    if (g[x][i] != par) DFS(g[x][i], x);
  ans[x] = n - (seg[1].first == 0 ? seg[1].second : 0);
  for (int i = 0; i < query[x].size(); i++)
    add(1, 1, n + 1, query[x][i].first, query[x][i].second, -1);
}
void dfs(int x, int par) {
  s[x] = ++c;
  for (int i = 0; i < g[x].size(); i++)
    if (g[x][i] != par) dfs(g[x][i], x);
  t[x] = c + 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  build();
  dfs(1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ;
    query[u].push_back(make_pair(s[v], t[v]));
    query[u].push_back(make_pair(s[u], t[u]));
    query[v].push_back(make_pair(s[u], t[u]));
    query[v].push_back(make_pair(s[v], t[v]));
  }
  DFS(1, 0);
  for (int i = 1; i < n + 1; i++) cout << ans[i] - (0 < ans[i]) << " ";
}
