#include <bits/stdc++.h>
using namespace std;
bool isRed[105];
int main() {
  int i, n, m, x, j, l, r, a[2];
  vector<pair<int, int> > segs, points;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> x, points.push_back(pair<int, int>(x, i));
  for (i = 0; i < m; i++) {
    cin >> l >> r;
    segs.push_back(pair<int, int>(l, r));
  }
  sort((points).begin(), (points).end()), sort((segs).begin(), (segs).end());
  for (i = 0; i < n; i++) isRed[points[i].second] = (i % 2);
  for (i = 0; i < m; i++) {
    l = segs[i].first, r = segs[i].second;
    a[0] = a[1] = 0;
    for (j = 0; j < n; j++) {
      if (points[j].first >= l && points[j].first <= r)
        a[isRed[points[j].second]]++;
    }
    if (abs(a[0] - a[1]) > 1) {
      printf("-1");
      return 0;
    }
  }
  for (i = 0; i < n; i++) printf("%d ", isRed[i]);
  return 0;
}
