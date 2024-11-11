#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q, dmg = 0, l = 0, r, mid;
  cin >> n >> q;
  vector<long long> a(n), k(q);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] += a[i - 1];
  }
  for (int i = 0; i < q; i++) {
    cin >> k[i];
    dmg += k[i];
    r = n;
    while (r - l > 1) {
      mid = (l + r) / 2;
      if (a[mid] > dmg) {
        r = mid;
      } else
        l = mid;
    }
    if (l == n - 1 and a[l] <= dmg) {
      l = 0;
      dmg = 0;
      cout << n << endl;
      continue;
    }
    if (a[l] <= dmg)
      cout << n - l - 1 << endl;
    else
      cout << n - l << endl;
  }
  return 0;
}
