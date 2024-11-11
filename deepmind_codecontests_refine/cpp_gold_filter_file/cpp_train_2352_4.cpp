#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans1 = 10000, ans2 = 10000;
  for (int i = m + 1; i <= n; i++) {
    if (a[i] != 0 && a[i] <= k) {
      ans1 = (i - m) * 10;
      break;
    }
  }
  for (int i = m - 1; i >= 1; i--) {
    if (a[i] != 0 && a[i] <= k) {
      ans2 = (m - i) * 10;
      break;
    }
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}
