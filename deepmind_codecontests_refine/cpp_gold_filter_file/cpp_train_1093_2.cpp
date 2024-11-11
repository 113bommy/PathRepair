#include <bits/stdc++.h>
using namespace std;
int ar[100010];
int32_t main() {
  int n, k;
  cin >> n >> k;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    m = max(m, ar[i]);
  }
  if (k > n) {
    cout << m;
    return 0;
  }
  int j = n - k - 1, ans = 0, i = n - k;
  for (i = n - k; i < n && j >= 0; i++, j--) {
    ans = max(ans, ar[i] + ar[j]);
  }
  for (; i < n; i++) {
    ans = max(ans, ar[i]);
  }
  cout << ans;
  return 0;
}
