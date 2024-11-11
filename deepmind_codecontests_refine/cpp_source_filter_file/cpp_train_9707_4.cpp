#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 2;
long long a[N], b[N];
priority_queue<pair<pair<long long, long long>, long long> > concac;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, i, j, k, l, sum, lef = -2e18, rig = 1e9, mid;
  cin >> n >> sum;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (lef < rig) {
    mid = (lef + rig) / 2;
    if (lef + rig < 0) {
      mid--;
    }
    l = 0;
    for (i = 1; i <= n; i++) {
      if (mid >= a[i]) {
        b[i] = 0;
        continue;
      }
      double cac = 1.0 / 2 + sqrt((double)(a[i] - mid - 1.0 / 4) / 3);
      k = cac;
      b[i] = min(a[i], k);
      l += b[i];
    }
    if (l < sum) {
      rig = mid;
    } else {
      lef = mid + 1;
    }
  }
  mid = rig;
  l = 0;
  for (i = 1; i <= n; i++) {
    if (mid >= a[i]) {
      b[i] = 0;
      continue;
    }
    double cac = 1.0 / 2 + sqrt((double)(a[i] - mid - 1.0 / 4) / 3);
    k = floor(cac);
    b[i] = min(a[i], k);
    l += b[i];
  }
  for (i = 1; i <= n; i++) {
    if (b[i] + 1 <= a[i]) {
      concac.push(
          {{a[i] - 3 * (b[i] + 1) * (b[i] + 1) + 3 * (b[i] + 1) - 1, a[i]}, i});
    }
  }
  if (sum - l > n) {
    cout << l << ' ' << sum << ' ' << "CAC " << endl;
    return 0;
  }
  while (l < sum) {
    j = concac.top().first.first;
    k = concac.top().first.second;
    i = concac.top().second;
    concac.pop();
    b[i]++;
    if (b[i] + 1 <= a[i]) {
      concac.push(
          {{a[i] - 3 * (b[i] + 1) * (b[i] + 1) + 3 * (b[i] + 1) - 1, a[i]}, i});
    }
    l++;
  }
  for (i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
}
