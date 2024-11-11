#include <bits/stdc++.h>
using namespace std;
const int MD = 30;
const int M = (1ll << 30) - 1;
int n, m, K;
int lb(int x) { return x & (-x); }
struct Que {
  int x, y1, y2, sym;
  bool operator<(const Que& o) const { return x < o.x; }
} que[100100];
int tq;
map<int, int> lg;
bitset<32> qlb(int l, int r, int st, int ed) {
  bitset<32> res;
  res.reset();
  if (l >= st && r <= ed) {
    int B = lg[r - l + 1];
    res[lg[lb(l)]] = res[lg[lb(l)]] ^ 1;
    if (B >= 0) res[B - 1] = res[B - 1] ^ 1;
    return res;
  }
  int mid = (l + r) / 2;
  if (mid >= st) res ^= qlb(l, mid, st, ed);
  if (mid < ed) res ^= qlb(mid + 1, r, st, ed);
  return res;
}
bitset<32> qlb(int l, int r) { return qlb(0, M, l, r); }
struct SEG {
  int ls[5000500], rs[5000500], tot;
  int cov[5000500];
  int B[5000500];
  bitset<32> bs[5000500];
  void up(int x, int l, int r) {
    if (cov[x]) {
      bs[x].reset();
      int p = lg[lb(l)];
      bs[x][p] = bs[x][p] ^ 1;
      if (B[x] >= 0) bs[x][B[x] - 1] = bs[x][B[x] - 1] ^ 1;
    } else
      bs[x] = bs[ls[x]] ^ bs[rs[x]];
  }
  void ins(int& x, int l, int r, int st, int ed, int sym) {
    if (!x) {
      x = ++tot;
      B[x] = lg[r - l + 1];
    }
    if (l >= st && r <= ed) {
      cov[x] += sym;
      up(x, l, r);
      return;
    }
    int mid = (l + r) / 2;
    if (mid >= st) ins(ls[x], l, mid, st, ed, sym);
    if (mid < ed) ins(rs[x], mid + 1, r, st, ed, sym);
    up(x, l, r);
  }
} seg;
int rt = 0;
int main() {
  for (int i = 0; i <= MD; ++i) lg[1ll << i] = i;
  scanf("%d%d%d", &n, &m, &K);
  int x1, y1, x2, y2;
  x1 = K;
  K = 0;
  while ((1ll << K) <= x1) K++;
  K--;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    que[++tq] = (Que){x1, y1, y2, 1};
    que[++tq] = (Que){x2 + 1, y1, y2, -1};
  }
  sort(que + 1, que + tq + 1);
  bitset<32> cur, cy;
  int l, r, mi, v;
  int sg = 0;
  for (int i = 1, j; i <= tq; i = j) {
    for (j = i; que[j].x == que[i].x && j <= tq; ++j)
      seg.ins(rt, 0, M, que[j].y1, que[j].y2, que[j].sym);
    l = que[i].x, r = que[j].x - 1;
    if (j > tq) break;
    cur = qlb(l, r);
    cy = seg.bs[rt];
    for (int b = 0; b <= MD; ++b) {
      if (!cur[b]) continue;
      mi = min(b, K);
      for (int d = 0; d < mi; ++d) sg ^= (cy[d] << d);
      v = 0;
      for (int d = mi; d <= MD; ++d) v ^= cy[d];
      sg ^= (v << mi);
    }
  }
  puts(sg ? "Hamed" : "Malek");
  return 0;
}
