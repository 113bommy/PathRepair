#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> s;
int main() {
  int n;
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  int a[n];
  int cnt[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    cnt[i] = __builtin_popcount(a[i]);
  }
  for (int i = 0; i < (1 << 15); ++i) {
    vector<int> v(n, 0);
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < 15; ++k) {
        if (((i >> k) & 1) == 0) continue;
        v[j] += ((a[j] >> k) & 1) ? -1 : 1;
      }
      v[j] += cnt[j];
    }
    s[v] = i;
  }
  int ans = -1;
  for (int i = 0; i < (1 << 30); i += (1 << 15)) {
    vector<int> v(n, 0);
    for (int j = 0; j < n; ++j) {
      for (int k = 15; k < 30; ++k) {
        if (((i >> k) & 1) == 0) continue;
        v[j] += ((a[j] >> k) & 1) ? -1 : 1;
      }
      v[j] = -v[j];
    }
    for (int tar = 0; tar <= 30; ++tar) {
      auto it = s.find(v);
      if (it != s.end()) {
        ans = i | it->second;
        break;
      }
      for (int k = 0; k < n; ++k) ++v[k];
    }
    if (ans != -1) break;
  }
  cout << ans << '\n';
}
