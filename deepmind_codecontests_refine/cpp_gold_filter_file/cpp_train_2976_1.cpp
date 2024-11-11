#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[100005];
int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);
  double lo = 0;
  double hi = 1e16;
  int iter = 150;
  while (iter--) {
    double mid = (lo + hi) / 2;
    double timeGot = mid;
    for (int i = 0; i < n; i++) {
      double toIncrease = arr[i].second - arr[i].first * mid * 1.00;
      if (toIncrease > 0) continue;
      toIncrease = fabs(toIncrease);
      double timeToCharge = toIncrease / p;
      timeGot -= timeToCharge;
    }
    if (timeGot < 0)
      hi = mid;
    else
      lo = mid;
  }
  cout << fixed << setprecision(5);
  if (lo >= 1e11) {
    cout << "-1";
    return 0;
  }
  cout << lo;
  return 0;
}
