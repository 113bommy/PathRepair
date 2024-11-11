#include <bits/stdc++.h>
using namespace std;
const int INFint = 2e9;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
struct segtree {
  vector<int> add;
  vector<pair<int, int> > t;
  int sz = 1;
  void push(int v) {
    if (add[v]) {
      t[2 * v].first += add[v] * t[2 * v].second;
      t[2 * v + 1].first += add[v] * t[2 * v + 1].second;
      add[2 * v] += add[v];
      add[2 * v + 1] += add[v];
      add[v] = 0;
    }
  }
  void modify(int l, int r, int lv, int rv, int v, int val) {
    if (l > rv || r < lv) return;
    if (lv >= l && rv <= r) {
      add[v] += val;
      t[v].first += t[v].second * val;
      return;
    }
    int md = (lv + rv) / 2;
    push(v);
    modify(l, r, lv, md, 2 * v, val);
    modify(l, r, md + 1, rv, 2 * v + 1, val);
    t[v].first = t[2 * v].first + t[2 * v + 1].first;
  }
  int sum(int l, int r, int lv, int rv, int v) {
    if (l > rv || r < lv) return 0;
    if (lv >= l && rv <= r) return t[v].first;
    push(v);
    int md = (lv + rv) / 2;
    int res = sum(l, r, lv, md, 2 * v) + sum(l, r, md + 1, rv, 2 * v + 1);
    t[v].first = t[2 * v].first + t[2 * v + 1].first;
    return res;
  }
  segtree(){};
  segtree(int n) {
    t.resize(4 * n);
    add.resize(4 * n);
    while (sz < n) sz *= 2;
    for (int i = sz; i < sz + n; i++) t[i].second = 1;
    for (int i = sz - 1; i > 0; i--)
      t[i].second = t[2 * i].second + t[2 * i + 1].second;
  }
};
vector<vector<int> > g;
vector<int> tin, tout, dist;
int timer;
void dfs(int v, int anc = -1, int len = 0) {
  tin[v] = timer++;
  dist[v] = len;
  for (auto to : g[v]) {
    if (to == anc) continue;
    dfs(to, v, len + 1);
  }
  tout[v] = timer++;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  g.resize(n);
  tin.resize(n);
  tout.resize(n);
  dist.resize(n);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0);
  segtree sg(timer);
  for (int i = 0; i < m; i++) {
    int t, v;
    cin >> t >> v;
    v--;
    if (t == 1) {
      int val;
      cin >> val;
      if (dist[v] & 1) {
        sg.modify(tin[v], tout[v], 0, sg.sz - 1, 1, -val);
      } else {
        sg.modify(tin[v], tout[v], 0, sg.sz - 1, 1, val);
      }
    } else {
      if (dist[v] & 1) {
        cout << a[v] - sg.sum(tin[v], tin[v], 0, sg.sz - 1, 1) << '\n';
      } else {
        cout << a[v] + sg.sum(tin[v], tin[v], 0, sg.sz - 1, 1) << '\n';
      }
    }
  }
  fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
  ;
  return 0;
}
