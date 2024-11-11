#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
ifstream fi("");
ofstream fo("");
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, p;
  cin >> n >> p;
  long double a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  long double m, l = 0, r = 10000000000;
  long double s;
  int it = 200;
  while (it--) {
    m = (l + r) / 2;
    s = 0;
    for (int i = 0; i < n; i++) {
      s += min((long double)0.0, b[i] - m * a[i]);
      if (s < -m * p) {
        r = m;
        continue;
      }
    }
    s += m * p;
    if (s > 0)
      l = m;
    else
      r = m;
  }
  if (l == 10000000000)
    cout << -1;
  else
    cout << setprecision(9) << fixed << l << endl;
}
