#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << 1 << " " << a[0] << " " << 0 << endl;
    } else {
      int i = 0, j = n - 1, c = 0, suma, aa = 0, b = 0, pre = 0;
      while (i <= j) {
        suma = 0;
        while (i <= j && suma <= pre) {
          suma += a[i];
          i++;
        }
        c++;
        aa += suma;
        pre = suma;
        suma = 0;
        if (i <= j) {
          while (i <= j && suma <= pre) {
            suma += a[j];
            j--;
          }
          b += suma;
          pre = suma;
          c++;
        }
      }
      cout << c << " " << aa << " " << b << endl;
    }
  }
  return 0;
}
