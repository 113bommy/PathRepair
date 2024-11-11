#include <bits/stdc++.h>
using namespace std;
struct SegmentTree {
  int n;
  vector<int> v, start, finish;
  void init(int root) {
    if (start[root] == finish[root]) return;
    int mid = (start[root] + finish[root]) / 2;
    start[root * 2] = start[root];
    finish[root * 2] = mid;
    init(root * 2);
    start[root * 2 + 1] = mid + 1;
    finish[root * 2 + 1] = finish[root];
    init(root * 2 + 1);
    v[root] = v[root * 2] + v[root * 2 + 1];
  }
  SegmentTree(int _n) {
    n = _n;
    v.assign(n * log2(n) * 5, 1);
    start.resize(n * log2(n) * 5);
    finish.resize(n * log2(n) * 5);
    start[1] = 1;
    finish[1] = n;
    init(1);
  }
  void update(int root, int i, int val) {
    if (start[root] == finish[root]) {
      v[root] += val;
      return;
    }
    int mid = (start[root] + finish[root]) / 2;
    if (i <= mid)
      update(root * 2, i, val);
    else
      update(root * 2 + 1, i, val);
    v[root] = v[root * 2] + v[root * 2 + 1];
  }
  int get(int root, int from, int to) {
    if (from > to) swap(from, to);
    if (from <= start[root] && to >= finish[root]) return v[root];
    if (to < start[root] || from > finish[root]) return 0;
    return get(root * 2, from, to) + get(root * 2 + 1, from, to);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  SegmentTree st(n + 1);
  int start = 1, finish = n;
  for (int q_i = 0; q_i < q; ++q_i) {
    int type;
    cin >> type;
    int len = abs(finish - start) + 1;
    int sgn = (finish != start) ? (abs(finish - start) / (finish - start)) : 1;
    if (type == 1) {
      int p;
      cin >> p;
      if (p > len - p) {
        swap(start, finish);
        sgn = -sgn;
        p = len - p;
      }
      for (int i = 0; i < p; ++i) {
        int val = st.get(1, start + i * sgn, start + i * sgn);
        st.update(1, start + (2 * p - 1 - i) * sgn, val);
      }
      start += p * sgn;
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.get(1, start + (l)*sgn, start + (r - 1) * sgn) << '\n';
    }
  }
}
