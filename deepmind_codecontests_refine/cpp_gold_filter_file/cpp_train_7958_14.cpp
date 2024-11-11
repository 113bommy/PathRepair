#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 4) {
    cout << "NO" << endl;
    return 0;
  } else if (n >= 6) {
    cout << "YES" << endl;
    cout << "6 * 4 = 24" << endl;
    cout << "3 - 2 = 1" << endl;
    cout << "1 - 1 = 0" << endl;
    cout << "5 * 0 = 0" << endl;
    for (int i = 7; i <= n; i++) {
      cout << i << " * 0 = 0" << endl;
    }
    cout << "24 + 0 = 24" << endl;
  } else if (n == 4) {
    cout << "YES" << endl;
    cout << "3 * 4 = 12" << endl;
    cout << "12 * 2 = 24" << endl;
    cout << "24 * 1 = 24" << endl;
  } else if (n == 5) {
    cout << "YES" << endl;
    cout << "5 * 4 = 20" << endl;
    cout << "3 - 1 = 2" << endl;
    cout << "20 + 2 = 22" << endl;
    cout << "22 + 2 = 24" << endl;
  }
  return 0;
}
