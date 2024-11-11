#include <bits/stdc++.h>
using namespace std;
int a[181], b[181], ans[181], n, m, k, i, j, l, kol, little;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (i = 1; i <= m; i++) cin >> a[i];
  for (i = 1; i <= k; i++) cin >> b[i];
  little = 1000000000;
  for (i = 1; i <= m; i++) {
    kol = 0;
    for (j = 1; j <= k; j++)
      if (b[j] % a[i] == 0) kol++;
    if (kol < little) {
      little = kol;
      l = 0;
    }
    if (kol == little) {
      l++;
      ans[l] = i;
    }
  }
  cout << l << '\n';
  for (i = 1; i <= l - 1; i++) cout << ans[i] << " ";
  cout << ans[l] << '\n';
  return 0;
}
