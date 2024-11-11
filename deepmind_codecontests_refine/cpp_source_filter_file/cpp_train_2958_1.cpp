#include <bits/stdc++.h>
using namespace std;
int n, m, a[200], b[200];
int ma, mi;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  ma = a[1];
  for (int i = 2; i <= n; i++) ma = max(ma, a[i]);
  mi = b[1];
  for (int i = 2; i <= m; i++) mi = min(ma, b[i]);
  while (ma < mi) {
    bool ok = true;
    for (int i = 1; i <= n; i++)
      if (a[i] * 2 <= ma) {
        ok = false;
      }
    if (ok) {
      ma++;
      continue;
    }
    for (int i = 1; i <= m; i++)
      if (ma >= b[i]) {
        ma++;
        continue;
      }
    cout << ma;
    return 0;
  }
  cout << -1;
}
