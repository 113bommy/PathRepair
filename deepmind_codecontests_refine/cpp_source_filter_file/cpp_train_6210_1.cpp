#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
using namespace std;
vector<long long> lnds(vector<long long> a) {
  long long n = a.size();
  vector<long long> p(n);
  iota(p.rbegin(), p.rend(), 0);
  stable_sort(p.begin(), p.end(),
              [&](long long i, long long j) { return a[i] > a[j]; });
  vector<long long> t(n + 1);
  auto upd = [&](long long i, long long x) {
    i++;
    t[i] = x;
    while (i) t[i] = max(t[i], x), i -= i & -i;
  };
  auto qry = [&](long long i) {
    i++;
    long long ret = 0;
    while (i < (long long)t.size()) ret = max(ret, t[i]), i += i & -i;
    return ret;
  };
  vector<long long> ret(n);
  for (long long i = 0; i < n; i++) {
    long long idx = p[i];
    long long x = qry(idx) + 1;
    upd(idx, x);
    ret[idx] = x;
  }
  return ret;
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  vector<long long> ct(m);
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    ct[l]++;
    if (r + 1 < m) ct[r + 1]--;
  }
  partial_sum(ct.begin(), ct.end(), ct.begin());
  auto fwd = lnds(ct);
  reverse(ct.begin(), ct.end());
  auto rev = lnds(ct);
  reverse(rev.begin(), rev.end());
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    ans = max(ans, fwd[i] + rev[i] - 1);
  }
  cout << ans << "\n";
}
