#include <bits/stdc++.h>
using namespace std;
long long int dis(long long int n) {
  long long int a[10] = {0};
  long long int c = 0;
  while (n > 0) {
    long long int k = n % 10;
    a[k]++;
    if (a[k] >= 2) {
      return 0;
    }
    n = n / 10;
  }
  return 1;
}
int32_t main() {
  long long int l, r;
  cin >> l >> r;
  if (r < l) {
    cout << -1 << endl;
    return 0;
  }
  long long int n = r - l;
  long long int ans = l, c, check = 0;
  for (long long int i = 1; i < n; i++) {
    ans = l + i;
    c = dis(ans);
    if (c == 1) {
      check = 1;
      cout << ans << endl;
      break;
    }
  }
  if (check == 0) cout << -1 << endl;
  return 0;
}
