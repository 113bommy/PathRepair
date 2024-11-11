#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 7 + 1e9;
int n, m, seed, vmax;
vector<pair<ll, int> > ve;
struct node {
  int l, r;
  mutable ll val;
  int operator<(const node& a) const { return l < a.l; }
  node(int L, int R, ll Val) : l(L), r(R), val(Val) {}
  node(int L) : l(L) {}
};
set<node> s;
set<node>::iterator Split(int pos) {
  set<node>::iterator it = s.lower_bound(node(pos));
  if (it != s.end() && it->l == pos) return it;
  --it;
  int l = it->l, r = it->r;
  int val = it->val;
  s.erase(it);
  s.insert(node(l, pos - 1, val));
  return s.insert(node(pos, r, val)).first;
}
int rnd() {
  int ret = seed;
  seed = (7LL * seed + 13) % mod;
  return ret;
}
ll qpow(ll q, ll n, ll mod) {
  ll ans = 1 % mod;
  while (n) {
    if (n & 1) ans = ans * q % mod;
    q = q * q % mod;
    n >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &seed, &vmax);
  for (int i = 1; i <= n; ++i) s.insert(node(i, i, rnd() % vmax + 1));
  int op, l, r, x, y;
  for (int i = 1; i <= m; ++i) {
    op = rnd() % 4 + 1;
    l = rnd() % n + 1;
    r = rnd() % n + 1;
    if (l > r) swap(l, r);
    if (op == 3)
      x = rnd() % (r - l + 1) + 1;
    else
      x = rnd() % vmax + 1;
    if (op == 4) y = rnd() % vmax + 1;
    if (op == 1) {
      set<node>::iterator R = Split(r + 1), L = Split(l);
      for (set<node>::iterator it = L; it != R; ++it) {
        it->val += x;
      }
    } else if (op == 2) {
      set<node>::iterator R = Split(r + 1), L = Split(l);
      s.erase(L, R);
      s.insert(node(l, r, x));
    } else if (op == 3) {
      set<node>::iterator R = Split(r + 1), L = Split(l);
      ve.clear();
      for (set<node>::iterator it = L; it != R; ++it) {
        ve.push_back(make_pair(it->val, it->r - it->l + 1));
      }
      sort(ve.begin(), ve.end());
      ll ans = 0;
      for (int i = 0; i < ve.size(); ++i) {
        x -= ve[i].second;
        if (x <= 0) {
          ans = ve[i].first;
          break;
        }
      }
      printf("%lld\n", ans);
    } else {
      set<node>::iterator R = Split(r + 1), L = Split(l);
      ll ans = 0;
      for (set<node>::iterator it = L; it != R; ++it) {
        ans += qpow(it->val % y, x, y) * (it->r - it->l + 1) % mod;
      }
      printf("%lld\n", ans % y);
    }
  }
  return 0;
}
