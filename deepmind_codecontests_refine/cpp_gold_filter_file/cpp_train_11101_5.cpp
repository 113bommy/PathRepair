#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000], c[1000];
int main() {
  int n;
  cin >> n;
  a[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) c[j] = a[j];
    if (i % 2 == 0) {
      for (int j = i + 1; j >= 0; j--) {
        if (j) {
          if (a[j - 1] && !b[j])
            a[j] = a[j - 1];
          else if (!a[j - 1] && b[j])
            a[j] = b[j];
          else
            a[j] = 0;
        } else
          a[j] = b[j];
      }
    } else {
      for (int j = i + 1; j >= 0; j--) {
        if (j) {
          if (a[j - 1] && !b[j])
            a[j] = a[j - 1];
          else if (!a[j - 1] && b[j])
            a[j] = -b[j];
          else
            a[j] = 0;
        } else
          a[j] = -b[j];
      }
    }
    for (int j = 0; j <= i; j++) b[j] = c[j];
  }
  cout << n << endl;
  for (int i = 0; i <= n; i++) cout << a[i] << " ";
  cout << endl;
  cout << n - 1 << endl;
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
}
