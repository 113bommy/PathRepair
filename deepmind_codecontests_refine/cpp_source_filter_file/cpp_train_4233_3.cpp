#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int k, n, m;
struct Line {
  int l, r;
} line[2][maxn];
int p[maxn << 1], pcnt;
vector<int> vc[2][maxn << 1];
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int mul(int x, int y) { return 1LL * x * y % mod; }
inline int qpm(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = mul(ret, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ret;
}
int L;
struct SegmentTree {
  int tr[maxn << 2], tag[maxn << 2];
  void push_down(int rt) {
    if (tag[rt]) {
      tag[rt << 1] = 1;
      tag[rt << 1 | 1] = 1;
      tr[rt << 1] = 0;
      tr[rt << 1 | 1] = 0;
      tag[rt] = 0;
    }
  }
  void upd1(int pos, int k, int rt = 1, int l = 1, int r = L) {
    if (pos > r) return;
    if (l == r) {
      tr[rt] = add(tr[rt], k);
      return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (pos <= mid)
      upd1(pos, k, rt << 1, l, mid);
    else
      upd1(pos, k, rt << 1 | 1, mid + 1, r);
    tr[rt] = add(tr[rt << 1], tr[rt << 1 | 1]);
  }
  void upd2(int nl, int nr, int rt = 1, int l = 1, int r = L) {
    if (nl > nr) return;
    if (nl <= l && nr >= r) {
      tr[rt] = 0;
      tag[rt] = 1;
      return;
    }
    push_down(rt);
    int mid = l + r >> 1;
    if (nl <= mid) upd2(nl, nr, rt << 1, l, mid);
    if (nr >= mid + 1) upd2(nl, nr, rt << 1 | 1, mid + 1, r);
    tr[rt] = add(tr[rt << 1], tr[rt << 1 | 1]);
  }
  int qry(int nl, int nr, int rt = 1, int l = 1, int r = L) {
    if (nl <= l && nr >= r) return tr[rt];
    push_down(rt);
    int mid = l + r >> 1;
    int ret = 0;
    if (nl <= mid) ret = add(ret, qry(nl, nr, rt << 1, l, mid));
    if (nr >= mid + 1) ret = add(ret, qry(nl, nr, rt << 1 | 1, mid + 1, r));
    return ret;
  }
} seg[2];
int main() {
  scanf("%d %d %d", &k, &n, &m);
  p[++pcnt] = k;
  p[++pcnt] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &line[0][i].l, &line[0][i].r);
    line[0][i].l--;
    p[++pcnt] = line[0][i].l;
    p[++pcnt] = line[0][i].r;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &line[1][i].l, &line[1][i].r);
    line[1][i].l--;
    p[++pcnt] = line[1][i].l;
    p[++pcnt] = line[1][i].r;
  }
  sort(p + 1, p + 1 + pcnt);
  pcnt = unique(p + 1, p + 1 + pcnt) - (p + 1);
  for (int i = 1; i <= n; i++) {
    line[0][i].l = lower_bound(p + 1, p + 1 + pcnt, line[0][i].l) - p;
    line[0][i].r = lower_bound(p + 1, p + 1 + pcnt, line[0][i].r) - p;
    vc[0][line[0][i].r].push_back(line[0][i].l);
  }
  for (int i = 1; i <= m; i++) {
    line[1][i].l = lower_bound(p + 1, p + 1 + pcnt, line[1][i].l) - p;
    line[1][i].r = lower_bound(p + 1, p + 1 + pcnt, line[1][i].r) - p;
    vc[1][line[1][i].r].push_back(line[1][i].l);
  }
  L = pcnt;
  seg[1].upd1(1, 1);
  seg[0].upd1(1, 1);
  for (int i = 1; i < pcnt; i++) {
    int temp0 = seg[0].tr[1], temp1 = seg[1].tr[1];
    int _2 = qpm(2, p[i + 1] - p[i] - 1);
    seg[0].upd1(i, temp1);
    seg[1].upd1(i, temp0);
    seg[0].upd1(i + 1, mul(temp0, _2 - 1));
    seg[1].upd1(i + 1, mul(temp0, _2 - 1));
    seg[0].upd1(i + 1, mul(temp1, _2 - 1));
    seg[1].upd1(i + 1, mul(temp1, _2 - 1));
    for (auto it : vc[0][i + 1]) seg[1].upd2(1, it);
    for (auto it : vc[1][i + 1]) seg[0].upd2(1, it);
  }
  int ans = add(seg[0].tr[1], seg[1].tr[1]);
  printf("%d\n", mul(ans, mod + 1 >> 1));
  return 0;
}
