#include <bits/stdc++.h>
using namespace std;
long long int n, r, k, i;
long long int a[500005], b[500005], lb, ub, md, now, alr, ans;
bool calc() {
  memcpy(b, a, sizeof(a));
  now = 0;
  alr = 0;
  for (i = 0; i <= r; i++) now += b[i + 1];
  for (i = 1; i <= n; i++, now += b[i + r]) {
    if (now < md) {
      alr += md - now;
      b[i + r] += md - now;
      now = md;
      if (alr > k) return false;
    }
    if (i > r) now -= b[i - r];
  }
  return true;
}
int main() {
  lb = INT_MAX;
  cin >> n >> r >> k;
  for (i = 1; i <= n; i++) cin >> a[i], lb = min(lb, a[i]);
  ub = 1000000000000000000;
  while (lb <= ub) {
    md = (lb + ub) / 2;
    if (calc())
      ans = md, lb = md + 1;
    else
      ub = md - 1;
  }
  cout << ans << "\n";
  return 0;
}
