#include <bits/stdc++.h>
using namespace std;
template <class T>
struct rge {
  T b, e;
};
template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
};
template <class A, class B>
ostream &operator<<(ostream &os, pair<A, B> p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, rge<T> d) {
  os << "[";
  for (auto it = d.b; it != d.e; it++) os << (it == d.b ? "" : ", ") << *it;
  return os << "]";
}
const int K = 10;
struct scc {
  vector<int> mn, mx;
  int sz;
  scc(vector<int> power) {
    for (int x : power) mn.push_back(x), mx.push_back(x);
    sz = 1;
  }
  bool operator<(const scc &cc) const {
    for (int i = (0); i <= (((int)(mn).size()) - 1); i += (+1))
      if (mx[i] >= cc.mn[i]) return false;
    return true;
  }
};
set<scc> st;
vector<int> power;
int n, k;
scc unite(scc a, scc b) {
  scc c = a;
  c.sz += b.sz;
  for (int i = (0); i <= ((k)-1); i += (+1)) {
    c.mn[i] = min(c.mn[i], b.mn[i]);
    c.mx[i] = min(c.mx[i], b.mx[i]);
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
  while (cin >> n >> k) {
    st.clear();
    power.resize(k);
    for (int i = (0); i <= ((n)-1); i += (+1)) {
      for (auto &x : power) cin >> x;
      scc cur(power);
      auto it = st.lower_bound(cur), jt = st.upper_bound(cur);
      while (it != jt) {
        cur = unite(cur, *it);
        it = st.erase(it);
      }
      st.insert(cur);
      cout << st.rbegin()->sz << '\n';
    }
  }
  return 0;
}
