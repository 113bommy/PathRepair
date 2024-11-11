#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 10000;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a" << endl;
    cout << "a" << endl;
    cout << "c" << endl;
    cout << "c" << endl;
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (n % 2 == 0) {
      if (i == 0) {
        for (int j = 0; j < n / 2; j++) {
          if (j % 2) {
            cout << "aa" << flush;
          } else {
            cout << "bb" << flush;
          }
        }
        cout << endl;
      } else if (i == 1) {
        cout << "h" << flush;
        for (int j = 0; j < (n - 2) / 2; j++) {
          if (j % 2) {
            cout << "dd" << flush;
          } else
            cout << "ee" << flush;
        }
        cout << "g" << flush;
        cout << endl;
      } else if (i == 2) {
        cout << "h" << flush;
        for (int j = 0; j < (n - 2) / 2; j++) {
          if (j % 2) {
            cout << "ee" << flush;
          } else
            cout << "dd" << flush;
        }
        cout << "g" << flush;
        cout << endl;
      } else if (i == 3) {
        for (int j = 0; j < n / 2; j++) {
          if (j % 2) {
            cout << "aa" << flush;
          } else {
            cout << "bb" << flush;
          }
        }
        cout << endl;
      }
    } else {
      if (i == 0) {
        for (int j = 0; j < n / 2; j++) {
          if (j % 2)
            cout << "aa" << flush;
          else
            cout << "bb" << flush;
        }
        cout << "c" << flush;
        cout << endl;
      } else if (i == 1) {
        for (int j = 0; j < n / 2; j++) {
          if (j % 2)
            cout << "bb" << flush;
          else
            cout << "aa" << flush;
        }
        cout << "c" << flush;
        cout << endl;
      } else if (i == 2) {
        cout << "c" << flush;
        for (int j = 0; j < n / 2; j++) {
          if (j % 2)
            cout << "dd" << flush;
          else
            cout << "ee" << flush;
        }
        cout << endl;
      } else if (i == 3) {
        cout << "c" << flush;
        for (int j = 0; j < n / 2; j++) {
          if (j % 2)
            cout << "ee" << flush;
          else
            cout << "dd" << flush;
        }
        cout << endl;
      }
    }
  }
}
int main() {
  solve();
  return 0;
}
