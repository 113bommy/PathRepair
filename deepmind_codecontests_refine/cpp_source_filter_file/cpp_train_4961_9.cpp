#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, inf = 1 << 30;
int rd() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * w;
}
struct node {
  int x, y;
  bool operator<(const node &bb) const {
    return x != bb.x ? x < bb.x : y < bb.y;
  }
  bool operator==(const node &bb) const { return x == bb.x && y == bb.y; }
} qr[N];
map<node, int> mp;
map<node, int>::iterator m1;
vector<node> ti[N << 1];
struct edge {
  node p;
  int z;
};
vector<edge> op[N << 2];
vector<edge>::iterator it;
void setop(int o, int l, int r, int ll, int rr, edge x) {
  if (ll <= l && r <= rr) {
    op[o].push_back(x);
    return;
  }
  if (ll <= ((l + r) >> 1)) setop(o << 1, l, ((l + r) >> 1), ll, rr, x);
  if (rr > ((l + r) >> 1)) setop(o << 1 | 1, ((l + r) >> 1) + 1, r, ll, rr, x);
}
int ff[N], sz[N], w[N], di[N];
int findf(int x) {
  if (ff[x] == x) return x;
  int an = findf(ff[x]);
  di[x] = di[ff[x]] ^ w[x];
  return an;
}
int s1[N][2], t1;
void wd1() {
  int x = s1[t1][0], y = s1[t1][1];
  ff[y] = x, sz[x] -= sz[y], w[y] = di[y] = 0;
  --t1;
}
int lb[N][30], s2[N * 30][2], t2;
void lbinst(int i, int x) {
  if (!x) return;
  for (int j = 29; ~j; --j)
    if (x >> j & 1) {
      if (!lb[i][j]) {
        s2[++t2][0] = i, s2[t2][1] = j;
        lb[i][j] = x;
        return;
      }
      x ^= lb[i][j];
      if (!x) return;
    }
}
int quer(int i, int x) {
  int an = x;
  for (int j = 29; ~j; --j)
    if (an > (an ^ lb[i][j])) an ^= lb[i][j];
  return an;
}
void wd2() {
  int i = s2[t2][0], j = s2[t2][1];
  lb[i][j] = 0;
  --t2;
}
int n, m, tt, q;
bool ok[N << 2];
void bui(int o, int l, int r) {
  if (l == r) {
    ok[o] = qr[l].x;
    return;
  }
  bui(o << 1, l, ((l + r) >> 1)), bui(o << 1 | 1, ((l + r) >> 1) + 1, r);
  ok[o] = ok[o << 1] | ok[o << 1 | 1];
}
void sv(int o, int l, int r) {
  if (!ok[o]) return;
  int ltp1 = t1, ltp2 = t2;
  for (it = op[o].begin(); it != op[o].end(); ++it) {
    int x = (*it).p.x, y = (*it).p.y, z = (*it).z;
    int xx = findf(x), yy = findf(y);
    if (xx == yy)
      lbinst(xx, di[x] ^ di[y] ^ z);
    else {
      if (sz[xx] < sz[yy]) swap(xx, yy), swap(x, y);
      s1[++t1][0] = xx, s1[t1][1] = yy;
      ff[yy] = xx, sz[xx] += sz[yy], w[yy] = di[x] ^ di[y] ^ z;
      for (int j = 29; ~j; --j)
        if (lb[yy][j]) lbinst(xx, lb[yy][j]);
    }
  }
  if (l == r) {
    int x = qr[l].x, y = qr[l].y;
    int xx = findf(x), yy = findf(y);
    printf("%d\n", quer(xx, di[x] ^ di[y]));
  } else
    sv(o << 1, l, ((l + r) >> 1)), sv(o << 1 | 1, ((l + r) >> 1) + 1, r);
  while (t1 > ltp1) wd1();
  while (t2 > ltp2) wd2();
}
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= m; ++i) {
    int x = rd(), y = rd(), z = rd();
    if (x > y) swap(x, y);
    if (!mp.count((node){x, y})) mp[(node){x, y}] = ++tt;
    ti[mp[(node){x, y}]].push_back((node){0, z});
  }
  q = rd();
  for (int i = 1; i <= q; ++i) {
    int op = rd(), x = rd(), y = rd();
    if (x > y) swap(x, y);
    if (op == 1) {
      int z = rd();
      if (!mp.count((node){x, y})) mp[(node){x, y}] = ++tt;
      ti[mp[(node){x, y}]].push_back((node){i, z});
    } else if (op == 2)
      ti[mp[(node){x, y}]].push_back((node){i, 0});
    else
      qr[i] = (node){x, y};
  }
  for (m1 = mp.begin(); m1 != mp.end(); ++m1) {
    int i = (*m1).second;
    ti[i].push_back((node){q + 1, 0});
    int nn = ti[i].size();
    for (int j = 0; j + 1 < nn; j += 2)
      setop(1, 0, q, ti[i][j].x, ti[i][j + 1].x - 1,
            (edge){(*m1).first, ti[i][j].y});
  }
  bui(1, 0, q);
  for (int i = 1; i <= n; ++i) ff[i] = i, sz[i] = 1;
  sv(1, 0, q);
  return 0;
}
