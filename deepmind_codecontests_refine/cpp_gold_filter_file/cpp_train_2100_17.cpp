#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s, a[200020], b, g, i, d, l, r, m, tmp, presum[200020];
  vector<pair<long long, long long>> v;
  cin >> s >> b;
  for (i = 1; i <= s; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= b; i++) {
    cin >> d >> g;
    v.push_back({d, g});
  }
  sort(v.begin(), v.end());
  for (i = 0; i < b; i++) {
    if (i == 0) {
      presum[0] = v[i].second;
    } else {
      presum[i] = presum[i - 1] + v[i].second;
    }
  }
  for (i = 1; i <= s; i++) {
    tmp = -1;
    l = 0;
    r = b - 1;
    while (l <= r) {
      m = (l + r) / 2;
      if (v[m].first <= a[i]) {
        tmp = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (tmp == -1) {
      cout << 0 << endl;
    } else {
      cout << presum[tmp] << endl;
    }
  }
}
