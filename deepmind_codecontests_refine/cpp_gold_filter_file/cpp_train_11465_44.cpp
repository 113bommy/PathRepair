#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double *arr1 = new double[n];
  double d, a1, a2, b1, b2;
  double *arr2 = new double[n];
  char *arr = new char[n];
  for (int i = 0; i < n; i++) {
    cin >> d;
    while (d < 0) cin >> d;
    if (d == 0) {
      arr[i] = 'Y';
      arr1[i] = 0.000000000;
      arr2[i] = 0.000000000;
    } else if (d > 0 && d < 4) {
      arr[i] = 'N';
      arr1[i] = 0.000000000;
      arr2[i] = 0.000000000;
    } else if (d == 4) {
      arr[i] = 'Y';
      arr1[i] = 2.00000000;
      arr2[i] = 2.000000000;
    } else {
      b1 = (d - sqrt(d * d - 4 * d)) / 2;
      a1 = d - b1;
      if (b1 + a1 == d && b1 * a1 == d) {
        arr[i] = 'Y';
        arr1[i] = a1;
        arr2[i] = b1;
      } else {
        b2 = (d + sqrt(d * d - 4 * d)) / 2;
        a2 = d - b2;
        arr[i] = 'Y';
        arr1[i] = a2;
        arr2[i] = b2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 'N')
      cout << setprecision(11) << arr[i] << endl;
    else
      cout << setprecision(11) << arr[i] << " " << setprecision(11) << arr2[i]
           << " " << setprecision(11) << arr1[i] << endl;
  }
  delete[] arr;
  delete[] arr1;
  delete[] arr2;
  return 0;
}
