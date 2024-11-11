#include <bits/stdc++.h>
using namespace std;
template <class T>
struct node {
  T val;
  T lazy;
  int l, r;
  node* left;
  node* right;
  node(int l, int r) {
    this->l = l;
    this->r = r;
    this->left = nullptr;
    this->right = nullptr;
  }
};
template <class T, int SZ>
struct segtree {
  T combIdentity = -1e9;
  T comb(T l, T r) { return max(l, r); }
  T pushIdentity = 0;
  void push(node<T>* n) {
    n->val += n->lazy;
    if (n->l != n->r) {
      n->left->lazy += n->lazy;
      n->right->lazy += n->lazy;
    }
    n->lazy = pushIdentity;
  }
  node<T>* root;
  segtree() {
    int ub = 1;
    while (ub < SZ) ub *= 2;
    root = new node<T>(0, ub - 1);
    root->val = pushIdentity;
    root->lazy = pushIdentity;
  }
  void propagate(node<T>* n) {
    if (n->l != n->r) {
      int mid = ((n->l) + (n->r)) / 2;
      if (n->left == nullptr) {
        n->left = new node<T>(n->l, mid);
        n->left->val = pushIdentity;
        n->left->lazy = pushIdentity;
      }
      if (n->right == nullptr) {
        n->right = new node<T>(mid + 1, n->r);
        n->right->val = pushIdentity;
        n->right->lazy = pushIdentity;
      }
    }
    push(n);
  }
  void updN(node<T>* n, int i1, int i2, T val) {
    propagate(n);
    if (i2 < n->l || i1 > n->r) return;
    if (i1 <= n->l && i2 >= n->r) {
      n->lazy = val;
      push(n);
      return;
    }
    updN(n->left, i1, i2, val);
    updN(n->right, i1, i2, val);
    n->val = comb(n->left->val, n->right->val);
  }
  void upd(int i1, int i2, T val) { updN(root, i1, i2, val); }
  T queryN(node<T>* n, int i1, int i2) {
    propagate(n);
    if (i2 < n->l || i1 > n->r) return combIdentity;
    if (n->l >= i1 && n->r <= i2) return n->val;
    T a = combIdentity;
    if (n->left != nullptr) a = comb(a, queryN(n->left, i1, i2));
    if (n->right != nullptr) a = comb(a, queryN(n->right, i1, i2));
    return a;
  }
  T query(int i1, int i2) { return queryN(root, i1, i2); }
};
const int MAX_M = 20020;
const int MAX_N = 52;
int n, m, k;
int arr[MAX_N][MAX_M];
int pref[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];
int getsum(int i, int j) {
  if (j == 0)
    return pref[i][j + k - 1];
  else {
    return pref[i][j + k - 1] - pref[i][j - 1];
  }
}
int get(int i, int j) { return getsum(i, j) + getsum(i + 1, j); }
pair<int, int> getBounds(int j) {
  int l = j - k + 1;
  int r = j;
  l = max(0, l);
  r = min(m - k, r);
  return make_pair(l, r);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  for (int i = 0; i < n; i++) {
    pref[i][0] = arr[i][0];
    for (int j = 1; j < m; j++) pref[i][j] = pref[i][j - 1] + arr[i][j];
  }
  for (int i = 0; i < m - k + 1; i++) dp[0][i] = get(0, i);
  for (int i = 1; i < n; i++) {
    segtree<int, MAX_M> st;
    for (int j = 0; j < m - k + 1; j++) st.upd(j, j, dp[i - 1][j]);
    for (int j = 0; j < k; j++) {
      pair<int, int> b = getBounds(j);
      st.upd(b.first, b.second, -arr[i][j]);
    }
    for (int j = 0; j < m - k + 1; j++) {
      dp[i][j] = st.query(0, m - k) + get(i, j);
      pair<int, int> b = getBounds(j);
      st.upd(b.first, b.second, arr[i][j]);
      b = getBounds(j + k);
      st.upd(b.first, b.second, -arr[i][j + k]);
    }
  }
  int res = 0;
  for (int i = 0; i < m - k + 1; i++) res = max(res, dp[n - 1][i]);
  return cout << res << '\n', 0;
  ;
}
