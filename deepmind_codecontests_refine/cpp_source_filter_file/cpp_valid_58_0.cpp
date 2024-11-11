#include <bits/stdc++.h>
using namespace std;
struct BIT {
  vector<long long> bit;
  long long n;
  BIT(long long size) {
    n = size + 1;
    bit.assign(n, 0);
  }
  void upd(long long pos, long long val) {
    for (++pos; pos < n; pos += pos & -pos) {
      bit[pos] += val;
    }
  }
  long long get(long long pos) {
    long long ret = 0;
    for (++pos; pos > 0; pos -= pos & -pos) {
      ret += bit[pos];
    }
    return ret;
  }
};
const long long mod = 998244353;
long long x[200005], y[200005];
long long pos[200005];
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long fact[200005];
long long ans(long long a, long long b) {
  return fact[a] * binpow(fact[b], mod - 2) % mod *
         binpow(fact[a - b], mod - 2) % mod;
}
BIT bt(200005);
void solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> x[i] >> y[i];
  }
  map<long long, long long> ck;
  for (long long i = m; i >= 1; i--) {
    long long l = 1, r = n;
    while (l < r) {
      long long m = (l + r) / 2;
      if (m - bt.get(m) < y[i]) {
        l = m + 1;
      } else
        r = m;
    }
    pos[i] = l;
    ck[l] = 1;
    bt.upd(l, 1);
  }
  set<long long> s2;
  for (long long i = 1; i <= m; i++) {
    if (!ck[pos[i] + 1]) {
      s2.insert(pos[i] + 1);
    }
  }
  map<long long, long long> mp;
  long long cnt = 0;
  for (long long i = 1; i <= m; i++) {
    long long mini = 1e9;
    if (s2.size() && *s2.rbegin() > pos[i]) {
      mini = min(mini, *s2.upper_bound(pos[i]));
    }
    if (!mp[mini]) cnt++;
    mp[mini] = 1;
    s2.insert(pos[i]);
  }
  for (long long i = 1; i <= m; i++) {
    bt.upd(pos[i], -1);
  }
  cnt = n - 1 - cnt;
  cout << ans(n + cnt, cnt) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = 1;
  for (long long i = 1; i < 2 * 200005; i++) {
    fact[i] = fact[i - 1] * i % mod;
  }
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
