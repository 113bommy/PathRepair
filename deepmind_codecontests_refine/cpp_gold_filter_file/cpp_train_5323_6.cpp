#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 7 == 0) {
    n /= 7;
    while (n--) cout << "7";
    cout << endl;
  } else if ((n % 7 == 1 && n != 1)) {
    n /= 7;
    cout << "44";
    while (n != 1) {
      cout << "7";
      n--;
    }
    cout << endl;
  } else if (n % 7 == 4 && n != 4) {
    cout << "4";
    n /= 7;
    while (n--) cout << "7";
    cout << endl;
  } else if (n % 7 == 5 && n != 5) {
    cout << "444";
    n /= 7;
    while (n != 1) {
      cout << "7";
      n--;
    }
    cout << endl;
  } else if (n % 7 == 3 && n != 3 && n / 7 > 3) {
    cout << "444444";
    n /= 7;
    n -= 3;
    while (n--) cout << "7";
    cout << endl;
  } else if (n % 7 == 6 && n != 6 && n / 7 > 2) {
    cout << "44444";
    n /= 7;
    n -= 2;
    while (n--) cout << "7";
    cout << endl;
  } else if (n % 7 == 2 && n != 2 && n / 7 > 2) {
    n /= 7;
    n -= 2;
    cout << "4444";
    while (n--) cout << "7";
    cout << endl;
  } else if ((n % 4 == 3 && n != 3)) {
    n /= 4;
    while (n != 1) {
      cout << "4";
      n--;
    }
    cout << "7\n";
  } else if (n % 4 == 0) {
    n /= 4;
    while (n--) cout << "4";
    cout << endl;
  } else
    cout << -1 << endl;
}
