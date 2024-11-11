#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int c[505050];
  memset(c, 0, sizeof(c));
  int k = 0;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x = a[i] + a[j];
      mx = max(x, mx);
      c[x]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < mx; ++i) {
    ans = max(ans, c[i]);
  }
  cout << ans;
  return 0;
}
