#include <bits/stdc++.h>
using namespace std;
struct item {
  long long sum[5];
  int sz;
  item *l;
  item *r;
  int x, y;
  item(int x) {
    l = r = 0;
    this->x = x;
    this->y = rand();
    sz = 1;
    memset(sum, 0, sizeof(sum));
    sum[0] = x;
  }
};
typedef item *pitem;
inline void recalc(pitem &t) {
  int cursz = 0;
  memset(t->sum, 0, sizeof(t->sum));
  if (t->l) {
    for (int i = (0); i < (5); ++i) t->sum[i] += t->l->sum[i];
    cursz += t->l->sz;
  }
  cursz++;
  t->sum[(cursz - 1) % 5] += t->x;
  if (t->r) {
    for (int i = (0); i < (5); ++i) t->sum[(cursz + i) % 5] += t->r->sum[i];
    cursz += t->r->sz;
  }
  t->sz = cursz;
}
pitem merge(pitem a, pitem b) {
  if (!a) return b;
  if (!b) return a;
  pitem res;
  if (a->y > b->y) {
    a->r = merge(a->r, b);
    recalc(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    recalc(b);
    return b;
  }
}
void split(pitem t, pitem &l, pitem &r, int v) {
  if (!t) {
    l = r = 0;
    return;
  }
  if (t->x >= v) {
    r = t;
    split(t->l, l, t->l, v);
    recalc(r);
  } else {
    l = t;
    split(t->r, t->r, r, v);
    recalc(l);
  }
}
inline void add(int x, pitem &t) {
  pitem now = new item(x);
  pitem l = 0, r = 0;
  split(t, l, r, x);
  t = merge(l, now);
  t = merge(t, r);
}
inline void del(int x, pitem &t) {
  pitem l = 0, r = 0, tmp = 0;
  split(t, l, r, x);
  split(r, tmp, r, x + 1);
  t = merge(l, r);
}
char s[10];
int main() {
  pitem t = 0;
  int sz = 0;
  int n;
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) {
    scanf("%s", &s);
    if (s[0] == 'a') {
      int v;
      scanf("%d", &v);
      add(v, t);
      sz++;
    }
    if (s[0] == 'd') {
      int v;
      scanf("%d", &v);
      del(v, t);
      sz--;
    }
    if (s[0] == 's') {
      if (sz == 0)
        printf("0\n");
      else
        printf("%d\n", t->sum[2]);
    }
  }
  return 0;
}
