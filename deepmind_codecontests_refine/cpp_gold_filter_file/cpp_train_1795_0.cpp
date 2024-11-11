#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxn = 2e5;
int useless[maxn];
signed main() {
  int t = 1;
  for (int qwerty = 0; qwerty < t; qwerty++) {
    vector<double> a(11);
    for (int i = 0; i < 11; i++) {
      cin >> a[i];
    }
    for (int i = 10; i > -1; i--) {
      cout << "f(" << (int)a[i] << ") = ";
      double f = a[i];
      a[i] = a[i] * a[i] * a[i];
      a[i] *= 5;
      a[i] += sqrt(abs(f));
      if (a[i] >= 400) {
        cout << "MAGNA NIMIS!\n";
      } else {
        cout << setprecision(2) << fixed << a[i] << "\n";
      }
    }
  }
}
