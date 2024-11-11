#include <bits/stdc++.h>
using namespace std;
struct Seg {
  long long int l, r;
  mutable long long int v;
  Seg(long long int ll, long long int rr = -1, long long int vv = 0)
      : l(ll), r(rr), v(vv) {}
  bool operator<(const Seg& o) const { return l < o.l; }
};
long long int rnd();
long long int pow(long long int b, long long int e);
set<Seg> st;
set<Seg>::iterator split(long long int pos) {
  auto it = st.lower_bound(Seg(pos));
  if (it != st.end() && it->l == pos) return it;
  --it;
  if (pos >= it->r) return st.end();
  long long int L = it->l, R = it->r, V = it->v;
  st.erase(it);
  st.insert(Seg(L, pos, V));
  return st.insert(Seg(pos, R, V)).first;
}
void add(long long int l, long long int r, long long int val) {
  split(l), split(r);
  auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
  for (; il != ir; ++il) {
    il->v += val;
  }
}
void flat(long long int l, long long int r, long long int val) {
  split(l), split(r);
  auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
  long long int L = il->l, R = ir->r;
  st.erase(il, ir);
  st.insert(Seg(l, r, val));
}
long long int getkth(long long int l, long long int r, long long int x) {
  vector<pair<long long int, long long int> > v;
  split(l), split(r);
  auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
  for (; il != ir; il++) {
    v.push_back({il->v, (il->r - il->l)});
  }
  sort(v.begin(), v.end());
  long long int k = x;
  for (pair<long long int, long long int> p : v) {
    k -= p.second;
    if (k <= 0) return p.first;
  }
  return -1;
}
long long int powsum(long long int l, long long int r, long long int x,
                     long long int y) {
  long long int ans = 0;
  split(l), split(r);
  auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
  for (; il != ir; il++) {
    ans = (ans + pow(il->v % y, x) * (il->r - il->l) % y) % y;
  }
  return ans;
}
void disp() {
  for (auto s : st) {
    printf("(%lld, %lld): %lld\n", s.l, s.r, s.v);
  }
  cout << endl;
}
long long int n, m, seed, vmax, a[100005], op, l, r, x, y, rxxx;
signed main() {
  cin >> n >> m >> seed >> vmax;
  for (long long int i = 1; i <= n; i++) {
    a[i] = (rnd() % vmax) + 1;
  }
  for (long long int i = 1; i <= n; i++) {
    long long int r = i;
    while (r <= n && a[r] == a[i]) {
      r++;
    }
    st.insert(Seg(i, r, a[i]));
    i += (r - i) - 1;
  }
  for (long long int i = 0; i < m; i++) {
    op = (rnd() % 4) + 1;
    l = (rnd() % n) + 1;
    r = (rnd() % n) + 1;
    if (l > r) swap(l, r);
    if (op == 3)
      x = (rnd() % (r - l + 1)) + 1;
    else
      x = (rnd() % vmax) + 1;
    if (op == 4) y = (rnd() % vmax) + 1;
    if (op < 4) {
    } else {
    }
    if (op == 1) {
      add(l, r + 1, x);
    } else if (op == 2) {
      flat(l, r + 1, x);
    } else if (op == 3) {
      cout << getkth(l, r + 1, x) << '\n';
    } else if (op == 4) {
      cout << powsum(l, r + 1, x, y) << '\n';
    }
  }
}
long long int pow(long long int b, long long int e) {
  if (!b) return 0;
  if (!e) return 1;
  long long int res = pow(b, e / 2);
  res = res * res % y;
  if (e % 2) res = res * b % y;
  return res;
}
long long int rnd() {
  rxxx = seed;
  seed = (seed * 7 + 13) % 1000000007;
  return rxxx;
}
