#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long MAXN = 100010;
const long long BSIZ = 800;
int A[MAXN];
int N, Q, U, a, b, c, d;
vector<long double> ans;
struct node {
  int prior, cnt = 0, value, flip;
  node *l, *r;
  node(int _value) : value(_value), prior(rand()), l(NULL), r(NULL), flip(0) {}
};
inline int cnt(node*& t) {
  if (!t) return 0;
  return t->cnt;
}
inline void upd(node*& t) {
  if (!t) return;
  t->cnt = 1 + cnt(t->l) + cnt(t->r);
}
void prop(node*& t) {
  if (!t) return;
  if (!t->flip) return;
  if (t->l) t->l->flip ^= 1;
  if (t->r) t->r->flip ^= 1;
  t->flip = 0;
  swap(t->l, t->r);
}
void merge(node*& t, node*& l, node*& r) {
  prop(l);
  prop(r);
  if (!l)
    t = r;
  else if (!r)
    t = l;
  else if (l->prior > r->prior) {
    merge(l->r, l->r, r);
    t = l;
  } else {
    merge(r->l, l, r->l);
    t = r;
  }
  upd(t);
}
void split(node* t, node*& l, node*& r, int key) {
  prop(t);
  if (!t) {
    l = r = NULL;
    return;
  }
  int k = cnt(t->l);
  if (key <= k) {
    split(t->l, l, t->l, key);
    r = t;
  } else if (key == k + 1) {
    r = t->r;
    t->r = NULL;
    l = t;
  } else {
    split(t->r, t->r, r, key - 1 - k);
    l = t;
  }
  upd(l);
  upd(r);
}
void db(node*& t) {
  if (!t) return;
  prop(t);
  db(t->l);
  ans.emplace_back(t->value);
  db(t->r);
}
int main() {
  cin >> N >> Q >> U;
  node* root = NULL;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    node* B = new node(A[i]);
    merge(root, root, B);
  }
  for (int i = 0; i < Q; ++i) {
    cin >> a >> b >> c;
    if (a == 2) {
      c = c - b + 1;
      node *B, *C, *D;
      B = C = D = NULL;
      split(root, B, C, b - 1);
      split(C, C, D, c);
      C->flip = 1;
      merge(root, B, C);
      merge(root, root, D);
    } else if (a == 1) {
      c = c - b + 1;
      node *B, *C, *D, *E;
      B = C = D = NULL;
      split(root, B, C, b - 1);
      split(C, C, D, c);
      split(C, C, E, cnt(C) - 1);
      merge(C, E, C);
      merge(root, B, C);
      merge(root, root, D);
    }
  }
  db(root);
  for (int i = 0; i < U; ++i) {
    cin >> a;
    cout << ans[a - 1] << ' ';
  }
}
