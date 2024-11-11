#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 7;
const long long mod = 998244353;
const long long INF = 1e9 + 7;
const long long mlog = 20;
const long long SQ = 400;
long long seg[maxn * 4], Add[maxn * 4], Mul[maxn * 4];
set<pair<pair<long long, long long>, long long>> st[maxn];
long long n, q;
void split(long long val, long long x) {
  auto it = --st[val].upper_bound({{x, +INF}, 0});
  pair<long long, long long> p = it->first;
  long long tmp = it->second;
  if (p.first == x) return;
  st[val].erase(it);
  st[val].insert({{p.first, x}, tmp});
  st[val].insert({{x, p.second}, tmp});
}
void add_lazy(long long s, long long e, long long id, long long mul,
              long long add) {
  seg[id] = (seg[id] * mul) % mod + ((e - s) * add) % mod;
  Mul[id] = (Mul[id] * mul) % mod;
  Add[id] = ((Add[id] * mul) + add) % mod;
}
void shift(long long s, long long e, long long id) {
  long long mid = (s + e) / 2;
  add_lazy(s, mid, id * 2 + 0, Mul[id], Add[id]);
  add_lazy(mid, e, id * 2 + 1, Mul[id], Add[id]);
  Mul[id] = 1;
  Add[id] = 0;
}
void UPDATE(long long l, long long r, long long mul, long long add,
            long long s = 1, long long e = n + 1, long long id = 1) {
  if (l >= e || r <= s) return;
  if (l <= s && r >= e) {
    add_lazy(s, e, id, mul, add);
    return;
  }
  shift(s, e, id);
  long long mid = (s + e) / 2;
  UPDATE(l, r, mul, add, s, mid, id * 2 + 0);
  UPDATE(l, r, mul, add, mid, e, id * 2 + 1);
  seg[id] = (seg[id * 2 + 0] + seg[id * 2 + 1]) % mod;
}
long long GET(long long l, long long r, long long s = 1, long long e = n + 1,
              long long id = 1) {
  if (l >= e || r <= s) return 0;
  if (l <= s && r >= e) return seg[id];
  shift(s, e, id);
  long long mid = (s + e) / 2;
  return (GET(l, r, s, mid, id * 2 + 0) + GET(l, r, mid, e, id * 2 + 1)) % mod;
}
void ADD(long long l, long long r, long long x) {
  split(x, l), split(x, r);
  while (true) {
    auto it = st[x].lower_bound({{l, l}, 0});
    if (it == st[x].end() || it->first.first == r) break;
    pair<long long, long long> p = it->first;
    if (it->second)
      UPDATE(p.first, p.second, 2, 0);
    else
      UPDATE(p.first, p.second, 1, 1);
    st[x].erase(it);
  }
  st[x].insert({{l, r}, 1});
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(), cout.tie();
  ;
  cin >> n >> q;
  for (long long i = 0; i < maxn; i++) st[i].insert({{1, n + 1}, 0});
  while (q--) {
    long long t, l, r;
    cin >> t >> l >> r;
    r++;
    if (t == 1) {
      long long x;
      cin >> x;
      ADD(l, r, x);
    }
    if (t == 2) {
      cout << GET(l, r) << "\n";
    }
  }
  return 0;
}
