#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << 2 << endl;
    if (n == 2)
      cout << "1 2\n";
    else if (n == 3)
      cout << "1 3\n2 2\n";
    else if (n == 4)
      cout << "2 4\n3 3\n1 3\n";
    else if (n & 1) {
      cout << n - 2 << " " << n << endl;
      cout << n - 1 << " " << n - 1 << endl;
      cout << n - 3 << " " << n - 1 << endl;
      n -= 2;
      for (int i = 1; i <= n - 2; i++) {
        cout << n - i - 1 << " " << n - i + 1 << endl;
      }
    } else {
      cout << n - 2 << " " << n << endl;
      cout << n - 1 << " " << n - 1 << endl;
      cout << n - 3 << " " << n - 1 << endl;
      cout << n - 4 << " " << n - 2 << endl;
      n -= 3;
      for (int i = 1; i <= n - 2; i++) {
        cout << n - i - 1 << " " << n - i + 1 << endl;
      }
    }
  }
  return 0;
}
