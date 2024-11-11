#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
typedef struct Seg {
  int l, r, id;
  double p;
  int maxd, maxval;
} Seg;
bool operator<(const Seg &a, const Seg &b) {
  if (a.l != b.l) return a.l < b.l;
  if (a.r != b.r) return a.r > b.r;
  return a.id < b.id;
}
int npers, nseg;
int have[100000];
Seg seg[5001];
int fst[5001], lst[5001], nxt[5001], par[5001];
void createtree() {
  int at = 0;
  fst[at] = lst[at] = nxt[at] = par[at] = -1;
  for (int i = (1); i < (nseg); ++i) {
    fst[i] = lst[i] = nxt[i] = -1;
    while (at != -1 && seg[i].r > seg[at].r) at = par[at];
    assert(at != -1 && seg[i].l >= seg[at].l && seg[i].r <= seg[at].r);
    assert(lst[at] == -1 || seg[i].l >= seg[lst[at]].r);
    par[i] = at;
    if (fst[at] == -1)
      fst[at] = lst[at] = i;
    else
      nxt[lst[at]] = i, lst[at] = i;
    at = i;
  }
  for (int i = nseg - 1; i >= 0; --i) {
    seg[i].maxd = 0;
    for (int j = fst[i]; j != -1; j = nxt[j])
      if (seg[j].maxd + 1 > seg[i].maxd) seg[i].maxd = seg[j].maxd + 1;
    seg[i].maxval = INT_MIN;
    if (fst[i] == -1) {
      for (int x = (seg[i].l); x <= (seg[i].r); ++x)
        if (have[x] > seg[i].maxval) seg[i].maxval = have[x];
    } else {
      for (int x = (seg[i].l); x <= (seg[fst[i]].l - 1); ++x)
        if (have[x] > seg[i].maxval) seg[i].maxval = have[x];
      for (int j = fst[i]; j != -1; j = nxt[j])
        if (seg[j].maxval > seg[i].maxval) seg[i].maxval = seg[j].maxval;
      for (int j = fst[i]; nxt[j] != -1; j = nxt[j])
        for (int x = (seg[j].r + 1); x <= (seg[nxt[j]].l - 1); ++x)
          if (have[x] > seg[i].maxval) seg[i].maxval = have[x];
      for (int x = (seg[lst[i]].r + 1); x <= (seg[i].r); ++x)
        if (have[x] > seg[i].maxval) seg[i].maxval = have[x];
    }
  }
}
void printtree(int at, int d) {
  for (int i = (0); i < (d); ++i) printf("  ");
  printf("%d = %d..%d: %lf [%d,%d]\n", at, seg[at].l, seg[at].r, seg[at].p,
         seg[at].maxval, seg[at].maxd);
  for (int to = fst[at]; to != -1; to = nxt[to]) printtree(to, d + 1);
}
bool done[5001][5001];
double mem[5001][5001];
double calc(int at, int lim) {
  if (lim >= seg[at].maxd) return 1;
  if (lim < 0) return 0;
  if (done[at][lim])
    return mem[at][lim];
  else
    done[at][lim] = true;
  double ret = 1;
  for (int to = fst[at]; to != -1; to = nxt[to]) {
    double cur = 0;
    cur += seg[to].p * calc(to, seg[at].maxval - seg[to].maxval + lim - 1);
    cur += (1 - seg[to].p) * calc(to, seg[at].maxval - seg[to].maxval + lim);
    ret *= cur;
  }
  return mem[at][lim] = ret;
}
void run() {
  scanf("%d%d", &npers, &nseg);
  for (int i = (0); i < (npers); ++i) scanf("%d", &have[i]);
  for (int i = (0); i < (nseg); ++i) {
    scanf("%d%d%lf", &seg[i].l, &seg[i].r, &seg[i].p);
    --seg[i].l, --seg[i].r, seg[i].id = i;
  }
  seg[nseg].l = 0, seg[nseg].r = npers - 1, seg[nseg].id = -1, seg[nseg].p = 0;
  ++nseg;
  sort(seg, seg + nseg);
  createtree();
  double ret = 0;
  memset(done, false, sizeof(done));
  for (int i = (0); i < (nseg); ++i)
    ret += (seg[0].maxval + i) * (calc(0, i) - (i == 0 ? 0 : calc(0, i - 1)));
  printf("%.9lf\n", ret);
}
int main() {
  run();
  return 0;
}
