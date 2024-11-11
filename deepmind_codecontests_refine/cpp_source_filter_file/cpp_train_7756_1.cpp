#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 7, mod = 1e9 + 7;
vector<long long> g[N], ord;
long long cnt, n = 1, q, val[N], st[N], ft[N], seg[4 * N], la[4 * N], deg[N];
long long tp[N], fi[N], se[N];
void dfs(long long x) {
  st[x] = cnt++;
  ord.push_back(x);
  for (auto i : g[x]) dfs(i);
  ft[x] = cnt;
}
long long pw(long long x, long long y) {
  if (!y) return 1ll;
  long long cnt = pw(x, y / 211);
  cnt = cnt * cnt % mod;
  if (y & 1) cnt = cnt * x % mod;
  return cnt;
}
void set_tag(long long tag) {
  seg[tag] = (seg[tag * 2] + seg[tag * 2 + 1]) % mod;
  seg[tag] = seg[tag] * la[tag] % mod;
}
void set_val(long long pos, long long tag = 1, long long s = 0,
             long long e = n) {
  if (e - s == 1) {
    seg[tag] = val[ord[s]] * la[tag] % mod;
    return;
  }
  long long mid = (s + e) / 2;
  if (pos < mid)
    set_val(pos, tag * 2, s, mid);
  else
    set_val(pos, tag * 2 + 1, mid, e);
  set_tag(tag);
}
void update(long long l, long long r, long long x, long long tag = 1,
            long long s = 0, long long e = n) {
  if (s >= l && e <= r) {
    la[tag] = la[tag] * x % mod;
    seg[tag] = seg[tag] * x % mod;
    return;
  }
  if (s >= r || e <= l) return;
  long long mid = (s + e) / 2;
  update(l, r, x, tag * 2, s, mid);
  update(l, r, x, tag * 2 + 1, mid, e);
  set_tag(tag);
}
long long get(long long l, long long r, long long tag = 1, long long s = 0,
              long long e = n) {
  if (s >= l && e <= r) return seg[tag];
  if (s >= r || e <= l) return 0;
  long long mid = (s + e) / 2;
  long long ans =
      (get(l, r, tag * 2, s, mid) + get(l, r, tag * 2 + 1, mid, e)) % mod;
  return (ans * la[tag] % mod);
}
long long real_power(long long x) {
  return (get(st[x], ft[x]) *
          pw((pw(val[x], mod - 2) * get(st[x], st[x] + 1)) % mod, mod - 2) %
          mod * deg[x] % mod);
}
int32_t main() {
  cin >> val[1] >> q;
  for (long long i = 0; i < q; i++) {
    cin >> tp[i] >> fi[i];
    if (tp[i] == 1) {
      cin >> se[i];
      val[++n] = se[i];
      g[fi[i]].push_back(n);
    }
  }
  dfs(1);
  fill(la, la + N * 4, 1);
  set_val(st[1]);
  deg[1] = 1;
  long long cn = 1;
  for (long long i = 0; i < q; i++) {
    if (tp[i] == 1) {
      cn++;
      long long x = fi[i];
      set_val(st[cn]);
      update(st[x], ft[x], pw(deg[x], mod - 2));
      deg[x]++, deg[cn]++;
      update(st[x], ft[x], deg[x]);
    } else
      cout << real_power(fi[i]) << endl;
    ;
  }
}
