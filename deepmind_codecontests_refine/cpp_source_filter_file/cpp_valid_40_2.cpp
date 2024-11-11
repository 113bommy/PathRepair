#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long INF = 1e10;
void solve() {
  int m;
  cin >> m;
  vector<long long> a(m), b(m), s1(m + 1), s2(m + 1);
  for (int i = 0; i < a.size(); ++i) cin >> a[i];
  ;
  for (int i = 0; i < b.size(); ++i) cin >> b[i];
  ;
  for (int i = 0; i < m; ++i) s1[i + 1] = s1[i] + a[i];
  for (int i = 0; i < m; ++i) s2[i + 1] = s2[i] + b[i];
  if (m == 1) {
    cout << 0 << '\n';
    return;
  }
  int l = 1, r = m + 1;
  while (l + 1 != r) {
    int j = (l + r) / 2;
    if (s1[m] - s1[j] >= s2[j - 1])
      r = j;
    else
      l = j;
  }
  long long minn = INF;
  for (int i = max(1, l - 3); i < min(m + 1, r + 3); ++i) {
    minn = min(minn, max(s1[m] - s1[i], s2[i - 1]));
  }
  cout << minn << '\n';
}
signed main() {
  int t = 1;
  cin >> t;
  for (; t > 0; --t) solve();
}
