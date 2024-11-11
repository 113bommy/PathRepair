#include <bits/stdc++.h>
using namespace std;
struct node {
  long double val;
  long double lzadd;
  long double lzmult;
  int l, r;
  node* left;
  node* right;
  node(int l, int r) {
    this->val = 0;
    this->lzadd = 0;
    this->lzmult = 1;
    this->l = l;
    this->r = r;
    this->left = nullptr;
    this->right = nullptr;
  }
};
template <int SZ>
struct lazysegtree {
  node* root;
  lazysegtree() {
    int ub = 1;
    while (ub < SZ) ub *= 2;
    root = new node(0, ub - 1);
  }
  void propagate(node* n) {
    if (n->l != n->r) {
      int mid = ((n->l) + (n->r)) / 2;
      if (n->left == nullptr) n->left = new node(n->l, mid);
      if (n->right == nullptr) n->right = new node(mid + 1, n->r);
    }
    if (n->lzmult != 1) {
      n->val *= n->lzmult;
      if (n->l != n->r) {
        n->left->lzmult *= n->lzmult;
        n->left->lzadd *= n->lzmult;
        n->right->lzmult *= n->lzmult;
        n->right->lzadd *= n->lzadd;
      }
      n->lzmult = 1;
    }
    if (n->lzadd != 0) {
      n->val += ((n->r) - (n->l) + 1) * n->lzadd;
      if (n->l != n->r) {
        n->left->lzadd += n->lzadd;
        n->right->lzadd += n->lzadd;
      }
      n->lzadd = 0;
    }
  }
  void addN(node* n, int i1, int i2, long double val) {
    propagate(n);
    if (i2 < n->l || i1 > n->r) return;
    if (n->l == n->r) {
      n->val += val;
      return;
    }
    if (i1 <= n->l && i2 >= n->r) {
      n->val += ((n->r) - (n->l) + 1) * val;
      n->left->lzadd += val;
      n->right->lzadd += val;
      return;
    }
    addN(n->left, i1, i2, val);
    addN(n->right, i1, i2, val);
    n->val = n->left->val + n->right->val;
  }
  void add(int i1, int i2, long double val) { addN(root, i1, i2, val); }
  void multN(node* n, int i1, int i2, long double val) {
    propagate(n);
    if (i2 < n->l || i1 > n->r) return;
    if (n->l == n->r) {
      n->val *= val;
      return;
    }
    if (i1 <= n->l && i2 >= n->r) {
      n->val *= val;
      n->left->lzmult *= val;
      n->left->lzadd *= val;
      n->right->lzmult *= val;
      n->right->lzadd *= val;
      return;
    }
    multN(n->left, i1, i2, val);
    multN(n->right, i1, i2, val);
    n->val = n->left->val + n->right->val;
  }
  void mult(int i1, int i2, long double val) { multN(root, i1, i2, val); }
  long double queryN(node* n, int i1, int i2) {
    propagate(n);
    if (i2 < n->l || i1 > n->r) return 0;
    if (n->l == n->r) {
      return n->val;
    }
    if (i1 <= n->l && i2 >= n->r) {
      return n->val;
    }
    return queryN(n->left, i1, i2) + queryN(n->right, i1, i2);
  }
  long double query(int i1, int i2) { return queryN(root, i1, i2); }
};
const int MAX_N = 100000;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> n >> q;
  lazysegtree<MAX_N> s;
  for (int i = 0; i < n; i++) {
    long double k;
    cin >> k;
    s.add(i, i, k);
  }
  cout << fixed << setprecision(15);
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 2) {
      int l, r;
      cin >> l >> r;
      cout << s.query(l - 1, r - 1) << "\n";
    } else {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      l1--;
      r1--;
      l2--;
      r2--;
      long double s1 = s.query(l1, r1);
      long double s2 = s.query(l2, r2);
      long double num1 = r1 - l1 + 1;
      long double num2 = r2 - l2 + 1;
      s.mult(l1, r1, (num1 - 1) / num1);
      s.add(l1, r1, s2 / (num1 * num2));
      s.mult(l2, r2, (num2 - 1) / num2);
      s.add(l2, r2, s1 / (num1 * num2));
    }
  }
}
