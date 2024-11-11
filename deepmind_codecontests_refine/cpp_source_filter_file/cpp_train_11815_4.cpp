#include <bits/stdc++.h>
using namespace std;
long long d[1000006], sum[1000006], ans[1000006] = {0};
int main() {
  long long n, A, i, j, k, S = 0, Z;
  cin >> n >> A;
  for (i = 0; i < n; i++) {
    cin >> d[i];
    S += d[i];
  }
  if (n == 1) {
    cout << d[0] - 1 << endl;
  } else {
    for (i = 0; i < n; i++) {
      sum[i] = S - d[i];
    }
    for (i = 0; i < n; i++) {
      if (d[i] < A) {
        Z = A - sum[i];
        if (Z > 0)
          ans[i] = Z - 1;
        else {
          ans[i] = (d[i] - (A - (n - 1)) > 0 ? d[i] - (A - (n - 1)) : 0);
        }
      } else {
        if (A - sum[i] < 0)
          ans[i] = d[i] - (A - (n - 1));
        else
          ans[i] = d[i] - ((A - (n - 1)) - (A - sum[i] - 1));
      }
    }
    for (i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
