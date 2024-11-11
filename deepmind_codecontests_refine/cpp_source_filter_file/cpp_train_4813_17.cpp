#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long int min = 100000;
    int A, B, C;
    for (int i = 1; i <= b; i++) {
      int temp = a - i;
      if (temp < 0) temp = temp * (-1);
      for (int j = i; j <= 10000; j += i) {
        int temp2 = b - j;
        if (temp2 < 0) temp2 = temp2 * (-1);
        for (int k = j; k <= 10000; k += j) {
          int temp3 = c - k;
          if (temp3 < 0) temp3 = temp3 * (-1);
          int sum = temp + temp2 + temp3;
          if (sum < min) {
            min = sum;
            A = i;
            B = j;
            C = k;
          }
        }
      }
    }
    cout << min << "\n";
    cout << A << " " << B << " " << C << "\n";
  }
}
