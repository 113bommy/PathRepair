#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, l[N], r[N];
struct node *null;
struct node {
  node *ch[2], *f;
  int t, k;
  void push() {
    if (t) {
      k += t;
      (ch[0]->t) += t;
      (ch[1]->t) += t;
      t = 0;
    }
  }
  int d() { return f->ch[1] == this; }
  void st(node *c, int d) {
    ch[d] = c;
    if (c != null) c->f = this;
  }
  bool c() { return f == null; }
} T[N];
int tl = 0;
void rot(node *o) {
  node *f = o->f;
  int d = o->d();
  if (!f->c())
    f->f->st(o, f->d());
  else
    o->f = f->f;
  f->st(o->ch[d ^ 1], d), o->st(f, d ^ 1);
}
void fix(node *o) {
  if (!o->c()) fix(o->f);
  o->push();
}
void splay(node *o, node *f) {
  fix(o);
  while (o->f != f) {
    if (o->f->f != f) (o->d() == o->f->d() ? rot(o->f) : rot(o));
    rot(o);
  }
}
node *tmp;
node *find(node *o, int k) {
  o->push();
  if (o == null || o->k == k)
    return o;
  else {
    tmp = o;
    if (k < o->k)
      return find(o->ch[0], k);
    else {
      node *t = find(o->ch[1], k);
      return t == null ? o : t;
    }
  }
}
node *insert(node *o, int k) {
  o->push();
  if (o == null) {
    o = &T[++tl];
    o->ch[0] = o->ch[1] = null;
    o->t = 0, o->k = k;
    o->f = null;
    return o;
  } else if (k <= o->k) {
    node *t = insert(o->ch[0], k);
    if (o->ch[0] == null) o->st(t, 0);
    return t;
  } else {
    node *t = insert(o->ch[1], k);
    if (o->ch[1] == null) o->st(t, 1);
    return t;
  }
}
node *fL(node *o) {
  o->push();
  return o->ch[0] == null ? o : fL(o->ch[0]);
}
void del(node *o) {
  o->push();
  if (o->ch[1] == null) {
    int d = o->d();
    o->f->st(o->ch[0], d);
  } else {
    int d = o->d();
    node *t1 = fL(o->ch[1]);
    splay(t1, o);
    t1->st(o->ch[0], 0);
    o->f->st(t1, d);
  }
}
int ans = 0;
void dfs(node *o) {
  if (o == null) return;
  o->push();
  dfs(o->ch[0]);
  ans++;
  dfs(o->ch[1]);
}
int main() {
  scanf("%d", &n);
  null = &T[0];
  null->ch[0] = null->ch[1] = null->f = null;
  null->t = null->k = 0;
  node *rt = null;
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    node *o = insert(rt, l);
    splay(o, null), rt = o;
    tmp = null;
    node *t = find(o->ch[1], r + 1);
    if (t == null) {
      if (tmp != null) splay(tmp, o), del(tmp);
    } else {
      splay(t, o);
      (t->ch[0]->t)++;
      t->push();
      if (t->k < r) {
        (t->t)++;
        node *t1 = fL(t->ch[1]);
        if (t1 != null) splay(t1, t), del(t1);
      } else
        del(t);
    }
  }
  ans = 0;
  dfs(rt);
  printf("%d\n", ans);
  return 0;
}
