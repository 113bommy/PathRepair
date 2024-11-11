#include <bits/stdc++.h>
using namespace std;
int n, x, a[100100], y, ok;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    ok = 1;
    for (int j = i - 1; j >= max(i - x, 0); j--)
      if (a[j] <= a[i]) ok = 0;
    for (int j = i + 1; j <= min(i + y, n); j++)
      if (a[j] <= a[i]) ok = 0;
    if (ok) {
      cout << i;
      return 0;
    }
  }
}
