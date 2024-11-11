#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12;
struct point {
  long double first, second;
  point(long double _x = 0, long double _y = 0) : first(_x), second(_y) {}
  point operator+(const point &r) const {
    return point(first + r.first, second + r.second);
  }
  point operator-(const point &r) const {
    return point(first - r.first, second - r.second);
  }
  point operator*(long double d) const { return point(first * d, second * d); }
  long double operator/(const point &r) const {
    return first * r.second - r.first * second;
  }
};
struct line {
  point p, q;
  int ind;
  line(point _p, point _q, int _ind) : p(_p), q(_q), ind(_ind) {}
};
point interPnt(line l, line l2, bool &res) {
  long double f = (l.q - l.p) / (l2.p - l.p);
  long double f2 = (l.q - l.p) / (l.p - l2.q);
  long double s = f + f2;
  if (fabs(s) < EPS) {
    res = false;
    return {0, 0};
  }
  res = true;
  return l2.p * (f2 / s) + l2.q * (f / s);
}
bool isin(line l, line l1, line l2) {
  bool res;
  point p = interPnt(l1, l2, res);
  return (l.q - l.p) / (p - l.p) > EPS;
}
vector<line> halfPlaneInter(vector<line> lines) {
  int n = lines.size();
  vector<long double> ata(n), ord(n);
  for (int i = 0; i < n; i++) {
    ord[i] = i;
    point d = lines[i].q - lines[i].p;
    ata[i] = atan2(d.second, d.first);
  }
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    if (abs(ata[i] - ata[j]) < EPS) {
      return (lines[i].q - lines[i].p) / (lines[j].q - lines[i].p) < 0;
    }
    return ata[i] < ata[j];
  });
  vector<line> fin;
  for (int i = 0; i < n; i++) {
    if (!i || fabs(ata[ord[i]] - ata[ord[i - 1]]) > EPS) {
      fin.push_back(lines[ord[i]]);
    }
  }
  deque<line> dq;
  for (int i = 0; i < fin.size(); i++) {
    while (dq.size() >= 2 &&
           !isin(fin[i], dq[dq.size() - 2], dq[dq.size() - 1]))
      dq.pop_back();
    while (dq.size() >= 2 && !isin(fin[i], dq[0], dq[1])) dq.pop_front();
    dq.push_back(fin[i]);
  }
  while (dq.size() >= 3 && !isin(dq[0], dq[dq.size() - 2], dq[dq.size() - 1]))
    dq.pop_back();
  while (dq.size() >= 3 && !isin(dq[dq.size() - 1], dq[0], dq[1]))
    dq.pop_front();
  vector<line> res(dq.begin(), dq.end());
  return res;
}
struct node {
  node *lc, *rc;
  vector<line> v;
  int l, r;
  node() { lc = rc = NULL; }
};
struct st {
  node *root;
  st(const vector<line> &v) { root = build(0, v.size() - 1, v); }
  node *build(int l, int r, const vector<line> &v) {
    node *res = new node;
    res->l = l, res->r = r;
    res->v = vector<line>(v.begin() + l, v.begin() + r + 1);
    res->v = halfPlaneInter(res->v);
    reverse(res->v.begin(), res->v.end());
    if (l < r) {
      int m = (l + r) / 2;
      res->lc = build(l, m, v);
      res->rc = build(m + 1, r, v);
    }
    return res;
  }
  pair<int, long double> query(node *p, int l, int r, long double t) {
    if (p->l == l && p->r == r) {
      bool tmp;
      while (p->v.size() >= 2 &&
             interPnt(p->v.back(), p->v[p->v.size() - 2], tmp).first <= t + EPS)
        p->v.pop_back();
      pair<int, long double> res;
      line &L = p->v.back();
      return {L.ind, L.p.second + (L.q.second - L.p.second) * t};
    } else if (r <= p->lc->r)
      return query(p->lc, l, r, t);
    else if (p->rc->l <= l)
      return query(p->rc, l, r, t);
    else {
      auto res = query(p->lc, l, p->lc->r, t);
      auto tmp = query(p->rc, p->rc->l, r, t);
      return res.second >= tmp.second ? res : tmp;
    }
  }
  int query(int l, int r, long double t) { return query(root, l, r, t).first; }
};
struct query {
  int l, r, ind;
  long double t;
  bool operator<(const query &r) const { return t < r.t; }
};
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<line> v;
  for (int i = 0; i < n; i++) {
    long double a, b;
    scanf("%Lf%Lf", &a, &b);
    v.push_back(line(point(0, a), point(1, a + b), i));
  }
  st T(v);
  vector<int> ans(q);
  vector<query> Q(q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%Lf", &Q[i].l, &Q[i].r, &Q[i].t);
    Q[i].l--, Q[i].r--;
    Q[i].ind = i;
  }
  sort(Q.begin(), Q.end());
  for (auto &t : Q) ans[t.ind] = T.query(t.l, t.r, t.t);
  for (int t : ans) printf("%d\n", t + 1);
}
