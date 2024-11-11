#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, x, p, l, r, e, ans, set;
  l = r = e = ans = 0;
  cin >> n >> x;
  vector<long long int> a(n);
  set = 0;
  m = (n + 1) / 2;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < x) l++;
    if (a[i] > x) r++;
    if (a[i] == x) e++;
  }
  if (e == 0)
    ans++;
  else
    e--;
  set = 1;
  if (e >= abs(r - l)) {
    cout << ans << "\n";
    return 0;
  }
  if (l < r) {
    l += e;
    e = 0;
    cout << ans + (r - 1) - l << endl;
  } else {
    r += e;
    e = 0;
    cout << ans + l - r << endl;
  }
}
