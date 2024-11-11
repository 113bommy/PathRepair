#include <bits/stdc++.h>
using namespace std;
struct nd {
  nd *l, *r;
  int cp;
};
nd lmmlc[4000005];
int mlci;
nd *newnd() { return lmmlc + mlci++; }
nd *ap(nd *i, int rs, int re, int qi) {
  nd *res = newnd();
  if (i) *res = *i;
  if (rs + 1 == re)
    res->cp++;
  else {
    int md = (rs + re) / 2;
    if (qi < md)
      res->l = ap(res->l, rs, md, qi);
    else
      res->r = ap(res->r, md, re, qi);
    res->cp = 0;
    if (res->l) res->cp += res->l->cp;
    if (res->r) res->cp += res->r->cp;
  }
  return res;
}
int hp(nd *i, int rs, int re, int qs, int qe) {
  if (!i) return 0;
  if (rs == qs && re == qe)
    return i->cp;
  else {
    int md = (rs + re) / 2;
    int res = 0;
    if (qs < md) res += hp(i->l, rs, md, qs, min(qe, md));
    if (qe > md) res += hp(i->r, md, re, max(qs, md), qe);
    return res;
  }
}
int n, k;
pair<int, int> d[100005];
pair<int, int> s[100005];
vector<int> cx, cy;
nd *rt[100005];
vector<int> ev[100005];
pair<int, int> o[100005];
bool rq(int lx, int rx, int ly, int ry) {
  lx = lower_bound(cx.begin(), cx.end(), lx) - cx.begin();
  rx = upper_bound(cx.begin(), cx.end(), rx) - cx.begin() - 1;
  ly = lower_bound(cy.begin(), cy.end(), ly) - cy.begin();
  ry = upper_bound(cy.begin(), cy.end(), ry) - cy.begin() - 1;
  return hp(rt[rx], 0, int(cy.size()), ly, ry + 1) -
             hp(rt[lx - 1], 0, int(cy.size()), ly, ry + 1) >
         0;
}
pair<int, int> ocd[200005];
int b[200005];
void ub(int i, int v) {
  for (i++; i < 200005; i += i & -i) b[i] = max(b[i], v);
}
int qb(int i) {
  int v = -1e9;
  for (i++; i > 0; i -= i & -i) v = max(v, b[i]);
  return v;
}
void calcdists() {
  for (int i = (0); i < (n); i++) o[i] = {4e8 + 5, i};
  for (int Z = (0); Z < (4); Z++) {
    for (int i = (0); i < (n); i++) d[i] = {d[i].second, -d[i].first};
    for (int i = (0); i < (k); i++) s[i] = {s[i].second, -s[i].first};
    for (int i = (0); i < (200005); i++) b[i] = -1e9;
    vector<int> first;
    for (int i = (0); i < (n); i++) first.push_back(d[i].first);
    for (int i = (0); i < (k); i++) first.push_back(s[i].first);
    sort(first.begin(), first.end());
    first.resize(unique(first.begin(), first.end()) - first.begin());
    for (int i = (0); i < (n); i++) ocd[i] = make_pair(d[i].second, i);
    for (int i = (0); i < (k); i++) ocd[i + n] = make_pair(s[i].second, ~i);
    sort(ocd, ocd + n + k);
    for (int j = (0); j < (n + k); j++) {
      int i = ocd[j].second;
      if (i < 0) {
        i = ~i;
        ub(lower_bound(first.begin(), first.end(), s[i].first) - first.begin(),
           s[i].first + s[i].second);
      } else {
        int qa = qb(lower_bound(first.begin(), first.end(), d[i].first) -
                    first.begin());
        o[i].first = min(o[i].first, d[i].first + d[i].second - qa);
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = (0); i < (n); i++) {
    scanf("%d %d", &d[i].second, &d[i].first);
  }
  for (int i = (0); i < (k); i++) {
    scanf("%d %d", &s[i].second, &s[i].first);
  }
  calcdists();
  for (int i = (0); i < (n); i++)
    d[i] = {d[i].second + d[i].first, d[i].second - d[i].first};
  for (int i = (0); i < (k); i++)
    s[i] = {s[i].second + s[i].first, s[i].second - s[i].first};
  for (int i = (0); i < (k); i++) {
    cx.push_back(s[i].second);
    cy.push_back(s[i].first);
  }
  cx.push_back(-1e9);
  cx.push_back(1e9);
  cy.push_back(-1e9);
  cy.push_back(1e9);
  sort(cx.begin(), cx.end());
  cx.resize(unique(cx.begin(), cx.end()) - cx.begin());
  sort(cy.begin(), cy.end());
  cy.resize(unique(cy.begin(), cy.end()) - cy.begin());
  for (int i = (0); i < (k); i++) {
    int ci = lower_bound(cx.begin(), cx.end(), s[i].second) - cx.begin();
    ev[ci].push_back(i);
  }
  for (int i = (1); i < (int(cx.size())); i++) {
    rt[i] = rt[i - 1];
    for (int j : ev[i]) {
      int ci = lower_bound(cy.begin(), cy.end(), s[j].first) - cy.begin();
      rt[i] = ap(rt[i], 0, int(cy.size()), ci);
    }
  }
  sort(o, o + n, greater<pair<int, int> >());
  int s = 0, e = 4e8 + 3, b = 4e8 + 3;
  while (s <= e) {
    int md = (s + e) / 2;
    int lx = -2e8 + 5, rx = 2e8 + 5;
    int ly = -2e8 + 5, ry = 2e8 + 5;
    bool good = false;
    for (int j = (0); j < (n); j++) {
      int i = o[j].second;
      int r = md - o[j].first;
      if (r >= 0) {
        good |= rq(lx - r, rx + r, ly - r, ry + r);
        if (good) break;
      }
      lx = max(lx, d[i].second - md);
      rx = min(rx, d[i].second + md);
      ly = max(ly, d[i].first - md);
      ry = min(ry, d[i].first + md);
      if (lx > rx || ly > ry) break;
    }
    good |= lx <= rx && ly <= ry;
    if (good) {
      b = md;
      e = md - 1;
    } else {
      s = md + 1;
    }
  }
  printf("%d\n", b);
}
