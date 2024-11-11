#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18;
const long long MOD = (long long)1e9 + 9;
int n, m, k, r[200][200], ans = 100, i, j, f;
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) cin >> r[i][j];
  if (n <= 10) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      int cur = 0;
      for (i = 1; i <= m; ++i) {
        int t1 = 0, t2 = 0;
        for (j = 1; j <= n; ++j)
          t1 += (r[j][i] == bool(mask & (1 << (j - 1)))),
              t2 += (r[j][i] != bool(mask & (1 << (j - 1))));
        cur += min(t1, t2);
      }
      ans = min(ans, cur);
    }
  } else {
    for (f = 1; f <= n; ++f) {
      int cur = 0;
      for (i = 1; i <= n; ++i) {
        int t1 = 0, t2 = 0;
        for (j = 1; j <= m; ++j)
          t1 += (r[i][j] == r[f][j]), t2 += (r[i][j] != r[f][j]);
        cur += min(t1, t2);
      }
      ans = min(ans, cur);
    }
  }
  if (ans <= k)
    cout << ans;
  else
    cout << -1;
  cout << endl;
}
