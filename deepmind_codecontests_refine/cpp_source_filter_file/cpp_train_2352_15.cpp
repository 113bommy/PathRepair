#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, a[200];
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = (n + 1) * 100;
  for (int i = m; i <= n; i++) {
    if (a[i] == 0) continue;
    if (a[i] <= k) {
      ans = i - m;
      break;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (a[i] == 0) continue;
    if (a[i] <= k && (m - i) < ans) {
      ans = m - i;
      break;
    }
  }
  cout << ans * 10 << endl;
}
