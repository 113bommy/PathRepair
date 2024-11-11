#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937_64 randGen(system_clock().now().time_since_epoch().count());
mt19937 rnd(42);
const int N = 2e5 + 10;
struct Tree {
  vector<long long> t;
  int n;
  set<int> ids;
  void init(int sn) {
    n = sn;
    t.assign(4 * n, 0LL);
  }
  void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
      ids.insert(tl);
    } else {
      int mid = (tl + tr) / 2;
      build(a, v * 2, tl, mid);
      build(a, v * 2 + 1, mid + 1, tr);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  long long sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return 0LL;
    }
    if (l == tl && r == tr) {
      return t[v];
    }
    int mid = (tl + tr) / 2;
    return sum(v * 2, tl, mid, l, min(r, mid)) +
           sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
  }
  void upd(int v, int tl, int tr, int id, int val) {
    if (tl == tr) {
      t[v] = val;
    } else {
      int mid = (tl + tr) / 2;
      if (id <= mid) {
        upd(v * 2, tl, mid, id, val);
      } else {
        upd(v * 2 + 1, mid + 1, tr, id, val);
      }
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  void rem(int l, int r) {
    auto efrom = ids.lower_bound(l);
    auto eto = ids.upper_bound(r);
    auto lcopy = efrom;
    while (lcopy != eto) {
      upd(1, 1, n, *lcopy, 0LL);
      ++lcopy;
    }
    ids.erase(efrom, eto);
  }
  void pour(int id, int val) {
    int l = id, r = n;
    int to = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      long long can = sum(1, 1, n, id, mid);
      if (can >= val) {
        to = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    long long right = sum(1, 1, n, id, to);
    long long left = sum(1, 1, n, id, to - 1);
    long long sright = sum(1, 1, n, to, to);
    rem(id, to);
    if (sright > (val - left)) {
      upd(1, 1, n, to, sright - val + left);
      ids.insert(to);
    }
  }
};
struct Solver {
  Tree tree;
  void solve() {
    int n, m, a[N] = {};
    int l, r, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    tree.init(n);
    tree.build(a, 1, 1, n);
    cin >> m;
    while (m--) {
      cin >> l >> r;
      if (l == 1) {
        cin >> q;
        tree.pour(r, q);
      } else {
        cout << a[r] - tree.sum(1, 1, n, r, r) << "\n";
      }
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Solver sol;
  sol.solve();
  return 0;
}
