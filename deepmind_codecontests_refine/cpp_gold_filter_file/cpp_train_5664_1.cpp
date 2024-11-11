#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
class SBT {
  struct Node {
    int value, size;
    Node *c[2];
    Node(int v, int s, Node *p) : value(v), size(s) { c[0] = c[1] = p; }
    void rz() { size = c[0]->size + c[1]->size + 1; }
  } * root, *null;
  void rotate(Node *&t, bool d) {
    Node *p = t->c[d];
    t->c[d] = p->c[!d];
    p->c[!d] = t;
    t->rz();
    p->rz();
    t = p;
  }
  void maintain(Node *&t, bool d) {
    if (t == null) return;
    Node *&p = t->c[d];
    if (p->c[d]->size > t->c[!d]->size) {
      rotate(t, d);
    } else if (p->c[!d]->size > t->c[!d]->size) {
      rotate(p, !d);
      rotate(t, d);
    } else {
      return;
    }
    maintain(t->c[0], 0);
    maintain(t->c[1], 1);
    maintain(t, 0);
    maintain(t, 1);
  }
  void ins(Node *&t, int x) {
    if (t == null) {
      t = new Node(x, 1, null);
      return;
    }
    if (x == t->value) return;
    bool d = x > t->value;
    ins(t->c[d], x);
    maintain(t, d);
    t->rz();
  }
  void rmv(Node *&t, int x) {
    if (t == null) return;
    if (t->value == x) {
      if (t->c[1] == null) {
        delete t;
        t = t->c[0];
        return;
      }
      if (t->c[0] == null) {
        delete t;
        t = t->c[1];
        return;
      }
      Node *p = t->c[1];
      while (p->c[0] != null) p = p->c[0];
      t->value = p->value;
      rmv(t->c[1], p->value);
      maintain(t, 0);
    } else {
      bool d = x > t->value;
      rmv(t->c[d], x);
      maintain(t, !d);
    }
    t->rz();
  }
  int sel(Node *t, int k) {
    int r = t->c[0]->size;
    if (k == r) return t->value;
    if (k < r) return sel(t->c[0], k);
    return sel(t->c[1], k - r - 1);
  }
  int rnk(Node *t, int x) {
    if (t == null) return 0;
    int r = t->c[0]->size;
    if (x == t->value) return r;
    if (x < t->value) return rnk(t->c[0], x);
    return r + 1 + rnk(t->c[1], x);
  }
  void clr(Node *t) {
    if (t == null) return;
    clr(t->c[0]);
    clr(t->c[1]);
    delete t;
  }

 public:
  SBT() {
    null = new Node(0, 0, 0);
    null->c[0] = null->c[1] = null;
    root = null;
  }
  ~SBT() {
    clr(root);
    delete null;
  }
  void insert(int x) {
    if (count(x)) return;
    ins(root, x);
  }
  void remove(int x) {
    if (!count(x)) return;
    rmv(root, x);
  }
  int select(int k) {
    if (k > root->size) return inf;
    return sel(root, k - 1);
  }
  int rank(int x) { return rnk(root, x); }
  bool count(int x) {
    int p = rnk(root, x);
    return sel(root, p) == x;
  }
  int size() { return root->size; }
  void clear() {
    clr(root);
    root = null;
  }
} tree;
const int maxn = 300000 + 5;
int n, q;
int a[maxn];
int idx[maxn];
int main() {
  scanf("%d", &n);
  memset(idx, 0, sizeof(idx));
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    idx[a[i]] = i;
    if (!idx[a[i] - 1]) tree.insert(a[i]);
  }
  scanf("%d", &q);
  while (q--) {
    int p, x, y;
    scanf("%d%d%d", &p, &x, &y);
    if (p == 1) {
      int l = tree.rank(x), r = tree.rank(y);
      l -= !tree.count(x);
      r -= !tree.count(y);
      printf("%d\n", r - l + 1);
    } else {
      int xx = a[x], yy = a[y];
      int xl = idx[xx - 1], xr = idx[xx + 1];
      int yl = idx[yy - 1], yr = idx[yy + 1];
      swap(a[x], a[y]);
      swap(idx[xx], idx[yy]);
      if (x < xl && idx[xx] > idx[xx - 1]) tree.remove(xx);
      if (x < xr && idx[xx] > idx[xx + 1]) tree.insert(xx + 1);
      if (y > yl && idx[yy] < idx[yy - 1]) tree.insert(yy);
      if (y > yr && idx[yy] < idx[yy + 1]) tree.remove(yy + 1);
    }
  }
  return 0;
}
