#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, mx = 0;
int a[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  for (int i = mx; i >= 0; i--) {
    int cur = i;
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      if (a[j] >= cur) continue;
      if (a[j] < cur) {
        if (a[j + 1] >= cur && j + 1 <= n)
          continue;
        else {
          ok = false;
          break;
        }
      }
    }
    if (ok) return cout << i, 0;
  }
  return 0;
}
