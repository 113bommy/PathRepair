#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &v : a) {
    cin >> v;
  }
  long long ans = (n - a[0] + 1) * a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      ans += (n - a[i] + 1) * (a[i] - a[i - 1]);
    } else {
      ans += (a[i - 1] - a[i]) * a[i];
    }
  }
  cout << ans;
  return 0;
}
