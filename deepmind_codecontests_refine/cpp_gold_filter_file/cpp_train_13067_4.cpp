#include <bits/stdc++.h>
using namespace std;
int n, d, m;
pair<int, int> a[200010];
set<pair<int, int> > segs;
set<pair<int, int> >::iterator it, it2;
long long res;
int main() {
  scanf("%d %d %d", &d, &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d %d", &a[i].second, &a[i].first);
  sort(a, a + m);
  segs.insert(pair<int, int>(0, min(n, d)));
  for (int i = 0; i < m; ++i) {
    it2 = it = segs.lower_bound(pair<int, int>(a[i].second + 1, -1));
    pair<int, int> p1, p2;
    if (it == segs.end())
      p1 = pair<int, int>(d, d);
    else
      p1 = *it;
    --it2;
    p2 = *it2;
    if (p2.second - a[i].second >= n) continue;
    if (a[i].second > p2.second) {
      if (a[i].second + n < p1.first) {
        res += (long long)n * a[i].first;
        segs.insert(pair<int, int>(a[i].second, a[i].second + n));
      } else {
        res += (long long)(p1.first - a[i].second) * a[i].first;
        if (it != segs.end()) segs.erase(it);
        segs.insert(pair<int, int>(a[i].second, p1.second));
      }
    } else {
      if (a[i].second + n < p1.first) {
        res += (long long)(a[i].second + n - p2.second) * a[i].first;
        segs.erase(it2);
        segs.insert(pair<int, int>(p2.first, a[i].second + n));
      } else {
        res += (long long)(p1.first - p2.second) * a[i].first;
        if (it != segs.end()) segs.erase(it);
        segs.erase(it2);
        segs.insert(pair<int, int>(p2.first, p1.second));
      }
    }
  }
  if (segs.size() != 1)
    res = -1;
  else if ((*segs.begin()).second != d)
    res = -1;
  printf("%lld", res);
  return 0;
}
