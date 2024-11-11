#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long modInv(long long a) { return binpow(a, MOD - 2); }
bool sortcol(const vector<long long>& v1, const vector<long long>& v2) {
  return v1[1] < v2[1];
}
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int pct(int x) { return __builtin_popcount(x); }
int bits(int x) { return 31 - __builtin_clz(x); }
int cdiv(int a, int b) { return a / b + !(a < 0 || a % b == 0); }
int fstTrue(function<bool(int)> first, int lo, int hi) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 2e5;
int q = 1, a1, b1, r1, R1, a2, b2, r2, R2, ans;
int cnt(long double dist) {
  int x = 0;
  if (r1 + R2 <= dist || r2 - r1 >= dist || r1 - R2 >= dist) x++;
  if (R1 + R2 <= dist || R1 - R2 >= dist || r2 - R1 >= dist) x++;
  if (R1 + r2 <= dist || r1 - r2 >= dist || r1 - R1 >= dist) x++;
  if (R1 + R2 <= dist || R2 - R1 >= dist || r1 - R2 >= dist) x++;
  return x;
}
void solve() {
  cin >> a1 >> b1 >> r1 >> R1 >> a2 >> b2 >> r2 >> R2;
  long double dist = sqrt((a2 - a1) * (a2 - a1) + (b2 - b1) * (b2 - b1));
  cout << cnt(dist) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (q--) {
    solve();
  }
}
