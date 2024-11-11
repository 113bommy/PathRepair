#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    if (n == 1 || n == 2)
      cout << "-1\n";
    else if (n == 3)
      cout << "210\n";
    else {
      if (n % 6 == 1) {
        cout << "1";
        for (int i = 3; i < n; i++) cout << "0";
        cout << "20\n";
      }
      if (n % 6 == 2) {
        cout << "1";
        for (int i = 3; i < n - 1; i++) cout << "0";
        cout << "200\n";
      }
      if (n % 6 == 3) {
        cout << "1";
        for (int i = 3; i < n - 2; i++) cout << "0";
        cout << "320\n";
      }
      if (n % 6 == 4) {
        cout << "1";
        for (int i = 3; i < n; i++) cout << "0";
        cout << "50\n";
      }
      if (n % 6 == 5) {
        cout << "1";
        for (int i = 3; i < n; i++) cout << "0";
        cout << "80\n";
      }
      if (n % 6 == 0) {
        cout << "1";
        for (int i = 3; i < n - 1; i++) cout << "0";
        cout << "170\n";
      }
    }
  }
  return 0;
}
