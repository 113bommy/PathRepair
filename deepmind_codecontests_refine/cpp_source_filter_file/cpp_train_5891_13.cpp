#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int rx[] = {1, 0, -1, -1, 0, 1};
int ry[] = {1, 1, 0, -1, -1, 0};
vector<pair<long long, long long> > a(1001);
long double rast(int i, int j, int q) {
  long double v1 = (a[q].second - a[j].second) * a[i].first -
                   (a[q].first - a[j].first) * a[i].second +
                   a[q].first * a[j].second - a[q].second * a[j].first;
  v1 = abs(v1);
  long double v2 =
      sqrt((a[q].second - a[j].second) * (a[q].second - a[j].second) +
           (a[q].first - a[j].first) * (a[q].first - a[j].first));
  v1 /= v2;
  return v1 / 2;
}
int32_t main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  vector<int> permutation;
  for (int i = 0; i < n; i++) permutation.push_back(i);
  for (int i = 0; i < 2; i++) permutation.push_back(i);
  long double ans = 1e18;
  for (int i = 0; i < n; i++) {
    for (int j = max(0, i - 2); j < min((int)permutation.size() - 1, i + 2);
         j++) {
      for (int q = max(0, i - 2); q < min((int)permutation.size() - 1, i + 2);
           q++)
        if (permutation[i] != permutation[j] &&
            permutation[j] != permutation[q] &&
            permutation[i] != permutation[q]) {
          ans = min(ans, rast(permutation[i], permutation[j], permutation[q]));
        }
    }
  }
  cout << fixed << setprecision(10) << ans;
}
