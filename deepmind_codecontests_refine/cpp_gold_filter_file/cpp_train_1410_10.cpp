#include <bits/stdc++.h>
using namespace std;
int seq[110000];
int par[110000];
int dn[110000];
int up[110000];
struct node {
  node *left, *right;
  int l, r;
  int vl;
} typedef node;
node* root;
void build(node* cur, int l, int r) {
  cur->l = l;
  cur->r = r;
  cur->vl = 11000000;
}
void expand(node* cur) {
  if (cur->left == NULL) {
    cur->left = new node();
    cur->right = new node();
    int m = (cur->l + cur->r) / 2;
    build(cur->left, cur->l, m);
    build(cur->right, m + 1, cur->r);
  }
}
void update(node* cur, int p, int vl) {
  if (cur->l == p && cur->r == p) {
    cur->vl = vl;
    return;
  }
  if (cur->l > p || cur->r < p) return;
  expand(cur);
  update(cur->left, p, vl);
  update(cur->right, p, vl);
  cur->vl = min(cur->left->vl, cur->right->vl);
}
int query(node* cur, int l, int r) {
  if (cur == NULL) return 11000000;
  if (cur->r < l || cur->l > r) return 11000000;
  if (cur->l >= l && cur->r <= r) return cur->vl;
  return min(query(cur->left, l, r), query(cur->right, l, r));
}
int main() {
  int i;
  int n;
  scanf("%d", &n);
  root = new node();
  build(root, 0, 1000000002);
  for (i = 0; i < n; i++) {
    scanf("%d", &seq[i]);
    dn[i] = 0;
    up[i] = 1000000002;
    if (i) update(root, seq[i], i);
  }
  for (i = 0; i < n; i++) {
    int lo = query(root, dn[i], seq[i] - 1);
    int hi = query(root, seq[i] + 1, up[i]);
    if (lo != 11000000) {
      par[lo] = seq[i];
      up[lo] = min(seq[i], up[i]);
      dn[lo] = dn[i];
      update(root, seq[lo], 11000000);
    }
    if (hi != 11000000) {
      par[hi] = seq[i];
      up[hi] = up[i];
      dn[hi] = max(seq[i], dn[i]);
      update(root, seq[hi], 11000000);
    }
  }
  for (i = 1; i < n; i++) {
    printf("%d", par[i]);
    if (i != n - 1)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
