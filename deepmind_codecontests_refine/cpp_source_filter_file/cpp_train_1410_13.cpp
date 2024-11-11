#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int key, p;
  Tree *ch[2], *fa;
  Tree() {
    key = p = 0;
    ch[0] = ch[1] = fa = NULL;
  }
} Aplay[100010], *Ap = &Aplay[0];
struct SPLAY {
  Tree *Root;
  SPLAY() { Root = NULL; }
  void Rotate(Tree *x) {
    Tree *y = (x->fa);
    int d = x == (y->ch[0]);
    y->ch[d ^ 1] = x->ch[d];
    if (x->ch[d]) (x->ch[d]->fa) = y;
    (x->fa) = (y->fa);
    if (y->fa) (y->fa)->ch[((y->fa)->ch[1]) == y] = x;
    (y->fa) = x;
    x->ch[d] = y;
  }
  void Splay(Tree *x, Tree *Stop) {
    for (Tree *y = (x->fa); y != Stop; y = (x->fa)) {
      if ((y->fa) != Stop)
        Rotate((x == (y->ch[0])) == (y == ((y->fa)->ch[0])) ? y : x);
      Rotate(x);
    }
    if (!Stop) Root = x;
  }
  void Search(int key) {
    Tree *x;
    for (x = Root; x;) {
      if (x->key == key) break;
      if (x->key > key) {
        if (!(x->ch[0])) break;
        x = (x->ch[0]);
      } else {
        if (!(x->ch[1])) break;
        x = (x->ch[1]);
      }
    }
    if (x) Splay(x, NULL);
  }
  void Insert(int key, int p) {
    Search(key);
    if (Root && Root->key == key)
      ;
    else {
      Tree *x = ++Ap;
      x->key = key;
      x->p = p;
      if (Root) {
        int d = Root->key > key;
        x->ch[d] = Root;
        (Root->fa) = x;
        x->ch[d ^ 1] = Root->ch[d ^ 1];
        if (Root->ch[d ^ 1]) (Root->ch[d ^ 1]->fa) = x;
        Root->ch[d ^ 1] = NULL;
      }
      Root = x;
    }
  }
  Tree *Pre(int key) {
    return Search(key), Root->key < key ? Root : Find((Root->ch[0]), 1);
  }
  Tree *Sub(int key) {
    return Search(key), Root->key > key ? Root : Find((Root->ch[1]), 0);
  }
  Tree *Find(Tree *x, int d) {
    if (!x) return NULL;
    while (x->ch[d]) x = x->ch[d];
    return x;
  }
} spy;
int main() {
  int i, n, a;
  Tree *l, *r;
  scanf("%d%d", &n, &a);
  spy.Insert(a, 1);
  for (i = 2; i <= n; ++i) {
    scanf("%d", &a);
    spy.Insert(a, 2);
    l = spy.Pre(a);
    r = spy.Sub(a);
    if (!l)
      printf("%d ", r->key);
    else if (!r)
      printf("%d ", l->key);
    else
      printf("%d ", r->p > l->p ? r->key : l->key);
  }
  return 0;
}
