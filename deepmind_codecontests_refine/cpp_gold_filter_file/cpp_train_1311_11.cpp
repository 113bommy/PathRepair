#include <bits/stdc++.h>
using namespace std;
struct node {
  int fa, son[2], p, d, lz1, lz2;
} t[310000];
int n, tl;
void down(int x) {
  int lc = t[x].son[0], rc = t[x].son[1];
  if (lc) t[lc].lz1 += t[x].lz1, t[lc].lz2 += t[x].lz2;
  if (rc) t[rc].lz1 += t[x].lz1, t[rc].lz2 += t[x].lz2;
  t[x].p += t[x].lz1;
  t[x].d += t[x].lz2;
  t[x].lz1 = t[x].lz2 = 0;
}
void rot(int x, int f1, int t1) {
  int f2 = t[f1].fa, t2 = (t[f2].son[1] == f1);
  t[f1].son[t1] = t[x].son[t1 ^ 1];
  if (t[f1].son[t1]) t[t[f1].son[t1]].fa = f1;
  t[x].fa = f2;
  if (f2) t[f2].son[t2] = x;
  t[x].son[t1 ^ 1] = f1;
  t[f1].fa = x;
}
void splay(int x, int aim) {
  while (t[x].fa != aim) {
    int f1 = t[x].fa, f2 = t[f1].fa, t1 = (t[f1].son[1] == x),
        t2 = (t[f2].son[1] == f1);
    down(f2);
    down(f1);
    down(x);
    if (f2 == aim)
      rot(x, f1, t1);
    else if (t1 == t2)
      rot(f1, f2, t2), rot(x, f1, t1);
    else
      rot(x, f1, t1), rot(x, f2, t2);
  }
  down(x);
}
int lb(int h) {
  splay(1, 0);
  int x = 1, k = 0;
  while (x) {
    down(x);
    if (t[x].p >= h)
      x = t[x].son[0];
    else {
      if (k == 0 || t[x].p > t[k].p) k = x;
      x = t[x].son[1];
    }
  }
  return k;
}
int ub(int h) {
  splay(1, 0);
  int x = 1, k = 0;
  while (x) {
    down(x);
    if (t[x].p <= h)
      x = t[x].son[1];
    else {
      if (k == 0 || t[x].p < t[k].p) k = x;
      x = t[x].son[0];
    }
  }
  return k;
}
void del(int x) {
  splay(x, 0);
  if (t[x].son[1] == 0) {
    t[t[x].son[0]].fa = 0;
    splay(t[x].son[0], 0);
    return;
  }
  int i = t[x].son[0], j = t[x].son[1];
  while (t[i].son[1]) i = t[i].son[1];
  while (t[j].son[0]) j = t[j].son[0];
  splay(i, 0);
  splay(j, i);
  t[j].son[0] = 0;
}
void move(int l, int r) {
  int x, y = lb(r + 1);
  splay(y, 0);
  if (t[y].p < l) return;
  x = lb(l);
  y = ub(r);
  if (y == 0)
    splay(x, 0);
  else {
    splay(y, 0);
    splay(x, y);
  }
  t[t[x].son[1]].lz1++;
  t[t[x].son[1]].lz2++;
}
void ins(int p, int d) {
  t[++tl].p = p;
  t[tl].d = d;
  splay(1, 0);
  int x = 1;
  while (1) {
    down(x);
    if (t[x].p > p) {
      if (t[x].son[0] == 0) {
        t[tl].fa = x;
        t[x].son[0] = tl;
        break;
      }
      x = t[x].son[0];
    } else {
      if (t[x].son[1] == 0) {
        t[tl].fa = x;
        t[x].son[1] = tl;
        break;
      }
      x = t[x].son[1];
    }
  }
  splay(tl, 0);
}
int main() {
  tl = 1;
  t[1].p = t[1].d = 0;
  scanf("%d", &n);
  while (n--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int x = ub(r - 1);
    if (x) del(x);
    if (l < r) move(l, r - 1);
    x = lb(l);
    splay(x, 0);
    ins(l, t[x].d + 1);
    splay(1, 0);
    int o = 1;
  }
  splay(1, 0);
  int x = 1;
  while (t[x].son[1]) {
    x = t[x].son[1];
    down(x);
  }
  printf("%d\n", t[x].d);
  return 0;
}
