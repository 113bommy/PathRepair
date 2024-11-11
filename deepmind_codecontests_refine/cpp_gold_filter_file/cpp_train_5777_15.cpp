#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    cout << "1";
  } else if (n == 2) {
    cout << "1\n";
    cout << "2";
  } else if (n == 3) {
    cout << "2" << endl;
    cout << "1 3";
  } else if (n == 4) {
    cout << "4" << endl;
    cout << "3 1 4 2";
  } else {
    cout << n << "\n";
    for (j = 1; j <= n; j++) {
      if (j % 2 != 0) {
        cout << j << " ";
      }
    }
    for (j = 2; j <= n; j++) {
      if (j % 2 == 0) {
        cout << j << " ";
      }
    }
  }
  return 0;
}
