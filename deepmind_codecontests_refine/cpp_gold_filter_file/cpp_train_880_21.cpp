#include <bits/stdc++.h>
using namespace std;
class segtree {
 private:
  inline int left(int first) { return (first + 1) * 2 - 1; }
  inline int right(int first) { return (first + 1) * 2; }
  inline int parent(int first) { return (first + 1) / 2 - 1; }
  int lookup[100010];
  int tree[((1 << 18) + 10)];
  int N;
  void init(int node, int s, int e) {
    tree[node] = -1;
    if (s == e) {
      lookup[s] = node;
      return;
    }
    int m = (s + e) / 2;
    init(left(node), s, m);
    init(right(node), m + 1, e);
  }
  int query(int node, int s, int e, int i, int j) {
    if (s > j || e < i) return (1e9);
    if (s >= i && e <= j) return tree[node];
    int m = (s + e) / 2;
    return min(query(left(node), s, m, i, j),
               query(right(node), m + 1, e, i, j));
  }

 public:
  void init(int n) {
    N = n;
    init(0, 0, N - 1);
  }
  void update(int i, int val) {
    int first;
    first = lookup[i];
    tree[first] = val;
    while (first) {
      first = parent(first);
      tree[first] = min(tree[left(first)], tree[right(first)]);
    }
  }
  int query(int i, int j) { return query(0, 0, N - 1, i, j); }
};
segtree T;
int N, M, K, Q;
pair<int, int> pts[200010];
pair<pair<int, int>, pair<int, int> > rect[200010];
pair<int, int> all[200010 * 2];
int protect[200010];
void compute() {
  int i, n, k;
  n = 0;
  for (i = 0; i < K; ++i) all[n++] = make_pair(pts[i].first, i);
  for (i = 0; i < Q; ++i) all[n++] = make_pair(rect[i].first.second, i + K);
  sort(all, all + n);
  T.init(M);
  for (k = 0; k < n; ++k) {
    i = all[k].second;
    if (i < K) {
      T.update(pts[i].second, pts[i].first);
      continue;
    }
    i -= K;
    protect[i] |= (T.query(rect[i].second.first, rect[i].second.second) >=
                   rect[i].first.first);
  }
}
int main() {
  int i;
  ios::sync_with_stdio(0);
  cin >> N >> M >> K >> Q;
  ++N, ++M;
  for (i = 0; i < K; ++i) cin >> pts[i].first >> pts[i].second;
  for (i = 0; i < Q; ++i)
    cin >> rect[i].first.first >> rect[i].second.first >>
        rect[i].first.second >> rect[i].second.second;
  compute();
  for (i = 0; i < K; ++i) swap(pts[i].first, pts[i].second);
  swap(N, M);
  for (i = 0; i < Q; ++i) swap(rect[i].first, rect[i].second);
  compute();
  for (i = 0; i < Q; ++i) cout << (protect[i] ? "YES" : "NO") << "\n";
  return 0;
}
