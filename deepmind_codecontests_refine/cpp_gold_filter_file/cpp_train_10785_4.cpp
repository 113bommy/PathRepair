#include <bits/stdc++.h>
using namespace std;
int n, k, a[3000], b[3000], p;
int main() {
  cin >> n >> k >> p;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < k; ++i) cin >> b[i];
  sort(a, a + n);
  sort(b, b + k);
  int ans = 2e9 + 100;
  for (int l = 0, r = n - 1; r < k; ++l, ++r) {
    int mx = 0;
    for (int i = 0, j = l; i < n; ++i, ++j)
      mx = max(mx, abs(a[i] - b[j]) + abs(p - b[j]));
    ans = min(mx, ans);
  }
  cout << ans << endl;
  return 0;
}
