#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  --h;
  vector<int> ds(m);
  for (int i = 0; i < m; ++i) {
    cin >> ds[i];
  }
  ds[h]--;
  int tot = accumulate(ds.begin(), ds.end(), 0);
  if (tot < n - 1) {
    cout << -1;
    return 0;
  }
  if (tot - ds[h] < n - 1) {
    cout << 1;
    return 0;
  }
  long double ans = 1.0000000;
  for (long double i = 1.0000000; i <= (long double)tot; i += 1.000000) {
    if (i <= (long double)(tot - ds[h])) ans *= i;
    if (i <= (long double)(tot - n - 1)) ans *= i;
    if (i <= (long double)(tot - ds[h] - n - 1)) ans /= i;
    ans /= i;
  }
  cout << setprecision(10) << fixed << (1.000000 - ans);
}
