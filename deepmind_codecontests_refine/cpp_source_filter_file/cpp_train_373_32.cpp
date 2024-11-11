#include <bits/stdc++.h>
using namespace std;
struct Node {
  Node *l, *r;
  int size;
  long long sum[5];
  int a;
  int h;
  Node(int a) : a(a), l(NULL), r(NULL), size(1), h(rand()) {
    for (int i = 0; i < 5; i++) sum[i] = 0LL;
  }
  long long psum(Node* p, int k) { return p == NULL ? 0 : p->sum[k]; }
  int psize(Node* p) { return p == NULL ? 0 : p->size; }
  ~Node() {
    delete l;
    delete r;
  }
  void upd() {
    size = psize(l) + 1 + psize(r);
    for (int i = 0; i < 5; i++) sum[i] = psum(l, i);
    sum[psize(l) % 5] += a;
    for (int i = 0; i < 5; i++) sum[(psize(l) + 1 + i) % 5] += psum(r, i);
  }
};
Node* zig(Node* p) {
  Node* t = p->l;
  p->l = t->r;
  t->r = p;
  p->upd();
  t->upd();
  return t;
}
Node* zag(Node* p) {
  Node* t = p->r;
  p->r = t->l;
  t->l = p;
  p->upd();
  t->upd();
  return t;
}
Node* insert(Node* p, int a) {
  if (p == NULL) {
    p = new Node(a);
  } else {
    if (a < p->a) {
      p->l = insert(p->l, a);
      if (p->l->h < p->h) p = zig(p);
    } else {
      p->r = insert(p->r, a);
      if (p->r->h < p->h) p = zag(p);
    }
  }
  p->upd();
  return p;
}
Node* merge(Node* l, Node* r) {
  if (l == NULL)
    return r;
  else if (r == NULL)
    return l;
  else if (l->h < r->h) {
    l->r = merge(l->r, r);
    l->upd();
    return l;
  } else {
    r->l = merge(r->l, l);
    r->upd();
    return r;
  }
}
Node* remove(Node* p, int a) {
  if (p == NULL)
    return p;
  else if (a < p->a) {
    p->l = remove(p->l, a);
    p->upd();
  } else if (a > p->a) {
    p->r = remove(p->r, a);
    p->upd();
  } else {
    Node* t = p;
    p = merge(p->l, p->r);
    t->l = t->r = NULL;
    delete t;
  }
  return p;
}
int main() {
  int n, a;
  cin >> n;
  char str[10];
  Node* p = NULL;
  while (n--) {
    scanf("%s", str);
    if (str[0] == 'a') {
      scanf("%d", &a);
      p = insert(p, a);
    } else if (str[0] == 'd') {
      scanf("%d", &a);
      p = remove(p, a);
    } else
      printf("%I64d\n", p == NULL ? 0LL : p->sum[2]);
  }
  return 0;
}
