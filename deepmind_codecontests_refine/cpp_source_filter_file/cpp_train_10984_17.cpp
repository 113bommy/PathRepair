#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e6;
long long int timer(-1);
long long int in[N], out[N], val[N], a[N];
std::vector<long long int> v[N];
void dfs(long long int src, long long int par) {
  in[src] = ++timer;
  a[timer] = val[src];
  for (auto x : v[src]) {
    if (x == par) continue;
    dfs(x, src);
  }
  out[src] = timer;
}
class SegmentTree {
  long long int *tree, *lazy;

 public:
  SegmentTree() {
    tree = new long long int[4 * N];
    lazy = new long long int[4 * N];
  }
  void build(long long int, long long int, long long int);
  long long int query(long long int, long long int, long long int,
                      long long int, long long int);
  void update(long long int, long long int, long long int, long long int,
              long long int, long long int);
};
void SegmentTree ::build(long long int id, long long int start,
                         long long int end) {
  if (start > end) return;
  if (start == end) {
    tree[id] = (1LL << a[start]);
    return;
  }
  long long int mid = (start + end) >> 1;
  build(2 * id, start, mid);
  build(2 * id + 1, mid + 1, end);
  tree[id] = (tree[2 * id + 1] | tree[2 * id]);
}
long long int SegmentTree ::query(long long int id, long long int start,
                                  long long int end, long long int qs,
                                  long long int qe) {
  if (start > end || start > qe || end < qs) return 0;
  if (lazy[id] != 0) {
    tree[id] = lazy[id];
    if (start != end) {
      lazy[2 * id] = lazy[id];
      lazy[2 * id + 1] = lazy[id];
    }
    lazy[id] = 0;
  }
  if (start >= qs && end <= qe) {
    return tree[id];
  }
  long long int mid = (start + end) >> 1;
  long long int L = query(2 * id, start, mid, qs, qe);
  long long int R = query(2 * id + 1, mid + 1, end, qs, qe);
  return L | R;
}
void SegmentTree ::update(long long int id, long long int start,
                          long long int end, long long int qs, long long int qe,
                          long long int val) {
  if (lazy[id] != 0) {
    tree[id] = lazy[id];
    if (start != end) {
      lazy[2 * id] = lazy[id];
      lazy[2 * id + 1] = lazy[id];
    }
    lazy[id] = 0;
  }
  if (start > end || start > qe || end < qs) return;
  if (start >= qs && end <= qe) {
    tree[id] = (1 << val);
    lazy[id] = (1LL << val);
    if (start != end) {
      lazy[2 * id] = (1LL << val);
      lazy[2 * id + 1] = (1LL << val);
    }
    return;
  }
  long long int mid = (start + end) >> 1;
  update(2 * id, start, mid, qs, qe, val);
  update(2 * id + 1, mid + 1, end, qs, qe, val);
  tree[id] = tree[2 * id] | tree[2 * id + 1];
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, q;
  cin >> n >> q;
  for (long long int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (long long int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, -1);
  SegmentTree ob;
  ob.build(1, 0, timer);
  while (q--) {
    long long int type;
    cin >> type;
    if (type == 2) {
      long long int x;
      cin >> x;
      cout << __builtin_popcountll(ob.query(1, 0, timer, in[x], out[x]))
           << "\n";
    } else {
      long long int x, val;
      cin >> x >> val;
      ob.update(1, 0, timer, in[x], out[x], val);
    }
  }
  return 0;
}
