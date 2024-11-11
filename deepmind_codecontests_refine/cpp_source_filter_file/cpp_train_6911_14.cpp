#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
using namespace std;
const int MOD = 1000000007;
int a[1000005], b[1000005], comp[31];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < 30; ++j)
      if ((a[i] >> j) & 1) comp[j]++;
  }
  for (int i = 0; i < m; ++i) cin >> b[i];
  sort(b, b + m);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    bool f = 0;
    if (comp[b[i]]) {
      comp[b[i]]--;
      ans++, f = 1;
    } else {
      for (int j = b[i] + 1; j < 30; ++j)
        if (comp[j]) {
          comp[j]--;
          ans++, f = 1;
          for (int z = j; z < j; ++z) comp[z]++;
          break;
        }
    }
    if (!f) break;
  }
  cout << ans << "\n";
  return 0;
}
