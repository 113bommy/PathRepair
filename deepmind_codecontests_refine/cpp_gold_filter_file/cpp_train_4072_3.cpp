#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 1000;
const long long mod = (long long)1e9 + 7;
long long cnt[maxn], cntd[maxn];
long long f[maxn], rf[maxn];
long long ans[maxn];
long long pw(long long a, long long p) {
  if (p == 0) return 1;
  long long rs = pw(a, p / 2);
  rs = (rs * rs) % mod;
  if (p & 1) rs = (rs * a) % mod;
  return rs;
}
long long rev(long long x) { return pw(x, mod - 2); }
void prepare() {
  f[0] = 1;
  rf[0] = rev(f[0]);
  for (long long i = 1; i < maxn; ++i) {
    f[i] = (f[i - 1] * i) % mod;
    rf[i] = rev(f[i]);
  }
}
long long cnk(long long n, long long k) {
  if (n - k < 0 || k > n) return 0;
  return (f[n] * ((rf[n - k] * rf[k]) % mod)) % mod;
}
long long n;
vector<long long> a;
bool ok(long long x) {
  for (long long i = maxn - 1; i >= 1; --i) {
    ans[i] = cnk(cntd[i], x);
    for (long long j = 2 * i; j < maxn; j += i) {
      ans[i] -= ans[j];
      ans[i] += mod;
      ans[i] %= mod;
    }
  }
  return ans[1] != 0;
}
void solve() {
  prepare();
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (long long i = 1; i < maxn; ++i) {
    for (long long j = i; j < maxn; j += i) {
      cntd[i] += cnt[j];
      cntd[i] %= mod;
    }
  }
  long long l = 0;
  long long r = n + 1;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (ok(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  if (r == n + 1) {
    cout << -1 << "\n";
    exit(0);
  }
  cout << r << "\n";
}
signed main() {
  long long t = 1;
  srand(time(0));
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (t--) {
    solve();
  }
}
