#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  while ((a = a % b) != 0) {
    swap(a, b);
  }
  return b;
}
long long modpow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % 998244353;
    y = y >> 1;
    x = x * x % 998244353;
  }
  return res;
}
long long ncr(long long n, long long r) {
  long long f1 = 1, f2 = 1;
  for (long long i = (n - r + 1); i < (n + 1); i++) f1 = f1 * i % 998244353;
  for (long long i = (1); i < (r + 1); i++) f2 = f2 * i % 998244353;
  return f1 * modpow(f2, 998244353 - 2) % 998244353;
}
long long *sieve(long long n) {
  long long *lpf = new long long[n + 1];
  for (long long i = 1; i <= n; i++) lpf[i] = i;
  long long rt = (long long)floor(sqrt(n)) + 1;
  for (long long i = (2); i < (rt); i++) {
    if (lpf[i] != i) continue;
    for (long long j = i * i; j <= n; j += i) {
      if (lpf[j] == j) lpf[j] = i;
    }
  }
  return lpf;
}
void solve() {
  long long n, x, y;
  cin >> n >> x >> y;
  pair<long long, long long> seg[n];
  for (long long i = (0); i < (n); i++) cin >> seg[i].first >> seg[i].second;
  sort(seg, seg + n);
  set<long long> r;
  long long cost = 0;
  for (long long i = (0); i < (n); i++) {
    long long c = x + y * (seg[i].second - seg[i].first);
    r.insert(seg[i].second);
    auto it = r.lower_bound(seg[i].first);
    if (it != r.begin()) {
      c = min(c, y * (seg[i].second - *(--it)));
      r.erase(it);
    }
    cost = (cost + c) % 1000000007;
  }
  cout << cost;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long i = (1); i < (t + 1); i++) {
    solve();
    cout << "\n";
  }
}
