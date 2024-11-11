#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long oo = 1e18;
inline void yn(long long x) {
  if (x)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
const long long N = 1e5 + 2, M = 1e6, mod = 1e9 + 7, mod1 = 998244353;
const long long MAXA = 0;
void solve() {
  long long k[3];
  for (long long i = 0; i < 3; i++) cin >> k[i];
  long long n = k[0] + k[1] + k[2];
  vector<long long> a(n);
  for (long long i = 0; i < k[0]; i++) {
    long long x;
    cin >> x;
    a[x - 1] = 0;
  }
  for (long long i = 0; i < k[1]; i++) {
    long long x;
    cin >> x;
    a[x - 1] = 1;
  }
  for (long long i = 0; i < k[1]; i++) {
    long long x;
    cin >> x;
    a[x - 1] = 2;
  }
  long long ans = 0, bestp = 0;
  ans = k[0] + k[1] + k[2] - max({k[0], k[1], k[2]});
  vector<long long> cntl(3, 0), cntr(3, 0);
  for (long long i = 0; i < n; i++) cntr[a[i]]++;
  for (long long i = 0; i < n; i++) {
    cntl[a[i]]++;
    cntr[a[i]]--;
    bestp = max(bestp, cntl[0] - cntl[1]);
    long long curans = cntr[0] + cntr[1] + cntl[2] + cntl[0] - bestp;
    ans = min(ans, curans);
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
