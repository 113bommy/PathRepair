#include <bits/stdc++.h>
using namespace std;
long long const M = 5e4 + 10, M2 = 3e6 + 10, mod = 1e9 + 7, inf = 1e9 + 10;
long long a[M], cn = 0;
long long tri[M2][2], cnt[M2], n, m, last = 0;
vector<long long> cnt2[M2];
long long pw(long long x, long long y) {
  if (y == 0) return 1;
  long long tmp = pw(x, y / 2);
  if (y % 2 == 0) return (tmp * tmp) % mod;
  return ((tmp * tmp) % mod * x) % mod;
}
void add(long long x) {
  long long now = 0;
  for (long long i = 30; i >= 0; i--) {
    for (long long j = i; j >= 0; j--) {
      if (!cnt2[now].size())
        for (long long j = i; j >= 0; j--) cnt2[now].push_back(0);
      if ((x & (1 << j))) {
        cnt2[now][i - j]++;
      }
    }
    cnt[now]++;
    long long t = 0;
    if ((x & (1 << i))) t = 1;
    if (!tri[now][t]) tri[now][t] = ++cn;
    now = tri[now][t];
  }
  cnt[now]++;
}
long long get(long long tmp, long long x) {
  long long ans = 0;
  long long now = 0;
  for (long long i = 30; i >= 0; i--) {
    long long bi = (tmp & (1 << i));
    if (bi)
      bi = 0;
    else
      bi = 1;
    long long bi2 = (x & (1 << i));
    if (!bi2) {
      if (tri[now][bi]) ans += cnt[tri[now][bi]];
      now = tri[now][1 - bi];
    } else
      now = tri[now][bi];
    if (!now) return ans;
  }
  ans += cnt[now];
  return ans;
}
bool check(long long x) {
  long long all = 0;
  for (long long i = 1; i <= n; i++) {
    all += get(a[i], x);
  }
  if (x == 0)
    all = ((all - n) / 2 + n);
  else
    all /= 2;
  last = all;
  return all < m;
}
long long get2(long long tmp, long long x) {
  long long ans = 0, now = 0, sv = 0;
  for (long long i = 30; i >= 0; i--) {
    long long bi = (tmp & (1LL << i));
    if (bi)
      bi = 0;
    else
      bi = 1;
    long long bi2 = (x & (1LL << i));
    if (!bi2) {
      if (tri[now][bi]) {
        long long hlp = tri[now][bi];
        ans += ((sv) + (1LL << i)) * cnt[hlp];
        ans %= mod;
        for (long long j = i - 1; j >= 0; j--) {
          long long t = 1;
          if ((tmp & (1 << j))) t = 0;
          long long tm = cnt2[hlp][i - 1 - j];
          if (!t) tm = cnt[hlp] - tm;
          ans += (1LL << j) * tm;
          ans %= mod;
        }
      }
      now = tri[now][1 - bi];
    } else {
      now = tri[now][bi];
      sv += (1LL << i);
    }
    if (!now) return ans;
  }
  ans += (sv)*cnt[now];
  ans %= mod;
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i], add(a[i]);
  long long lo = 1, hi = 2e9 + 10;
  while (hi > lo + 1) {
    long long mid = (lo + hi) >> 1;
    if (check(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  long long ind = hi;
  if (check(lo)) ind = lo;
  ind--;
  check(ind);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += get2(a[i], ind), ans %= mod;
  }
  ans *= pw(2, mod - 2);
  ans %= mod;
  ans -= (((last - m) * ind) % mod);
  while (ans < 0) ans += mod;
  ans %= mod;
  cout << ans;
}
