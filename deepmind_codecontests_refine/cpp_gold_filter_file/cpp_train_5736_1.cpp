#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 3e18 + 5;
long long add(long long a, long long b) { return (a += b) < mod ? a : a - mod; }
long long mul(long long a, long long b) { return 1LL * a * b % mod; }
long long sub(long long a, long long b) { return (a -= b) < 0 ? a + mod : a; }
long long ctz(long long x) { return __builtin_ctz(x); }
long long clz(long long x) { return __builtin_clz(x); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> v(n);
  long long aa = 0, ind = 0;
  for (long long& x : v) {
    cin >> x;
    if (x == m) {
      ind = aa;
      aa++;
      continue;
    }
    if (x < m)
      x = -1;
    else
      x = 1;
    aa++;
  }
  map<long long, long long> suf;
  suf[0] = 1;
  long long cum = 0;
  for (long long i = ind + 1; i < n; i++) {
    cum += v[i];
    suf[cum]++;
  }
  long long res = 0;
  long long pref = 0;
  for (long long i = ind; i >= 0; i--) {
    pref += (i == ind ? 0 : v[i]);
    res += suf[-pref];
    res += suf[1 - pref];
  }
  cout << res;
}
