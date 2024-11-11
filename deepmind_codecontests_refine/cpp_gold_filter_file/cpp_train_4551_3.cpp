#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  std::cout << std::setprecision(8) << std::fixed;
  int n, i, ans = 0;
  double s = 0, a[111], p;
  p = 40.0 / 9.0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    if ((s / (double)n) >= 4.5) break;
    s += 5.0 - a[i];
    ans++;
  }
  cout << ans;
  return 0;
}
