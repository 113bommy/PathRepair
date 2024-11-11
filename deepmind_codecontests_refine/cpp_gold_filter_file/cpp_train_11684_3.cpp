#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int db;
    cin >> db;
    if (db == 1) {
      int _1;
      cin >> _1;
      if (_1 % 2 == 0) {
        cout << 1 << endl << 1 << endl;
      } else {
        cout << -1 << endl;
      }
    } else {
      int _1, _2;
      cin >> _1;
      cin >> _2;
      if (_1 % 2 == 0) {
        cout << 1 << endl << 1 << endl;
      } else if (_2 % 2 == 0) {
        cout << 1 << endl << 2 << endl;
      } else {
        cout << 2 << endl << "1 2" << endl;
      }
      int a;
      for (int j = 0; j < db - 2; j++) {
        cin >> a;
      }
    }
  }
}
