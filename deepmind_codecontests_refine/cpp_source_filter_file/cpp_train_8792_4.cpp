#include <bits/stdc++.h>
using namespace std;
const int QUERY = -1;
struct Range {
  int l, r, id;
  mutable int k;
  Range(int l, int r, int k, int id) : l(l), r(r), k(k), id(id) {}
  bool operator<(const Range& oth) const { return r < oth.r; }
  void dec() const { k--; }
};
int ans[1 << 17];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<Range> Intv;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    Intv.emplace_back(l, r, QUERY, i);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int l, r, k;
    cin >> l >> r >> k;
    --l;
    Intv.emplace_back(l, r, k, i);
  }
  sort(Intv.begin(), Intv.end(), [=](Range a, Range b) {
    return a.l == b.l ? (a.k == QUERY) < (b.k == QUERY) : a.l < b.l;
  });
  set<Range> rb;
  for (Range r : Intv) {
    if (r.k == QUERY) {
      auto it = rb.lower_bound(r);
      if (it == rb.end()) {
        cout << "NO\n", exit(0);
      } else {
        it->dec();
        ans[r.id] = it->id;
        if (it->k == 0) {
          rb.erase(it);
        }
      }
    } else {
      rb.insert(r);
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " \n"[i + 1 == n];
}
