#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, n1;
  cin >> n;
  if (n % 2 == 0) {
    n1 = n / 2;
    if (n1 % 2 == 0) {
      cout << "0" << endl;
      cout << n1 << " ";
      for (i = 1; i <= n1 / 2; i++) cout << i << " " << n + 1 - i << " ";
    } else {
      cout << "1" << endl;
      cout << n1 << " ";
      for (i = 1; i <= n1 / 2; i++) cout << i << " " << n + 1 - i << " ";
      cout << n / 2;
    }
  } else {
    n1 = (n - 1) / 2;
    if (n1 % 2 == 0) {
      cout << 1 << endl;
      cout << n1 + 1 << " ";
      for (i = 1; i <= n1 / 2; i++) {
        cout << i + 1 << " " << n + 1 - i << " ";
      }
    } else {
      cout << "0" << endl;
      cout << n1 + 1 << " ";
      for (i = 1; i <= n1 / 2; i++) {
        cout << i + 1 << " " << n + 1 - i << " ";
      }
      cout << n1 + 1 << " " << 1;
    }
  }
}
