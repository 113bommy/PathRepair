#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 10;
double L[MAXN], R[MAXN];
int n;
double abaixo(int v, int i) {
  if (v <= L[i]) return 0.;
  if (v > R[i]) return 1.;
  return (v - L[i]) / (R[i] - L[i] + 1);
}
double igual(int v, int i) {
  if (v < L[i]) return 0.;
  if (v > R[i]) return 0.;
  return 1. / (R[i] - L[i] + 1);
}
double acima(int v, int i) {
  if (v >= R[i]) return 0.;
  if (v < L[i]) return 1.;
  return (R[i] - v) / (R[i] - L[i] + 1);
}
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> L[i] >> R[i];
    double ans = 0;
    for (int i = 1; i < 10001; ++i) {
      double res = 0;
      int m = 1;
      for (int j = 0; j < n; ++j) m *= 3;
      for (int j = 0; j < m; ++j) {
        int c1 = 0, c2 = 0, c0 = 0;
        double p = 1.;
        int tmp = j;
        for (int k = 0; k < n; ++k) {
          int x = tmp % 3;
          if (x == 0) {
            c0++;
            p *= abaixo(i, k);
          } else if (x == 1) {
            p *= igual(i, k);
            c1++;
          } else {
            p *= acima(i, k);
            c2++;
          }
          tmp /= 3;
        }
        if ((c2 == 0 && c1 > 1) || (c2 == 1 && c1 > 0)) {
          res += p;
        }
      }
      ans += res * i;
    }
    cout << setprecision(15) << fixed << ans << endl;
  }
}
