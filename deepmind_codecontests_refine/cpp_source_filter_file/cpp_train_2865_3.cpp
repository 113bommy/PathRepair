#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("-ffloat-store")
const long long INF = 0xFFFFFFFFFFFFFFFL;
const long long N = 1e9 + 7;
void zark() {}
void solve() {
  string g, p;
  cin >> g >> p;
  long long ans = 0;
  long long ng = g.length();
  long long np = p.length();
  for (long long i = 0; i < ng - np;) {
    string r = g.substr(i, np);
    if (r == p) {
      ans += 1;
      i += np;
    } else
      i++;
  }
  cout << ans;
}
int32_t main(int32_t argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
