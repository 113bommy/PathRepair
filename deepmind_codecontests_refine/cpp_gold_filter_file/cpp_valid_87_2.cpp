#include <bits/stdc++.h>
using namespace std;
class SegTree {
 public:
  long long val, lb, rb;
  SegTree *left, *right;
  SegTree(long long l, long long r) {
    lb = l, rb = r;
    if (l == r) {
      val = 0;
      return;
    }
    long long mid = (l + r) / 2;
    left = new SegTree(l, mid);
    right = new SegTree(mid + 1, r);
    val = 0;
  }
  void update(long long idx) {
    if (lb == rb) {
      val = 1;
      return;
    }
    if (idx > left->rb)
      right->update(idx);
    else
      left->update(idx);
    val = left->val + right->val;
  }
  long long query(long long l, long long r) {
    if (lb >= l and rb <= r)
      return val;
    else if (lb > r || rb < l)
      return 0;
    return left->query(l, r) + right->query(l, r);
  }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  map<long long, vector<long long> > mp;
  for (long long i = 0, x; i < m; ++i) {
    cin >> x;
    mp[x].emplace_back(i);
  }
  SegTree tr(0, m - 1);
  vector<long long> seat(m);
  long long last = 0;
  for (auto &i : mp) {
    if ((long long)(i.second).size() > 1) {
      for (long long id = (long long)(i.second).size() - 1; id >= 0; id--) {
        seat[i.second[id]] = last++;
      }
    } else {
      seat[i.second[0]] = last++;
    }
  }
  long long res = 0;
  for (long long i = 0; i < m; ++i) {
    res += tr.query(0, seat[i]);
    tr.update(seat[i]);
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T;
  cin >> T;
  while (T--) solve();
  return 0;
}
