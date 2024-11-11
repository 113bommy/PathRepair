#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <class S, class T>
inline S smax(S &l, T r) {
  return l = max(l, (S)r);
}
template <class S, class T>
inline S smin(S &l, T r) {
  return l = min(l, (S)r);
}
const long long MAXN = 70;
long long a[MAXN][MAXN];
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, ans = 0;
  cin >> n;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < n; ++j) cin >> a[i][j];
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < n; ++j) {
      long long sumcol = 0, sumrow = 0;
      for (long long row = 0; row < n; ++row) sumcol += a[row][j];
      for (long long col = 0; col < n; ++col) sumrow += a[i][col];
      if (sumcol > sumrow) ans++;
    }
  cout << ans << '\n';
  return 0;
}
