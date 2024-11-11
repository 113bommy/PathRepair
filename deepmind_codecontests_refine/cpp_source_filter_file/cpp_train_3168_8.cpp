#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e6 + 10, MAXM = 2e5 + 10;
int n, m, w;
struct query {
  long long x1, x2, y1, y2, v, t;
};
vector<query> vc;
vector<int> xs, ys;
long long A;
struct segm {
  struct node {
    long long laz, m;
    int l, r;
  };
  node vs[MAXM * 4];
  vector<int> R;
  void upd(node &a, node &b, node &c) {
    a.m = b.m + c.m;
    a.m += a.laz * (R[a.r] - R[a.l]);
  }
  void prep() { make(0, 0, R.size()); }
  void make(int v, int l, int r) {
    vs[v].l = l, vs[v].r = r;
    if (r - l == 1) return;
    int mid = (l + r) / 2;
    make(2 * v, l, mid);
    make(2 * v + 1, mid, r);
  }
  void lax(int v) {
    if (vs[v].r - vs[v].l != 1) {
      vs[2 * v].laz += vs[v].laz;
      vs[2 * v + 1].laz += vs[v].laz;
    }
    vs[v].m += vs[v].laz * (R[vs[v].r] - R[vs[v].l]);
    vs[v].laz = 0;
  }
  void add(int v, int ql, int qr, long long val) {
    lax(v);
    if (qr <= vs[v].l || vs[v].r <= ql) return;
    if (ql <= vs[v].l && vs[v].r <= qr) {
      vs[v].laz += val;
      lax(v);
      return;
    }
    add(2 * v, ql, qr, val);
    add(2 * v + 1, ql, qr, val);
    upd(vs[v], vs[2 * v], vs[2 * v + 1]);
  }
  long long get(int v, int ql, int qr) {
    lax(v);
    if (qr <= vs[v].l || vs[v].r <= ql) return 0;
    if (ql <= vs[v].l && vs[v].r <= qr) return vs[v].m;
    return get(2 * v, ql, qr) + get(2 * v + 1, ql, qr);
  }
  int getind(int num) {
    return lower_bound(R.begin(), R.end(), num) - R.begin();
  }
} seg[2];
int main() {
  cin >> n >> m >> w;
  for (int i = 0; i < w; i++) {
    query tmp;
    cin >> tmp.t >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
    if (tmp.t == 0) cin >> tmp.v;
    vc.push_back(tmp);
    xs.push_back(tmp.x1);
    xs.push_back(tmp.x2 + 1);
    ys.push_back(tmp.y1);
    ys.push_back(tmp.y2 + 1);
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
  seg[0].R = xs, seg[1].R = ys;
  seg[0].prep(), seg[1].prep();
  for (int i = 0; i < w; i++) {
    if (vc[i].t == 0) {
      long long val;
      int s, e;
      A += (vc[i].x2 - vc[i].x1 + 1) * (vc[i].y2 - vc[i].y1 + 1) * vc[i].v;
      s = seg[0].getind(vc[i].x1);
      e = seg[0].getind(vc[i].x2 + 1);
      val = vc[i].v * (vc[i].y2 - vc[i].y1 + 1);
      seg[0].add(1, s, e, val);
      s = seg[1].getind(vc[i].y1);
      e = seg[1].getind(vc[i].y2 + 1);
      val = vc[i].v * (vc[i].x2 - vc[i].x1 + 1);
      seg[1].add(1, s, e, val);
    } else {
      long long res = A;
      int s, e;
      s = seg[0].getind(vc[i].x1);
      e = seg[0].getind(vc[i].x2 + 1);
      res -= seg[0].get(1, s, e);
      s = seg[1].getind(vc[i].y1);
      e = seg[1].getind(vc[i].y2 + 1);
      res -= seg[1].get(1, s, e);
      cout << res << '\n';
    }
  }
}
