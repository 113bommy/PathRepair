#include <bits/stdc++.h>
using namespace std;
long long n, l, r, a[3000003], c[3000003], x = 0, cmin = 999999999999,
                                           cmax = -999999999999;
bool ok = 1;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    cmin = min(c[i] + a[i], cmin);
    cmax = max(c[i] + a[i], cmax);
  }
  if (cmax > r) {
    x = r - cmax;
    if (cmin + x < l) ok = 0;
  } else if (cmin < l) {
    x = l - cmin;
    if (cmax + x > r) ok = 0;
  }
  if (ok) {
    for (int i = 0; i < n; i++) {
      cout << a[i] + c[i] + x << " ";
    }
  } else
    cout << -1 << endl;
}
