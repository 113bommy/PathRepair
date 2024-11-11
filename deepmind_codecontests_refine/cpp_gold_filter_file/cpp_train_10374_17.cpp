#include <bits/stdc++.h>
using namespace std;
int a[200005];
int minn[200005];
int ans[200005];
int b[200005];
int main() {
  ios::sync_with_stdio(false);
  ;
  int m, n, i, j, k;
  cin >> m;
  for (i = 1; i <= m; i++) cin >> b[i];
  reverse(b + 1, b + 1 + m);
  for (i = 1; i <= m; i++) a[i] = b[i];
  minn[0] = 999999999;
  for (i = 1; i <= m; i++) minn[i] = min(minn[i - 1], a[i]);
  for (i = 1; i <= m; i++) {
    a[i] *= -1;
    minn[i] *= -1;
  }
  ans[1] = -1;
  for (i = 2; i <= m; i++) {
    int p = upper_bound(minn + 1, minn + i - 1, a[i]) - minn;
    if (a[i] >= a[p])
      ans[i] = -1;
    else
      ans[i] = abs(p - i) - 1;
  }
  for (i = m; i >= 1; i--) cout << ans[i] << ' ';
  cout << endl;
}
