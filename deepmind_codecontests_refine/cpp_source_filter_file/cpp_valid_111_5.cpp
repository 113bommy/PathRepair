#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "()" << endl;
    } else if (n == 2) {
      cout << "()" << endl;
      cout << "(())" << endl;
    } else {
      for (int i = 1; i <= n; i++) {
        int k = 2 * n;
        for (int j = 0; j < i; j++) {
          cout << "(";
        }
        for (int j = 0; j < i; j++) {
          cout << ")";
        }
        k = k - (2 * i);
        for (int j = 0; j < k / 2; j++) {
          cout << "()";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
