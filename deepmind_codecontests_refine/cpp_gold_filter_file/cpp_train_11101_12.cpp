#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, j, i, p;
  cin >> n;
  long long a[200], b[200], la = 2, lb = 1;
  a[0] = 0;
  a[1] = 1;
  b[0] = 1;
  for (i = 2; i <= n; i++) {
    long long c[la];
    for (j = 0; j < la; j++) c[j] = a[j];
    for (j = la; j > 0; j--) {
      a[j] = a[j - 1];
    }
    a[0] = 0;
    p = 0;
    for (j = 0; j < lb; j++) {
      if ((a[j] == 1 && b[j] == 1) || (a[j] == -1 && b[j] == -1)) {
        p = 1;
        break;
      }
    }
    if (p == 0) {
      for (j = 0; j < lb; j++) a[j] += b[j];
    } else {
      for (j = 0; j < lb; j++) a[j] -= b[j];
    }
    la++;
    lb++;
    for (j = 0; j < lb; j++) b[j] = c[j];
  }
  cout << la - 1 << endl;
  for (i = 0; i < la; i++) cout << a[i] << " ";
  cout << endl;
  cout << lb - 1 << endl;
  for (i = 0; i < lb; i++) cout << b[i] << " ";
  return 0;
}
