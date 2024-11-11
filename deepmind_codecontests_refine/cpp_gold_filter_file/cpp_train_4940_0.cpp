#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
int n, m;
struct node {
  pair<int, int> key;
  int fix, mxy, miy, miid;
  node *lf, *rg;
} nodes[111111 * 30];
int memNodes;
struct Treap {
  node *rt;
  void cls() { rt = NULL; }
  void update(node *&r) {
    if (!r) return;
    r->miid = r->key.second;
    if (r->lf) r->miid = min(r->miid, r->lf->miid);
    if (r->rg) r->miid = min(r->miid, r->rg->miid);
    r->miy = r->mxy = r->key.first;
    if (r->lf) r->miy = min(r->miy, r->lf->miy);
    if (r->rg) r->mxy = max(r->mxy, r->rg->mxy);
  }
  void rotrg(node *&r) {
    node *tmp = r->lf;
    r->lf = tmp->rg;
    tmp->rg = r;
    update(r);
    r = tmp;
    update(r);
  }
  void rotlf(node *&r) {
    node *tmp = r->rg;
    r->rg = tmp->lf;
    tmp->lf = r;
    update(r);
    r = tmp;
    update(r);
  }
  void insert(pair<int, int> num, node *&r) {
    if (!r) {
      r = &nodes[++memNodes];
      r->lf = r->rg = NULL;
      r->key = num;
      r->miy = r->mxy = num.first;
      r->miid = num.second;
      r->fix = rand();
    } else {
      if (num < r->key) {
        insert(num, r->lf);
        if (r->lf->fix > r->fix) rotrg(r);
      } else {
        insert(num, r->rg);
        if (r->rg->fix < r->fix) rotlf(r);
      }
    }
    update(r);
  }
  void del(pair<int, int> num, node *&r) {
    if (!r) return;
    if (num < r->key)
      del(num, r->lf);
    else if (num > r->key)
      del(num, r->rg);
    else {
      if (r->lf == NULL && r->rg == NULL) {
        r = NULL;
      } else if (r->lf == NULL) {
        node *tmp = r;
        r = r->rg;
      } else if (r->rg == NULL) {
        node *tmp = r;
        r = r->lf;
      } else {
        if (r->lf->fix < r->rg->fix) {
          rotlf(r);
          del(num, r->lf);
        } else {
          rotrg(r);
          del(num, r->rg);
        }
      }
    }
    update(r);
  }
  int query(int ly, int ry, node *&r) {
    if (r == NULL) return m;
    if (ly <= r->miy && r->mxy <= ry) return r->miid;
    int ret = m;
    if (r->key.first < ly)
      return query(ly, ry, r->rg);
    else if (r->key.first > ry)
      return query(ly, ry, r->lf);
    else {
      ret = min(ret, r->key.second);
      if (r->rg) ret = min(ret, query(ly, ry, r->rg));
      if (r->lf) ret = min(ret, query(ly, ry, r->lf));
    }
    return ret;
  }
};
struct rect {
  int xl, xr, yl, yr, z;
  int id;
  bool operator<(const rect &b) const { return z < b.z; }
} d[111111];
struct SegmentTree {
  Treap root[111111 * 10];
  void build(int p, int l, int r) {
    root[p].cls();
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
  }
  void insert(int p, int l, int r, int idx, pair<int, int> key) {
    root[p].insert(key, root[p].rt);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (idx <= mid)
      insert(p << 1, l, mid, idx, key);
    else
      insert(p << 1 | 1, mid + 1, r, idx, key);
  }
  void Delete(int p, int l, int r, int idx, pair<int, int> key) {
    root[p].del(key, root[p].rt);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (idx <= mid)
      Delete(p << 1, l, mid, idx, key);
    else
      Delete(p << 1 | 1, mid + 1, r, idx, key);
  }
  int querymin(int p, int l, int r, int lx, int rx, int ly, int ry) {
    if (lx <= l && r <= rx) {
      return root[p].query(ly, ry, root[p].rt);
    }
    int mid = (l + r) >> 1;
    int ret = m;
    if (lx <= mid) ret = min(ret, querymin(p << 1, l, mid, lx, rx, ly, ry));
    if (rx > mid)
      ret = min(ret, querymin(p << 1 | 1, mid + 1, r, lx, rx, ly, ry));
    return ret;
  }
} seg;
inline int getint() {
  char c = getchar();
  int t = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    t = t * 10 + c - '0';
    c = getchar();
  }
  return t;
}
pair<int, int> Query[111111];
int bX[111111 * 4], totX;
int ans[111111];
int main() {
  srand(time(NULL));
  n = getint();
  totX = memNodes = 0;
  for (int i = (0); i < (n); i++) {
    d[i].xl = getint();
    d[i].xr = getint();
    d[i].yl = getint();
    d[i].yr = getint();
    d[i].z = getint();
    d[i].id = i + 1;
    bX[totX++] = d[i].xl;
    bX[totX++] = d[i].xr;
  }
  sort(d, d + n);
  m = getint();
  for (int i = (0); i < (m); i++) {
    Query[i].first = getint();
    Query[i].second = getint();
    bX[totX++] = Query[i].first;
  }
  sort(bX, bX + totX);
  totX = unique(bX, bX + totX) - bX;
  seg.build(1, 0, totX - 1);
  for (int i = (0); i < (m); i++) {
    Query[i].first = lower_bound(bX, bX + totX, Query[i].first) - bX;
    seg.insert(1, 0, totX - 1, Query[i].first, make_pair(Query[i].second, i));
  }
  memset(ans, 0, sizeof(ans));
  for (int i = (0); i < (n); i++) {
    d[i].xl = lower_bound(bX, bX + totX, d[i].xl) - bX;
    d[i].xr = lower_bound(bX, bX + totX, d[i].xr) - bX;
    int idx = seg.querymin(1, 0, totX - 1, d[i].xl, d[i].xr, d[i].yl, d[i].yr);
    if (idx >= m)
      continue;
    else {
      ans[idx] = d[i].id;
      seg.Delete(1, 0, totX - 1, Query[idx].first,
                 make_pair(Query[idx].second, idx));
    }
  }
  for (int i = (0); i < (m); i++) printf("%d\n", ans[i]);
  return 0;
}
