#include <bits/stdc++.h>
using namespace std;
long long n, l, r, i, a[100005], x, m = 1000000000000, mn = 0;
int main() {
  cin >> n >> l >> r;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[i] += x;
    m = min(m, a[i]);
    mn = max(mn, a[i]);
  }
  if (mn - m > r - l)
    cout << -1 << endl;
  else {
    x = m - l;
    for (i = 1; i <= n; i++) cout << a[i] - x << " ";
    cout << endl;
  }
  return 0;
}
