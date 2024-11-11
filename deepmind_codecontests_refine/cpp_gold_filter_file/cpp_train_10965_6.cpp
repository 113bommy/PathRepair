#include <bits/stdc++.h>
using namespace std;
template <class T, class F>
class RangeTree {
  vector<T> _tree;
  vector<T> _dta;
  T neitral;
  F fun;
  const T findon(int on, int l, int r, int lm, int rm) const {
    if ((lm > r) || (l > rm)) return neitral;
    if (lm == rm) {
      return _dta[lm];
    }
    if ((l <= lm) && (r >= rm)) {
      return _tree[on];
    }
    T f, s;
    return fun(findon(on * 2 + 1, l, r, lm, (lm + rm) / 2),
               findon(on * 2 + 2, l, r, (lm + rm) / 2 + 1, rm));
  }
  T& mod(int on, int lm, int rm, int ps, T& nz) {
    if (lm == rm) {
      if (lm == ps) _dta[ps] = nz;
      return _dta[lm];
    }
    if ((lm > ps) || (rm < ps)) return _tree[on];
    _tree[on] = fun(mod(on * 2 + 1, lm, (lm + rm) / 2, ps, nz),
                    mod(on * 2 + 2, (lm + rm) / 2 + 1, rm, ps, nz));
    return _tree[on];
  }

 public:
  const T getF(int left, int right) const {
    if (left > right) return neitral;
    return findon(0, left, right, 0, _dta.size() - 1);
  }
  const T& getElem(int index) const { return _dta[index]; }
  void setElem(int index, T newvalue) {
    mod(0, 0, _dta.size() - 1, index, newvalue);
  }
  RangeTree(int x, T ne) {
    neitral = ne;
    _dta.resize(x, neitral);
    _tree.resize(x * 2, neitral);
    fun = F();
  }
};
template <class T>
struct sum : binary_function<T, T, T> {
  T operator()(const T& x, const T& y) const { return x + y; }
};
template <class T>
struct maxt : binary_function<T, T, T> {
  T operator()(const T& x, const T& y) const { return max(x, y); }
};
template <class T>
class Compress {
  map<T, int> gg;

 public:
  Compress(vector<T> a) {
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
      if (gg.find(a[i]) == gg.end()) {
        int tt = gg.size();
        gg[a[i]] = tt;
      }
    }
  }
  int size() const { return gg.size(); }
  bool isin(const T& a) { return (gg.find() != gg.end()); }
  int lborder(const T& a) {
    typename map<T, int>::iterator x = gg.lower_bound(a);
    if (x == gg.end()) return gg.size();
    return x->second;
  }
};
struct pers {
  int a, r;
};
struct qr {
  int ia, aa, ir;
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<pers> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].r;
  }
  for (int i = 0; i < n; ++i) {
    cin >> p[i].a;
  }
  int qn;
  cin >> qn;
  vector<qr> q(qn);
  for (int i = 0; i < qn; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    q[i].ir = max(p[x].r, p[y].r);
    q[i].ia = max(p[x].a - k, p[y].a - k);
    q[i].aa = min(p[x].a + k, p[y].a + k);
  }
  vector<int> as(n);
  for (int i = 0; i < n; ++i) {
    as[i] = p[i].a;
  }
  Compress<int> sza(as);
  vector<pair<int, int> > rsp;
  for (int i = 0; i < n; ++i) {
    rsp.push_back(make_pair(p[i].r, i));
  }
  sort(rsp.begin(), rsp.end());
  RangeTree<int, sum<int> > fsum(rsp.size(), 0);
  int tu = 0;
  vector<int> la(n);
  while (tu < n) {
    int j = tu;
    for (; (j < n) && (rsp[j].first == rsp[tu].first); ++j) {
      int kk = sza.lborder(p[rsp[j].second].a);
      fsum.setElem(kk, fsum.getElem(kk) + 1);
    }
    for (; tu < j; ++tu) {
      int a = p[rsp[tu].second].a;
      int rr = fsum.getF(sza.lborder(a - k), sza.lborder(a + k + 1) - 1);
      la[rsp[tu].second] = rr;
    }
  }
  vector<pair<int, int> > rsp2;
  for (int i = 0; i < n; ++i) rsp2.push_back(make_pair(p[i].r, i));
  for (int i = 0; i < qn; ++i) rsp2.push_back(make_pair(q[i].ir, -i - 1));
  sort(rsp2.rbegin(), rsp2.rend());
  vector<int> ans(qn);
  RangeTree<int, maxt<int> > fm(rsp.size(), -1);
  for (int i = 0; i < rsp2.size(); ++i) {
    if (rsp2[i].second >= 0) {
      int cc = sza.lborder(p[rsp2[i].second].a);
      fm.setElem(cc, max(fm.getElem(cc), la[rsp2[i].second]));
    } else {
      int qi = -(rsp2[i].second + 1);
      int lg = sza.lborder(q[qi].ia);
      int rg = sza.lborder(q[qi].aa + 1) - 1;
      ans[qi] = fm.getF(lg, rg);
    }
  }
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
  return 0;
}
