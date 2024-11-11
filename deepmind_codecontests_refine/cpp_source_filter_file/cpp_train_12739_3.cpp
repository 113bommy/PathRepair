#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> G[100000];
pair<int, int> req[100000];
vector<int> que[100000];
int tin[100000];
int tout[100000];
int tinorder[100000];
int T = 0;
void dfs(int v) {
  if (tin[v] != -1) return;
  tinorder[T] = v;
  tin[v] = T++;
  for (int i = 0; i < G[v].size(); i++) dfs(G[v][i]);
  tinorder[T] = -1;
  tout[v] = T++;
}
struct stree {
  stree *lt, *rt;
  int l, r;
  int sum;
  stree(stree* lt, stree* rt, int l, int r) {
    this->l = l;
    this->r = r;
    this->lt = lt;
    this->rt = rt;
    sum = (lt == 0 ? 0 : lt->sum) + (rt == 0 ? 0 : rt->sum);
  }
  stree(int t, int s) {
    lt = rt = 0;
    l = r = t;
    sum = s;
  }
};
stree* create(int l, int r) {
  if (l == r) {
    if (tinorder[l] == -1)
      return new stree(l, 0);
    else
      return new stree(l, 1);
  }
  int m = (l + r) / 2;
  return new stree(create(l, m), create(m + 1, r), l, r);
}
stree* zero(stree* t, int l, int r) {
  if (t == 0 || t->l > r || t->r < l) return t;
  if (l <= t->l && t->r <= r) return 0;
  return new stree(zero(t->lt, l, r), zero(t->rt, l, r), t->l, t->r);
}
int get(stree* t, int l, int r) {
  if (t == 0 || t->l > r || t->r < l) return 0;
  if (l <= t->l && t->r <= r) return t->sum;
  return get(t->lt, l, r) + get(t->rt, l, r);
}
int c[100000];
int an(int i, int v) { return req[i].first + req[i].second - v; }
void ddfs(int v, int p, int delta, stree* rsq) {
  if (!que[v].empty()) {
    delta += get(rsq, tin[v], tout[v]);
    rsq = zero(rsq, tin[v], tout[v]);
  }
  for (int i = 0; i < que[v].size(); i++) {
    delta += get(rsq, tin[an(que[v][i], v)], tout[an(que[v][i], v)]);
    rsq = zero(rsq, tin[an(que[v][i], v)], tout[an(que[v][i], v)]);
  }
  c[v] = delta;
  for (int i = 0; i < G[v].size(); i++)
    if (G[v][i] != p) ddfs(G[v][i], v, delta, rsq);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  memset(tin, -1, sizeof tin);
  dfs(0);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    req[i] = make_pair(a, b);
    que[a].push_back(i);
    que[b].push_back(i);
  }
  ddfs(0, -1, 0, create(0, T - 1));
  for (int i = 0; i < n; i++) cout << max(0, c[i] - 1) << " ";
}
