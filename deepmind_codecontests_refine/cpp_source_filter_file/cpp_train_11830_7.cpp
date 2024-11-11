#include <bits/stdc++.h>
using namespace std;
int n, k, m, cnt;
int X[200010];
struct Pair {
  int id;
  long long tim;
  Pair(int _ = 0, long long __ = 0LL) {
    id = _;
    tim = __;
  }
  bool operator<(const Pair &WT) const { return tim > WT.tim; }
};
priority_queue<Pair> Q;
struct Treap {
  int fix, id, pos;
  Treap *L, *R;
  long long tim;
} Node[200010 << 1], *Root;
bool Check(Treap *p, int id, long long tim, int pos) {
  if (pos < p->pos) return true;
  if (pos == p->pos && tim < p->tim) return true;
  if (pos == p->pos && tim == p->tim && id < p->id) return true;
  return false;
}
Treap *NewTnode(int id, long long tim, int pos) {
  Node[cnt].L = Node[cnt].R = NULL;
  Node[cnt].id = id;
  Node[cnt].pos = pos;
  Node[cnt].tim = tim;
  Node[cnt].fix = rand();
  return Node + cnt++;
}
void LRotate(Treap *&a) {
  Treap *b = a->R;
  a->R = b->L;
  b->L = a;
  a = b;
}
void RRotate(Treap *&a) {
  Treap *b = a->L;
  a->L = b->R;
  b->R = a;
  a = b;
}
void TreapInsert(Treap *&p, int id, long long tim, int pos) {
  if (!p)
    p = NewTnode(id, tim, pos);
  else if (Check(p, id, tim, pos)) {
    TreapInsert(p->L, id, tim, pos);
    if (p->L->fix < p->fix) RRotate(p);
  } else {
    TreapInsert(p->R, id, tim, pos);
    if (p->R->fix < p->fix) LRotate(p);
  }
}
void TreapDel(Treap *&p, Treap *x) {
  if (x == p) {
    if (!p->L || !p->R) {
      if (p->L)
        p = p->L;
      else
        p = p->R;
    } else if (p->L->fix < p->R->fix) {
      RRotate(p);
      TreapDel(p->R, x);
    } else {
      LRotate(p);
      TreapDel(p->L, x);
    }
  } else if (Check(p, x->id, x->tim, x->pos))
    TreapDel(p->L, x);
  else
    TreapDel(p->R, x);
}
Treap *FindPre(Treap *p, int pos, Treap *now) {
  if (!p) return now;
  if (p->pos <= pos)
    return FindPre(p->R, pos, p);
  else
    return FindPre(p->L, pos, now);
}
Treap *FindSuc(Treap *p, int pos, Treap *now) {
  if (!p) return now;
  if (p->pos >= pos)
    return FindSuc(p->L, pos, p);
  else
    return FindSuc(p->R, pos, now);
}
void Take(int id, long long tim, int pos, long long tt, int aa, int bb) {
  tim += (long long)abs(pos - aa);
  printf("%d %I64d\n", id, tim);
  Q.push(Pair(id, tt + tim + (long long)abs(aa - bb)));
  X[id] = bb;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) scanf("%d", &X[i]);
  for (int i = 1; i <= k; i++) TreapInsert(Root, i, 0LL, X[i]);
  long long tt;
  int aa, bb;
  for (int i = 1; i <= m; i++) {
    scanf("%I64d%d%d", &tt, &aa, &bb);
    long long Lim = tt;
    if (!Root) Lim = Q.top().tim;
    while (!Q.empty()) {
      Pair temp = Q.top();
      if (temp.tim > Lim) break;
      TreapInsert(Root, temp.id, temp.tim, X[temp.id]);
      Q.pop();
    }
    Treap *Left = FindPre(Root, aa, NULL);
    Treap *Right = FindSuc(Root, aa, NULL);
    if (Left) Left = FindSuc(Root, Left->pos, NULL);
    if (Left && !Right) {
      Take(Left->id, max(0LL, Left->tim - tt), Left->pos, tt, aa, bb);
      TreapDel(Root, Left);
    } else if (Right && !Left) {
      Take(Right->id, max(0LL, Right->tim - tt), Right->pos, tt, aa, bb);
      TreapDel(Root, Right);
    } else {
      int d1 = abs(Left->pos - aa), d2 = abs(Right->pos - aa);
      if (d1 > d2)
        swap(Left, Right);
      else if (d1 == d2 && Left->tim > Right->tim)
        swap(Left, Right);
      else if (d1 == d2 && Left->tim == Right->tim && Left->id > Right->id)
        swap(Left, Right);
      Take(Left->id, max(0LL, Left->tim - tt), Left->pos, tt, aa, bb);
      TreapDel(Root, Left);
    }
  }
  return 0;
}
