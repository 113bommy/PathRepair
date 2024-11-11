#include <bits/stdc++.h>
using namespace std;
struct node {
  int count;
  node *left, *right;
  node(int count, node *left, node *right)
      : count(count), left(left), right(right) {}
  node *insert(int l, int r, int w, int val);
};
node *null = new node(0, NULL, NULL);
node *node::insert(int l, int r, int w, int val) {
  if (l <= w && w <= r) {
    if (l == r) return new node(this->count + val, null, null);
    int mid = (l + r) / 2;
    return new node(this->count + val, this->left->insert(l, mid, w, val),
                    this->right->insert(mid + 1, r, w, val));
  }
  return this;
}
int query(node *x, int a, int b, int k) {
  if (a == b) return a;
  int got = x->left->count;
  int mid = (a + b) / 2;
  if (got >= k)
    return query(x->left, a, mid, k);
  else
    return query(x->right, mid + 1, b, k - got);
}
node *root[100005];
int n, arr[100005], store[100005];
int helper(int l, int distinct) {
  if (root[l]->count <= distinct) return n;
  return query(root[l], 1, n, distinct);
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  int i, j, x, y, cur, nxt, ans = 0, k;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> arr[i];
  null->left = null->right = null;
  root[n + 1] = null;
  for (i = n; i >= 1; i--) {
    root[i] = root[i + 1];
    root[i] = root[i]->insert(1, n, i, 1);
    if (store[arr[i]]) root[i] = root[i]->insert(1, n, store[arr[i]], -1);
    store[arr[i]] = i;
  }
  for (k = 1; k <= n; k++) {
    cur = 1;
    ans = 0;
    while (1) {
      if (cur > n) break;
      nxt = helper(cur, k);
      ans++;
      cur = nxt + 1;
    }
    cout << ans << " ";
  }
  return 0;
}
