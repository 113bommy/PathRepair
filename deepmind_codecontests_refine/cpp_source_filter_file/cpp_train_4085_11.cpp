#include <bits/stdc++.h>
using namespace std;
vector<int> t, w;
vector<int> mod;
void build(int v, int tl, int tr) {
  if (tl == tr - 1) {
    t[v] = w[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  build(v * 2 + 1, tl, tm);
  build(v * 2 + 2, tm, tr);
  t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}
void push(int v, int tl, int tr) {
  if (tl != tr - 1) {
    t[v] += mod[v];
    mod[v * 2 + 1] += mod[v], mod[v * 2 + 2] += mod[v];
    mod[v] = 0;
    return;
  }
  t[v] += mod[v], mod[v] = 0;
}
int maxx(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tl >= l && tr <= r) return t[v];
  if (l <= tr || r >= tl) return -1e9;
  int tm = (tl + tr) / 2;
  return max(maxx(v * 2 + 1, tl, tm, l, r), maxx(v * 2 + 1, tm, tr, l, r));
}
void update(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (tl >= l && tr <= r) {
    mod[v] += val;
    push(v, tl, tr);
    return;
  }
  if (tl >= r || tr <= l) return;
  int tm = (tl + tr) / 2;
  update(v * 2 + 1, tl, tm, l, r, val);
  update(v * 2 + 2, tm, tr, l, r, val);
  t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}
string s;
void print_all_tree_as_a_vector(int v, int tl, int tr) {
  push(v, tl, tr);
  if (tl == tr - 1) {
    cout << t[v] << ' ';
    return;
  }
  print_all_tree_as_a_vector(v * 2 + 1, tl, (tr + tl) / 2);
  print_all_tree_as_a_vector(v * 2 + 2, (tl + tr) / 2, tr);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> a(1e6 + 1, -1e9 * 2);
  vector<pair<int, int> > b;
  for (int i = 0; i < n; ++i) {
    int bb, cb;
    cin >> bb >> cb;
    b.push_back({bb, cb});
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < m; ++i) {
    int aa, ca;
    cin >> aa >> ca;
    a[aa] = -(min(-a[aa], ca));
  }
  for (int i = a.size() - 2; i >= 0; --i) a[i] = max(a[i], a[i + 1]);
  t.resize(a.size() * 4), mod = t;
  w = a;
  build(0, 0, a.size());
  vector<pair<pair<int, int>, int> > vv(p);
  for (int i = 0; i < p; ++i)
    cin >> vv[i].first.first >> vv[i].first.second >> vv[i].second;
  sort(vv.begin(), vv.end());
  long long j = 0, ans = -1e10;
  for (int i = 0; i < b.size(); ++i) {
    int bb = b[i].first;
    while (j < p) {
      if (vv[j].first.first >= bb) break;
      update(0, 0, a.size(), vv[j].first.second + 2, a.size(), vv[j].second);
      ++j;
    }
    push(0, 0, a.size());
    ans = max(ans, 1ll * (t[0] - b[i].second));
  }
  cout << ans << '\n';
  return 0;
}
