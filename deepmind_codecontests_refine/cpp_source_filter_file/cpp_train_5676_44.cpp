#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2")
using namespace std;
int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
  long long n, A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  vector<pair<long long, long long> > a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vector<long long> need(n, 0), prf(n, A - a[0].first);
  for (int i = 1; i < n; ++i) {
    need[i] = need[i - 1] + i * (a[i].first - a[i - 1].first);
    prf[i] = prf[i - 1] + A - a[i].first;
  }
  long long ans = 0, c = 0, mn = 0;
  for (int cnt = 0; cnt <= n; ++cnt) {
    long long m1 = prf[n - 1] - (cnt == n ? 0 : prf[n - cnt - 1]);
    long long m2 = m - m1;
    if (m2 < 0) continue;
    int l = 0, r = n, mi;
    while (r - l > 1) {
      mi = (l + r) / 2;
      if (need[mi] <= m2)
        l = mi;
      else
        r = mi;
    }
    m2 -= need[l];
    long long dlt = m2 / (l + 1);
    long long cmn = min(A, a[l].first + dlt);
    if (cnt == n) cmn = A;
    long long cst = cnt * cf + cmn * cm;
    if (cst > ans) {
      c = cnt, ans = cst, mn = cmn;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; ++i) {
    a[i].first = max(mn, a[i].first);
  }
  for (int i = n - 1; i >= 0; --i) {
    if (c == 0) break;
    a[i].first = A;
    --c;
  }
  sort(a.begin(), a.end(),
       [&](pair<long long, long long> x, pair<long long, long long> y) {
         return x.second < y.second;
       });
  for (int i = 0; i < n; ++i) cout << a[i].first << " ";
  return 0;
}
