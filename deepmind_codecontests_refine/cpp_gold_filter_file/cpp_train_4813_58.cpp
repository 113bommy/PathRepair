#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int diff = INT_MAX;
    int a1, b1, c1;
    for (int i = 1; i <= 10000; i++) {
      for (int j = i; j <= 20000; j += i) {
        for (int k = j; k <= 50000; k += j) {
          int dif = abs(a - i) + abs(b - j) + abs(c - k);
          if (dif < diff) {
            diff = dif;
            a1 = i;
            b1 = j;
            c1 = k;
          }
        }
      }
    }
    cout << diff << endl << a1 << " " << b1 << " " << c1 << endl;
  }
}
