#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, i;
  vector<pair<pair<int, int>, int> > v;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    scanf("%d", &y);
    v.push_back(make_pair(make_pair(x, y), i + 1));
  }
  sort(v.begin(), v.end());
  for (i = 1; i < v.size(); ++i) {
    if (v[i].first.first == v[i - 1].first.first) break;
  }
  if (i == v.size()) {
    printf("%d %d ", v[0].second, v[1].second);
    for (i = 2; i < n; ++i) {
      if ((v[i].first.second - v[1].first.second) * 1LL *
              (v[1].first.first - v[0].first.first) !=
          (v[1].first.second - v[0].first.second) * 1LL *
              (v[i].first.first - v[1].first.second)) {
        printf("%d\n", v[i].second);
        break;
      }
    }
  } else if (i == 1) {
    for (i = 0; v[i].first.first == v[0].first.first; ++i)
      ;
    printf("%d %d %d\n", v[0].second, v[1].second, v[i].second);
  } else
    printf("%d %d %d\n", v[i - 2].second, v[i - 1].second, v[i].second);
  return 0;
}
