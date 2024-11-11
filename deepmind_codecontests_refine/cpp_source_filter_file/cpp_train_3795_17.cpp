#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t, tr;
  cin >> n;
  m = (n / 2) + 1;
  t = (n - 1);
  for (int i = 1; i <= n; i++) {
    if (i == m) {
      for (int j = 1; j <= n; j++) {
        cout << "D";
      }
      tr = 5;
      t = t + 2;
    } else if (tr == 5) {
      for (int k = 1; k <= t / 2; k++) {
        cout << "*";
      }
      for (int k = 1; k <= n - t; k++) cout << "D";
      for (int k = 1; k <= t / 2; k++) cout << "*";
      t = t + 2;
    } else {
      for (int k = 1; k <= t / 2; k++) {
        cout << "*";
      }
      for (int k = 1; k <= n - t; k++) cout << "D";
      for (int k = 1; k <= t / 2; k++) cout << "*";
      t = t - 2;
    }
    cout << endl;
  }
  return 0;
}
