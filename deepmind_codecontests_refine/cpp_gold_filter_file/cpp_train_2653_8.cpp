#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
signed main() {
  int m, t, r;
  cin >> m >> t >> r;
  vector<int> w(m);
  for (int i = 0; i < m; i++) cin >> w[i];
  if (t < r) {
    cout << -1 << "\n";
    return 0;
  }
  unordered_map<int, int> used;
  vector<int> cnt(500, 0);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int l = w[i] - (r - cnt[w[i]]);
    for (int j = w[i] - 1; j >= l; j--) {
      ans++;
      if (j + r < w[i]) {
        cout << -1 << "\n";
        return 0;
      }
      if (used[j] > 0) {
        l--;
        continue;
      }
      used[j]++;
      for (int k = j + 1; k <= j + t; k++) {
        if (k >= 0 && k < 500) cnt[k]++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
