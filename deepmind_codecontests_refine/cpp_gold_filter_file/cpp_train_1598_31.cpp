#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = 3.14159265359;
double dpCur[201][401], dpPrev[201][401];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l, k2;
  cin >> n >> l >> k2;
  if (k2 > n) k2 = n;
  vector<double> prob(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> prob[i];
    prob[i] /= 100;
  }
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > n) a[i] = n;
  }
  dpPrev[0][n + k2] = 1;
  for (int i = 1; i <= n; i++) {
    for (int win = 0; win <= i; win++) {
      for (int xs = -n; xs <= n; xs++) {
        dpCur[win][n + xs] += dpPrev[win][n + xs] * (1 - prob[i]);
        if (win) {
          if (a[i] == -1) {
            if (xs != n)
              dpCur[win][n + xs] += prob[i] * dpPrev[win - 1][n + xs + 1];
          } else {
            dpCur[win][min(xs + n + a[i], 2 * n)] +=
                prob[i] * dpPrev[win - 1][n + xs];
          }
        }
      }
    }
    for (int win = 0; win <= i; win++) {
      for (int xs = -n; xs <= n; xs++) {
        dpPrev[win][n + xs] = dpCur[win][n + xs];
        if (i != n) dpCur[win][n + xs] = 0;
      }
    }
  }
  double ans = 0;
  for (int win = l; win <= n; win++) {
    for (int xs = 0; xs <= n; xs++) {
      ans += dpCur[win][n + xs];
    }
  }
  cout << setprecision(12) << ans;
}
