#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<vector<long long> > p(k + 1, vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) cin >> p[1][i];
  for (int i = 2; i <= k; ++i)
    for (int j = 0; j < n; ++j) p[i][j] = p[i - 1][j] + p[1][j];
  int q;
  cin >> q;
  for (int a = 0; a < q; ++a) {
    long long x;
    cin >> x;
    int res = 21;
    for (int i = 0; i < n; ++i) {
      for (int y = 1; y <= min(k, res); ++y) {
        long long s = x - p[y][i];
        if (s < 0) break;
        for (int z = 0; z <= min(k, (res - y)); ++z) {
          int t = lower_bound(p[z].begin(), p[z].end(), s) - p[z].begin();
          if (t >= int((p[z]).size())) continue;
          if (p[z][t] == s) res = min(res, (y + z));
        }
      }
    }
    if (res >= 21) res = -1;
    cout << res << "\n";
  }
  return 0;
}
