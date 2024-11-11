#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
const int oo = 2e9;
int a[N];
mt19937 rnd(chrono::system_clock().now().time_since_epoch().count());
struct node {
  node *l, *r, *pr;
  int vl, cnt, prior;
  node(int vl) : l(0), r(0), pr(0), vl(vl), cnt(1), prior(rnd()) {}
};
typedef node *pnode;
pnode A, B, A1, B1, A2, B2, BAD, pt[N];
map<int, pnode> mem[N];
vector<pnode> vc;
int cnt(pnode t) { return (t ? t->cnt : 0); }
void upd_cnt(pnode t) {
  if (!t) return;
  t->cnt = cnt(t->l) + cnt(t->r) + 1;
  t->pr = 0;
  if (t->l) t->l->pr = t;
  if (t->r) t->r->pr = t;
}
void merge(pnode &t, pnode l, pnode r) {
  if (!l || !r) {
    t = (l ? l : r);
    return;
  }
  if (l->prior < r->prior) {
    merge(l->r, l->r, r);
    t = l;
    upd_cnt(t);
  } else {
    merge(r->l, l, r->l);
    t = r;
    upd_cnt(t);
  }
}
void split(pnode t, pnode &l, pnode &r, int key) {
  if (!t) {
    l = r = 0;
    return;
  }
  int cur_key = cnt(t->l) + 1;
  if (cur_key <= key) {
    split(t->r, t->r, r, key - cnt(t->l) - 1);
    if (r) r->pr = 0;
    if (r && r->l) r->l->pr = r;
    if (r && r->r) r->r->pr = r;
    l = t;
    upd_cnt(l);
  } else {
    split(t->l, l, t->l, key);
    if (l) l->pr = 0;
    if (l && l->l) l->l->pr = l;
    if (l && l->r) l->r->pr = l;
    r = t;
    upd_cnt(r);
  }
}
inline pair<int, int> combine(pair<int, int> l, pair<int, int> r) {
  pair<int, int> res;
  if (l.first == r.first) {
    res.first = l.first;
    res.second = l.second + r.second;
  } else if (l.first > r.first)
    res = r;
  else
    res = l;
  return res;
}
int get_ind(pnode v) {
  int res = cnt(v->l) + 1;
  while (v->pr) {
    if (v->pr->r == v) res += cnt(v->pr->l) + 1;
    v = v->pr;
  }
  return res;
}
pnode get_root(pnode v) {
  while (v->pr) v = v->pr;
  return v;
}
bool Is_connected(int x, int y) { return get_root(pt[x]) == get_root(pt[y]); }
pnode LEFT(pnode v) { return (v->l ? LEFT(v->l) : v); }
pnode RIGHT(pnode v) { return (v->r ? RIGHT(v->r) : v); }
void link(int x, int y) {
  int kx = get_ind(pt[x]);
  int ky = get_ind(pt[y]);
  A = get_root(pt[x]);
  B = get_root(pt[y]);
  split(A, A1, A2, kx);
  split(B, B1, B2, ky);
  pnode lef = LEFT(B1);
  if (pt[lef->vl] == lef)
    split(B2, B2, BAD, cnt(B2) - 1);
  else
    split(B1, BAD, B1, 1);
  pnode cx = new node(x);
  pnode cy = new node(y);
  if (cnt(A2)) mem[x][LEFT(A2)->vl] = cx;
  merge(A2, cx, A2);
  if (cnt(B2) && LEFT(B2)->vl != y) mem[y][LEFT(B2)->vl] = cy;
  if (!(!cnt(B2) && LEFT(B1)->vl == y)) merge(B2, cy, B2);
  pnode rgt = RIGHT(A1);
  if (cnt(B2)) mem[rgt->vl][LEFT(B2)->vl] = rgt;
  merge(A, A1, B2);
  if (cnt(A)) {
    rgt = RIGHT(A);
    if (cnt(B1)) mem[rgt->vl][LEFT(B1)->vl] = rgt;
  }
  merge(A, A, B1);
  rgt = RIGHT(A);
  if (cnt(A2)) mem[rgt->vl][LEFT(A2)->vl] = rgt;
  merge(A, A, A2);
}
void cut(int x, int y) {
  pnode n1 = mem[x][y];
  pnode n2 = mem[y][x];
  mem[x].erase(y);
  mem[y].erase(x);
  int ind1 = get_ind(n1);
  int ind2 = get_ind(n2);
  if (ind1 > ind2) {
    swap(ind1, ind2);
    swap(x, y);
    swap(n1, n2);
  }
  A = get_root(n1);
  split(A, A, A2, ind2);
  split(A, A1, B, ind1);
  if (LEFT(A2) == pt[x])
    split(A1, A1, BAD, cnt(A1) - 1);
  else
    split(A2, BAD, A2, 1);
  if (cnt(A1) && cnt(A2)) {
    pnode rgt = RIGHT(A1);
    mem[rgt->vl][LEFT(A2)->vl] = rgt;
  }
  merge(A, A1, A2);
}
pair<int, int> st[4 * N];
int psh[4 * N], n, m, obr[N];
void build(int v, int l, int r) {
  if (l == r) {
    psh[v] = 0;
    st[v] = {0, 1};
    return;
  }
  int md = (l + r) >> 1;
  build(v + v, l, md);
  build(v + v + 1, md + 1, r);
  st[v] = combine(st[v + v], st[v + v + 1]);
}
void push(int v) {
  if (psh[v] != 0) {
    st[v].first += psh[v];
    if (v + v + 1 < 4 * N) {
      psh[v + v] += psh[v];
      psh[v + v + 1] += psh[v];
    }
    psh[v] = 0;
  }
}
void update(int v, int tl, int tr, int l, int r, int vl) {
  push(v);
  if (l > r) return;
  if (tl == l && tr == r) {
    psh[v] += vl;
    push(v);
    return;
  }
  int md = (tl + tr) >> 1;
  update(v + v, tl, md, l, min(r, md), vl);
  update(v + v + 1, md + 1, tr, max(l, md + 1), r, vl);
  st[v] = combine(st[v + v], st[v + v + 1]);
}
pair<int, int> min(int v, int tl, int tr, int l, int r) {
  push(v);
  if (l > r) return {oo, 0};
  if (tl == l && tr == r) return st[v];
  int md = (tl + tr) >> 1;
  pair<int, int> n1 = min(v + v, tl, md, l, min(r, md));
  pair<int, int> n2 = min(v + v + 1, md + 1, tr, max(md + 1, l), r);
  return combine(n1, n2);
}
bool good(int l, int r) {
  int x = obr[r] / m, y = obr[r] % m;
  int cx, cy;
  vc.clear();
  if (x < n - 1) {
    cx = x + 1;
    cy = y;
    int nw = a[cx * m + cy];
    if (nw >= l && nw < r) vc.push_back(get_root(pt[nw]));
  }
  if (x > 0) {
    cx = x - 1;
    cy = y;
    int nw = a[cx * m + cy];
    if (nw >= l && nw < r) vc.push_back(get_root(pt[nw]));
  }
  if (y < m - 1) {
    cx = x;
    cy = y + 1;
    int nw = a[cx * m + cy];
    if (nw >= l && nw < r) vc.push_back(get_root(pt[nw]));
  }
  if (y > 0) {
    cx = x;
    cy = y - 1;
    int nw = a[cx * m + cy];
    if (nw >= l && nw < r) vc.push_back(get_root(pt[nw]));
  }
  for (int i = 0; i < int(vc.size()); i++)
    for (int j = i + 1; j < int(vc.size()); j++)
      if (vc[i] == vc[j]) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n * m; i++) {
    cin >> a[i];
    a[i]--;
    obr[a[i]] = i;
  }
  long long ans = 0ll;
  build(1, 0, n * m - 1);
  for (int i = 0; i < n * m; i++) pt[i] = new node(i);
  for (int r = 0, l = 0; r < n * m; r++) {
    while (!good(l, r)) {
      int x = obr[l] / m, y = obr[l] % m;
      int cx, cy;
      if (x < n - 1) {
        cx = x + 1;
        cy = y;
        int nw = a[cx * m + cy];
        if (nw >= l && nw < r) cut(nw, l);
      }
      if (x > 0) {
        cx = x - 1;
        cy = y;
        int nw = a[cx * m + cy];
        if (nw >= l && nw < r) cut(nw, l);
      }
      if (y < m - 1) {
        cx = x;
        cy = y + 1;
        int nw = a[cx * m + cy];
        if (nw >= l && nw < r) cut(nw, l);
      }
      if (y > 0) {
        cx = x;
        cy = y - 1;
        int nw = a[cx * m + cy];
        if (nw >= l && nw < r) cut(nw, l);
      }
      l++;
    }
    update(1, 0, n * m - 1, 0, r, 1);
    int x = obr[r] / m, y = obr[r] % m;
    int cx, cy;
    if (x < n - 1) {
      cx = x + 1;
      cy = y;
      int nw = a[cx * m + cy];
      if (nw >= l && nw < r) {
        link(nw, r);
        update(1, 0, n * m - 1, 0, nw, -1);
      }
    }
    if (x > 0) {
      cx = x - 1;
      cy = y;
      int nw = a[cx * m + cy];
      if (nw >= l && nw < r) {
        link(nw, r);
        update(1, 0, n * m - 1, 0, nw, -1);
      }
    }
    if (y < m - 1) {
      cx = x;
      cy = y + 1;
      int nw = a[cx * m + cy];
      if (nw >= l && nw < r) {
        link(nw, r);
        update(1, 0, n * m - 1, 0, nw, -1);
      }
    }
    if (y > 0) {
      cx = x;
      cy = y - 1;
      int nw = a[cx * m + cy];
      if (nw >= l && nw < r) {
        link(nw, r);
        update(1, 0, n * m - 1, 0, nw, -1);
      }
    }
    ans += min(1, 0, n * m - 1, l, r).second;
  }
  cout << ans;
  return 0;
}
