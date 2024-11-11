#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
const long long mod = 998244353;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
vector<long long> v;
long long n, k;
void solve(long long l, long long r) {
  if (k == 0 || l + 1 == r) {
    return;
  }
  long long mid = l + (r - l) / 2;
  k -= 2;
  swap(v[mid], v[mid - 1]);
  solve(l, mid);
  solve(mid, r);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    cin >> n >> k;
    if (k % 2 == 0) {
      cout << -1;
      return 0;
    }
    for (long long i = 1; i <= n; i++) v.push_back(i);
    k--;
    if (k > 0) {
      solve(0, n);
    }
    if (k > 0) {
      cout << -1;
      return 0;
    }
    for (long long i = 0; i < n; i++) cout << v[i] << " ";
  }
}
