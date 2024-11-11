#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct Shirt {
  int pr, q;
  bool operator()(const Shirt &a, const Shirt &b) const {
    if (a.q > b.q) return 1;
    if (a.q == b.q && a.pr < b.pr) return 1;
    return 0;
  }
};
int n, k;
vector<int> ans;
vector<Shirt> vs;
struct Node {
  int key, pr, i, lv, lcnt, cnt;
  Node *c[2];
  Node(int &k, int &id) {
    key = k;
    pr = rand();
    i = id;
    lv = lcnt = cnt = 0;
    c[0] = c[1] = nullptr;
  }
};
void pd(Node *&x) {
  if (x == nullptr) return;
  if (x->lv) {
    x->key -= x->lv;
    x->cnt += x->lcnt;
    if (x->c[0] != nullptr) x->c[0]->lv += x->lv, x->c[0]->lcnt += x->lcnt;
    if (x->c[1] != nullptr) x->c[1]->lv += x->lv, x->c[1]->lcnt += x->lcnt;
    x->lv = x->lcnt = 0;
  }
}
void inOrder(Node *x) {
  if (x == nullptr) return;
  pd(x);
  inOrder(x->c[0]);
  ans[x->i] = x->cnt;
  inOrder(x->c[1]);
}
Node *getMin(Node *x) {
  if (x == nullptr) return nullptr;
  while (x->c[0] != nullptr) pd(x), x = x->c[0];
  pd(x);
  return x;
}
Node *getMax(Node *x) {
  if (x == nullptr) return nullptr;
  while (x->c[1] != nullptr) pd(x), x = x->c[1];
  pd(x);
  return x;
}
void Split(Node *x, Node *&L, Node *&R, int c) {
  if (x == nullptr) return void(L = R = nullptr);
  pd(x);
  if (c <= x->key)
    Split(x->c[0], L, x->c[0], c), R = x;
  else
    Split(x->c[1], x->c[1], R, c), L = x;
}
void Merge(Node *&x, Node *L, Node *R) {
  pd(L), pd(R);
  if (L == nullptr || R == nullptr)
    x = (L != nullptr) ? L : R;
  else if (L->pr > R->pr)
    Merge(L->c[1], L->c[1], R), x = L;
  else
    Merge(R->c[0], L, R->c[0]), x = R;
}
void Insert(Node *&x, Node *n) {
  Node *t;
  Split(x, x, t, n->key);
  Merge(t, n, t);
  Merge(x, x, t);
}
int main() {
  ios_base::sync_with_stdio(0);
  srand(time(0));
  Node *root = nullptr;
  scanf("%d", &n);
  vs.resize(n);
  for (int t1 = 0; t1 < n; ++t1) scanf("%d %d", &vs[t1].pr, &vs[t1].q);
  sort(vs.begin(), vs.end(), Shirt());
  scanf("%d", &k);
  ans.resize(k);
  for (int t1 = 0; t1 < k; ++t1) {
    int x;
    scanf("%d", &x);
    Insert(root, new Node(x, t1));
  }
  for (int t1 = 0; t1 < n; ++t1) {
    Node *L, *R;
    Split(root, L, R, vs[t1].pr);
    if (R == nullptr) {
      root = L;
      continue;
    } else
      R->lv += vs[t1].pr, ++R->lcnt;
    if (L == nullptr) {
      root = R;
      continue;
    }
    Node *Lmax = getMax(L);
    Node *Rmin = getMin(R);
    while (Rmin->key < Lmax->key) {
      Node *a, *b;
      Split(R, a, b, Rmin->key + 1);
      Insert(L, a);
      R = b;
      if (R == nullptr) break;
      Lmax = getMax(L);
      Rmin = getMin(R);
    }
    Merge(root, L, R);
  }
  inOrder(root);
  for (int t1 = 0; t1 < k; ++t1) printf("%d", ans[t1]);
  printf("\n");
  return 0;
}
