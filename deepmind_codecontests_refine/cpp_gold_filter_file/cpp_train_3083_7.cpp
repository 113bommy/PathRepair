#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > v;
int main() {
  int i, j, k, l, n, m;
  int q;
  cin >> n >> m >> k >> q;
  for (i = 0; i < q; i++) {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    v.push_back({a3, {a1, a2}});
  }
  int low, high, ans;
  low = 0;
  high = ans = 1000000009;
  while (high >= low) {
    int mid = (low + high) / 2;
    int a[502][502];
    int b[502][502];
    int c[502][502];
    int d[502][502];
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= m; j++) {
        a[i][j] = b[i][j] = c[i][j] = d[i][j] = 0;
      }
    }
    for (i = 0; i < q; i++) {
      if (v[i].first <= mid) d[v[i].second.first][v[i].second.second] = 1;
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (d[i][j] != 0) a[i][j] = a[i][j - 1] + 1;
      }
    }
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        if (d[j][i] != 0) b[j][i] = b[j - 1][i] + 1;
      }
    }
    int ans1 = 0;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (d[i][j] != 0) {
          c[i][j] = min(c[i - 1][j - 1] + 1, min(a[i][j], b[i][j]));
          ans1 = max(ans1, c[i][j]);
        }
      }
    }
    if (ans1 >= k) {
      ans = min(ans, mid);
      high = mid - 1;
    } else
      low = mid + 1;
  }
  if (ans == 1000000009)
    cout << -1;
  else
    cout << ans;
}
