#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n;
int h[maxn];
int hp[maxn];
bool hsort(const int a, const int b) { return h[a] > h[b]; }
struct moe {
  int oprefix, omax, osuffix;
  moe(int pre, int mx, int suf) : oprefix(pre), omax(mx), osuffix(suf) {}
  moe() {}
};
struct node {
  moe m;
  node *l, *r;
  node() {
    m.oprefix = m.osuffix = m.omax = 0;
    l = r = 0;
  }
};
const int MXT = 1 << 17;
void build(int s, int e, node **r) {
  *r = new node();
  if (s + 1 == e) return;
  int mid = s + (e - s) / 2;
  build(s, mid, &((*r)->l));
  build(mid, e, &((*r)->r));
}
void updateo(const moe l, const moe r, moe *c, int chlen) {
  c->oprefix = l.omax == chlen ? l.omax + r.oprefix : l.oprefix;
  c->osuffix = r.omax == chlen ? r.omax + l.osuffix : r.osuffix;
  c->omax = max(l.osuffix + r.oprefix, max(l.omax, r.omax));
}
void sett(int pos, int s, int e, node *org, node **nw) {
  *nw = new node();
  if (s + 1 == e) {
    assert(s == pos);
    (*nw)->m = moe(1, 1, 1);
  } else {
    int mid = s + (e - s) / 2;
    (*nw)->l = org->l;
    (*nw)->r = org->r;
    if (pos < mid) {
      sett(pos, s, mid, org->l, &((*nw)->l));
    } else {
      sett(pos, mid, e, org->r, &((*nw)->r));
    }
  }
  if ((*nw)->l && (*nw)->r) {
    updateo((*nw)->l->m, (*nw)->r->m, &((*nw)->m), (e - s) / 2);
  }
}
moe maxone(int s, int e, int cs, int ce, node *r) {
  if (s <= cs && e >= ce) {
    return r->m;
  } else if (s >= ce || e <= cs) {
    return moe(0, 0, 0);
  } else {
    int mid = cs + (ce - cs) / 2;
    assert(r->l && r->r);
    moe lm = maxone(s, e, cs, mid, r->l);
    moe rm = maxone(s, e, mid, ce, r->r);
    moe res;
    updateo(lm, rm, &res, (ce - cs) / 2);
    return res;
  }
}
node *ht[maxn + 1];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", h + i);
    hp[i] = i;
  }
  sort(hp, hp + n, hsort);
  build(0, MXT, &ht[0]);
  for (int i = 0; i < n; i++) {
    sett(hp[i], 0, MXT, ht[i], &ht[i + 1]);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int l, r, w;
    scanf("%d%d%d", &l, &r, &w);
    int s = 0, e = n;
    while (s != e) {
      int mid = s + (e - s) / 2;
      moe res = maxone(l, r + 1, 0, MXT, ht[mid]);
      ;
      if (res.omax >= w) {
        e = mid;
      } else {
        s = mid + 1;
      }
    }
    printf("%d\n", h[hp[s - 1]]);
  }
  return 0;
}
