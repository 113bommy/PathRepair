#include <bits/stdc++.h>
using namespace std;
template <typename T, int size>
struct segtree_t {
  int n;
  vector<int> tree;
  segtree_t() : n(size), tree(4 * n, 0) {}
  T operation(const T &a, const T &b) { return max(a, b); }
  void build() {
    for (int i = 0; i < n; ++i)
      tree[i] = operation(tree[2 * i], tree[2 * i + 1]);
  }
  T query(int l, int r) {
    T x = 0, y = 0;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) x = operation(x, tree[l++]);
      if (r & 1) y = operation(tree[--r], y);
    }
    return operation(x, y);
  }
  void update(int idx, int val) {
    for (tree[idx += size] = val; idx > 1; idx >>= 1)
      tree[idx >> 1] = operation(tree[(idx | 1) ^ 1], tree[idx | 1]);
  }
};
int main() {
  int n;
  scanf("%d", &n);
  segtree_t<int, 10000> segtree;
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int b = segtree.query(0, a - 1);
    ret = max(ret, b + 1);
    segtree.update(a, b + 1);
  }
  printf("%d\n", ret);
  return 0;
}
