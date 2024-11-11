#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXM = 233333;
const int Inf = 0x3f3f3f3f;
struct segtree {
  int dt[MAXM << 3];
  void upd(int to, int x, int now = 1, int nl = 0, int nr = MAXM) {
    if (nl == to && nr == to) {
      dt[now] = x;
      return;
    }
    int m = (nl + nr) >> 1;
    if (m >= to) {
      upd(to, x, now << 1, nl, m);
    } else {
      upd(to, x, now << 1 | 1, m + 1, nr);
    }
    dt[now] = max(dt[now << 1], dt[now << 1 | 1]);
  }
  int qry(int l, int r = MAXM, int now = 1, int nl = 0, int nr = MAXM) {
    if (nl >= l && nr <= r) {
      return dt[now];
    }
    if (nl > r || nr < l) {
      return 0;
    }
    int m = (nl + nr) >> 1;
    return max(qry(l, r, now << 1, nl, m), qry(l, r, now << 1 | 1, m + 1, nr));
  }
} seg[2];
set<int> xs, ys;
int x2y[MAXM], y2x[MAXM];
void add(int x, int y) {
  xs.insert(x);
  ys.insert(y);
  x2y[x] = y;
  y2x[y] = x;
  vector<pair<int, int> > ff;
  for (int yy : ys) {
    int xx = y2x[yy];
    seg[0].upd(xx, 0);
    seg[1].upd(yy, 0);
    ff.emplace_back(xx, yy);
    if (yy == y) {
      break;
    }
  }
  for (int i = ff.size() - 1; ~i; i--) {
    int xx = ff[i].first, yy = ff[i].second;
    int val = seg[0].qry(xx + 1) + 1;
    seg[0].upd(xx, val);
    seg[1].upd(yy, val);
  }
}
void del(int whr) {
  vector<pair<int, int> > ff;
  for (int xx : xs) {
    int yy = x2y[xx];
    seg[0].upd(xx, 0);
    seg[1].upd(yy, 0);
    ff.emplace_back(xx, yy);
    if (!--whr) {
      xs.erase(xx);
      ys.erase(yy);
      break;
    }
  }
  for (int i = ff.size() - 2; ~i; i--) {
    int xx = ff[i].first, yy = ff[i].second;
    int val = seg[1].qry(yy + 1) + 1;
    seg[0].upd(xx, val);
    seg[1].upd(yy, val);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int mode;
    scanf("%d", &mode);
    if (mode == 1) {
      int p, h;
      scanf("%d%d", &p, &h);
      add(p, h - i + m);
    } else {
      int x;
      scanf("%d", &x);
      del(x);
    }
    printf("%d\n", seg[0].qry(0));
  }
  return 0;
}
