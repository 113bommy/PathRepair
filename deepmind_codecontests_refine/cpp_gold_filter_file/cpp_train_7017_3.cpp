#include <bits/stdc++.h>
using namespace std;
int ans[512345], a[3];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) ans[i] = -1;
  for (int i = 0; i < m; ++i) {
    cin >> a[0] >> a[1] >> a[2];
    bool fl = true;
    for (int j = 0; j < 3; ++j)
      if (ans[a[j]] != -1) {
        fl = false;
        ans[a[(j + 1) % 3]] = (ans[a[j]] + 1) % 3;
        ans[a[(j + 2) % 3]] = (ans[a[j]] + 2) % 3;
        break;
      }
    if (fl)
      for (int j = 0; j < 3; ++j) ans[a[j]] = j;
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] + 1 << " ";
  return 0;
}
