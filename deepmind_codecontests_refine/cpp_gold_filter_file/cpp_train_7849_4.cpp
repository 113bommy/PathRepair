#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);
long long pr[14] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
long long x[10500], sz = 0, kold = 0;
int main() {
  long long n, i, f, k, m;
  scanf("%I64d", &n);
  m = ((n) * (n)) * 2;
  for (i = 0; i < 14; i++) {
    long long koldel = 0;
    x[sz] = pr[i];
    sz++;
    kold++;
    koldel++;
    if (sz == n) {
      sz = 0;
    }
    for (f = 0; f < min(kold, n); f++) {
      if (sz == 1 && kold != 1) {
        f++;
      }
      if (x[f] * pr[i] <= m) {
        x[sz] = x[f] * pr[i];
        sz++;
        kold++;
        koldel++;
        if (sz == n) {
          sz = 0;
        }
        if (koldel >= n - n / 2 && kold >= n) {
          break;
        }
      }
    }
    if (koldel >= n - n / 2 && kold >= n) {
      break;
    }
  }
  sort(&x[0], &x[n]);
  for (i = 0; i < n; i++) {
    cout << x[i] << " ";
  }
  return (0);
}
