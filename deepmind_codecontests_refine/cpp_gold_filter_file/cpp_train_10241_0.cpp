#include <bits/stdc++.h>
using namespace std;
int x[500111], v[5001111], n;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> v[i];
  double ll = 0, rr = 1000111222;
  while (abs(rr - ll) > 1e-9) {
    double mid = (ll + rr) / 2;
    bool enek = false;
    double tekan = -1e50;
    for (int i = 1; i <= n; i++) {
      if (v[i] > 0)
        tekan = max(tekan, x[i] + mid * v[i]);
      else if (x[i] + mid * v[i] <= tekan)
        enek = true;
    }
    if (enek)
      rr = mid;
    else
      ll = mid;
  }
  if (rr >= 1000111222)
    cout << -1 << endl;
  else
    cout << setprecision(11) << fixed << (ll + rr) / 2 << endl;
}
