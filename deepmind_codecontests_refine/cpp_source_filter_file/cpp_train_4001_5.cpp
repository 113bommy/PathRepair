#include <bits/stdc++.h>
using namespace std;
struct node {
  node *left, *right;
  int size;
  int key, mx;
};
int pos[100110];
struct SplayTree {
  int cnt, top, count;
  node *root, *null, *stack[100110 * 2], nodes[100110 * 2];
  node *newnode(int c) {
    node *res;
    if (top)
      res = stack[--top];
    else
      res = nodes + (++cnt);
    res->left = res->right = null;
    res->size = 1;
    res->mx = res->key = c;
    return res;
  }
  void pushup(node *x) {
    if (x == null) return;
    x->size = x->left->size + x->right->size + 1;
    x->mx = max(x->key, max(x->left->mx, x->right->mx));
  }
  void init() {
    top = cnt = 0;
    count = 0;
    null = &nodes[++cnt];
    null->size = 0;
    null->left = null->right = null;
    null->mx = -0x3f3f3f3f;
    root = newnode(0);
    root->right = newnode(0);
  }
  void rightrotate(node *&x) {
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    pushup(x);
    x = y;
  }
  void leftrotate(node *&x) {
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    pushup(x);
    x = y;
  }
  void leftlink(node *&t, node *&l) {
    node *temp = t;
    t = t->right;
    temp->right = l;
    l = temp;
  }
  void rightlink(node *&t, node *&r) {
    node *temp = t;
    t = t->left;
    temp->left = r;
    r = temp;
  }
  void leftfinish(node *l, node *p) {
    while (1) {
      node *temp = l;
      l = l->right;
      temp->right = p;
      pushup(temp);
      p = temp;
      if (temp == null) break;
    }
  }
  void rightfinish(node *r, node *p) {
    while (1) {
      node *temp = r;
      r = r->left;
      temp->left = p;
      pushup(temp);
      p = temp;
      if (temp == null) break;
    }
  }
  void splay(node *&t, int k) {
    node *l = null, *r = null;
    null->left = null->right = null;
    while (k != t->left->size + 1) {
      if (k <= t->left->size) {
        if (k == t->left->left->size + 1)
          rightlink(t, r);
        else if (k <= t->left->left->size) {
          rightrotate(t);
          rightlink(t, r);
        } else {
          k -= t->left->left->size + 1;
          rightlink(t, r);
          leftlink(t, l);
        }
      } else {
        k -= t->left->size + 1;
        if (k == t->right->left->size + 1)
          leftlink(t, l);
        else if (k > t->right->left->size + 1) {
          k -= t->right->left->size + 1;
          leftrotate(t);
          leftlink(t, l);
        } else {
          leftlink(t, l);
          rightlink(t, r);
        }
      }
    }
    leftfinish(l, t->left);
    rightfinish(r, t->right);
    t->left = null->right;
    t->right = null->left;
    pushup(t);
  }
  void insert(int pos, int v) {
    splay(root, pos + 1);
    splay(root->right, 1);
    (root->right->left) = newnode(v);
    pushup(root->right);
    pushup(root);
    count++;
  }
  int find(int v) {
    splay(root, 1);
    splay(root->right, count + 1);
    return find((root->right->left), v);
  }
  int find(node *r, int v) {
    if (r == null) return 0;
    if (r->right->mx > v) return r->left->size + find(r->right, v);
    if (r->key > v) return r->left->size + 1;
    if (r->left->mx > v) return find(r->left, v);
    return 0;
  }
  void visit() {
    splay(root, 1);
    splay(root->right, count + 1);
    visit((root->right->left));
  }
  void visit(node *r) {
    if (r == null) return;
    visit(r->left);
    printf("%d ", pos[r->key]);
    visit(r->right);
  }
} st;
int n, a, c;
int main() {
  scanf("%d", &n);
  st.init();
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a, &c);
    pos[a] = i;
    int p = st.find(a);
    p = max(p, i - c - 1);
    st.insert(p, a);
  }
  st.visit();
  return 0;
}
