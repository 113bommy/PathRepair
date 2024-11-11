#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20);
const int mod = (int)1e9 + 7;
const int mod_inv_2 = 500000004;
template <class T>
struct fenwick_range_update {
  int sz;
  T tr[MAXN];
  void init(int _sz) {
    sz = _sz + 1;
    memset(tr, 0, sizeof(tr));
  }
  T query(int idx) {
    T ans = 0;
    for (; idx >= 1; idx -= (idx & -idx)) ans += tr[idx];
    return ans;
  }
  void update(int idx, T val) {
    if (idx <= 0) return;
    for (; idx <= sz; idx += (idx & -idx)) tr[idx] += val;
  }
  void update(int l, int r, T val) {
    update(l, val);
    update(r + 1, -val);
  }
};
template <class T>
struct fenwick {
  int sz;
  fenwick_range_update<T> t0, t1;
  void init(int _sz) {
    sz = _sz;
    t0.init(sz + 1);
    t1.init(sz + 1);
  }
  void update(int l, int r, T val) {
    t0.update(l, r, val);
    t1.update(l, r, -(l - 1) * val);
    t1.update(r + 1, sz, (r - l + 1) * val);
  }
  T query(int idx) { return t0.query(idx) * idx + t1.query(idx); }
  T query(int l, int r) { return query(r) - query(l - 1); }
};
int64_t fact[MAXN];
inline int64_t inv_cnt(int64_t n) {
  return (((n * (n - 1ll) / 2ll) % mod) * ((fact[n] * mod_inv_2) % mod)) % mod;
}
int n;
int p[MAXN];
void read() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
}
fenwick<int64_t> t, g;
void solve() {
  fact[0] = 1;
  for (int64_t i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % mod;
  int64_t invs = 0, bef = 0, ans = 0;
  g.init(n + 1);
  for (int i = 1; i <= n; i++) g.update(p[i], p[i], 1);
  t.init(n + 1);
  for (int i = 1; i <= n; i++) {
    int64_t cnt_less = g.query(1, p[i] - 1);
    int64_t cnt_perms = (cnt_less * fact[n - i]) % mod;
    ans = (ans + cnt_less * inv_cnt(n - i)) % mod;
    ans =
        (ans + ((cnt_less * (cnt_less - 1ll) / 2ll) % mod) * fact[n - i]) % mod;
    ans = (ans + invs * cnt_perms) % mod;
    ans = (ans + bef * cnt_perms) % mod;
    invs = (invs + t.query(p[i], n)) % mod;
    bef = (bef - t.query(p[i], n) + mod + g.query(1, p[i] - 1)) % mod;
    t.update(p[i], p[i], 1);
    g.update(p[i], p[i], -1);
  }
  ans = (ans + invs) % mod;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
