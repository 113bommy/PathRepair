#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.precision(11);
  cout << fixed;
  double ans = -1;
  bool ok = 0;
  int n, u;
  cin >> n >> u;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  for (int j = 1; j < n - 1; j++) {
    double temp = 0;
    int ind =
        lower_bound((vec).begin(), (vec).end(), vec[j - 1] + u) - vec.begin();
    if (ind == n) ind = n - 1;
    if (vec[ind] >= vec[j - 1] + u) ind--;
    if (ind <= j) continue;
    temp = ((vec[ind] - vec[j]) * 1.0) / (vec[ind] - vec[j - 1]);
    ans = max(ans, temp);
    ok = 1;
  }
  if (ok)
    cout << ans << "\n";
  else
    cout << "-1\n";
}
