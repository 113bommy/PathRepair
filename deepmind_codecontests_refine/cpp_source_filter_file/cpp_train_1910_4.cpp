#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, i, j, k, x, y, ans, xx, yy, ct, xxx, yyy, x2, y2;
  cin >> n >> m;
  vector<pair<long long, long long>> plist(m);
  for (i = 0; i < n; i++) cin >> plist[i].second >> plist[i].first;
  sort(plist.rbegin(), plist.rend());
  vector<long long> maxx(n + 1, 1);
  for (i = 0; i < m; i++) {
    x = plist[i].second;
    y = plist[i].first;
    for (j = i + 1; j < m; j++) {
      xx = plist[j].second;
      yy = plist[j].first;
      if (y == yy) continue;
      if (((x - xx) * yy) % (y - yy) == 0) {
        xxx = xx - (x - xx) * yy / (y - yy);
        if ((xxx >= 1) && (xxx <= n)) {
          ct = 2;
          for (k = j + 1; k < m; k++) {
            x2 = plist[k].second;
            y2 = plist[k].first;
            if (y2 == yy) continue;
            if ((x - xx) * (yy - y2) == (xx - x2) * (y - yy)) ct++;
          }
          maxx[xxx] = max(maxx[xxx], ct);
        }
      }
    }
  }
  ans = 0;
  for (i = 1; i <= n; i++) ans += maxx[i];
  cout << ans << "\n";
  return 0;
}
