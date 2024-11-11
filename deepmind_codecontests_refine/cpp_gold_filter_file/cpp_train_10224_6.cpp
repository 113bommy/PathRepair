#include <bits/stdc++.h>
using namespace std;
long long N;
long long n, x, k, z, m, pos, q, ans_v, y;
long long x1, p1, x2;
pair<long long, long long> a[200500];
vector<pair<long long, long long> > f;
struct SegmentTree {
  SegmentTree(long long n) : n(n), t(n * 2, 0) {}
  SegmentTree(vector<long long> x) : n(x.size()), t(n * 2, 0) {
    for (int i = 0; i < n; ++i) {
      t[i + n] = x[i];
    }
    build();
  }
  long long combine(long long a, long long b) { return a + b; }
  void build() {
    for (long long i = n - 1; i > 0; --i)
      t[i] = combine(t[i << 1], t[(i << 1) | 1]);
  }
  void modify(long long p, long long value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = combine(t[p], t[p ^ 1]);
  }
  long long query(long long l, long long r) {
    long long res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = combine(res, t[l++]);
      if (r & 1) res = combine(res, t[--r]);
    }
    return res;
  }
  long long n;
  vector<long long> t;
};
long long ans[200500];
vector<pair<long long, long long> > queries[200500];
SegmentTree seg_tree(200500);
long long b[200500];
bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
  return make_pair(-x.first, x.second) < make_pair(-y.first, y.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n, cmp);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    queries[x].push_back(make_pair(y, i));
  }
  for (int i = 1; i <= n; i++) {
    b[a[i - 1].second] = a[i - 1].first;
    seg_tree.modify(a[i - 1].second, 1);
    for (auto curq : queries[i]) {
      long long l = 0, r = n - 1;
      long long val = curq.first;
      while (l < r) {
        long long mid = (l + r) / 2;
        if (seg_tree.query(0, mid + 1) >= val) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      ans[curq.second] = b[l];
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
