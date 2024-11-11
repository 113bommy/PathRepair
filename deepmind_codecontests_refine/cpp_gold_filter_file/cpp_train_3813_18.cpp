#include <bits/stdc++.h>
using namespace std;
long long mod = 100000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, i, j, k, q, t, y, x, k1, i1, j1, z, x1, y1, index;
  cin >> n >> m >> k;
  bool a[n][m];
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) cin >> a[i][j];
  }
  long long ans = 0, ans1 = 0;
  y = 0;
  for (i = 0; i < m; i++) {
    vector<long long> v;
    for (j = 0; j < n; j++) {
      if (a[j][i] == 1) v.push_back(j);
    }
    if (v.size() != 0) {
      x = -1;
      for (j = 0; j < v.size(); j++) {
        y = 0;
        for (k1 = v[j]; k1 < min(n, v[j] + k); k1++) {
          if (a[k1][i] == 1) y++;
        }
        if (y > x) {
          x = y;
          index = v[j];
          if (x >= k) break;
        }
      }
      ans += min(x, k);
      for (j = 0; j < index; j++) {
        if (a[j][i] == 1) ans1++;
      }
    }
  }
  cout << ans << " " << ans1;
}
