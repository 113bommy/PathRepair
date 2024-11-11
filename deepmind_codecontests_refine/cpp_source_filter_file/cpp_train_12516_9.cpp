#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 1e9;
int n, m, p;
pair<int, int> a[maxn], b[maxn];
pair<pair<int, int>, int> mon[maxn];
struct segment_tree {
  int val[maxn * 4], lazy[maxn * 4];
  void build(int x, int l, int r) {
    if (l == r) {
      val[x] = -b[l].second;
      return;
    }
    int mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
    val[x] = max(val[x * 2], val[x * 2 + 1]);
  }
  void push(int x) {
    if (lazy[x] == 0) return;
    int t = lazy[x];
    val[x * 2] += t;
    lazy[x * 2] += t;
    val[x * 2 + 1] += t;
    lazy[x * 2 + 1] += t;
    lazy[x] = 0;
  }
  void upd(int x, int l, int r, int L, int R, int k) {
    if (L > r || l > R || L > R) return;
    if (l >= L && r <= R) {
      val[x] += k;
      lazy[x] += k;
      return;
    }
    push(x);
    int mid = (l + r) / 2;
    upd(x * 2, l, mid, L, R, k);
    upd(x * 2 + 1, mid + 1, r, L, R, k);
    val[x] = max(val[x * 2], val[x * 2 + 1]);
  }
  int get() { return val[1]; }
} tree;
void read_input() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
  for (int i = 1; i <= m; ++i) cin >> b[i].first >> b[i].second;
  for (int i = 1; i <= p; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    mon[i] = make_pair(pair<int, int>(x, y), z);
  }
}
void init() {
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  sort(mon + 1, mon + p + 1);
  tree.build(1, 1, m);
}
void solve() {
  int cur = 1;
  int ans = -inf;
  for (int i = 1; i <= n; ++i) {
    int ap = a[i].first;
    while (cur <= p && mon[cur].first.first < ap) {
      int p = upper_bound(b + 1, b + m + 1,
                          pair<int, int>(mon[cur].first.second, 0)) -
              b;
      tree.upd(1, 1, m, p, m, mon[cur].second);
      ++cur;
    }
    ans = max(ans, -a[i].second + tree.get());
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  read_input();
  init();
  solve();
}
