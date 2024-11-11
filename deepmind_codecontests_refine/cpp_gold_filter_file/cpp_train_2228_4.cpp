#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int main() {
  cin >> k >> n;
  int a[n + 1];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  ans = INT_MAX;
  for (int i = 0; i <= n - k; ++i) {
    ans = min(ans, a[i + k - 1] - a[i]);
  }
  cout << ans << endl;
  return 0;
}
