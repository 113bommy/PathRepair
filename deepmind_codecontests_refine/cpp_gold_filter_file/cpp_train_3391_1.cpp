#include <bits/stdc++.h>
using namespace std;
const int inf = 1100000000;
int n, Q;
map<int, int> h;
struct node {
  int x, y, aux, size;
  node *l, *r;
  node();
} * null;
node::node() {
  aux = rand() % inf;
  size = 0, l = null, r = null;
}
class treap {
 private:
  node *root;
  int low_ans, up_ans;

 public:
  treap() { root = null; }
  ~treap(){};
  void rotateL(node *&x);
  void rotateR(node *&x);
  void Insert(node *&root, int x);
  void Insert(node *&root, int x, int y);
  void Delete(node *&root, int x);
  void Delete(node *&root, int x, int y);
  void ins(int x) { Insert(root, x); }
  void ins(int x, int y) { Insert(root, x, y); }
  void del(int x) { Delete(root, x); }
  void del(int x, int y) { Delete(root, x, y); }
  void Low(node *root, int x);
  void Up(node *root, int x);
  int Rank(node *root, int x);
  int get_low(int x) {
    low_ans = -inf;
    Low(root, x);
    return low_ans;
  }
  int get_up(int x) {
    up_ans = inf;
    Up(root, x);
    return up_ans;
  }
  int get_rank(int x) { return Rank(root, x); }
  int get_pos() {
    node *R = root;
    while (R->r != null) R = R->r;
    int st = R->y, len = R->x;
    return st + len / 2 + 1;
  }
} * A, *B;
int treap::Rank(node *root, int x) {
  if (root == null) return 0;
  if (root->x == x)
    return root->l->size + 1;
  else if (root->x > x)
    return Rank(root->l, x);
  else
    return Rank(root->r, x) + root->l->size + 1;
}
void treap::Low(node *root, int x) {
  if (root == null) return;
  if (root->x <= x)
    low_ans = max(low_ans, root->x), Low(root->r, x);
  else
    Low(root->l, x);
}
void treap::Up(node *root, int x) {
  if (root == null) return;
  if (root->x >= x)
    up_ans = min(up_ans, root->x), Up(root->l, x);
  else
    Up(root->r, x);
}
void treap::rotateL(node *&x) {
  node *y = x->r;
  x->r = y->l;
  y->l = x;
  y->size = x->size;
  x->size = x->l->size + x->r->size + 1;
  x = y;
}
void treap::rotateR(node *&x) {
  node *y = x->l;
  x->l = y->r;
  y->r = x;
  y->size = x->size;
  x->size = x->l->size + x->r->size + 1;
  x = y;
}
void treap::Insert(node *&root, int x) {
  if (root == null) {
    root = new node();
    root->x = x, root->y = root->size = 1;
    return;
  }
  root->size++;
  if (root->x > x) {
    Insert(root->l, x);
    if (root->l->aux > root->aux) rotateR(root);
  } else {
    Insert(root->r, x);
    if (root->r->aux > root->aux) rotateL(root);
  }
}
void treap::Insert(node *&root, int x, int y) {
  if (root == null) {
    root = new node();
    root->x = x, root->y = y, root->size = 1;
    return;
  }
  if (root->x > x || (root->x == x && root->y > y)) {
    Insert(root->l, x, y);
    if (root->l->aux > root->aux) rotateR(root);
  } else {
    Insert(root->r, x, y);
    if (root->r->aux > root->aux) rotateL(root);
  }
}
void treap::Delete(node *&root, int x) {
  if (root == null) return;
  root->size--;
  if (root->x == x) {
    if (root->l == null || root->r == null)
      if (root->l == null)
        root = root->r;
      else
        root = root->l;
    else if (root->l->aux > root->r->aux)
      rotateR(root), Delete(root->r, x);
    else
      rotateL(root), Delete(root->l, x);
  } else if (root->x > x)
    Delete(root->l, x);
  else
    Delete(root->r, x);
}
void treap::Delete(node *&root, int x, int y) {
  if (root == null) return;
  if (root->x == x && root->y == y) {
    if (root->l == null || root->r == null)
      if (root->l == null)
        root = root->r;
      else
        root = root->l;
    else if (root->l->aux > root->r->aux)
      rotateR(root), Delete(root->r, x, y);
    else
      rotateL(root), Delete(root->l, x, y);
  } else if (root->x > x || (root->x == x && root->y > y))
    Delete(root->l, x, y);
  else
    Delete(root->r, x, y);
}
void delete_people(int x) {
  map<int, int>::iterator p = h.find(x);
  int pos = p->second;
  int last = A->get_low(pos - 1), next = A->get_up(pos + 1);
  B->del(pos - last - 1, last);
  B->del(next - pos - 1, pos);
  B->ins(next - last - 1, last);
  A->del(pos);
  h[x] = -1;
}
void insert_people(int x) {
  int pos = B->get_pos();
  A->ins(pos);
  h[x] = pos;
  int last = A->get_low(pos - 1), next = A->get_up(pos + 1);
  B->del(next - last - 1, last);
  B->ins(pos - last - 1, last);
  B->ins(next - pos - 1, pos);
}
bool exists(int x) {
  map<int, int>::iterator p = h.find(x);
  if (p == h.end() || p->second == -1) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &Q);
  null = new node();
  A = new treap();
  A->ins(0);
  A->ins(n + 1);
  B = new treap();
  B->ins(n, 0);
  h.clear();
  for (int i = 1; i <= Q; i++) {
    int k;
    scanf("%d", &k);
    if (k == 0) {
      int a, b;
      scanf("%d%d", &a, &b);
      a = A->get_rank(a - 1), b = A->get_rank(b);
      printf("%d\n", b - a);
    } else if (exists(k))
      delete_people(k);
    else
      insert_people(k);
  }
  return 0;
}
