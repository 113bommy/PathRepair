#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, ans, i, j, k, p, aa, bb, res;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  res = 1;
  for (ans = 4; ans >= 1; ans--) {
    p = (1 << ans);
    if (p > n) continue;
    for (aa = 0; aa + p <= n; aa += p) {
      bb = aa + p;
      bool valid = true;
      for (i = aa + 1; i < bb; i++) {
        if (a[i] < a[i - 1]) valid = false;
      }
      if (valid) {
        res = p;
        goto outer;
      }
    }
  }
outer:
  cout << res << "\n";
  return 0;
}
