#include <bits/stdc++.h>
using namespace std;
int n, k, h;
pair<pair<long double, long double>, int> lem[100000];
int lemsTest[100000];
int lemsTrue[100000];
int main() {
  cin >> n >> k >> h;
  for (int i = 0; i < n; ++i) cin >> lem[i].first.first;
  for (int i = 0; i < n; ++i) cin >> lem[i].first.second;
  for (int i = 0; i < n; ++i) lem[i].second = i + 1;
  sort(lem, lem + n);
  long double lo = 0, hi = 2e9;
  while (hi - lo > (1 + lo) * 1e-16) {
    long double mid = (lo + hi) / 2;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      long double maxLedge = mid * lem[i].first.second;
      if (maxLedge >= h * (j + 1)) {
        lemsTest[j] = lem[i].second;
        j++;
      }
    }
    if (j < k)
      lo = mid;
    else {
      hi = mid;
      for (int i = 0; i < k; ++i) lemsTrue[i] = lemsTest[i];
    }
  }
  cout << lemsTrue[0];
  for (int i = 1; i < k; ++i) cout << ' ' << lemsTrue[i];
  cout << endl;
}
