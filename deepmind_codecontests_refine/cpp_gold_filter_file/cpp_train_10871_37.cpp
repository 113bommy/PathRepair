#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans, fi, x;
  for (int d = 0; d <= 20000; d++) {
    int mi = 1e9, ma = -1e9;
    for (int i = 1; i <= n; i++) {
      mi = min(mi, (i - 1) * d - a[i]);
      ma = max(ma, (i - 1) * d - a[i]);
    }
    int mid = (ma + mi) / 2;
    int op = max(ma - mid, mid - mi);
    if (!d || ans > op) {
      x = d;
      fi = -mid;
      ans = op;
    }
  }
  cout << ans << "\n" << fi << " " << x;
}
