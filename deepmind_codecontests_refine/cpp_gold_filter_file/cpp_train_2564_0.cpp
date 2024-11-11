#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int r[160] = {0};
  int d[160] = {0};
  int r1[160] = {0};
  int d1[160] = {0};
  if (n == 1) {
    cout << 1 << endl << 0 << " " << 1 << endl << 0 << endl << "1" << endl;
  } else {
    r[0] = -1;
    d[0] = 0;
    d[1] = 1;
    for (int i = 1; i <= n - 1; i++) {
      d1[0] = r[0];
      for (int j = 0; j <= i; j++) {
        r1[j] = d[j];
      }
      for (int j = 0; j <= i; j++) {
        d1[j + 1] = (d[j] + r[j + 1]) % 2;
      }
      d[0] = d1[0];
      for (int j = 0; j <= i; j++) {
        r[j] = r1[j];
      }
      for (int j = 0; j <= i; j++) {
        d[j + 1] = d1[j + 1];
      }
    }
    cout << n << endl;
    for (int j = 0; j <= n; j++) cout << d[j] << " ";
    cout << endl << n - 1 << endl;
    for (int j = 0; j <= n - 1; j++) cout << r[j] << " ";
  }
  return 0;
}
