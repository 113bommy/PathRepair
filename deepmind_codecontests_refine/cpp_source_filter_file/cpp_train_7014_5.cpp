#include <bits/stdc++.h>
using namespace std;
class E {
 public:
  int pos, t, type;
  E() {}
  E(int _p, int _t, int _type) {
    pos = _p;
    t = _t;
    type = _type;
  }
  bool operator<(const E& e) const {
    if (pos != e.pos) return pos < e.pos;
    if (type != e.type) return type < e.type;
    return t < e.t;
  }
};
class P {
 public:
  int l, r, t;
  P() {}
  P(int _l, int _r, int _t) {
    l = _l;
    r = _r;
    t = _t;
  }
};
vector<E> a;
multiset<int> h;
vector<P> b;
vector<pair<int, int> > e;
int main(void) {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    int l, r, t;
    scanf("%d%d%d", &l, &r, &t);
    a.push_back(E(l, t, 1));
    a.push_back(E(r, t, -1));
  }
  sort(a.begin(), a.end());
  int lastpos = 0;
  for (int i = 0; i < ((int)(a).size()); i++) {
    if (i && a[i].pos != a[i - 1].pos) {
      if (((int)(h).size())) {
        b.push_back(P(lastpos, a[i].pos, *h.begin()));
      }
    }
    lastpos = a[i].pos;
    if (a[i].type == 1)
      h.insert(a[i].t);
    else
      h.erase(h.find(a[i].t));
  }
  int init = 0, slope = 0;
  for (int i = 0; i < ((int)(b).size()); i++) {
    if (b[i].t <= b[i].l)
      init += b[i].r - b[i].l;
    else if (b[i].t <= b[i].r) {
      init += b[i].r - b[i].t;
      slope++;
      e.push_back(pair<int, int>(b[i].t - b[i].l, 1));
    } else {
      e.push_back(pair<int, int>(b[i].t - b[i].r, b[i].r - b[i].t));
      e.push_back(pair<int, int>(b[i].t - b[i].l, 1));
    }
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    e.push_back(pair<int, int>(x, 0));
  }
  sort(e.begin(), e.end());
  for (int i = 0; i < ((int)(e).size()); i++) {
    if (e[i].second == 0) {
      printf("%d\n", init + slope * e[i].first);
    } else if (e[i].second == 1) {
      init += e[i].first;
      --slope;
    } else {
      init += e[i].second;
      ++slope;
    }
  }
  return 0;
}
