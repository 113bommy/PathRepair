#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  double ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
  }
  ans /= n;
  cout << setprecision(12) << fixed << ans;
  return 0;
}
