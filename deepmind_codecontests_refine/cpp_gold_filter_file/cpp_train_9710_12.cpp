#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e3 + 7, Max = 1e6 + 7;
int n, m, res;
pii a[N], b[N];
int surf[Max];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    res = 1e9;
    fill(surf, surf + Max, 0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= m; ++i) cin >> b[i].first >> b[i].second;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i].first <= b[j].first && a[i].second <= b[j].second)
          surf[b[j].second - a[i].second] =
              max(surf[b[j].second - a[i].second], b[j].first - a[i].first + 1);
    for (int i = Max - 2; i >= 0; --i) {
      surf[i] = max(surf[i], surf[i + 1]);
      res = min(res, i + surf[i]);
    }
    cout << res << '\n';
  }
  return 0;
}
