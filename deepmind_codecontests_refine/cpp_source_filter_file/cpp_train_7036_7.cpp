#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long V;
  cin >> V;
  while (V--) {
    double a[250];
    for (long long i = 0; i < 250; i++) cin >> a[i];
    double exp = 0;
    for (long long i = 0; i < 250; i++) exp += a[i];
    exp /= 250;
    double var = 0;
    for (long long i = 0; i < 250; i++) var += (a[i] - exp) * (a[i] - exp);
    var /= 250;
    double k = exp / var;
    double err = 0.30;
    if (1.0 - err <= k && k <= 1.0 + err)
      cout << "poisson" << endl;
    else
      cout << "uniform" << endl;
  }
  return 0;
}
