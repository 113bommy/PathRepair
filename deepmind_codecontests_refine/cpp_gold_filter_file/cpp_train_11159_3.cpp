#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long t, flag = 0;
  cin >> t;
  while (t--) {
    long n;
    cin >> n;
    if (n >= 0) {
      if (n % 2 != 0) {
        if (flag == 1) {
          cout << n / 2 + 1 << "\n";
          flag = 0;
        } else {
          cout << n / 2 << "\n";
          flag = 1;
        }
      } else {
        cout << n / 2 << "\n";
      }
    } else {
      if (n % 2 != 0) {
        if (flag == 0) {
          cout << n / 2 - 1 << "\n";
          flag = 1;
        } else {
          cout << n / 2 << "\n";
          flag = 0;
        }
      } else {
        cout << n / 2 << "\n";
      }
    }
  }
}
