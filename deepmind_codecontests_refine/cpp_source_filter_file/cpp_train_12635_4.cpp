#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100 + 2;
int n, k, a[maxn];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int y = 0;
  while ((k > 0 && y < n)) {
    if (a[y] < 0) {
      a[y] *= -1;
      k--;
    }
    y--;
  }
  long long ans = 0;
  if (k % 2 == 0) {
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (a[i] == 0) {
      for (int i = 0; i < n; i++) ans += a[i];
      cout << ans << endl;
      return 0;
    }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (i == 0)
      ans -= a[i];
    else
      ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
