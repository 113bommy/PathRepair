#include <bits/stdc++.h>
using namespace std;
int n, k, a[1100], b[1100];
int can(int x) {
  int need = 0;
  for (int i = 1; i <= n; i++) need += max(0, a[i] * x - b[i]);
  if (need > k)
    return 0;
  else
    return 1;
}
int erfen(int l, int r) {
  if (l == r)
    return l;
  else if (l == r - 1) {
    if (can(r))
      return r;
    else
      return l;
  } else {
    int mid = (l + r) / 2;
    if (can(mid))
      return erfen(mid, r);
    else
      return erfen(l, mid - 1);
  }
}
int main() {
  int ans, i;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  ans = erfen(0, 1000);
  cout << ans << endl;
  return 0;
}
