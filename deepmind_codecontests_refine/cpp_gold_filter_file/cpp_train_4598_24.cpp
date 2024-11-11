#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> a, lft, rit, rs, ls;
int main(void) {
  cin >> n >> x;
  a.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  lft.assign(x + 2, n + 1);
  rit.assign(x + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (lft[a[i]] == n + 1) lft[a[i]] = i;
    rit[a[i]] = i;
  }
  ls.assign(x + 2, n + 1);
  rs.assign(x + 1, 0);
  for (int i = 1; i <= x; i++) {
    rs[i] = rs[i - 1];
    if (rs[i] < rit[i]) rs[i] = rit[i];
  }
  for (int i = x; i >= 0; i--) {
    ls[i] = ls[i + 1];
    if (ls[i + 1] < rit[i]) ls[i] = -1;
    if (ls[i] > lft[i]) ls[i] = lft[i];
  }
  long long ans = 0;
  for (int l = 1; l <= x; l++) {
    if (l >= 2 && lft[l - 1] < rs[l - 2]) break;
    int ng = l - 1, ok = x;
    while (ng + 1 < ok) {
      int mid = (ng + ok) / 2;
      if (ls[mid + 1] < rs[l - 1])
        ng = mid;
      else
        ok = mid;
    }
    ans += x - ng;
  }
  cout << ans << endl;
}
