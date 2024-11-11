#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > homs;
int main() {
  int n, k, h;
  scanf("%d%d%d", &n, &k, &h);
  homs.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &homs[i].first.first);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &homs[i].first.second);
    homs[i].second = i + 1;
  }
  sort(homs.begin(), homs.end());
  long double t, l = 0, r = 1e9, m;
  int st, iter = 0;
  vector<int> ans(k + 1), temp(k + 1);
  while (abs(r - l) > 1e-18 && iter < 90) {
    m = (l + r) / 2;
    st = 1;
    for (int i = 0; i < n && st <= k; ++i) {
      t = ((long double)st * h) / ((long double)homs[i].first.second);
      if (t <= m) {
        temp[st] = homs[i].second;
        ++st;
      }
    }
    if (st <= k)
      l = m;
    else {
      ans = temp;
      r = m;
    }
    ++iter;
  }
  for (int i = 1; i <= k; ++i) printf("%d ", ans[i]);
  return 0;
}
