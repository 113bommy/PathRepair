#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long fp(long long a, long long b) {
  if (b == 0) return 1;
  long long x = fp(a, b / 2);
  x = (x * x) % mod;
  if (b & 1) x = (x * a) % mod;
  return x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q;
  cin >> q;
  map<array<long long, 2>, long long> mp;
  while (q--) {
    long long typ, u, v, w;
    cin >> typ;
    if (typ == 1) {
      cin >> u >> v >> w;
      long long d1 = log2(u);
      long long d2 = log2(v);
      if (d1 > d2) {
        swap(d1, d2);
        swap(u, v);
      }
      while (d1 != d2) {
        mp[{v / 2, v}] += w;
        v /= 2;
        d2--;
      }
      while (u != v) {
        mp[{v / 2, v}] += w;
        v /= 2;
        mp[{u / 2, u}] += w;
        u /= 2;
      }
    } else {
      cin >> u >> v;
      long long ans = 0;
      long long d1 = log2(u);
      long long d2 = log2(v);
      if (d1 > d2) {
        swap(d1, d2);
        swap(u, v);
      }
      while (d1 != d2) {
        ans += mp[{v / 2, v}];
        v /= 2;
        d2--;
      }
      while (u != v) {
        ans += mp[{v / 2, v}];
        v /= 2;
        ans += mp[{u / 2, u}];
        u /= 2;
      }
      cout << ans << "\n";
    }
  }
}
