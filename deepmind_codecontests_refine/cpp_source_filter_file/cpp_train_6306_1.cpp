#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18, MOD = 998244353;
mt19937 rng(time(0));
long long int n, k;
struct treap {
  long long int pri, key, size;
  treap *ch[2] = {};
  treap() {}
  treap(long long int i) : pri(rand()), key(i), size(1) {}
};
long long int size(treap *a) { return a ? a->size : 0; }
void pull(treap *a) { a->size = size(a->ch[0]) + size(a->ch[1]) + 1; }
treap *merge(treap *a, treap *b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->ch[1] = merge(a->ch[1], b);
    pull(a);
    return a;
  } else {
    b->ch[0] = merge(a, b->ch[0]);
    pull(b);
    return b;
  }
}
void split(treap *x, long long int k, treap *&a, treap *&b) {
  if (!x)
    a = b = NULL;
  else if (x->key <= k) {
    a = x;
    split(x->ch[1], k, a->ch[1], b);
    pull(a);
  } else {
    b = x;
    split(x->ch[0], k, a, b->ch[0]);
    pull(b);
  }
}
long long int kth(treap *x, long long int k) {
  if (k <= size(x->ch[0]))
    return kth(x->ch[0], k);
  else if (k == size(x->ch[0]) + 1)
    return x->key;
  else
    return kth(x->ch[1], k - size(x->ch[0]) - 1);
}
treap *insert(treap *x, long long int k) {
  treap *a, *b;
  split(x, k, a, b);
  return merge(merge(a, new treap(k)), b);
}
long long int order_of_key(treap *x, long long int k) {
  if (!x) return 0;
  if (k == x->key)
    return size(x->ch[0]) + 1;
  else if (k > x->key) {
    return order_of_key(x->ch[1], k) + size(x->ch[0]) + 1;
  } else
    return order_of_key(x->ch[0], k);
}
vector<long long int> r;
bool sorting(long long int i, long long int j) { return r[i] > r[j]; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, k;
  cin >> n >> k;
  vector<long long int> x(n), f(n), order(n);
  r.resize(n);
  for (long long int i = 0; i < n; i++) cin >> x[i] >> r[i] >> f[i];
  vector<treap *> tree(1e4 + 10);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), sorting);
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int j = order[i];
    for (long long int pos = max<long long int>(f[j] - k, 0); pos <= f[j] + k;
         pos++) {
      ans += order_of_key(tree[pos], x[j] + r[j] + 1) -
             order_of_key(tree[pos], x[j] - r[j]);
    }
    tree[f[j]] = insert(tree[f[j]], x[j]);
  }
  cout << ans;
}
