#include <bits/stdc++.h>
using namespace std;
int arr[11];
int main() {
  for (int i = 0; i < 11; i++) {
    cin >> arr[i];
  }
  for (int i = 10; i >= 0; i--) {
    cout << "f(" << arr[i] << ") = ";
    double a = sqrt(abs(arr[i]));
    double b = arr[i] * arr[i] * arr[i] * 5;
    double res = a + b;
    if (res < 400)
      cout << fixed << setprecision(2) << res << "\n";
    else
      cout << "MAGNA NIMIS!\n";
  }
  return 0;
}
