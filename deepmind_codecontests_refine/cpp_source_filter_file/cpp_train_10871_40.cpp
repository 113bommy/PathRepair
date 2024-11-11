#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int cur = 1000000;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int cst = 1000000;
  int ans;
  int a1;
  for (int i = 1; i <= 30000; i++) {
    int mn = a[0];
    int mx = a[0];
    for (int j = 1; j < n; j++) {
      mn = min(mn, a[j] - i * j);
      mx = max(mx, a[j] - i * j);
    }
    int h = (mn + mx) >> 1;
    int tmp = max(mx - h, h - mn);
    if (cst > tmp) {
      cst = tmp;
      a1 = h;
      ans = i;
    }
  }
  cout << cst << endl;
  cout << a1 << " " << ans;
  return 0;
}
