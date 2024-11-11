#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
vector<tuple<int, int, int>> edges;
vector<vector<int>> g;
map<int, int> w[N];
bool ready[N + 1];
int value[N + 1];
int go(int pos) {
  if (ready[pos]) return value[pos];
  int res = 0;
  int v = get<1>(edges[pos]);
  int c = get<2>(edges[pos]);
  int l = 0, r = (int((g[v]).size())) - 1;
  int last = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (g[v][m] > pos) {
      last = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  if (last == -1) return 0;
  for (int(i) = (last); (i) < ((int((g[v]).size()))); (i)++) {
    int k = g[v][i];
    if (get<2>(edges[k]) > c) {
      res = max(res, go(k) + 1);
    }
  }
  ready[pos] = 1;
  value[pos] = res;
  return res;
}
struct SegTree {
  int n;
  int ds;
  vector<int> t;
  SegTree() {}
  SegTree(int n) : n(n) {
    for (ds = 1; ds < n; ds *= 2)
      ;
    t.assign(2 * ds + 1, -1);
  }
  void Update(int x, int val) {
    x += ds;
    t[x] = val;
    for (x /= 2; x >= 1; x /= 2) {
      t[x] = max(t[x + x], t[x + x + 1]);
    }
  }
  int Get(int l, int r) {
    l += ds;
    r += ds;
    int res = -1;
    for (; l <= r; l /= 2, r /= 2) {
      if (l % 2 == 1) res = max(res, t[l++]);
      if (r % 2 == 0) res = max(res, t[r--]);
    }
    return res;
  }
};
vector<SegTree> trees;
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  g.resize(n);
  for (int(i) = (0); (i) < (m); (i)++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges.push_back(make_tuple(a, b, c));
    g[a].push_back((int((edges).size())) - 1);
  }
  for (int(i) = (0); (i) < (n); (i)++) {
    sort(g[i].begin(), g[i].end(), [](int a, int b) { return a < b; });
  }
  for (int(v) = (0); (v) < (n); (v)++) {
    for (auto k : g[v]) {
      w[get<1>(edges[k])][get<2>(edges[k])];
      w[get<0>(edges[k])][get<2>(edges[k])];
    }
  }
  for (int(v) = (0); (v) < (n); (v)++) {
    int cnt = 0;
    for (auto& k : w[v]) {
      k.second = cnt++;
    }
  }
  trees.resize(n);
  for (int(v) = (0); (v) < (n); (v)++) {
    trees[v] = SegTree((int((w[v]).size())));
  }
  for (int pos = m - 1; pos >= 0; pos--) {
    int res = 0;
    int v = get<1>(edges[pos]);
    int c = get<2>(edges[pos]);
    int up = -1;
    auto it = w[v].upper_bound(c);
    if (it != w[v].end()) {
      up = it->second;
    }
    if (up != -1) {
      int val = trees[v].Get(up, (int((w[v]).size())) - 1);
      if (val != -1) {
        res = val + 1;
      }
    }
    value[pos] = res;
    int p = get<0>(edges[pos]);
    int now = trees[p].Get(w[p][c], w[p][c]);
    trees[p].Update(w[p][c], max(now, value[pos]));
  }
  int mx = 0;
  for (int(i) = (0); (i) < (m); (i)++) {
    mx = max(mx, value[i] + 1);
  }
  cout << mx << endl;
  return 0;
}
