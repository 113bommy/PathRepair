#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, i, j, k, l1, r1, l2, r2, m, n, l;
  cin >> n >> l1 >> r1 >> l2 >> r2;
  long long int ar1[n + 1];
  long long int ar2[n + 1];
  long long int ar3[n + 1];
  for (i = 1; i <= n; i++) cin >> ar1[i];
  ar2[1] = ar1[1] * l1;
  for (i = 2; i <= n; i++) ar2[i] = (ar1[i] * l1) + ar2[i - 1];
  ar3[n] = ar1[n] * r1;
  for (i = n - 1; i > 0; i--) ar3[i] = (ar1[i] * r1) + ar3[i + 1];
  k = min((ar2[n] + l2 * (n - 1)), (ar3[1] + r2 * (n - 1)));
  if (n == 1) {
    cout << k << endl;
    return 0;
  }
  if (n == 2) {
    k = min(k, l1 * ar1[1] + r1 * ar1[2]);
    cout << k << endl;
    return 0;
  }
  for (i = 1; i < n; i++) {
    if (i < n - i) {
      a = (n - i) - i;
      ;
      if (a < 2) a = 2;
      l = ar2[i] + ar3[i + 1] + r2 * (a - 2);
    } else {
      a = i - (n - i);
      if (a < 2) a = 2;
      l = ar2[i] + ar3[i + 1] + l2 * (a - 2);
    }
    k = min(k, l);
  }
  cout << k << endl;
  return 0;
}
