#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 43;
const long long INF = 1e9;
long long st[N << 2];
vector<long long> a;
long long n;
void build(long long id, long long l, long long r) {
  if (l == r) {
    st[id] = 1;
    return;
  }
  long long mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  st[id] = st[id * 2] + st[id * 2 + 1];
}
void update(long long id, long long l, long long r, long long p,
            long long val) {
  if (l == r) {
    st[id] = val;
    return;
  }
  long long mid = (l + r) / 2;
  if (p <= mid)
    update(id * 2, l, mid, p, val);
  else
    update(id * 2 + 1, mid + 1, r, p, val);
  st[id] = st[id * 2] + st[id * 2 + 1];
}
long long rsq(long long id, long long l, long long r, long long u,
              long long v) {
  if (u <= l && r <= v) return st[id];
  if (v < l || r < u) return 0;
  long long mid = (l + r) / 2;
  return rsq(id * 2, l, mid, u, v) + rsq(id * 2 + 1, mid + 1, r, u, v);
}
map<long long, set<long long>> process;
inline void input() {
  cin >> n;
  a.resize(n + 1);
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    process[a[i]].insert(i);
  }
}
void preprocess() {}
set<long long> fset;
void solve() {
  build(1, 1, n);
  long long currpos = 0;
  long long ans = 0;
  for (auto &p : process) {
    while (!p.second.empty()) {
      long long now;
      auto it = p.second.upper_bound(currpos);
      if (it != p.second.end()) {
        now = (*it);
        p.second.erase(it);
      } else {
        now = *(p.second.begin());
        p.second.erase(p.second.begin());
      }
      if (now >= currpos) {
        ans += rsq(1, 1, n, currpos, now);
      } else {
        ans += rsq(1, 1, n, currpos, n) + rsq(1, 1, n, 1, now);
      }
      currpos = now;
      update(1, 1, n, now, 0);
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  input();
  preprocess();
  solve();
  return 0;
}
