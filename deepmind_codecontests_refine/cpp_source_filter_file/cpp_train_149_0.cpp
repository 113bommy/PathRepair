#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int w[n + 1], a[m + 1];
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 0; i <= m; ++i) cin >> a[i];
  bool f[100 * 1000 + 1];
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) f[j] = false;
    for (int j = i - 1; j >= 1; j--) {
      if (a[j] == a[i]) break;
      if (f[a[j]]) continue;
      f[a[j]] = true;
      ans += w[a[j]];
    }
  }
  cout << ans << endl;
}
