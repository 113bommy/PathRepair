#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
class {
 public:
  pair<long long, long long> T[200009 << 2];
  long long lz[200009 << 2];
  long long n, f[200009], ans[200009];
  void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i];
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
      auto res = query(1, 1, n, 1, n);
      ans[res.second] = i;
      update(1, 1, n, res.second + 1, n, -i);
      update(1, 1, n, res.second, res.second, 1e18);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  }
  void build(int rt, int l, int r) {
    lz[rt] = 0;
    if (l == r) {
      T[rt] = {f[l], l};
      return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    up(rt);
  }
  void up(int rt) {
    if (T[rt << 1].first == T[rt << 1 | 1].first) {
      T[rt] = T[rt << 1 | 1];
    } else {
      T[rt] = min(T[rt << 1], T[rt << 1 | 1]);
    }
  }
  void update(int rt, int l, int r, int ll, int rr, int v) {
    if (ll > rr) return;
    if (ll <= l && rr >= r) {
      lz[rt] += v;
      T[rt].first += v;
      return;
    }
    int mid = l + r >> 1;
    down(rt);
    if (ll <= mid) update(rt << 1, l, mid, ll, rr, v);
    if (rr > mid) update(rt << 1 | 1, mid + 1, r, ll, rr, v);
    up(rt);
  }
  pair<long long, long long> query(int rt, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
      return T[rt];
    }
    int mid = l + r >> 1;
    down(rt);
    pair<long long, long long> res = {1e18, 1e18};
    if (ll <= mid) {
      pair<long long, long long> ret = query(rt << 1, l, mid, ll, rr);
      if (ret.first == res.first)
        res.second = ret.second;
      else
        res = min(res, ret);
    }
    if (rr > mid) {
      pair<long long, long long> ret = query(rt << 1 | 1, mid + 1, r, ll, rr);
      if (ret.first == res.first)
        res.second = ret.second;
      else
        res = min(res, ret);
    }
    return res;
  }
  void down(int rt) {
    if (lz[rt]) {
      T[rt << 1].first += lz[rt];
      lz[rt << 1] += lz[rt];
      T[rt << 1 | 1].first += lz[rt];
      lz[rt << 1 | 1] += lz[rt];
      lz[rt] = 0;
    }
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
