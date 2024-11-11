#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long x, q = k - 1, flag, a[k], i, j;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (!i)
      a[q--] = x;
    else {
      flag = 0;
      for (j = k - 1; j > q; j--) {
        if (a[j] == x) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        if (q < 0) {
          for (j = k - 1; j > 0; j--) a[j] = a[j - 1];
          a[0] = x;
        } else
          a[q--] = x;
      }
    }
  }
  cout << k - (q + 1) << endl;
  for (i = q + 1; i < k; i++) cout << a[i] << " ";
}
