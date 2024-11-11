#include <bits/stdc++.h>
const long long INF = 2e18;
const double EPS = 1e-9;
using namespace std;
void WEZaa() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<int> arr(100100);
int n, pr;
bool chk(double x) {
  double rem = 0.0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > x) {
      rem += (arr[i] - x) * (1.0 - pr / 100.0);
    } else if (arr[i] < x)
      rem -= x - arr[i];
  }
  return rem >= 0;
}
int main() {
  WEZaa();
  cin >> n >> pr;
  for (int i = 0; i < n; i++) cin >> arr[i];
  double l = 0, r = 1e5;
  double ans = 0;
  while (fabs(l - r) >= EPS) {
    double mid = (l + r) / 2;
    if (chk(mid)) {
      ans = mid;
      l = mid;
    } else
      r = mid;
  }
  cout << fixed << setprecision(6);
  cout << ans << "\n";
}
