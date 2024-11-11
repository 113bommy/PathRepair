#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n < k) {
      cout << k - n << "\n";
    } else if (n == k) {
      cout << "0\n";
    } else {
      if (n % 2 == 0) {
        if (k % 2 == 0) {
          cout << "0\n";
        } else {
          cout << "1\n";
        }
      } else {
        if (k % 2 == 0) {
          cout << "1\n";
        } else {
          cout << "0\n";
        }
      }
    }
  }
  return 0;
}
