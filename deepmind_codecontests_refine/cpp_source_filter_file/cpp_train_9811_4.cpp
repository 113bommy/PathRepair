#include <bits/stdc++.h>
using namespace std;
long long calc(long long x, long long y, long long z) {
  return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n[3];
    vector<int> v[3];
    cin >> n[0] >> n[1] >> n[2];
    for (int p = 0; p < 3; p++) {
      v[p].resize(n[p]);
      for (int i = 0; i < n[p]; i++) cin >> v[p][i];
      sort(v[p].begin(), v[p].end());
    }
    long long ans = (long long)4e18 + 10;
    for (int p1 = 0; p1 < 3; p1++) {
      for (int p2 = 0; p2 < 3; p2++) {
        for (int p3 = 0; p3 < 3; p3++) {
          if (p1 == p2 || p2 == p3 || p3 == p1) continue;
          for (auto x : v[p1]) {
            auto it1 = lower_bound(v[p2].begin(), v[p2].end(), x);
            auto it2 = lower_bound(v[p3].begin(), v[p3].end(), x);
            if (it1 != v[p2].end() && it2 != v[p3].begin()) {
              int y = *it1;
              it2--;
              int z = *it2;
              ans = min(ans, calc(x, y, z));
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
