#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i].second);
  for (int i = 0; i < n; i++) {
    if (v[i].second & 10 != 0) v[i].first = 10 - (v[i].second % 10);
  }
  sort(v.begin(), v.end());
  int i = 0;
  while (m > 0 && i < n) {
    if (m >= v[i].first) {
      m -= v[i].first;
      v[i].second += v[i].first;
      v[i].first = 0;
    } else {
      v[i].second += m;
      m = 0;
    }
    i++;
  }
  i = 0;
  for (int i = 0; i < n && m - 10 >= 0; i++) {
    if (v[i].second < 100) {
      if (m >= 100 - v[i].second) {
        m -= 100 - v[i].second;
        v[i].second = 100;
      } else {
        v[i].second += m;
        m = 0;
        break;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += v[i].second / 10;
  }
  printf("%d\n", res);
  return 0;
}
