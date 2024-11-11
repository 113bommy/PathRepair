#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  int l = 0, r = 0, t = 0, b = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    if (a[i].first > a[r].first) r = i;
    if (a[i].first < a[l].first) l = i;
    if (a[i].second > a[t].second) t = i;
    if (a[i].second < a[b].second) b = i;
  }
  vector<int> p = {l, r, t, b};
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int res = 0;
  for (int i = 0; i < p.size(); i++) {
    for (int j = i + 1; j < p.size(); j++) {
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        vector<int> pt = {p[i], p[j], k};
        sort(pt.begin(), pt.end());
        res = max(res, abs(a[pt[0]].first - a[pt[1]].first) +
                           abs(a[pt[0]].second - a[pt[1]].second) +
                           abs(a[pt[1]].first - a[pt[2]].first) +
                           abs(a[pt[1]].second - a[pt[2]].second) +
                           abs(a[pt[0]].first - a[pt[2]].first) +
                           abs(a[pt[0]].second - a[pt[2]].second));
      }
    }
  }
  int res2 = (a[r].first - a[l].first + a[t].second - a[b].second) * 2;
  cout << res << " ";
  for (int i = 4; i <= n; i++) {
    cout << res2 << " ";
  }
  return 0;
}
