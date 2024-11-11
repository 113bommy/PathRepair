#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
using namespace std;
long long gcd(long long a, long long b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long bigmod(long long b, long long p, long long m) {
  long long ans = 1;
  b %= m;
  if (!b) return 0;
  while (p) {
    if (p & 1) ans = (ans * b) % m;
    p >>= 1;
    b = (b * b) % m;
  }
  return ans;
}
long long ncr(long long n, long long r) {
  if (n < r) return 0ll;
  long long ans = 1, k = min(n - r, r);
  for (long long i = 1; i <= k; i++) ans = ans * (n - i + 1) / i;
  return ans;
}
long double eu(long long x1, long long y1, long long x2, long long y2) {
  long long dx = abs(x1 - x2), dy = abs(y1 - y2);
  return sqrt(dx * dx + dy * dy);
}
long long ham(string s, string t) {
  long long ans = 0;
  for (long long i = 0; i < s.size(); i++) ans += (s[i] != t[i]);
  return ans;
}
long long ce(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
bool cmp() { return 1; }
void gen() {}
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a + b, c + d);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
