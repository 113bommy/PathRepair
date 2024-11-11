#include <bits/stdc++.h>
using namespace std;
int n;
pair<pair<int, int>, pair<int, int> > rects[323456];
pair<pair<int, int>, pair<int, int> > lft[323456];
pair<pair<int, int>, pair<int, int> > rgt[323456];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rects[i].first.first >> rects[i].first.second;
    cin >> rects[i].second.first >> rects[i].second.second;
  }
  lft[0] = rects[0];
  rgt[n - 1] = rects[n - 1];
  for (int i = 1; i < n; i++) {
    lft[i].first.first = max(rects[i].first.first, lft[i - 1].first.first);
    lft[i].first.second = max(rects[i].first.second, lft[i - 1].first.second);
    lft[i].second.first = min(rects[i].second.first, lft[i - 1].second.first);
    lft[i].second.second =
        min(rects[i].second.second, lft[i - 1].second.second);
    rgt[n - i - 1].first.first =
        max(rects[n - i - 1].first.first, rgt[n - i].first.first);
    rgt[n - i - 1].first.second =
        max(rects[n - i - 1].first.second, rgt[n - i].first.second);
    rgt[n - i - 1].second.first =
        min(rects[n - i - 1].second.first, rgt[n - i].second.first);
    rgt[n - i - 1].second.second =
        min(rects[n - i - 1].second.second, rgt[n - i].second.second);
  }
  if (rgt[1].first.first <= rgt[1].second.first &&
      rgt[1].first.second <= rgt[1].second.second) {
    cout << rgt[1].first.first << " " << rgt[1].first.second << endl;
  } else if (lft[n - 2].first.first <= lft[n - 2].second.first &&
             lft[n - 2].first.second <= lft[n - 2].second.second) {
    cout << lft[n - 2].first.first << " " << lft[n - 2].first.second << endl;
  } else {
    for (int i = 1; i < n - 1; i++) {
      pair<pair<int, int>, pair<int, int> > inter;
      inter.first.first = max(lft[i - 1].first.first, rgt[i + 1].first.first);
      inter.first.second =
          max(lft[i - 1].first.second, rgt[i + 1].first.second);
      inter.second.first =
          min(lft[i - 1].second.first, rgt[i + 1].second.first);
      inter.second.second =
          min(lft[i - 1].second.second, rgt[i + 1].second.second);
      if (inter.first.first <= inter.second.first &&
          inter.first.second <= inter.second.second) {
        cout << inter.first.first << " " << inter.first.second << endl;
        return 0;
      }
    }
  }
  return 0;
}
