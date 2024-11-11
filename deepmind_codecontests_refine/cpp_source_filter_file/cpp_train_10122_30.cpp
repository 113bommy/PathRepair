#include <bits/stdc++.h>
using namespace std;
int n, i;
string s;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == b) cout << "0" << endl;
    if (a > b) {
      if (a % 2 == 0 && b % 2 == 0) {
        cout << "1" << endl;
      }
      if (a % 2 != 0 && b % 2 == 0) {
        cout << "2" << endl;
      }
      if (a % 2 == 0 && b % 2 != 0) {
        cout << "2" << endl;
      }
      if (a % 2 != 0 && b % 2 != 0) {
        cout << "1" << endl;
      }
    }
    if (b > a) {
      if (a % 2 == 0 && b % 2 != 0) {
        cout << "1" << endl;
      }
      if (a % 2 != 0 && b % 2 == 0) {
        cout << "1" << endl;
      }
      if (a % 2 == 0 && b % 2 == 0) {
        cout << "2" << endl;
      }
      if (a % 2 != 0 && b % 2 != 0) {
        cout << "1" << endl;
      }
    }
  }
  return 0;
}
