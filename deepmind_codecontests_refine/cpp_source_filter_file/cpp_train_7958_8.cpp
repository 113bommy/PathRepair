#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n <= 3)
    cout << "NO\n";
  else {
    cout << "YES\n";
    if (n == 4) {
      cout << "1 + 3 = 4\n";
      cout << "2 + 4 = 6\n";
      cout << "4 * 6 = 24\n";
    } else if (n % 2 == 0) {
      cout << "1 + 5 = 6\n";
      cout << "6 - 3 = 3\n";
      cout << "3 - 2 = 1\n";
      cout << "1 * 6 = 6\n";
      for (int i = 7; i < n; i++) {
        cout << i + 1 << " - " << i << " = "
             << "1\n";
        cout << 1 << " * " << 6 << " = "
             << "6\n";
      }
      cout << "4 * 6 = 24\n";
    } else {
      cout << "1 + 5 = 6\n";
      cout << "3 - 2 = 1\n";
      cout << "1 * 6 = 6\n";
      for (int i = 6; i < n; i++) {
        cout << i + 1 << " - " << i << " = "
             << "1\n";
        cout << 1 << " * " << 6 << " = "
             << "6\n";
      }
      cout << "4 * 6 = 24\n";
    }
  }
}
