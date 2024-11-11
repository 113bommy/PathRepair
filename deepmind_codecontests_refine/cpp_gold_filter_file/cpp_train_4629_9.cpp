#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n >= 4) {
    cout << "YES" << endl;
    if (n == 4) {
      cout << "1 * 2 = 2" << endl;
      cout << "2 * 3 = 6" << endl;
      cout << "6 * 4 = 24" << endl;
    } else if (n == 5) {
      cout << "5 * 4 = 20" << endl;
      cout << "3 + 20 = 23" << endl;
      cout << "2 - 1 = 1" << endl;
      cout << "23 + 1 = 24" << endl;
    } else if (n % 2 == 0) {
      for (int i = 6; i <= n; i += 2) {
        cout << i << " - " << i - 1 << " = 1" << endl;
        cout << "1 * 1 = 1" << endl;
      }
      cout << "1 * 2 = 2" << endl;
      cout << "2 * 3 = 6" << endl;
      cout << "6 * 4 = 24" << endl;
    } else {
      for (int i = 7; i <= n; i += 2) {
        cout << i << " - " << i - 1 << " = 1" << endl;
        cout << "1 * 1 = 1" << endl;
      }
      cout << "5 * 4 = 20" << endl;
      cout << "3 + 20 = 23" << endl;
      cout << "2 - 1 = 1" << endl;
      cout << "23 + 1 = 24" << endl;
    }
  } else
    cout << "NO";
  return 0;
}
